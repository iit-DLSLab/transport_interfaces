function(transport_install_target target_name)
    install(TARGETS ${target_name}
        EXPORT ${target_name}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
    install(EXPORT ${target_name}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
        NAMESPACE ${PROJECT_NAME}::
        FILE ${target_name}Targets.cmake
    )
    install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
endfunction()
