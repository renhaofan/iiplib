get_filename_component(EXAMPLE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${EXAMPLE_NAME} log_usage.cpp)
target_include_directories(${EXAMPLE_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src/include)
target_link_libraries(${EXAMPLE_NAME} iipl)