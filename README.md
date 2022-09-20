# iiplib

```
set -e
cd 3rdparty
git clone -b v0.6.0 https://github.com/google/glog
git clone -b v2.2.2 https://github.com/gflags/gflags.git
git clone -b yaml-cpp-0.7.0 https://github.com/jbeder/yaml-cpp.git

## ERROR
cd glog
cmake -B build
cmake --build build
cd ..

## PASS
cd gflags
cmake -B build
cmake --build build
cd ..

## PASS
cd yaml-cpp
mkdir build 
cd build
cmake -DYAML_BUILD_SHARED_LIBS=ON ..
make

```


# TODO
* write json and yaml cpp, then test. NOTICE judege the config mode
* use a single shared library iipl
* All libraries located in 3rdparty rather than local environement
* gtest????
* #include<iipl> rather than #include "iipl.h" 
* https://github.com/gflags/example
  参考这里把库线程download的形式
* https://www.jianshu.com/p/ab7a94115d10
