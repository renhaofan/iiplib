#!/bin/bash
#########################################################################
# File Name: install.sh
# Author: steve
# mail: yqykrhf@163.com
# Created Time: Wed 12 Oct 2022 02:06:03 PM CST
# Brief: install iipllib
#########################################################################
set -e
sudo apt install -y libboost-all-dev libgoogle-glog-dev libgflags-dev
git clone -b yaml-cpp-0.7.0 https://github.com/jbeder/yaml-cpp.git

cd yaml-cpp
mkdir build
cd build
cmake -DYAML_BUILD_SHARED_LIBS=ON ..
make
sudo make install


