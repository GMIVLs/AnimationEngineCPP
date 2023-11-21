# CMAKE IN ACTION

In order to streamline the building process, the `cmake` commands are
translated into a `Makefile`. This allows for faster execution of the necessary
steps required to create the final executable. After passing instructions on
how to build the project, we also need to construct the binary itself.

## ORIGINAL COMMANDS - NO Makefile

1. In order to construct the project, we must first specify the `build_type` using
   `-DCMAKE_BUILD_TYPE`. Afterward, when building the project, we need to use the
   `--build` flag.

```sh
cmake -DCMAKE_BUILD_TYPE=Debug -S .  -B Build/debug
```

2. Then we build the project

```
cmake --build . -j 8
```

## SAME COMMANDS - Using Makefile

```sh
debug_using_ninja: link_compile_commands
	cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=/opt/homebrew/bin/ninja \
		-DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake \
		-G Ninja -S . \
		-B ./build/debug
	/opt/homebrew/bin/ninja -j${NUMBER_CORES} -C build/debug
	./build/debug/$(BINARY_NAME)
```

| idx | command                                                  | similar to (but not equal) | Action                       |
| --- | -------------------------------------------------------- | -------------------------- | ---------------------------- |
| 1   | /opt/homebrew/bin/ninja -j${NUMBER_CORES} -C build/debug | cmake --build . -j 8       | to build the proj.with ninja |
| 2   | $(MAKE) -j $(NUMBER_CORES) -C build/debug                | cmake --build . -j 8       | to build the proj. with make |
| 3   | cd to build/debug then just make                         | cmake --build . -j 8       | to build the proj using make |

## BUILD AND LINK LIBRARIES

In this project, I utilized several methods that are familiar to me:

1. Git subdirectory, which is my preferred choice, and implementing a script
   for fetching and updating similar to the googletest library.
2. Leveraging vckpg and find_package in CMakeLists.txt, comparable to using
   golog::golog.
3. Directly connecting libraries inside CMakeLists.txt by referencing their
   include and lib files (SDL2).
4. Passing all necessary definitions to the run command using clang++ flags, as
   seen in our Makefile with the run command.
5. Using a manual bash/zsh script for automating library downloads, similar to
   how we obtained SDL2.


