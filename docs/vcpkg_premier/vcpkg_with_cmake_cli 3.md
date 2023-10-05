# vcpkg with cmake command line

To install a package globally, run

```sh
vcpkg install <package-name>
```
- Or you can also use locally for your project using the manifest file
`vcpkg.json`.

- When building your project, you can either set the toolchain file or include
  the directories directly: Using the toolchain file:

```sh
cmake -B [build directory] -S . -DCMAKE_TOOLCHAIN_FILE=[vcpkg root]\scripts\buildsystems\vcpkg.cmake
```

- Or by directly including the directories:

```cpp
#include "[vcpkg root]/installed/[triplet]/include/<library-header>"
```
