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

* https://github.com/gflags/example
参考这里把库线程download的形式
* boost & glog into 3rdparty