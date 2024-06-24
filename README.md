## Description
Used to read network interface counters (RX&TX). iperf3 is there to run "traffic" on the interfaces so I can see if counters ramp up. 
This was originally used to test if we could view network interface counters through OCP4 with iplink.

## iplink
Basic container running "ip -s link".   

## iperf3
Test bandwidth
https://iperf.fr/

### How to deploy iplink on all nodes
$ oc create -f https://raw.githubusercontent.com/backchristoffer/iplink/master/setup/iplink-deploy.yaml

### How to setup iplink and iperf3 on all nodes
$ ansible-playbook iperf-test-playbook.yaml

### How to deploy iperf3-server standalone
$ ansible-playbook iperf3-server.yaml
