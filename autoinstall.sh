#!/bin/bash
echo 'ADDING REPOSITORY'
echo 'deb http://ftp.us.debian.org/debian wheezy main' >> /etc/apt/sources.list
echo '# deb-src http://ftp.us.debian.org/debian wheezy main' >> /etc/apt/sources.list
echo 'UPDATING PACKAGE LISTS'
apt-get update
echo 'INSTALLING USBIP'
apt-get install usbip -y --force-yes
echo 'REMOVING DEBIAN REPOSITORY'
sed -i '$d' /etc/apt/sources.list
sed -i '$d' /etc/apt/sources.list
echo 'usbip-core' >> /etc/modules
echo 'usbip-host' >> /etc/modules
echo 'vhci_hcd' >> /etc/modules
reboot
