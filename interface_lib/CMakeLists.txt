cmake_minimum_required(VERSION 3.13)
project(interface_lib VERSION 2.4.6)

add_library(interface_lib INTERFACE)
# target_include_directories(static_lib PUBLIC include)
add_library(interface_lib::interface_lib ALIAS interface_lib)

target_include_directories(static_lib INTERFACE  
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  
    $<INSTALL_INTERFACE:include>  # <prefix>/include/mylib
)

target_compile_features(interface_lib INTERFACE cxx_std_17)

# include(CMakePackageConfigHelpers)
# configure_package_config_file(<input> <output>
#   INSTALL_DESTINATION <path>
#   [PATH_VARS <var1> <var2> ... <varN>]
#   [NO_SET_AND_CHECK_MACRO]
#   [NO_CHECK_REQUIRED_COMPONENTS_MACRO]
#   [INSTALL_PREFIX <path>]
#   )
# configure_package_config_file()

install(TARGETS interface_lib EXPORT interface_libTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(EXPORT interface_libTargets
    FILE interface_libTargets.cmake
    NAMESPACE interface_lib::
    DESTINATION lib/cmake/interface_lib
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("interface_libConfigVersion.cmake"
    VERSION ${interface_lib_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES "interface_libConfig.cmake" "interface_libConfigVersion.cmake"
    DESTINATION lib/cmake/interface_lib
)

export(EXPORT interface_libTargets
       FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/interface_libTargets.cmake"
       NAMESPACE interface_lib::
)