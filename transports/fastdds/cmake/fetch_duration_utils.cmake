function(fetch_duration_utils)
	include(FetchContent)
	FetchContent_Declare(
		duration_utils
		GIT_REPOSITORY https://github.com/iit-DLSLab/duration_utils.git
		GIT_TAG main
	GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(duration_utils)
endfunction()