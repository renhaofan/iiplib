cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
set(TGFLAGS test_gflags)
set(TBOOST test_boost)
set(TGLOG test_glog)
set(TYAML test_yaml_cpp)
set(TIIPL test_iipl)

add_executable(${TGFLAGS} test_gflags.cpp)
if (GFLAGS_USE_TARGET_NAMESPACE)
    if (TARGET gflags::gflags)
        target_link_libraries(${TGFLAGS} gflags::gflags)
    else ()
        message(FATAL_ERROR "gflags::gflags target not defined")
    endif ()
else ()
    if (TARGET gflags)
        target_link_libraries(${TGFLAGS} gflags)
    else ()
        message(FATAL_ERROR "gflags target not defined")
    endif ()
endif ()

add_executable(${TGLOG} test_glog.cpp)
target_link_libraries(${TGLOG} glog ${Boost_LIBRARIES})

add_executable(${TBOOST} test_boost.cpp)
target_link_libraries(${TBOOST} ${Boost_LIBRARIES})

add_executable(${TYAML} test_yaml_cpp.cpp)
target_link_libraries(${TYAML} ${YAML_CPP_LIB})

add_executable(${TIIPL} test_iipl.cpp)
target_link_libraries(${TIIPL}
        ${Boost_LIBRARIES}
        gflags
        glog
        iipl)