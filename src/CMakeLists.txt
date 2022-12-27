# include(FetchContent)

# FetchContent_Declare(
#     glog 
#     GIT_REPOSITORY https://github.com/google/glog
#     GIT_TAG v0.6.0-rc2
# )

# FetchContent_MakeAvailable(glog)

# add_library(glog::glog INTERFACE IMPORTED)
# target_link_libraries(glog::glog INTERFACE gtest_main)



#------------------------------------------
add_library(${PROJECT_NAME} engine.cpp log.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# CMake Error: "iiplib/src/include" which is prefixed in the source dirctory.
# target_include_directories(${PROJECT_NAME} PUBLIC include)
# target_include_directories(${PROJECT_NAME} PUBLIC
        # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # $<INSTALL_INTERFACE:include>)

target_link_libraries(${PROJECT_NAME} PUBLIC
        ${Boost_LIBRARIES}
        glog)

# ------------------------------- install script -------------------------------
# Prepare exposed headers
set(HEADERS 
	${CMAKE_CURRENT_SOURCE_DIR}/include/iipl/engine.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/iipl/log_timer.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/iipl/log.h)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADERS}")

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


# uninstall target
# This will not remove empty directories which may have been created by the install
add_custom_target("uninstall" COMMENT "Uninstall installed files")
add_custom_command(
    TARGET "uninstall"
    POST_BUILD
    COMMENT "Uninstall files with install_manifest.txt"
    COMMAND xargs rm -vrf <  ${CMAKE_BINARY_DIR}/install_manifest.txt || echo Nothing in
            install_manifest.txt to be uninstalled!
)