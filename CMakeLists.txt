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

# # Include directories
# include_directories(${CMAKE_SOURCE_DIR}/dependencies/sdl2/include
#                     ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/include
#                     ${CMAKE_SOURCE_DIR}/dependencies/sdl2_gfx/include
#                     ${CMAKE_SOURCE_DIR}/dependencies/sdl2_ttf/include)
#
# # Link directories
# link_directories(${CMAKE_SOURCE_DIR}/dependencies/sdl2/lib
#                  ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/lib
#                  ${CMAKE_SOURCE_DIR}/dependencies/sdl2_gfx/lib
#                  ${CMAKE_SOURCE_DIR}/dependencies/sdl2_ttf/lib)

add_executable(main ${SOURCES})

target_include_directories(main PRIVATE
    ${CMAKE_SOURCE_DIR}/dependencies/sdl2/include
    ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/include
    # ${CMAKE_SOURCE_DIR}/dependencies/sdl2_gfx/include
    # ${CMAKE_SOURCE_DIR}/dependencies/sdl2_ttf/include
)
# target_link_libraries(main PRIVATE
#     #${CMAKE_SOURCE_DIR}/dependencies/sdl2/lib
#     # ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/lib
#     # ${CMAKE_SOURCE_DIR}/dependencies/sdl2_gfx/lib
#     # ${CMAKE_SOURCE_DIR}/dependencies/sdl2_ttf/lib
# )
#

# Link libraries
target_link_libraries(main PRIVATE SDL2 SDL2_image)
# -----------------------------
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(main ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# -----------------------------


# Link libraries
#target_link_libraries(main SDL2 SDL2_image SDL2_gfx SDL2_ttf)

# Set compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

