# Recursive find all files and add them to the project
#file(GLOB_RECURSE SOURCES "src/*.cpp")
#set(SOURCES src/main.cpp src/lib/veclib/Vector_2d.cpp)
# This will read all the cpp files in the src directory recursively,
# no need to specifiy one by one.
file(GLOB_RECURSE SOURCES ./*.cpp)

# Set the build type if not provided
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      "Debug"
      CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()


if(APPLE)
## vcpkg libraries - Logging header
find_package(glog CONFIG REQUIRED)

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
                 ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/include/SDL2
            glog::glog
            GTest::gtest_main
    )
  # Link libraries
  target_link_libraries(
    main
    PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/sdl2/lib/libSDL2.dylib
            ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/lib/libSDL2_image.dylib
            glog::glog
            GTest::gtest_main
    )


  # -----------------------------
  list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
  # -----------------------------

  # You can add (-Werror, -Wc++11-extensions), However, this will make the compiler more restrictive.
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

endif()

