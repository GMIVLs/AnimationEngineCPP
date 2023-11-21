# Build Type in CPP

keyword: static, dynamic, framework

1. git subdirectory ( my favourite method!) with a script for fetching and
   update (similar to googletest library)
2. Using vckpg and find_package in CMakeLists.txt (similar to golog::golog
   library)
3. Manually connect them inside CMakeLists.txt using the direct path to the
   include and lib files (SDL2)
4. Pass all the definition to the run command using the flags of clang++ , see
   Makefile the command run
5. Using a manual bash/zsh script (automate) the download of the libraries
   (similar to what we did with SDL2)

Here's a table that compares dynamic libraries and static libraries in various aspects:

| **Aspect**                     | **Dynamic Library**                                                                                                | **Static Library**                                                                                  |
| ------------------------------ | ------------------------------------------------------------------------------------------------------------------ | --------------------------------------------------------------------------------------------------- |
| **Description**                | Libraries that are loaded at runtime.                                                                              | Libraries that are linked at compile time.                                                          |
| **Extension**                  | Typically `.dll` (Windows), `.so` (Linux), `.dylib` (macOS).                                                       | Typically `.lib` (Windows), `.a` (Unix/Linux/macOS).                                                |
| **Linking Type**               | Dynamic Linking                                                                                                    | Static Linking                                                                                      |
| **Size of Executable**         | Generally smaller, as the actual library code resides in the shared library.                                       | Larger, as the library code is incorporated into the final executable.                              |
| **Memory Footprint**           | Multiple programs can share a single instance in memory.                                                           | Each program has its own copy of the library functions in memory.                                   |
| **Loading Time**               | May increase, as linking is done at runtime.                                                                       | Typically faster, as all linking is done at compile time.                                           |
| **Versioning**                 | Can update without recompiling dependent applications (if ABI is preserved).                                       | Applications must be recompiled if the library is updated.                                          |
| **Portability**                | Executable needs the correct version of the library present at runtime.                                            | No external dependencies are required at runtime.                                                   |
| **Performance**                | Slight overhead due to dynamic linking, though often negligible.                                                   | Might be slightly faster due to early binding.                                                      |
| **Compilation Time**           | Might be faster as each change to the library doesn't require recompiling dependent applications.                  | Could be slower, especially if the library is large and the application needs to be relinked often. |
| **Code Snippet (Compilation)** | `gcc -shared -o libmylib.so mylib.c` (Linux)                                                                       | `ar rcs libmylib.a mylib.o` (after compiling `mylib.c` to object file)                              |
| **Code Snippet (Linking)**     | `gcc -o myprog myprog.c -L/path/to/lib -lmylib` (dynamic linking in Linux)                                         | `gcc -o myprog myprog.c -L/path/to/lib -lmylib` (static linking)                                    |
| **Distribution**               | Must distribute the library and the executable. Also, may need to consider version compatibility.                  | Only the executable is distributed.                                                                 |
| **Use Case**                   | When you expect updates to the library without wanting to recompile all dependent applications. Also, for plugins. | When you want a standalone executable without any external dependencies.                            |

**Notes:**

1. The above table provides a general overview. The specifics can vary based on
   the operating system, compiler, and specific use cases.
2. Dynamic libraries also have the concept of an "Application Binary Interface"
   (ABI). If you maintain ABI compatibility, you can update a dynamic library
   without recompiling programs that use it. However, if you break ABI
   compatibility, it requires recompilation.
3. Always consider licensing when distributing libraries. Some licenses have
   different requirements or implications for static vs. dynamic linking.

- **Note**: The "Compilation Time" aspect is a general observation and the actual
  compilation time can vary based on the size of the library, the number of
  dependencies, and the specific system and build setup.

## Hello World library - both as static and dyanmic

let's create a simple "Hello World" library, both as a static library and a
dynamic library.

1. **Library Code (`hello.cpp`)**

```cpp
#include <iostream>

void hello() {
    std::cout << "Hello, World from the library!" << std::endl;
}
```

2. **Static Library Compilation**:

To create a static library:

```bash
g++ -c hello.cpp -o hello.o
ar rcs libhello.a hello.o
```

3. **Dynamic Library Compilation**:

To create a dynamic/shared library:

```bash
g++ -shared -fPIC hello.cpp -o libhello.so
```

4. **Using the Libraries in a Main Program (`main.cpp`)**

```cpp
extern void hello();

int main() {
    hello();
    return 0;
}
```

5. **Linking with the Static Library**:

```bash
g++ main.cpp -L. -lhello -o static_hello
```

6. **Linking with the Dynamic Library**:

```bash
g++ main.cpp -L. -lhello -o dynamic_hello
```

- Make sure the dynamic library is in the library path or in the same directory
  when running the executable, or use `LD_LIBRARY_PATH`:

```bash
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./dynamic_hello
```

**Comparison Table**:

