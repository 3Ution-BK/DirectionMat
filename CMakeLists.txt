cmake_minimum_required(VERSION 3.1.0)

project("DirectionMat"
        VERSION 1.0.0
        DESCRIPTION "Print the simple image of the direction matrix.")

set(${PROJECT_NAME}_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(${PROJECT_NAME}_CMAKE_DIR "${CMAKE_SOURCE_DIR}/cmake")
set(${PROJECT_NAME}_CONFIG_DIR "${CMAKE_SOURCE_DIR}/configures")

include(${${PROJECT_NAME}_CMAKE_DIR}/CompilerOptions.cmake)

set(${PROJECT_NAME}_EXECUTABLE_NAME ${PROJECT_NAME})

set(${PROJECT_NAME}_SOURCE_CODE
    ${${PROJECT_NAME}_SOURCE_DIR}/main.cpp
    ${${PROJECT_NAME}_SOURCE_DIR}/CommandLineParser/CommandLineParser.cpp
    ${${PROJECT_NAME}_SOURCE_DIR}/CommandLineParser/CommandLineParser.h
    ${${PROJECT_NAME}_SOURCE_DIR}/ImageProcessing/ImageProcessing.cpp
    ${${PROJECT_NAME}_SOURCE_DIR}/ImageProcessing/ImageProcessing.h
)

configure_file(
    ${${PROJECT_NAME}_CONFIG_DIR}/ProjectConfigures.h.in
    ${PROJECT_BINARY_DIR}/configures/ProjectConfigures.h
)

find_package(OpenCV REQUIRED)

add_executable(${${PROJECT_NAME}_EXECUTABLE_NAME}
    ${${PROJECT_NAME}_SOURCE_CODE}
)

set_target_properties(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>
)

target_include_directories(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PUBLIC
        ${${PROJECT_NAME}_SOURCE_DIR}
        ${PROJECT_BINARY_DIR}/configures
)

target_compile_options(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PUBLIC
        "$<$<CONFIG:DEBUG>:${${PROJECT_NAME}_CXX_FLAGS_DEBUG}>"
        "$<$<CONFIG:RELEASE>:${${PROJECT_NAME}_CXX_FLAGS_RELEASE}>"
)

target_compile_features(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PUBLIC
        cxx_std_14
)

target_link_libraries(${${PROJECT_NAME}_EXECUTABLE_NAME}
    ${OpenCV_LIBS}
)

include(${${PROJECT_NAME}_CMAKE_DIR}/PostBuildCommand.cmake)

message(STATUS "====== Summary ======")
message(STATUS "")
message(STATUS "------ Project ------")
message(STATUS "Project name: " ${PROJECT_NAME})
message(STATUS "Project version: " ${PROJECT_VERSION})

message(STATUS "")

message(STATUS "------ Platform ------")
message(STATUS "CMake version: " ${CMAKE_VERSION})
message(STATUS "CMake generator: " ${CMAKE_GENERATOR})
message(STATUS "CMake build tool: " ${CMAKE_BUILD_TOOL})
if(MSVC)
    message(STATUS "MSVC version: " ${MSVC_VERSION})
elseif(CMAKE_GENERATOR MATCHES Xcode)
    message(STATUS "Xcode version: " ${XCODE_VERSION})
else()
    message(STATUS "Build Type: " ${CMAKE_BUILD_TYPE})
endif()
message(STATUS "")

message(STATUS "------ Compiler ------")
message(STATUS
    "C Compiler: "
    "${CMAKE_C_COMPILER_ID} ${CMAKE_C_COMPILER_VERSION} (${CMAKE_C_COMPILER})"
)
message(STATUS
    "C++ Compiler: "
    "${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} "
    "(${CMAKE_CXX_COMPILER})"
)
message(STATUS "")

message(STATUS "------ OpenCV ------")
message(STATUS "Version: " ${OpenCV_VERSION})

message(STATUS "")

message(STATUS "=====================")
