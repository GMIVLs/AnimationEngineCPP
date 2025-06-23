######################################
#     BASICS CONFIGURATION CMAKE
######################################
cmake_minimum_required(VERSION 3.16...3.25)
project(AnimationEngineCPP CXX)
if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()

# Set compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Suppress developer/deprecation warnings if necessary
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1)

# Explicitly set policies for compatibility
if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()

######################################
# Update the submodules here
######################################
include(cmake/UpdateSubmodules.cmake)
######################################


######################################
#     Adding dependencies
######################################
# Adding googletest for testing
# Rest of dependencies are managed with vckpkg
# and direct linking in ./src/CMakeLists.txt (e.g., SDL2)
add_subdirectory(dependencies)

######################################
#   WHICH BUILD (BINARY vs TEST)
######################################
# By default we will not operate that
# until we call the make test command
option(BUILD_TESTS "Build the unit tests" OFF)
if (BUILD_TESTS)
# ------------------------------------
# Running the test module
# ------------------------------------
    # Enable testing for this project
    include(CTest)
    # Add the test directory with its own CMakeLists.txt
    add_subdirectory(tests)
else()
# ------------------------------------
# Running the Main Binary
# ------------------------------------
    add_subdirectory(src)
endif()
