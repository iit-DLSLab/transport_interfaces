include(fetch_duration_utils)

set(FASTDDS_STATISTICS OFF CACHE BOOL "Enable fastdds statistics")

add_library(dls_com STATIC
		src/dds_participant.cpp
		src/dds_listeners.cpp
		src/dds_reader.cpp
		src/dds_writer.cpp
)

target_include_directories(dls_com
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

fetch_duration_utils()

target_link_libraries(dls_com
	PUBLIC
		fastcdr
		fastdds
		dls_domains
		dls_topics
		duration_utils
		yaml-cpp
		fastdds_statistics_backend
)

target_compile_definitions(dls_com PRIVATE ENABLE_FASTDDS_STATISTICS=$<BOOL:${FASTDDS_STATISTICS}>)

set_property(TARGET dls_com PROPERTY POSITION_INDEPENDENT_CODE TRUE)

# add_subdirectory(test)

transport_install_target(dls_com)