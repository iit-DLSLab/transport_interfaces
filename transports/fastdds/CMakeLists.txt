set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

add_subdirectory(dls2_msgs)
add_subdirectory(topics)

add_subdirectory(domains)
add_subdirectory(ddscom)
add_subdirectory(signal)
add_subdirectory(plugin)

add_library(fastdds_transport SHARED
    src/fastdds_transport.cpp
)
target_include_directories(fastdds_transport PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(fastdds_transport PUBLIC plugin dls_domains)

transport_install_target(fastdds_transport)