set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

option(BUILD_DLS2_MSGS "Build the dls2_msgs submodule. Disable when dls2_msgs is pre-installed (e.g. in CI)." ON)
if(BUILD_DLS2_MSGS)
	add_subdirectory(dls2_msgs)
endif()
add_subdirectory(topics)

add_subdirectory(domains)
add_subdirectory(ddscom)
add_subdirectory(signal)
add_subdirectory(plugin)
add_subdirectory(fastdds_transport)

# include(CMakePackageConfigHelpers)
# # This will be used to replace @PACKAGE_cmakeModulesDir@
# set(cmakeModulesDir ${CMAKE_INSTALL_PREFIX}/cmake)

# configure_package_config_file(
#     cmake/fastdds_transportConfig.cmake.in fastdds_transportConfig.cmake
#     INSTALL_DESTINATION cmake # INSTALL_PREFIX omitted,so that the path is relative to the install prefix
#     PATH_VARS cmakeModulesDir
#     NO_SET_AND_CHECK_MACRO
#     NO_CHECK_REQUIRED_COMPONENTS_MACRO
# )