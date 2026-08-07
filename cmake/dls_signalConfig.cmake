include(CMakeFindDependencyMacro)

find_dependency(dls_com CONFIG)
find_dependency(dls_topics CONFIG)

# duration_utils is fetched and installed together with transport_interfaces.
# Load that exact colocated export instead of searching for another copy.
if(NOT TARGET duration_utils::duration_utils)
    include("${CMAKE_CURRENT_LIST_DIR}/duration_utilsConfig.cmake")
endif()

include("${CMAKE_CURRENT_LIST_DIR}/dls_signalTargets.cmake")
