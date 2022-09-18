cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

get_filename_component(MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
#set(PROJECT_NAME "iipl_${MODULE_NAME}")
set(PROJECT_NAME "${MODULE_NAME}")
message(STATUS "${PROJECT_NAME}")
project(${PROJECT_NAME})

set(${PROJECT_NAME}_HEADERS
        config.h
        iipl_engine.h
        log_timer.h
        log.h
        )

set(${PROJECT_NAME}_SOURCES
        config.cpp
        iipl_engine.cpp
        log.cpp
        )

add_library(${PROJECT_NAME} STATIC
        ${${PROJECT_NAME}_SOURCES}
        ${${PROJECT_NAME}_HEADERS}
        )

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME} PUBLIC
        ${Boost_LIBRARIES}
        ${YAML_CPP_LIB}
        gflags
        glog)