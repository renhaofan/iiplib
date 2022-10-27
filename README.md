# iiplib

# 安装 
```
bash install.sh
```

# 使用
```CMake
# CMakelist.txt
find_package(iipl)
add_executable(find_iipl main.cpp)
target_link_libraries(find_iipl iipl)
```

```cpp
// main.cpp
int main(int argc, char** argv) {

  iiplib::init(&argc, &argv);


  log_tic(test);
  iiplib::IIPLEngine::instance()->print_test();
  log_toc(test);

  LOG_WARNING("this is warning");
  LOG_ERROR("this is error");

  iiplib::shutdown();
}
```



# TODO
* ~~make uninstall~~
* enable -logtostd after installed
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
