add_library(dls_domains SHARED
		src/domains.cpp
)

target_include_directories(dls_domains
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

transport_install_target(dls_domains)
