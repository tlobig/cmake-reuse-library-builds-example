cmake_minimum_required(VERSION 3.13)
project(project_a)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../static_lib ${CMAKE_CURRENT_BINARY_DIR}/../static_lib)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../interface_lib ${CMAKE_CURRENT_BINARY_DIR}/../interface_lib)
# find_package(static_lib QUIET PATHS ../static_lib)
# if (NOT static_lib_FOUND)
# message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
# find_file(static_lib_TARGETS_file NAME static_libTargets.cmake PATHS "${CMAKE_CURRENT_BINARY_DIR}/../static_lib/cmake")
# include(${static_lib_TARGETS_file})
# endif()

add_executable(project_a src/main.cpp)
target_link_libraries(project_a static_lib::static_lib interface_lib::interface_lib)