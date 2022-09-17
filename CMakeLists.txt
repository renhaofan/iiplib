cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(iiplib
  VERSION 0.0.0
  DESCRIPTION "IIPL lab C++ utilis moduel, include logging, timer..."
  HOMEPAGE_URL https://github.com/renhaofan/iiplib
  LANGUAGES CXX
)


#if(LOGGING)
#    cmake option
#    add_definitions("-DLOGGING")
#endif(LOGGING)

################################################################################

# log info configuration
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLOGGING") # enable
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLOGTOSTD") # print to std

################################################################################

################################################################################
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
################################################################################


################################################################################
# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
################################################################################


################################################################################
# include modern json C++
include_directories(3rdparty/json)

# include yaml-cpp

#set(yaml-cpp_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/yaml-cpp/build)
#find_package(yaml-cpp REQUIRED)
#include_directories(${YAML_CPP_INCLUDE_DIR})

include_directories(3rdparty/yaml-cpp/include)
set(YAML_CPP_LIB ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/yaml-cpp/build/libyaml-cpp.so)

# find gflags
set(gflags_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gflags/build)
find_package(gflags REQUIRED)
include_directories(${GFLAGS_INCLUDE_DIRS})

# sudo apt install libgoogle-glog-dev
# [TODO] change glog used in 3rdparty, now is apt installation
#set(glog_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/glog/build)
find_package(PkgConfig REQUIRED)
pkg_check_modules(glog REQUIRED libglog)
include_directories(${GLOG_INCLUDE_DIRS})

# find boost
find_package(Boost COMPONENTS filesystem)
# reference: https://stackoverflow.com/questions/53647596/building-boost-from-sources-on-linux
if(Boost_FOUND)
    message(STATUS "Boost found")
    include_directories(${BOOST_INCLUDE_DIRS})
else()
    message(STATUS "Boost not found")
endif()

# include iiplib libraries
#include_directories(log)
#include_directories(timer)
#include_directories(config)

################################################################################

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples)
add_subdirectory(examples)
#add_subdirectory(timer)
#add_subdirectory(log)
#add_subdirectory(config)




#CMake Error at CMakeLists.txt:16 (find_package):
#By not providing "Findglog.cmake" in CMAKE_MODULE_PATH this project has
#asked CMake to find a package configuration file provided by "glog", but
#CMake did not find one.
#
#Could not find a package configuration file provided by "glog" with any of
#the following names:
#
#glogConfig.cmake
#glog-config.cmake
#
#Add the installation prefix of "glog" to CMAKE_PREFIX_PATH or set
#"glog_DIR" to a directory containing one of the above files.  If "glog"
#provides a separate development package or SDK, be sure it has been
#installed.

# useful command maybe
#set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
#list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
#find_package(glog REQUIRED)

#cmake --help-command link_directories