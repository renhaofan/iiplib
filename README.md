# iiplib

# 安装 
```
bash install.sh
```

# 使用
见test文件夹



# TODO
* // TODO: after making install, error occours:
  // engine.cpp:(.text+0x13e): undefined reference to `fLU::FLAGS_max_log_size'
  // // FLAGS_max_log_size = 16;        // set max log file size(MB)
  // FLAGS_stop_logging_if_full_disk = true;  // If disk if full
* install glog gflag in cmake
* marco LOGTOSTD not work
* ~~make uninstall~~
* ~~enable -logtostd after installed~~
```
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLOGTOSTD") # print to std
```

* write json and yaml cpp, then test. NOTICE judege the config mode
* use a single shared library iipl
* All libraries located in 3rdparty rather than local environement
* gtest????
* #include<iipl> rather than #include "iipl.h" 
* https://github.com/gflags/example
  参考这里把库线程download的形式
* https://www.jianshu.com/p/ab7a94115d10
* https://blog.csdn.net/weixin_43742643/article/details/115293427
