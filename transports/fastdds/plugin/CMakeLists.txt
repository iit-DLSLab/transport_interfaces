add_library(plugin
	SHARED
		src/plugin.cpp
)

target_include_directories(plugin
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(plugin
	PUBLIC
		dls_signal
)

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 REQUIRED)

execute_process(
	COMMAND
		${Python3_EXECUTABLE} -c "import sysconfig; schemes = sysconfig.get_scheme_names(); scheme = 'deb_system' if 'deb_system' in schemes else sysconfig.get_default_scheme(); print(sysconfig.get_path('purelib', scheme=scheme))"
	OUTPUT_VARIABLE
		_ABS_PYTHON_MODULE_PATH
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

get_filename_component(_ABS_PYTHON_MODULE_PATH ${_ABS_PYTHON_MODULE_PATH} ABSOLUTE)
file(RELATIVE_PATH PYTHON_MODULE_PATH ${CMAKE_INSTALL_PREFIX} ${_ABS_PYTHON_MODULE_PATH})

# INSTALL
# -- plugin
transport_install_target(plugin)


install(
	DIRECTORY python/dls2_py
	DESTINATION ${PYTHON_MODULE_PATH}
	COMPONENT dls_runtime
)

install(
	FILES python/config/dds_participant_config.xml
	DESTINATION /usr/include/dls2/util/messaging
	COMPONENT dls_dev
)

install(
	FILES python/scripts/setup.sh
	DESTINATION ${PYTHON_MODULE_PATH}/dls2_py/scripts
	COMPONENT dls_runtime
)