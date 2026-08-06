option (COMPILE_TRANSPORT_FASTDDS "Compile transport implementations" ON)

if(COMPILE_TRANSPORT_FASTDDS)
    add_subdirectory(fastdds)
endif()
