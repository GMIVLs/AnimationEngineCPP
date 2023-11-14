# VCPKG How It Works?

<!-- vim-markdown-toc GitLab -->

* [Summary](#summary)
* [Installed vs Package directories](#installed-vs-package-directories)
    * [Installed Directory vs. Package Directory](#installed-directory-vs-package-directory)
    * [Installing Libraries](#installing-libraries)
    * [How vcpkg works:](#how-vcpkg-works)
* [Steps vcpkg takes to install a library](#steps-vcpkg-takes-to-install-a-library)
* [What is the role of Package directory in these steps?](#what-is-the-role-of-package-directory-in-these-steps)

<!-- vim-markdown-toc -->

## Summary

Here, we will demonstrate the difference between installed directory and
package directory for vcpkg assume I have installed it in my home directory
~/vcpkg, using macOS add example when I install globally and when I install a
library using the manifest file vcpkg.json then elaborate later on how vcpkg
works with all necessary details

## Installed vs Package directories

`vcpkg` is a cross-platform package manager that makes it easy to manage
dependencies for your C++ projects. Here, I'll explain the difference between
the installed directory and the package directory, and then delve deeper into
how `vcpkg` operates.

### Installed Directory vs. Package Directory

1. **Installed Directory**: This is where `vcpkg` stores all the libraries that
   you have installed. When you install a package, the compiled binaries,
   headers, and other files related to the package are placed in this directory.
   By default, the installed directory for `vcpkg` is the `installed/`
   subdirectory inside the main `vcpkg` directory.

   For your case (assuming you installed `vcpkg` in `~/vcpkg`), the installed
   directory would be:

   ```sh
   ~/vcpkg/installed/
   ```

2. **Package Directory**: This is where the sources and portfiles for each
   package reside. A portfile is a script that `vcpkg` uses to build and
   install a library. The package directory contains a subdirectory for each
   available package, and that subdirectory will contain the portfile and any
   patches or additional files needed for the build.

   For your setup, the package directory would be:

   ```sh
   ~/vcpkg/ports/
   ```

### Installing Libraries

1. **Globally**: When you install a library globally, you typically use the
   following command:

   ```sh
   ./vcpkg install <library-name>
   ```

   This will download, build, and install the library to the `installed/`
   directory. You can then use the library in your projects by pointing your
   build system to the appropriate directories inside `installed/`.

2. **Using Manifest File (vcpkg.json)**: With the manifest mode, you can
   specify your project's dependencies in a `vcpkg.json` file. When you build
   your project, `vcpkg` will automatically ensure that all required libraries are
   installed.

   A simple example of a `vcpkg.json` file might look like:

   ```json
   {
     "name": "my-project",
     "version-string": "1.0",
     "dependencies": ["fmt", "boost"]
   }
   ```

   When you build your project, `vcpkg` will check the `vcpkg.json` file, and
   if the libraries (like `fmt` and `boost` in this case) are not installed, it
   will install them for you.

### How vcpkg works:

1. **Portfiles**: For each library, there's a corresponding portfile in the
   `ports/` directory. This portfile is a CMake script that tells `vcpkg` how
   to fetch, extract, build, and install the library.
2. **Binary Caching**: `vcpkg` can cache compiled binaries. This means that
   once you've built a library, subsequent installations (on the same machine
   or others, if shared) can use the cached binaries instead of building from
   source, speeding up the process.
3. **Toolchain Integration**: `vcpkg` provides integration with various build
   systems. For instance, if you're using CMake, you can point CMake to the
   `vcpkg.cmake` toolchain file, and CMake will automatically find and use
   libraries installed by `vcpkg`.
4. **Triplets**: Triplets define the build configuration for packages. For
   instance, if you want to build a library for x64 and Windows, you would use
   the `x64-windows` triplet. There are default triplets provided by `vcpkg`, but
   you can also create custom ones.
5. **Manifest Mode**: As mentioned earlier, with manifest mode, you can specify
   your project's dependencies in a `vcpkg.json` file. This makes it easy to
   ensure that all developers on a project have the same dependencies installed.
6. **Versioning**: `vcpkg` also offers versioning features, allowing you to
   specify which versions of libraries you want to use in your project.
7. **Cross-Platform**: `vcpkg` supports multiple platforms, including Windows,
   macOS, and Linux. This means that you can use the same package manager and
   process to manage dependencies across different platforms.

- To conclude, `vcpkg` is a powerful tool that streamlines the process of
  managing C++ libraries across various platforms. Its flexible features, like
  manifests and versioning, make it a popular choice for modern C++ development.

## Steps vcpkg takes to install a library

Certainly, here's a concise step-by-step overview of how `vcpkg` installs a
library in your root project directory using the manifest file `vcpkg.json`:

1. **Detect Manifest File**: `vcpkg` checks if a `vcpkg.json` file exists in
   your project's root directory.
2. **Parse `vcpkg.json`**: If the manifest file is found, `vcpkg` reads and
   parses the `vcpkg.json` to determine which libraries and their respective
   versions are required.
3. **Check Installed Libraries**: `vcpkg` checks the `installed/` directory to
   see if the required libraries (and the specified versions) are already
   installed.
4. **Download Missing Libraries**: For any libraries that aren't already
   installed, `vcpkg` fetches the source code.
5. **Compile Libraries**: `vcpkg` compiles the downloaded libraries using the
   instructions provided in their respective portfiles.
6. **Install Libraries**: Once compiled, `vcpkg` installs the libraries into
   the `installed/` directory.
7. **Integration**: If you're using a build system like CMake, and you've
   integrated `vcpkg`, the build system will now be able to find and link
   against the newly installed libraries.

That's a quick overview of the steps involved when using `vcpkg` with a
manifest file.

## What is the role of Package directory in these steps?

When using the manifest mode with `vcpkg.json`, the `vcpkg/packages` directory
is generally not used in the same way as with the traditional `vcpkg install
<package_name>` command.

However, the `vcpkg/packages` directory still plays a role behind the scenes.
Here's a brief breakdown:

1. **Traditional Installation (`vcpkg install <package_name>`)**:

   - Source code is downloaded and extracted.
   - Library is built.
   - Built results are temporarily stored in the `vcpkg/buildtrees` directory.
   - Successful builds are copied over to the `vcpkg/packages` directory.
   - Finally, from the `vcpkg/packages` directory, the relevant files
     (binaries, headers, etc.) are copied and installed to the `vcpkg/installed`
     directory.

2. **Manifest Mode (using `vcpkg.json`)**:
   - The general process of downloading, building, and installing is similar.
   - The `vcpkg/packages` directory can still be used as an intermediate
     storage location before the libraries are installed to the `vcpkg/installed`
     directory. However, the focus with manifest mode is on the final
     installation in the `vcpkg/installed` directory, making the presence of the
     `vcpkg/packages` directory less noticeable to the user.

- In summary, while the manifest mode emphasizes the use of the
  `vcpkg/installed` directory, the `vcpkg/packages` directory still exists and
  can be used as an intermediate step, even if it's less prominent in this
  workflow.

- let's elaborate on the ASCII diagram to better showcase the roles of the `installed` and `packages` directories:

```sh

+-----------------+
|                 |
| vcpkg.json      |
| (Specify Libs)  |
|                 |
+-----------------+
        |
        V
+------------------+
|                  |
| Download Source  |
| & Compile Libs   |
|                  |
+------------------+
        |
        V
+------------------------+
|  vcpkg/buildtrees      |
|  (Compilation &        |
| Intermediate Artifacts)|
+------------------------+
        |
        V
+-----------------+
|                 |
| vcpkg/packages  |
| (Staging before |
| Final Install)  |
|                 |
+-----------------+
        |
        V
+-------------------------+
|                         |
| vcpkg/installed         |
| (Final Installation &   |
| Libraries Ready for Use)|
|                         |
+-------------------------+
```

1. `vcpkg.json` specifies which libraries and their respective versions are
   needed for the project.
2. The required libraries' source code is downloaded, and the libraries are
   compiled.
3. The `vcpkg/buildtrees` directory is used for compilation and as a storage
   for intermediate build artifacts.
4. Successful builds are moved to the `vcpkg/packages` directory, which acts as
   a staging area before final installation.
5. Libraries are then installed into the `vcpkg/installed` directory, where
   they are ready for use in projects.

This process streamlines library management in the project, ensuring all
dependencies are correctly installed and available for use.
