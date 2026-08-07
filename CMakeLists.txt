cmake_minimum_required(VERSION 3.28.3)
project(transport_interfaces)

set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
set(CMAKE_INSTALL_PREFIX /opt/dls2 CACHE PATH "Install path" FORCE)

include(transport_install_target)
include(fetch_duration_utils)

include(GNUInstallDirs)

add_compile_options("-std=c++20")

# Fetch duration_utils once for the whole project. FetchContent_MakeAvailable()
# also adds the dependency's install rules, so the exact headers and exported
# target used by this build are installed alongside transport_interfaces.
fetch_duration_utils()

add_subdirectory(transport_interface)
add_subdirectory(transports)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/cmake/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
