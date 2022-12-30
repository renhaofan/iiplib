# IIPL
This is encapsule of glog offering cross-file function.

In the future, I will import json parser and something else.
So far, only cross-file log function is supplied.

# Install

```
bash install.sh
```

# Usage
After installation, a simple demo by CMakelists.txt:
```
find_package(iipl REQUIRED)

if(iipl_FOUND)
    message(STATUS "iipl found")
else()
    message(STATUS "iipl not found")
endif()


add_executable(test test.cpp)
target_link_libraries(test iipl)
```

See more details on run it in test folder.

# TODO
* // TODO: after making install, error occours:
  // engine.cpp:(.text+0x13e): undefined reference to `fLU::FLAGS_max_log_size'
  // // FLAGS_max_log_size = 16;        // set max log file size(MB)
  // FLAGS_stop_logging_if_full_disk = true;  // If disk if full
* install glog gflag in cmake
* Add examples
* ~~marco LOGTOSTD not work~~
* ~~make uninstall~~
* ~~enable -logtostd after installed~~

# Reference
* [CMake install scripts](https://www.jianshu.com/p/ab7a94115d10)
* [CMake uninstall](https://blog.csdn.net/weixin_43742643/article/details/115293427)