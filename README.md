###How to test

`vagrant up` up vm with 512Mb

`ansible-playbook -i ./hosts makeit.yml` role ufw deny all connections for ssh except `100.100.100.100, 101.100.100.101`

