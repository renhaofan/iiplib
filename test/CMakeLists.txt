cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(test_IIPL)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(iipl REQUIRED)

if(iipl_FOUND)
    message(STATUS "iipl found")
else()
    message(STATUS "iipl not found")
endif()


add_executable(test test.cpp)
target_link_libraries(test iipl)
