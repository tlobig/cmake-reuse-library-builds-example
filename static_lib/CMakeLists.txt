cmake_minimum_required(VERSION 3.13)
project(static_lib VERSION 1.2.3)

add_library(static_lib STATIC src/static_lib.cpp)
# target_include_directories(static_lib PUBLIC include)
add_library(static_lib::static_lib ALIAS static_lib)

target_include_directories(static_lib PUBLIC  
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  
    $<INSTALL_INTERFACE:include>  # <prefix>/include/mylib
)

target_compile_features(static_lib PRIVATE cxx_std_17)

# include(CMakePackageConfigHelpers)
# configure_package_config_file(<input> <output>
#   INSTALL_DESTINATION <path>
#   [PATH_VARS <var1> <var2> ... <varN>]
#   [NO_SET_AND_CHECK_MACRO]
#   [NO_CHECK_REQUIRED_COMPONENTS_MACRO]
#   [INSTALL_PREFIX <path>]
#   )
# configure_package_config_file()

install(TARGETS static_lib EXPORT static_libTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(EXPORT static_libTargets
    FILE static_libTargets.cmake
    NAMESPACE static_lib::
    DESTINATION lib/cmake/static_lib
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("static_libConfigVersion.cmake"
    VERSION ${static_lib_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES "static_libConfig.cmake" "static_libConfigVersion.cmake"
    DESTINATION lib/cmake/static_lib
)

export(EXPORT static_libTargets
       FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/static_libTargets.cmake"
       NAMESPACE static_lib::
)