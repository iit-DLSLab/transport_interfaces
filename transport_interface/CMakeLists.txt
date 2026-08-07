add_library(transport_interface INTERFACE)
add_library(transport_interfaces::transport_interface ALIAS transport_interface)

target_include_directories(transport_interface INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    # $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

transport_install_target(transport_interface)
