# Animation Engine CPP

[![MIT License](https://img.shields.io/badge/License-MIT-blue)](https://github.com/Ghasak/AnimationEngineCPP/blob/main/LICENSE)
[![SDL2.0](https://img.shields.io/badge/SDL-2.0-yellow)](https://www.libsdl.org)
[![Static Badge](https://img.shields.io/badge/clang--format-formatter-red)](https://clang.llvm.org/docs/ClangFormat.html)
[![Static Badge](https://img.shields.io/badge/make-C%2B%2B%20Build%20Systems-blue)](https://github.com/wkusnierczyk/make)
[![Static Badge](https://img.shields.io/badge/Ninja-C%2B%2B%20Build%20Systems-red)](https://github.com/ninja-build/ninja)

---

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white)
![Shell Script](https://img.shields.io/badge/shell_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white)
![macOS](https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=macos&logoColor=F0F0F0)

- [ChangingLog](#changinglog)
  - [Graphics Architecture Diagram:](#graphics-architecture-diagram)
- [Prerequisites](#prerequisites)
  - [Fundamental](#fundamental)
  - [Graphics libraries](#graphics-libraries)
  - [development](#development)
  - [Verfication](#verfication)
- [Running while in progress](#running-while-in-progress)

<!-- vim-markdown-toc -->

## ChangingLog

- `2023-11-14 23:00`: Migrated to the GMIVLs
- `2023-10-22 21:38`: Added `glog` library using vcpkg.
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

### Graphics Architecture Diagram:

Currently under development is our engine's structure, which may still undergo
modifications.

```lua
 ┌───────────────────────────────────────────────────────────┐
 │           ┌1.──────┐ ┌2.──────┐ ┌3.──────┐                │
 │           │ Physics│ │ Math   │ │ stats  │                │
 │           │ Module │ │ Module │ │ Module │                │
 │           └─────┬──* └─────┬──* └─────┬──*                │
 │                 │          ▼          │                   │
 │                 │     ┌4.───────┐     │                   │
 │                 │     │ Particle│◀────┘                   │
 │                 └────▶│ Module  │                         │
 │                       └─────┬───*                         │
 │                             │                             │
 │                             ▼                             │
 │                     ┌5.───────────┐                       │
 │                     │   Motion    │                       │
 │                     │    Module   │                       │
 │                     └─────────────*                       │
 │                            │                              │
 │           ┌6.───────────┐  │   ┌7.───────────┐            │
 │           │  Utilities  │  │   │   Platform  │            │
 │           │    Module   │  │   │    Module   │            │
 │           └─────┬───────*  ▼   └─────────────*            │
 │                 │    ┌8.───────────┐     │                │
 │                 └──▶ │ Experiments │     │                │
 │                      │    Module   │◀────┘                │
 │                      └─────┬───────*                      │
 │                            ▼                              │
 │                 ┌───────────────────────┐                 │
 │                 │       `2d` Canvus     │                 │
 │                 │    Graphics Display   │                 │
 │                 └───────────────────────*                 │
 │ 2D - graphics architecture                                │
 └───────────────────────────────────────────────────────────┘
```

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
4. Installing `vcpkg` can be found [here](./docs/vcpkg_premier/vcpkg_fundamentals.md)

### Verfication

1. Checking the `sdl2` headers

```sh
/opt/homebrew/Cellar/sdl2/2.28.3/bin/sdl2-config --cflags
-I/opt/homebrew/Cellar/sdl2/2.28.3/include/SDL2 -D_THREAD_SAFE
```

2. Checking the `sdl2` and all other extenstions installed

```sh
brew info sdl2
brew info sdl_image
brew info sdl_gfx
```

or

```sh
sdl2-config --version
```

## Running while in progress

- Using the `fswatch`cli, while changing any code in the `src` and save, it
  will be load and run the command from `Makefile`.

```sh
fswatch -o src/ | xargs -n1 -I{} make all
```

## Debugger in Emacs

Adding the following:

1. Assume you have installed already the `cpptools` which we here are using the `nvim` original setup for the `lldb-mi`.
2. Later on, I was able to successfully utilize it by running the command
   `dap-debug-edit-template` first. However, before doing so, you will notice that
   I am using the **lldb-mi** extension from the `cpptools` package installed via
   `mason` from: `~/.local/share/nvim/mason/packages/cpptools/extension`. Any
   `lldb-mi` should work fine for debugging in `spacemacs`.

```lisp
(dap-register-debug-template
 "cpptools::Run Configuration-GHASAKII"
 (list :type "cppdbg"
       :request "launch"
       :name "cpptools::Run Configuration"
       :miDebuggerPath (expand-file-name ".local/share/nvim/mason/packages/cpptools/extension/debugAdapters/lldb-mi/bin/lldb-mi" "~")
       :MIMode "gdb"
       :program "${workspaceFolder}/build/debug/main"  ;; Refer to your binary here
       :cwd "${workspaceFolder}"))

```

## Documentations

I am using in terminal a tool called [cppman](https://github.com/aitjcize/cppman), which give us the ability to navigate between C++98/11/14/17 and 20 manual
pages of the standard library.


- ADDING TESTING -01
- ADDING TESTING -02
- ADDING TESTING -03
- ADDING TESTING -04
- ADDING TESTING -05
- ADDING TESTING -06
- ADDING TESTING -07
- ADDING TESTING -08
- ADDING TESTING -09
