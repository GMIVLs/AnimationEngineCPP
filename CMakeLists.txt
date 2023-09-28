cmake_minimum_required(VERSION 3.5)
project(AnimationEngineCPP CXX)
# Adding all the modules for our build:
set(SOURCES src/main.cpp src/lib/veclib/vector2d.cpp)

# Set the build type if not provided
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      "Debug"
      CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# Setting my compling command for clangd language server, offer jump to
# definition,
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE})

# Adding executable
add_executable(main ${SOURCES})

# Link headers
target_include_directories(
  main PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/sdl2/include/SDL2
               ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/include/SDL2)
# Link libraries
target_link_libraries(
  main
  PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/sdl2/lib/libSDL2.dylib
          ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/lib/libSDL2_image.dylib)
# -----------------------------
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
# -----------------------------

# Set compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g"
)# You can add (-Werror), but it will make the complier more restrictive.
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

