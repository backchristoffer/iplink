## iplink
Basic container running "ip -s link" 

## iperf3
Test bandwidth
https://iperf.fr/

### How to deploy iplink on all nodes
$ oc create -f https://raw.githubusercontent.com/backchristoffer/iplink/master/setup/iplink-deploy.yaml

### How to setup iplink and iperf3 on all nodes
$ ansible-playbook iperf-test-playbook.yaml

### How to build iperf3-handler
$ docker build --file ./Docker/Dockerfile.iperf3handler -t iperf3handler . --no-cache --progress=plain

### How to deploy iperf3-server standalone
$ ansible-playbook iperf3-server.yaml
