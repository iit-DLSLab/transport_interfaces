include(fetch_duration_utils)

add_library(dls_signal 
	SHARED
		src/signal_base.cpp
		src/reader_base.cpp
		src/writer_base.cpp
)

set_property(TARGET dls_signal PROPERTY POSITION_INDEPENDENT_CODE ON)

target_include_directories(dls_signal
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

fetch_duration_utils()

target_link_libraries(dls_signal
	PUBLIC
		dls_com
		dls_topics
		duration_utils		
)

add_subdirectory(test)

transport_install_target(dls_signal)