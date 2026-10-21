cmake_minimum_required(VERSION 3.28.3)
project(transport_interfaces)

set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
set(CMAKE_INSTALL_PREFIX /opt/dls2 CACHE PATH "Install path" FORCE)

include(transport_install_target)

include(GNUInstallDirs)

add_compile_options("-std=c++20")

# duration_utils is a git submodule. Adding it here also adds its install rules,
# so its headers and exported target are installed alongside transport_interfaces.
add_subdirectory(duration_utils)

add_subdirectory(transport_interface)
add_subdirectory(transports)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/cmake/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
