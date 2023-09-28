# Animation Engine CPP

## ChangingLog

- `2023-09-29 00:00`: Loading image is possible now:

  - [x] merge the `cpp_habits.md` done by M,
  - [x] and updating the `CMakeList.txt` for `SDL_image` extension.
  - [x] documentation updated for several data structures in `C++`.

- `2023-09-03 12:48`: Starting documentation for the tips and tricks in `CPP`.
- `2023-07-16 22:29`:

  - [x] Adding script to download dependencies.
  - [x] Provoid documentation for the building the project.
    - [x] Create the `CMakeList.txt` for `SDL2` and all the attached dependencies.

- `2023-07-15 02:30`
  - Create the base for the animation engine in CPP
  - Create branching for each developer
  - Added the `CMakeList.txt` build the project in `debug` and `release` modes

## Prerequisites

### Fundamental

If you have a fresh MacBook without any development tools installed, including
Xcode, you'll need the following to compile C/C++ code:

- Command Line Tools (CLT) for Xcode: This provides a standalone version of the
  compiler and essential tools without the need for the full Xcode IDE. It
  includes: clang: The C, C++, and Objective-C compiler. lldb: The debugger.
- Essential system headers and libraries.

```bash
Copy code
xcode-select --install
```

- Homebrew (Optional but Recommended): While not strictly necessary for
  compiling C/C++ code, Homebrew is a package manager for macOS that makes it
  easy to install various software and libraries. It can be very useful if you
  need external libraries for your projects. To install Homebrew, you can use:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

- CMake (Optional): If you want to use CMake as a build system (as in your
  previous examples), you'd need to install CMake. With Homebrew, it's as easy

```bash
brew install cmake
```

### Graphics libraries

- Run the script `./tools/fetch_dependencies_if_not_existed_macOS.sh` to get
  the `SDL2` and its extensions up and running.

### development

You will need several libraries for `development` mode including

1. The `clang` complier which comes with the xcode pre-installed with the `xcode`.
2. The `clangd` the language server, which is also pre-installed with the `xcode`.
3. The `clang-format` for formatting your `C/C++` code using `brew install clang-format`.

### Verfication

1. Checking the `sdl2` headers

```sh
╰─ /opt/homebrew/Cellar/sdl2/2.28.3/bin/sdl2-config --cflags
-I/opt/homebrew/Cellar/sdl2/2.28.3/include/SDL2 -D_THREAD_SAFE
```

2. Checking the `sdl2` and all other extenstions installed

```sh
brew info sdl2
brew info sdl_image
brew info sdl_gfx
```
