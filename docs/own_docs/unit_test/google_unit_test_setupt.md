# INSTALLING GOOGLE UNIT TEST

<!-- vim-markdown-toc GitLab -->

* [METHODs OF INTEGRATING GTEST](#methods-of-integrating-gtest)
* [1. MANUALLY](#1-manually)
    * [1.1 Design](#11-design)
        * [1.1.1 CMakeLists at root directory](#111-cmakelists-at-root-directory)
        * [1.1.2 CMakeLists at dependencies directory](#112-cmakelists-at-dependencies-directory)
        * [1.1.3 CMakeLists at source directory](#113-cmakelists-at-source-directory)
    * [1.1.3 CMakeLists at tests directory](#113-cmakelists-at-tests-directory)
    * [1.2 Makefile at the Root Directory](#12-makefile-at-the-root-directory)

<!-- vim-markdown-toc -->


## METHODs OF INTEGRATING GTEST

In reality, there are several methods for incorporating your `google-unit-test`
library into your project. These options include:

1. Manually
2. Using `CMakeLists.txt`, recommended by `Google`
3. Using `git submodule`, the method that we will implemented (see below to know why).

## 1. MANUALLY

We download the `gtest` from the following [link](https://github.com/google/googletest/releases), for example using `v1.14.0`.

1. Unzip the directory
2. Place it in `dependencies` directory in our project.
3. Create a directory called `googletest` inside the `dependencies` directory.

### 1.1 Design

```sh
                ┌─────────────────────────┐
                │  Project Root Directory │
                │     CMakeLists.txt      │
                └─────────────────────────*
                              │
        ┌─────────────────────────────────────────┐
        │                     │                   │
        ▼                     ▼                   ▼
1.───────────────┐    2.───────────────┐    3.───────────────┐
│ dependencies   │    │  source (src)  │    │      tests     │
│ CMakeLists.txt │    │ CMakeLists.txt │    │ CMakeLists.txt │
└────────────────*    └────────────────*    └────────────────*


```

#### 1.1.1 CMakeLists at root directory

We will need to add two things here:

1. We add the `add_subdirectory` to refer to the dependencies ->
   `CMakeLists.txt` that we place it there
2. We add also the `GTest::gtest_main` to the `target_include_directories`
3. Call in `src/main.cpp` with the directive `#include <gtest/gtest.h>`

- We will define an option variable `BUILD_TESTS` which is `OFF` by default,
  the build will be `binary` for our source files and related libraries.
- Once we trigger `make test` we apss the flag `-DBUILD_TESTS=ON` to all build against the test module.

```sh
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
```

#### 1.1.2 CMakeLists at dependencies directory

We will add also a `CMakeLists.txt` at the `dependencies` directory to refer to
the Manually installed directory of `googletest`. We put in this CMakeLists.txt the following,

```sh
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(googletest)
```

#### 1.1.3 CMakeLists at source directory

Here, we have three methods for linking external variables.

1. `googletest`: for the google test will be fetch in the `CMakeLists.txt` at
   the root of our project directory using the `add_subdirectory(dependencies)`.

   - Using, `add_subdirectory(dependencies)` at `CMakeLists.txt` at root project directory.
   - Using, the following at `CMakeLists.txt` at the `dependencies` directory

   ```
        set(CMAKE_CXX_STANDARD 17)
        add_subdirectory(googletest)
   ```

2. `golog`: this library will be loaded using the `vcpkg` module, and it is
   defined using the `TOOLCHAIN` and the vckpg_config.json file:

   - (using find_page(glog CONFIG REQUIRED)
   - Adding `glog::glog`, to the `target_link_libraries` and `target_include_directories`.

3. `SDL2`: library, this will be linked directly as shown below:

```sh
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

  # You can add (-Werror, -Wc++11-extensions), but it will make the complier more restrictive.
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

endif()


```

### 1.1.3 CMakeLists at tests directory

The testing here almost follow the same config for the `binary` configuration
of the `cmake` in the `src/CMakelists.txt`. But, it will not look into the
`main.cpp`.

- We can remove any library that we dont want to be included in the test, to speedup the testing.
  - You can remove the log (we dont need this)
  - You can remove the `SDL2` as well.
  - Then, you should specify only the files in the `src` individually rather thant the `files(GLOBAL)` as shown below, otherwise, it will not link as it not be seen by the build
  ```
      file(GLOB_RECURSE SOURCES ./*.cpp            # For define all curernt tests/*.cpp
                                ../src/lib/*.cpp   # For define all the source files excpet main.cpp
      )
  ```
- Right now, any file in the src and test of `*.cpp` supposed to be included in
  the build (`/*.hpp`/`*.h`, should be added if you put the defnition and
  declarationn in same header file, as this command will not look only for
  `*.cpp` files)
- I have added also `Test` build type as the `cmake`, supports only `Debug`,
  `Release` and `MinSizeRel`, and it works after passing the flag `-DBUILD_TESTS`
  for the `make` command in the root of our directory.

```sh

######################################
#      BUILD FOR TESTING MODULE
######################################

if(BUILD_TESTS)

    ## vcpkg libraries - Logging header
    # Required by vckpge
    find_package(glog CONFIG REQUIRED)
    ######################################
    # definition,
    ######################################
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    # This will read all the files inside our tests module
    file(GLOB_RECURSE SOURCES ./*.cpp            # For define all curernt tests/*.cpp
                              ../src/lib/*.cpp   # For define all the source files excpet main.cpp
    )
    # Remove main.cpp from the list
    # list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp") # Not Working!!
    add_executable(my_test ${SOURCES}) # ../src/lib/veclib/lib/vector2d.cpp ../src/lib/veclib/lib/vect.cpp


  # Link headers
  target_include_directories(
    my_test PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/sdl2/include/SDL2
                 ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/include/SDL2
            glog::glog
            GTest::gtest_main
    )

  target_link_libraries(
    my_test
    PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/sdl2/lib/libSDL2.dylib
            ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/lib/libSDL2_image.dylib
            glog::glog
            GTest::gtest_main
    )
    include(GoogleTest)
    gtest_discover_tests(my_test)

    # --------------------------------------------------------------------
    #                  Define A Build Type (Test)
    # --------------------------------------------------------------------
    set(CMAKE_BUILD_TYPE Test CACHE STRING "Set the build type to Test" FORCE)
    # Define flags for Test build
    set(CMAKE_CXX_FLAGS_TEST "${CMAKE_CXX_FLAGS_TEST} -Wall -Wextra -g")
    set(CMAKE_C_FLAGS_TEST "${CMAKE_C_FLAGS_TEST} -Wall -Wextra -g")
    # Check if we are using the Test build
    if(CMAKE_BUILD_TYPE STREQUAL "Test")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_TEST}")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_TEST}")
    endif()


endif()

```

### 1.2 Makefile at the Root Directory

- Adding the following command to the `Makefile` at the project root directory.
- The build is based on using `Ninja`, and specified number of cores accordingly.

```sh

BINARY_TEST_NAME=my_test

test:
	cmake -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Test \
	-DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake \
	-DCMAKE_MAKE_PROGRAM=/opt/homebrew/bin/ninja \
	-G Ninja -S . -B ./build/test
	/opt/homebrew/bin/ninja -j${NUMBER_CORES} -C ./build/test
	if [ -L compile_commands.json ]; then \
		rm -f compile_commands.json; \
	fi
	ln -s build/test/compile_commands.json compile_commands.json
	./build/test/tests/$(BINARY_TEST_NAME)

```
