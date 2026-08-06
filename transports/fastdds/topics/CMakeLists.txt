add_library(dls_topics SHARED
	src/topics.cpp
)
target_include_directories(dls_topics
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(dls_topics
	PUBLIC
		dls_messages
)

transport_install_target(dls_topics)