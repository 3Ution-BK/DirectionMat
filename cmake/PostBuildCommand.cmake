function(copy_file LIBRARIES DESTINATION)
    foreach(LIBRARY ${LIBRARIES})
        add_custom_command(
            TARGET ${${PROJECT_NAME}_EXECUTABLE_NAME} POST_BUILD
            COMMAND
                ${CMAKE_COMMAND} -E copy_if_different
                ${LIBRARY}
                ${DESTINATION}
        )
    endforeach()
endfunction(copy_file)

if (WIN32)
    function(include_opencv_libraries LIBRARIES)
        set(FILE_POSTFIX
            "${OpenCV_VERSION_MAJOR}${OpenCV_VERSION_MINOR}${OpenCV_VERSION_PATCH}${OpenCV_VERSION_STATUS}"
        )

        set(FILE_POSTFIX "${FILE_POSTFIX}$<$<CONFIG:Debug>:d>")

        foreach(LIBRARY ${OpenCV_LIBS})
            set(LIBRARY "${LIBRARY}${VERSION_NUM}${FILE_POSTFIX}")
            if (MINGW)
                set(LIBRARY "lib${LIBRARY}")
            endif ()

            set(LIBRARIES
                ${LIBRARIES}
                "${OpenCV_CONFIG_PATH}/../bin/${LIBRARY}.dll"
                PARENT_SCOPE
            )
        endforeach()
    endfunction(include_opencv_libraries)

    set(LIBRARIES "")

    include_opencv_libraries("${LIBRARIES}")

    copy_file(
        "${LIBRARIES}"
        $<TARGET_FILE_DIR:${${PROJECT_NAME}_EXECUTABLE_NAME}>
    )
endif()
