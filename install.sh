#!/bin/bash
#########################################################################
# File Name: install.sh
# Author: steve
# mail: yqykrhf@163.com
# Created Time: Wed 12 Oct 2022 02:06:03 PM CST
# Brief: install iipllib
#########################################################################
set -e
sudo apt update
sudo apt install -y libboost-all-dev libgoogle-glog-dev
cmake -B build
cmake --build build
sudo make install
