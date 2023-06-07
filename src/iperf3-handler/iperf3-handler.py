import time
from kubernetes import config
from kubernetes.client import Configuration
from kubernetes.client.api import core_v1_api
from kubernetes.client.rest import ApiException
from kubernetes.stream import stream

def exec_commands(api_instance):
    name = 'iperf3-client'
    namespace = 'iplink'
    image = 'ghcr.io/backchristoffer/iperf3:latest'
    resp = None
    try:
        resp = api_instance.read_namespaced_pod(name=name,
                                                namespace=namespace)
    except ApiException as e:
        if e.status != 404:
            print("Unknown error: %s" % e)
            exit(1)

    if not resp:
        print("Pod %s does not exist. Creating it..." % name)
        pod_manifest = {
            'apiVersion': 'v1',
            'kind': 'Pod',
            'metadata':{
                'namespace': 'iplink',
                'name': name
            },
            'spec': {
                'containers': [{
                    'name': 'iperf3-client',
                    'image': 'ghcr.io/backchristoffer/iperf3:latest',
                    'command': ['/bin/sh', '-c', 'sleep infinity']
                }]
            }
        }
        resp = api_instance.create_namespaced_pod(body=pod_manifest,
                                                  namespace=namespace)
        while True:
            resp = api_instance.read_namespaced_pod(name=name,
                                                    namespace=namespace)
            if resp.status.phase != 'Pending':
                break
            time.sleep(1)
        print("Done.")

    exec_command = [
        'iperf3',
        '-c',
        'iperf3-server']
    resp = stream(api_instance.connect_get_namespaced_pod_exec,
                  name,
                  namespace,
                  command=exec_command,
                  stderr=True, stdin=False,
                  stdout=True, tty=False)
    print("Response: " + resp)

def main():
    config.load_kube_config()
    try:
        c = Configuration().get_default_copy()
    except AttributeError:
        c = Configuration()
        c.assert_hostname = False
    Configuration.set_default(c)
    core_v1 = core_v1_api.CoreV1Api()
    exec_commands(core_v1)


if __name__ == '__main__':
    main()