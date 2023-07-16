cmake_minimum_required(VERSION 3.5)
project(AnimationEngineCPP CXX)
set(SOURCES src/main.cpp src/lib/veclib/vector2d.cpp)

# Set the build type if not provided
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      "Debug"
      CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# Setting my compling command for clangd language server
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE})

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/dependencies/sdl2/include
                    ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/include
                    ${CMAKE_SOURCE_DIR}/dependencies/sdl2_gfx/include
                    ${CMAKE_SOURCE_DIR}/dependencies/sdl2_ttf/include)

# Link directories
link_directories(${CMAKE_SOURCE_DIR}/dependencies/sdl2/lib
                 ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/lib
                 ${CMAKE_SOURCE_DIR}/dependencies/sdl2_gfx/lib
                 ${CMAKE_SOURCE_DIR}/dependencies/sdl2_ttf/lib)

# Add the executable target
add_executable(main ${SOURCES})

# Link libraries
target_link_libraries(main SDL2 SDL2_image SDL2_gfx SDL2_ttf)

# Set compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

