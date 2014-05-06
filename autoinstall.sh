#!/bin/bash
echo 'deb http://ftp.us.debian.org/debian wheezy main' >> /etc/apt/sources.list
echo '# deb-src http://ftp.us.debian.org/debian wheezy main' >> /etc/apt/sources.list
apt-get update
apt-get install usbip -y

