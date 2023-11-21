# GTEST Fundamental

The following steps are executed at the root directory of our project.

1. Generate the build type `test` with the flag for running the test module

```sh
cmake -DCMAKE_BUILD_TYPE=test -DBUILD_TESTS=ON -S .  -B Build/test
```

2. Build the `test` binary using:

```sh
cmake --build build/test/ -j 8
```

- **NOTE**: You can also use either:
  - `/opt/homebrew/bin/ninja -j${NUMBER_CORES} -C./build/test;` After passing the `Ninja -G`. or,
  - `cd build/test && make`

3. Run the `ctest` command

```sh
GTEST_COLOR=1 ctest --test-dir build/test/ --output-on-failure -j8
```

- **NOTE**: This command just will run the test binary, with `8` cores, which
  is equivalent to `./build/test/tests/$(BINARY_TEST_NAME);`, but this binary will not run with `8` cores.

4. Dont forget to add the

```sh
# Enable testing for this project
include(CTest)

```

## UNDERSTANDING THE CTEST WITH GOOGLETEST

To learn more about Google Test (GTest) and understand the specific command you
mentioned (`GTEST_COLOR=1 ctest --test-dir build/test/ --output-on-failure
-j12`), you can refer to the following resources:

1. **Google Test (GTest) Documentation**:
   - GoogleTest is Google's C++ testing and mocking framework. The user’s guide
     provides a comprehensive resource, including a Primer for beginners,
     advanced topics, samples, FAQs, and guidance on mocking【12†source】. You
     can access the GoogleTest User’s Guide
     [here](https://google.github.io/googletest/).
2. **Understanding the `ctest` Command**:
   - The `ctest` command is part of the CMake build system and is used for
     running tests. The flags in your command have specific functions:
     - `--output-on-failure` will output anything produced by the test program
       if the test fails【20†source】.
     - `-j <jobs>` or `--parallel <jobs>` tells CTest to run tests in parallel
       using the specified number of jobs【21†source】.
   - You can read more about `ctest` in the CMake documentation [here](https://cmake.org/cmake/help/latest/manual/ctest.1.html).
3. **Understanding the `GTEST_COLOR` Environment Variable**:
   - The `GTEST_COLOR` environment variable is used in Google Test to control
     the coloring of test output. Setting `GTEST_COLOR=1` or `GTEST_COLOR=ansi`
     enables colored output. The behavior of this variable with existing values
     remains unchanged, so it's backward-compatible and won't affect existing use
     cases unless the new value `ansi` is used【31†source】.

Combining these resources will give you a thorough understanding of Google Test
and how to use the `ctest` command effectively in your testing environment,
including controlling the output format and running tests in parallel for
efficiency.
