cmake_minimum_required(VERSION 3.16.2)
project(transport_interfaces)

add_compile_options("-std=c++20")

add_library(transport_interfaces INTERFACE)

target_include_directories(transport_interfaces INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS transport_interfaces
    EXPORT transport_interfacesTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# install include folder
install(DIRECTORY include/
    DESTINATION /usr/include
)

if(COMPILE_TRANSPORTS)
    add_subdirectory(transports/fastdds)
endif()
