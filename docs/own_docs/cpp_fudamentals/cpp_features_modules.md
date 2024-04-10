# Features in Modern CPP

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Features in Modern CPP](#features-in-modern-cpp)
    - [Modules](#modules)
        - [Example_1](#example_1)
        - [Example 2](#example-2)
        - [Key Differences](#key-differences)
    - [Relative Path vs Absolute Path in Calling](#relative-path-vs-absolute-path-in-calling)
        - [Makefile Setup](#makefile-setup)
        - [Source Code](#source-code)
        - [Using CMake](#using-cmake)

<!-- markdown-toc end -->


## Modules

In modern C++, the module concept is an alternative to header files. Instead of
including a header file in multiple source files with the risk of multiple
definitions or name collisions, modules allow for more efficient and modularized
code organization. For example, in the old way using header files, to add two
integers from another file, you might have a `math_functions.h` header file
containing:

### Example_1

```c++
#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

namespace math {
    int add(int x, int y);
}

#endif

```

And a `main.cpp` file including the header and using the function:

```c++
#include "math_functions.h"

int main() {
    int x = 5;
    int y = 10;
    int result = math::add(x, y);
    std::cout << "The sum is: " << result << "\n";
    return 0;
}
```

With the new module concept in modern C++, instead of a header file, you would
have a `math_functions.cpp` source file containing:

```c++
namespace math {
    int add(int x, int y);
}
```

And a separate `math_module.cpp` compilation unit with the following contents to
import and export the module:

```c++
export module math;

#include "math_functions.cpp"
```

The `main.cpp` file can then include the module using:

```c++
import math;

int main() {
    int x = 5;
    int y = 10;
    int result = math::add(x, y);
    std::cout << "The sum is: " << result << "\n";
    return 0;
}
```

This approach reduces the number of header files and makes it easier to manage
dependencies between source files.

### Example 2

1. Create the `add.d` header file to have the declaration.

```cpp
#ifndef ADD_H
#define ADD_H

int add(int a, int b);

#endif // ADD_H
```

3. Include the necessary header files in the `add.cpp` file.

4. Add the following function definition for the "add" function:

```cpp
int add(int x, int y) {
    return x + y;
}
```

5. In the main.cpp

```sh
#include <iostream>
#include "add.h"

int main() {
    std::cout << "Sum: " << add(3, 4) << std::endl;
    return 0;
}

```

### Key Differences

Syntax: Modules use export module for definition and import for using them, replacing #include and header guards.

- Compilation: Modules can be compiled separately, which can significantly
  improve compile times, especially for large projects.
- Namespace Pollution: Modules reduce global namespace pollution and improve
  encapsulation compared to traditional header files.
- Dependency Management: Modules make dependencies clearer and more explicit,
  leading to better maintainability.
- Modules in C++ are a significant shift in how code is organized and compiled,
  aiming to address many of the longstanding issues associated with the
  preprocessor and header files.

As of my last update in April 2023, Clang, the compiler front-end for the C,
C++, and Objective-C programming languages, does have support for C++20 modules,
which includes support for the module feature. However, the extent of this
support and its stability can vary, as the implementation of C20 features,
including modules, is an ongoing process.

For using modules in Clang on a Mac, you would typically need to ensure a few things:

1. **Latest Version**: Make sure you are using the latest version of Clang that
   includes the most up-to-date support for C++20 features.
2. **Build System**: Your build system needs to understand C++ modules. This can
   be an area of complexity, as modules change how source files depend on each
   other compared to traditional header and source files.
3. **Compiler Flags**: You might need to use specific compiler flags to enable
   module support. This often involves experimental or feature-specific flags.
4. **Standard Library**: The standard library implementation that comes with
   Clang should also support modules. The LLVM project, which includes Clang,
   has its own standard library implementation (libc++) that is typically
   updated alongside Clang.

To check the current status of module support in Clang on a Mac, you can refer
to the official Clang documentation or community resources for the most recent
updates. Keep in mind that as the C++ standard evolves, compiler support for
features like modules will also continue to evolve and improve.

## Relative Path vs Absolute Path in Calling

Creating paths relative to the root directory of your project is a common and
good practice in C++ projects, and it's often the preferred approach over
absolute paths for reasons of portability and maintainability.

To implement this, you typically set up your build system (like CMake, Makefile,
etc.) to include the project root directory in the list of include directories.
This way, you can use paths relative to the project root in your `#include`
statements, which effectively makes them "absolute" with respect to your
project, but not your filesystem. This approach keeps the advantages of relative
paths while providing a clear and consistent way to include files from anywhere
in your project.

Here's an example of how you can do this in a Makefile and in your source code:

### Makefile Setup

In your Makefile, you can add a flag to your compiler call to include the root directory:

```makefile
# Example Makefile
CXX = g++
CXXFLAGS = -I/path/to/your/project/root -std=c++17 # Add the project root directory

# Define your build targets and rules here
```

### Source Code

Now, in your source code, you can include headers using paths relative to the
project root. For example:

```cpp
// src/main.cpp
#include "concepts/my_add_function/add.hpp"

int main() {
    // Your code here
}
```

```cpp
// src/concepts/my_add_function/add.cpp
#include "concepts/my_logging/my_logging.hpp"

// Implementation of add function
```

In this setup, even though the include statements look like relative paths, they
are effectively relative to your project's root directory, thanks to the `-I`
compiler flag in the Makefile.

### Using CMake

If you're using CMake, you can achieve a similar setup by using `target_include_directories` in your CMakeLists.txt file:

```cmake
# Example CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Add the project root directory to the include path
include_directories(${CMAKE_SOURCE_DIR})

# Define your targets and add source files
```

This approach maintains the flexibility and portability of your project while allowing a more organized and readable way of including files.
