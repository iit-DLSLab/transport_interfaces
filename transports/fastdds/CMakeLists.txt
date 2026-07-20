add_library(fastdds_transport SHARED
    src/fastdds_transport.cpp
)
target_include_directories(fastdds_transport PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(fastdds_transport PUBLIC plugin dls_domains)

target_link_directories(fastdds_transport PUBLIC
    /usr/lib/dls2
)

install(TARGETS fastdds_transport
    EXPORT fastdds_transportTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)
install(DIRECTORY include/
    DESTINATION /usr/include
)