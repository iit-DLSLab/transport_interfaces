add_library(fastdds_transport SHARED
    src/fastdds_transport.cpp
)
add_library(transport_interfaces::fastdds_transport ALIAS fastdds_transport)

target_include_directories(fastdds_transport PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    # $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(fastdds_transport PUBLIC plugin dls_domains)

transport_install_target(fastdds_transport)
