set(${PROJECT_NAME}_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(${PROJECT_NAME}_THIRDPARTY_DIR "${CMAKE_SOURCE_DIR}/thirdparty")

set(CMAKE_CONFIGURATION_TYPES
    "Debug;Release;RelWithDebInfo;MinSizeRel"
    CACHE STRING
    "Configs"
    FORCE
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIGURATION>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIGURATION>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIGURATION>)

if (MSVC)
    set(${PROJECT_NAME}_CXX_FLAGS_DEBUG
        "/W3"
        "/WX"
    )
    set(${PROJECT_NAME}_CXX_FLAGS_RELEASE "/O2")
else()
    set(${PROJECT_NAME}_CXX_FLAGS_DEBUG
        "-pedantic"
        "-pedantic-errors"
        "-W"
        "-Wall"
        "-Wdouble-promotion"
        "-Werror"
        "-Wextra"
        "-Wfloat-equal"
        "-Wformat=1"
        "-Wimplicit-fallthrough"
        "-Winit-self"
        "-Winline"
        "-Wno-long-long"
        "-Wpointer-arith"
        "-Wshadow"
        "-Wsign-promo"
        "-Wundef"
        "-Wno-attributes"
    )
    set(${PROJECT_NAME}_CXX_FLAGS_RELEASE "-O3")
endif()