| **Aspect**          | **Static Library**                                                                  | **Dynamic Library**                                                                                                                  |
| ------------------- | ----------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------ |
| **Compilation**     | Two steps: Compile source to object file, then archive object files into a library. | Compile with `-shared` to directly create the shared library.                                                                        |
| **Linking**         | Library content is included in the final executable.                                | Only references to library functions are included. Library must be present at runtime.                                               |
| **Executable Size** | Generally larger, as library content is embedded inside it.                         | Smaller. The actual library code is in the shared library, not the executable.                                                       |
| **Distribution**    | Just the executable is required.                                                    | Both the executable and the shared library (.so, .dll) must be distributed.                                                          |
| **Update Library**  | Need to relink and possibly recompile the executable.                               | Just replace the shared library file (if ABI compatibility is maintained).                                                           |
| **Performance**     | No overhead of dynamic linking at runtime.                                          | Minimal overhead due to dynamic linking, but generally negligible.                                                                   |
| **Flexibility**     | Not as flexible. Changing the library requires relinking the executable.            | More flexible. Applications can use different versions or implementations of a library without needing to be recompiled or relinked. |

This table provides a general comparison between static and dynamic libraries in the context of a "Hello World" library. The exact benefits and trade-offs can vary based on the specific use-case and system setup.

## How about Framework

- Framework is a bundle, usually in `macOS`, read more about it in the
  `CMake_for_Professional` book.

![Meaning of framework](./images/M02.png)

### What is a Framework?

A framework in the context of software development is a pre-written set of code
or tools that provides generic functionality, upon which more specific software
can be built. Frameworks enable developers to avoid "reinventing the wheel" by
offering a structure and foundation for building applications.

**Examples**:

1. **Web Development**: Django is a high-level Python web framework that
   encourages rapid development and clean, pragmatic design.
2. **Mobile Development**: SwiftUI is a framework for building UIs across all
   Apple devices with the power of Swift.
3. **Desktop Development**: Qt is a free and open-source widget toolkit for
   creating GUIs as well as cross-platform applications that run on various
   software and hardware platforms.

### Using Frameworks in CMakeLists.txt

When using a framework in CMake, you typically use the `find_package` command
to locate the framework, and then link against it.

**Example** (using a hypothetical "MyFramework"):

```cmake
# Find the MyFramework package
find_package(MyFramework REQUIRED)

# Link against MyFramework when creating your executable or library
add_executable(my_app main.cpp)
target_link_libraries(my_app PRIVATE MyFramework::MyFramework)
```

### Using Frameworks in the Command Line

When you're compiling a program from the command line, you often have to
specify where the compiler can find the framework headers and libraries. In
macOS, frameworks are typically bundled in a `.framework` directory.

**Example** (using a hypothetical "MyFramework"):

```bash
g++ main.cpp -F /path/to/framework/directory -framework MyFramework -o my_app
```

- In the above, `-F` specifies the path to search for frameworks and
  `-framework` is used to link against a specific framework.

### Features, Usages, and Common Practices for Frameworks:

| **Feature**                     | **Description**                                                                                       | **Common Practices**                                                                                                |
| ------------------------------- | ----------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------- |
| **Structure and Organization**  | Provides a predefined structure for organizing code, resources, and other assets.                     | Stick to the structure provided by the framework for maintainability and better collaboration.                      |
| **Reusable Components**         | Contains pre-built components or modules that can be reused across different parts of an application. | Use the built-in components before trying to build custom solutions; it saves time and ensures consistency.         |
| **Documentation and Community** | Often comes with extensive documentation and a supportive community.                                  | Regularly consult the official documentation; participate in community forums or discussion boards for support.     |
| **Extensibility**               | Allows developers to extend or override built-in functionality to cater to specific requirements.     | Use extension points provided by the framework; avoid "hacking" or working against the framework's design.          |
| **Testing and Debugging**       | Often includes tools or modules for testing and debugging to ensure the application works correctly.  | Regularly write tests as you develop; utilize built-in debugging tools for efficient troubleshooting.               |
| **Updates and Maintenance**     | Regularly receives updates, which might include new features, bug fixes, or performance improvements. | Stay updated with the latest version; however, always test the application thoroughly after updating the framework. |

### Common Frameworks for macOS:

| **Framework**          | **Description**                                                                                         | **Common Use Cases**                                                   |
| ---------------------- | ------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------- |
| **Cocoa/Cocoa Touch**  | Apple's native object-oriented APIs for macOS/iOS UI development.                                       | Building native macOS and iOS applications.                            |
| **Core Foundation**    | C-based framework by Apple that provides data types and utilities for macOS and iOS.                    | Used for low-level operations in macOS and iOS development.            |
| **Metal**              | High-performance graphics and compute API by Apple.                                                     | Game development, graphics-intensive apps, and compute tasks on macOS. |
| **WebKit**             | The web rendering engine behind Safari, used for embedding web content in apps.                         | Building web browsers or embedding web content within native apps.     |
| **Core ML**            | Apple's machine learning framework for adding trained ML models into applications.                      | Implementing machine learning features in macOS/iOS apps.              |
| **SceneKit/SpriteKit** | Graphics rendering and animation infrastructure for creating 3D (SceneKit) and 2D (SpriteKit) graphics. | Game development and 3D/2D graphics on macOS/iOS.                      |

- Frameworks serve as a foundational layer or a scaffold upon which developers
  build their applications. They provide a consistent and structured way to build
  applications, enabling developers to focus on the unique aspects of their
  application rather than the repetitive or common functionalities.
