cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

get_filename_component(MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
#set(PROJECT_NAME "iipl_${MODULE_NAME}")
set(PROJECT_NAME "${MODULE_NAME}")
message(STATUS "${PROJECT_NAME}")
project(${PROJECT_NAME} VERSION 0.0.0)

set(${PROJECT_NAME}_HEADERS
        ../include/config.h
        ../include/iipl_engine.h
        ../include/log_timer.h
        ../include/log.h
        ../3rdparty/json/json.hpp
        )

set(${PROJECT_NAME}_SOURCES
        config.cpp
        iipl_engine.cpp
        log.cpp
        )

#aux_source_directory(. DIR_SRCS)
#add_library(${PROJECT_NAME} SHARED ${DIR_SRCS})
add_library(${PROJECT_NAME} STATIC
        ${${PROJECT_NAME}_SOURCES}
        ${${PROJECT_NAME}_HEADERS}
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)


target_link_libraries(${PROJECT_NAME} PUBLIC
        ${Boost_LIBRARIES}
		/usr/local/lib/libyaml-cpp.so
#		${YAML_CPP_LIBRARIES}
        gflags
        glog)

# ------------------------------- install script -------------------------------
# Prepare exposed headers

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${${PROJECT_NAME}_HEADERS}")

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include/iipl)

# Generate library version info which will generate xxxConfigVersion.cmake,
# the ${PACKAGE_VERSION} is the version defined in project()
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY SameMajorVersion)

install(EXPORT ${PROJECT_NAME}Targets
        FILE ${PROJECT_NAME}Targets.cmake
        DESTINATION "lib/cmake/${PROJECT_NAME}")

configure_package_config_file(
        cmake/Config.cmake.in ${PROJECT_NAME}Config.cmake
        INSTALL_DESTINATION "lib/cmake/${PROJECT_NAME}")

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION "lib/cmake/${PROJECT_NAME}")
