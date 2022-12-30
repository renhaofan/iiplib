cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(iipl
  VERSION 0.0.1
  DESCRIPTION "IIPL lab C++ utilis moduel, include logging, timer..."
  LANGUAGES CXX
)


#if(LOGGING)
#    cmake option
#    add_definitions("-DLOGGING")
#endif(LOGGING)


# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLOGTOSTD") # print to std


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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

configure_file(IIPLConfig.h.in IIPLConfig.h)

# include IIPL libraries
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include/iipl)

add_subdirectory(src)
add_subdirectory(tutorial_code)