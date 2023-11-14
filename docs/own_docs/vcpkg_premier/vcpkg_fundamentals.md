# VCPKG Fundamental

- This file is associated with my other graphics engine using `raylib`, as we
  will use the `sdl2` here in different approach.
  Check for more details [RaylibEngine](https://github.com/Ghasak/RaylibEngine/tree/main)

### Introduction to vcpkg

- `vcpkg` is a cross-platform package manager for C and C++ libraries. It
  simplifies the process of acquiring and building open-source libraries on
  Windows, macOS, and Linux. The tool offers a collection of pre-built libraries
  and the capability to compile libraries from source. It's particularly useful
  for C++ developers, as managing dependencies can often be a complex task in the
  C++ ecosystem.

### How to use vcpkg

1. **Installation:**

   - Clone the repository:
     ```bash
     git clone https://github.com/microsoft/vcpkg.git
     ```
   - Bootstrap the tool on Windows:
     ```bash
     .\vcpkg\bootstrap-vcpkg.bat
     ```
     Or on macOS/Linux:
     ```bash
     ./vcpkg/bootstrap-vcpkg.sh
     ```

2. **Installing Packages:**
   To install a library, you can use:

   ```bash
   ./vcpkg install <library-name>
   ```

3. **Integration:**

   - **Globally:** If you want to use the libraries system-wide, you can
     integrate `vcpkg` with your build system. For instance, with Visual Studio
     on Windows:

     ```bash
     .\vcpkg integrate install
     ```

     This command provides a system-wide integration. After running it, any
     MSBuild project will be able to find and link against libraries installed
     by `vcpkg`.

   - **Locally:** For a local project, you typically pass the toolchain file to
     your build system. The toolchain file is located at
     `<vcpkg_root>/scripts/buildsystems/vcpkg.cmake`. For instance, with CMake,
     you can specify the toolchain file as:

     ```bash
     cmake -B [build directory] -S . -DCMAKE_TOOLCHAIN_FILE=[vcpkg root]/scripts/buildsystems/vcpkg.cmake
     ```

### Comparison

Let's list the main differences between using `vcpkg` globally vs. locally:

| Aspect          | Global Usage                                                | Local Usage                                                          |
| --------------- | ----------------------------------------------------------- | -------------------------------------------------------------------- |
| Scope           | All projects on the system can access libraries.            | Only the specific project can access libraries.                      |
| Integration     | A one-time command integrates with the build system.        | Must specify the toolchain file for each project.                    |
| Version Control | Harder to manage different versions for different projects. | Easier to specify different library versions for different projects. |
| Independence    | Projects are dependent on the global `vcpkg` installation.  | Projects are isolated from each other.                               |
| Maintenance     | Update once, all projects get the new version.              | Each project can decide when to update its dependencies.             |

### Package Installed - Globally (for the given system)

1. After installing the vcpkg (assume ~/vcpkg), and source it in your `.bashrc`
   or `.zshrc`. using `~/vcpkg/vcpkg integrate zsh`, (you can check other
   options using `./vcpkg integrate help` ). Check the code snippet below and add
   it to your `.zshrc`.

   ```sh
   #####################################################################
   #        VCPKG: Package Manager for C/C++ Libraries
   #####################################################################
    export PATH="$PATH:$HOME/vcpkg/" # Added by myself
    # Generated using ~/vcpkg/vcpkg integrate zsh
    autoload bashcompinit
    bashcompinit
    source $HOME/vcpkg/scripts/vcpkg_completion.zsh
   ```

2. Now, we are ready to use `vcpkg` as following:

- If you want to install lets say `raylib` without specifying a version, you can search for it first (recommended).
  ```sh
  vcpkg search raylib
  vcpkg install raylib
  ```
- Now, you can run `list` to list all the global packages installed at
  `~/vcpkg/packages/` and you will get a list from this directory. - It will also list all the dependencies for any given library you
  downloaded.

  ```sh
  vcpkg list #you must run this command only at your given project root dir
  ```

  when I check I get something similar to below (you must run this command only at your given project root dir)

  ```sh
  vcpkg list
    glfw3:arm64-osx                    3.3.8#2       GLFW is a free, Open Source, multi-platform libr...
    raylib:arm64-osx                   4.5.0#2       A simple and easy-to-use library to enjoy videog...
    raylib[use-audio]:arm64-osx                      Build raylib with audio module
    vcpkg-cmake-config:arm64-osx       2022-02-06#1
    vcpkg-cmake:arm64-osx              2023-05-04
  ```

- You must now configure your `CMakeList.txt` to know the location of these packages at:

  ```cmake
  # Include directories
  include_directories($ENV{ROOT_HOME}/vcpkg/packages/raylib_arm64-osx/include/)
  link_directories($ENV{ROOT_HOME}/vcpkg/packages/raylib_arm64-osx/lib/)
   # Headers [optional]
   target_include_directories(
     main PRIVATE $ENV{ROOT_HOME}/vcpkg/packages/raylib_arm64-osx/include/)
   # Link the libraries
   target_link_libraries(
     main PRIVATE raylib ${COREFOUNDATION_LIBRARY} ${COREGRAPHICS_LIBRARY}
                   ${APPKIT_LIBRARY} ${IOKIT_LIBRARY} raylib) # notice raylib has to
  ```

- Check the legacy `CMakeList.txt` for this configurations located at `./legacy`

### Packages Installed - Locally (with the project root dir)

1. Generate a new manifiest file

```cpp
vcpkg new --name animation_engine_cpp --version 1.0
```

2. Generate a baseline if you add `version` in your manifiest

```cpp
vcpkg x-update-baseline --add-initial-baseline
```

Here, we will have the packages within our given project at a directory will
created automatically called `vcpkg_installed`. We first create this file and
assume the given manifest file is located at root directory of our given
project called `vcpkg.json`. Now we follow:

- Create first the manifest file with all the required libraries at the root directory of your project

```json
{
  "name": "raylibengine",
  "version-string": "0.1.0",
  "builtin-baseline": "db0473513e5d6f431ff05d2f398e",
  "dependencies": [
    {
      "name": "raylib",
      "version>=": "4.5.0",
      "platform": "osx"
    },
    {
      "name": "glfw3",
      "version>=": "3.3.8",
      "platform": "osx"
    }
  ]
}
```

- Install them directly using (this command will know to install
  libraries from the manifest file (our the vcpkg.json).
  - **Note**: Lets run first in `vcpkg install --dry-run`, which will allow us to examine
    all the libraries that will be downloaded without actually download them

```sh
vcpkg install
```

- All libraries in the manifest file will be also installed in the root of
  `vcpkg` at `~/vcpkge/installed/`,

- We need to update the `CMakeLists.txt` file, as following (assume PROJECT_DIR
  is a `env` variable carry the project root path).

```cmake
# Include directories
include_directories($ENV{PROJECT_DIR}/vcpkg_installed/arm64-osx/include/)
link_directories($ENV{PROJECT_DIR}/vcpkg_installed/arm64-osx/lib/)
# Headers [optional]
target_include_directories(
  main PRIVATE $ENV{PROJECT_DIR}/vcpkg_installed/arm64-osx/include/)
```
