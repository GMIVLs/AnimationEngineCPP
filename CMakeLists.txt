cmake_minimum_required(VERSION 3.5)
project(AnimationEngineCPP CXX)
# Set compiler flags
set(CMAKE_CXX_STANDARD 17)

######################################
# Adding googletest for testing
# Rest of dependencies are managed with vckpkg
# and direct linking in ./src/CMakeLists.txt (e.g., SDL2)
add_subdirectory(dependencies)

# By default we will not operate that
# until we call the make test command
option(BUILD_TESTS "Build the unit tests" OFF)
######################################
# Running the Main Binary
######################################
if (BUILD_TESTS)
######################################
# Running the test module
######################################
add_subdirectory(tests)
else()
add_subdirectory(src)
endif()




