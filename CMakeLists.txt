cmake_minimum_required(VERSION 3.28.3)
project(transport_interfaces)

set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
include(transport_install_target)

include(GNUInstallDirs)

add_compile_options("-std=c++20")

add_library(transport_interface INTERFACE)

target_include_directories(transport_interface INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

add_subdirectory(transports)

transport_install_target(transport_interface)