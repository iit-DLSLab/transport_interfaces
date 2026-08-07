# @PACKAGE_INIT@
# list(APPEND CMAKE_MODULE_PATH "@PACKAGE_cmakeModulesDir@")

unset(extraArgs)
if(${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
list(APPEND extraArgs QUIET)
endif()
if(${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED)
list(APPEND extraArgs REQUIRED)
endif()

find_package(plugin ${extraArgs})
find_package(dls_domains ${extraArgs})


include(${CMAKE_CURRENT_LIST_DIR}/fastdds_transportTargets.cmake)