get_filename_component(EXAMPLE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${EXAMPLE_NAME} print_version.cpp)
target_include_directories(
	${EXAMPLE_NAME} PUBLIC
	${PROJECT_BINARY_DIR}
)