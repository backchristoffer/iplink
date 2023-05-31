# iplink
Test container with ip link. Mainly for OCP4.10 and later.

# How to deploy iplink on all nodes
$ oc create -f https://raw.githubusercontent.com/backchristoffer/iplink/master/setup/iplink-deploy.yaml

# How to setup iplink and iperf3 on all nodes
$ ansible-playbook iperf-test-playbook.yaml
