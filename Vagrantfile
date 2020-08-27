# -*- mode: ruby -*-
# vi: set ft=ruby :

hosts = {
  "host0" => "10.10.58.58"
}

Vagrant.configure("2") do |config|
  hosts.each do |name, ip|
    config.vm.define name do |machine|
      machine.vm.box = "ubuntu/bionic64"
      machine.vm.hostname = "%s" % name
      machine.vm.network :private_network, ip: ip
      machine.vm.provider "virtualbox" do |v|
          v.name = name
          v.customize ["modifyvm", :id, "--memory", 512]
      end
      machine.vm.provision "shell", inline: <<-SHELL
            apt-get install -y apt-transport-https ca-certificates curl software-properties-common
            curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
            apt-get update
          SHELL
    end
  end
end
