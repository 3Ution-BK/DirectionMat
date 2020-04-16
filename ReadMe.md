# DirectionMat

## Overview

This toy program demonstrates visualized flow image in HSV format by using C++
and CMake with OpenCV libraries.

## Install and run

### Build environment

We have tested various build environment. For MSVC, we suggested to used 14.0
(2015) and beyond since we use `noexcept` keyword in command line parser.

Below shows the working environment:

| Computer & Virtual machines    | Compiler         | Build system | OpenCV |
| ------------------------------ | ---------------- | ------------ | ------ |
| Windows 10 Version 1803 64-bit | MSVC 14.0 (2015) | MSBuild 14.0 | 4.1.1  |
| Windows 10 Version 1803 64-bit | MSVC 14.2 (2019) | MSBuild 16.5 | 4.1.1  |
| Windows 10 Version 1803 64-bit | MSVC 14.2 (2019) | Ninja 1.8.2  | 4.1.1  |
| (VM) Ubuntu 18.04.1 LTS 64-bit | gcc 7.5.0        | GNU Make 4.1 | 4.2.0  |
| (VM) Ubuntu 18.04.1 LTS 64-bit | gcc 7.5.0        | Ninja 1.8.2  | 4.2.0  |

### Build system

We use CMake to generate the program. Please install CMake in order to build
this program.

Requirement is listed below:

| Build system | Requirement    |
| ------------ | -------------- |
| CMake        | At least 3.1.0 |

### Library

This program use various libraries. Each library plays important role of this
program. In order to run correctly, please install these libraries first.

Essential Library is listed below:

| Library | Requirement (Suggested) | Role               |
| ------- | ----------------------- | ------------------ |
| OpenCV  | At least 3.0            | Image manipulation |

### How to

Below used cmake-gui as the example:

1. Open cmake-gui
2. Select this folder as the source code folder and choose proper build folder.
3. Configure the project using your favorite compiler
4. Choose correct library folder
5. Generate the program
