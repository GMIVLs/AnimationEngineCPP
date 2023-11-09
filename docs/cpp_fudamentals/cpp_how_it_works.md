# HOW CPP WORKS - Deep Dive
<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [HOW CPP WORKS - Deep Dive](#how-cpp-works---deep-dive)
    - [Main C++ Working](#main-c-working)
        - [The key terms are:](#the-key-terms-are)
    - [ASCII diagram to illustrate the process:](#ascii-diagram-to-illustrate-the-process)
        - [Explanation of steps:](#explanation-of-steps)
    - [Where the translation unit and where is the object file](#where-the-translation-unit-and-where-is-the-object-file)
    - [Static Linking with Third Party Library](#static-linking-with-third-party-library)
    - [Dynamic Linking](#dynamic-linking)
    - [Files Types in Building Process](#files-types-in-building-process)
    - [Can a Project has several translation units?](#can-a-project-has-several-translation-units)
    - [Header files](#header-files)
    - [Guards for Directives (#include)](#guards-for-directives-include)
    - [Question -1](#question--1)
    - [Question -2](#question--2)
    - [Question -3](#question--3)
    - [Question -4](#question--4)
    - [Question -5](#question--5)

<!-- markdown-toc end -->

## Main C++ Working

When you're working with C++ and you have a set of source files like
`main.cpp`, `lib.cpp`, and a header file `lib.h`, you're dealing with multiple
steps of compilation and linking.

Here's what happens step-by-step:

1. **Preprocessing**: Before actual compilation, the preprocessor handles
   directives such as `#include`, `#define`, and `#ifdef`. For your `main.cpp`
   and `lib.cpp`, the `#include "lib.h"` directive would cause the content of
   `lib.h` to be included (copied) into each of those cpp files. This step
   doesn't produce any files you interact with; it's done in-memory before
   compilation.

2. **Compilation**: Each cpp file is compiled separately. The compiler
   translates `main.cpp` into `main.o` and `lib.cpp` into `lib.o`. These are
   called object files. This is the step where the compiler checks for syntax
   errors and other language rules. After this step, each object file contains
   machine code, but it's not yet executable because it might contain unresolved
   symbols that it expects to find in other object files.

   - `main.o` is a translation unit corresponding to `main.cpp` after preprocessing.
   - `lib.o` is a translation unit corresponding to `lib.cpp` after preprocessing.

3. **Linking**: The linker takes all object files (`main.o`, `lib.o`) and
   resolves any references between them. If `main.cpp` calls a function that's
   implemented in `lib.cpp`, the linker connects these two parts together. The
   result is an executable file (like `a.out` on Unix systems or `main.exe` on
   Windows).

4. **Execution**: You can now run the executable file on your computer. If there
   were no linking errors, and your code is correctly written, it should execute
   and produce whatever output your program is designed to produce.

### The key terms are:

- **Source files**: The original `.cpp` and `.h` files you write.
- **Translation units**: The combination of a source file and all the headers it
  includes, after preprocessing.
- **Object files**: The machine code output from compiling a translation unit,
  typically with `.o` or `.obj` extension.
- **Executable**: The final runnable program created by the linker.

The resulting executable is what you run on your computer. The intermediary
files, like the object files, are usually not needed once the final linking is
done, unless you're doing incremental compilation.

## ASCII diagram to illustrate the process:

```sh
 Step 1: Preprocessing
----------------------------
main.cpp      lib.cpp     lib.h
  |             |          |
  |             |          |
  | #include    |          |
  v             |          |
<iostream>      |          |
  |             |          |
  | #include "lib.h"       |
  |------------------------|
  |             |
  |             | #include "lib.h"
  |             |-----------------|
  |             |
  v             v
main.i        lib.i

Step 2: Compilation
----------------------------
main.i        lib.i
  |             |
  | Compiles    | Compiles
  v             v
main.o        lib.o

Step 3: Linking
----------------------------
main.o        lib.o
  |             |
  |             |
  |   Linker    |
  |-------------|
        |
        v
     program
     (a.out)

```

### Explanation of steps:

1. **Preprocessing**:

   - `main.cpp` includes `iostream` and `lib.h`. The content of `iostream` and
     `lib.h` is effectively copied into `main.cpp` to create `main.i`.
   - `lib.cpp` includes `lib.h`. The content of `lib.h` is copied into `lib.cpp`
     to create `lib.i`.
   - The `.i` files are preprocessed source files, which you usually don't see
     as they are intermediate and kept in memory.

2. **Compilation**:

   - `main.i` is compiled into an object file `main.o`.
   - `lib.i` is compiled into an object file `lib.o`.
   - The `.o` files contain the compiled machine code, but external references
     are not resolved yet.

3. **Linking**:
   - The linker takes all the object files (`main.o`, `lib.o`) and resolves
     symbols, references, etc., to produce the final executable (`a.out` on
     Unix-like systems).

Each `.cpp` file is processed independently until the linking stage, where the
generated object files are combined to create the final executable.

## Where the translation unit and where is the object file

the ASCII diagram updated to include where the translation units and object files come into play:

```sh
 Step 1: Preprocessing
----------------------------
main.cpp      lib.cpp     lib.h
  |             |          |
  | #include    | #include |
  |-------------|----------|
  |             |          |
  |             |          |
  v             v          |
main.i        lib.i       |
(Translation (Translation |
 Unit)        Unit)       |

 Step 2: Compilation
----------------------------
main.i        lib.i
(Translation (Translation
 Unit)        Unit)
  |             |
  | Compiles    | Compiles
  |             |
  v             v
main.o        lib.o
(Object       (Object
 File)        File)

 Step 3: Linking
----------------------------
main.o        lib.o
(Object       (Object
 File)        File)
  |             |
  |             |
  |   Linker    |
  |-------------|
        |
        v
     program
   (Executable)

```

**Explanation of additions:**

- **Translation Units**: After preprocessing, `main.i` and `lib.i` are the
  translation units. These consist of the source code in `main.cpp` and
  `lib.cpp`, with the contents of `lib.h` and any other included headers (like
  `iostream` for `main.cpp`) directly inserted in place of the `#include`
  directives.
- **Object Files**: The result of compiling each translation unit is an object
  file. `main.o` is the object file for `main.i`, and `lib.o` is the object file
  for `lib.i`. These contain the compiled code in a binary format, but not yet
  linked to other object files.

## Static Linking with Third Party Library

I'll illustrate how static linking with a third-party library works across
different platforms. Let's assume we have a static library named
`libthirdparty`.

On Windows, static libraries typically have a `.lib` extension, on macOS and
Linux, the extension is usually `.a`.

Here's the updated ASCII diagram:

```sh
 Step 1: Preprocessing
----------------------------
main.cpp      lib.cpp     lib.h     libthirdparty (Third-Party Library)
  |             |          |              |
  | #include    | #include |              |
  |-------------|----------|              |
  |             |          |              |
  |             |          |              |
  v             v          |              |
main.i        lib.i       |           libthirdparty.lib (Windows)
(Translation (Translation |           libthirdparty.a   (macOS/Linux)
 Unit)        Unit)       |           (Static Library)
                           |
 Step 2: Compilation
----------------------------
main.i        lib.i
(Translation (Translation
 Unit)        Unit)
  |             |
  | Compiles    | Compiles
  |             |
  v             v
main.o        lib.o
(Object       (Object
 File)        File)

 Step 3: Linking (with Static Library)
----------------------------
main.o        lib.o       libthirdparty.lib (Windows)
(Object       (Object     libthirdparty.a   (macOS/Linux)
 File)        File)       (Static Library)
  |             |              |
  |             |              |
  |   Linker    |--------------|
  |-------------|
        |
        v
     program.exe (Windows)
     program     (macOS/Linux)
   (Executable)

```

**Explanation of additions:**

- **Static Library**: The third-party static library `libthirdparty` is shown
  here before linking. It is included by the linker, not by the preprocessor, so
  it doesn't go through the preprocessing or compilation stages that your own
  source code does.
- **Linking with Static Library**: During the linking step, the static library
  (`libthirdparty.lib` for Windows, `libthirdparty.a` for macOS and Linux) is
  combined with your object files (`main.o` and `lib.o`) to produce the final
  executable. Static linking copies the library code into your executable at
  build time, so the library becomes part of your application.

When you compile and link your program, you'll need to tell the compiler/linker
where to find the `libthirdparty` library files and how to include them. This is
typically done through command-line arguments or project settings in your
development environment.

## Dynamic Linking

Dynamic linking involves linking against shared libraries (also known as Dynamic
Link Libraries (DLL) on Windows or Shared Objects (.so) on Unix-like systems
such as Linux and macOS). Unlike static libraries, dynamic libraries are not
embedded into the executable at link time; instead, they are loaded at runtime.

Here’s how the ASCII diagram would look with dynamic linking:

```sh
 Step 1: Preprocessing
----------------------------
main.cpp      lib.cpp     lib.h     libthirdparty (Third-Party Library)
  |             |          |              |
  | #include    | #include |              |
  |-------------|----------|              |
  |             |          |              |
  |             |          |              |
  v             v          |              |
main.i        lib.i       |           libthirdparty.dll (Windows)
(Translation (Translation |           libthirdparty.so  (macOS/Linux)
 Unit)        Unit)       |           (Dynamic Library)
                           |
 Step 2: Compilation
----------------------------
main.i        lib.i
(Translation (Translation
 Unit)        Unit)
  |             |
  | Compiles    | Compiles
  |             |
  v             v
main.o        lib.o
(Object       (Object
 File)        File)

 Step 3: Linking (with Dynamic Library)
----------------------------
main.o        lib.o       libthirdparty.dll (Windows)
(Object       (Object     libthirdparty.so  (macOS/Linux)
 File)        File)       (Dynamic Library)
  |             |              |
  |             |              |
  |   Linker    |--------------|
  |-------------|              |
        |                      |
        v                      v
     program.exe           Loaded at
     program               Runtime
   (Executable)

```

**Explanation of changes for Dynamic Linking:**

- **Dynamic Library**: `libthirdparty.dll` for Windows or `libthirdparty.so` for
  Unix-like systems represents the dynamic library. The dynamic library itself
  isn't included in the linking step to be part of the executable. Instead,
  information about where to find the dynamic library at runtime is included.
- **Linking with Dynamic Library**: During the linking phase, the executable is
  prepared to call into the dynamic library. It knows the names of the functions
  it needs to call, but not where they are located in memory.
- **Runtime**: When the program runs, the operating system loads the dynamic
  library into memory, and the program uses the OS-provided mechanisms to call
  functions within the dynamically linked library.

**Note\***: that when distributing your application, you need to ensure that the target
system has access to the required dynamic library at the correct version, or the
application won't run. This is often managed by installing the library in a
standard location, using the operating system's package management, or by
distributing the library alongside the application with appropriate paths set.

## Files Types in Building Process

Can you make a table for all files types that is generated in this process?
Here is a table summarizing the different file types generated during the C++ compilation process and their meanings:

| Extension      | Platform       | Description                                                             |
| -------------- | -------------- | ----------------------------------------------------------------------- |
| `.cpp`         | Cross-Platform | C++ Source file which contains the code written by the programmer.      |
| `.h`           | Cross-Platform | Header file which typically contains function declarations and macros.  |
| `.hpp`         | Cross-Platform | C++ Header file, similar to `.h` but specifically for C++ declarations. |
| `.i`           | Cross-Platform | Preprocessed source file (rarely seen; often a temporary file).         |
| `.o`           | Unix-like      | Object file, contains machine code generated by the compiler.           |
| `.obj`         | Windows        | Object file, contains machine code generated by the compiler.           |
| `.a`           | Unix-like      | Static library, an archive of object files for static linking.          |
| `.lib`         | Windows        | Static library file or an import library for dynamic linking.           |
| `.so`          | Unix-like      | Shared Object, dynamic library loaded at runtime.                       |
| `.dll`         | Windows        | Dynamic Link Library, dynamic library loaded at runtime.                |
| `.exe`         | Windows        | Executable file, the final runnable program.                            |
| (No extension) | Unix-like      | Executable file, the final runnable program.                            |
| `.dylib`       | macOS          | Dynamic library, similar to `.so`, used in macOS.                       |
| `.dSYM`        | macOS          | Debug symbols file, contains debug information for use in a debugger.   |
| `.pdb\*\*      | Windows        | Program Database, stores debugging information about a program.         |

**Note\***: This table does not cover every possible file type associated with C++
development, such as those used by various Integrated Development Environments
(IDEs) for project management or by other tools for resources, but it does cover
the main file types produced and used during the build process.

- Here is an expanded version of the table with `.dylib` included and
  other relevant file types:

This table includes file extensions for debug symbols which are also an
important part of the development process, especially when debugging
applications. Debug symbols are generated alongside executables and libraries to
provide a mapping from the binary code to the original source code, making it
possible to step through the source code during debugging sessions.

## Can a Project has several translation units?

Yes, a project can have several translation units. In fact, it's quite common in
larger C++ projects. A translation unit is essentially a single compiled source
file, but it includes all the headers and included source files that are brought
in via `#include` preprocessor directives. Here's how it works:

1. **Each `.cpp` File Is a Separate Translation Unit**: When you compile a
   `.cpp` file, the compiler processes it along with all the included headers
   and generates one object file (`.o` or `.obj`) per `.cpp` file. Each of these
   is a translation unit.
2. **Headers Are Not Translation Units**: Header files (`.h` or `.hpp`) are not
   compiled on their own; they are included in one or more `.cpp` files. They
   become part of a translation unit when they are included and processed in a
   `.cpp` file.
3. **Linking Translation Units**: After all the individual translation units
   have been compiled into object files, a linker combines all the object files
   into a single executable (or library). If there are multiple `.cpp` files,
   the linker resolves cross-references between them.

Here's an example with multiple `.cpp` files in a project:

- `main.cpp` includes `main.h` and possibly other headers.
- `utils.cpp` includes `utils.h`.
- `network.cpp` includes `network.h`.

Each of these `.cpp` files will be compiled into its own object file:

- `main.o`
- `utils.o`
- `network.o`

These object files are then linked together to create the final executable
program. Each `.cpp` file and the headers it includes form separate translation
units during the compilation process.

Here's a table defining various terms related to the C++ build process:

| Term                 | Meaning                                                                                           | Associated File Extension(s)                                           |
| -------------------- | ------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------- |
| Source File          | Contains code written by the programmer. It's the starting point of the compilation process.      | `.cpp`, `.cc`, `.cxx`, `.c++`                                          |
| Header File          | Used to declare the structure of the program. Contains declarations of functions, classes, etc.   | `.h`, `.hpp`                                                           |
| Translation Unit     | The result of processing a source file and all its included headers and source files.             | N/A (conceptual, corresponds to a `.cpp` file pre-compilation)         |
| Object File          | Contains machine code output by the compiler. It's what the linker uses to create the executable. | `.o` (Unix-like), `.obj` (Windows)                                     |
| Static Library       | An archive of object files, linked into an executable at build time.                              | `.a` (Unix-like), `.lib` (Windows)                                     |
| Dynamic Library      | A library loaded at runtime, allowing for shared code across programs.                            | `.so` (Unix-like), `.dll` (Windows), `.dylib` (macOS)                  |
| Executable           | The final runnable program file resulting from the linking process.                               | `.exe` (Windows), (No extension or `.out`) (Unix-like), `.app` (macOS) |
| Preprocessed File    | An intermediate file created after the preprocessing step. It's not usually saved.                | `.i` (rarely used as a file extension)                                 |
| Standard Library     | A collection of classes and functions prescribed by the language standard.                        | N/A (implemented in compilers, may be part of runtime)                 |
| Import Library       | Used on some platforms like Windows to describe a dynamic library's interface to the linker.      | `.lib` (Windows)                                                       |
| Shared Object        | The Linux term for a dynamic library.                                                             | `.so` (Unix-like)                                                      |
| Dynamic Link Library | The Windows term for a dynamic library.                                                           | `.dll` (Windows)                                                       |
| Archive File         | A static library in Unix-like systems.                                                            | `.a` (Unix-like)                                                       |
| Debug Symbols File   | Contains debug information, mapping the executable to the source code for debugging.              | `.pdb` (Windows), `.dSYM` (macOS)                                      |

This table includes terms that represent both physical files (with extensions)
and conceptual aspects of the build process (like the translation unit). The
standard library files are usually part of the runtime and are typically
pre-compiled with the compiler, not directly visible in the project file
structure.

## Header files

How the header will not repeated among the translation units in case it is mentioned twice

- To prevent a header from being included multiple times within the same
  translation unit, which can cause errors due to redefinition, C++ uses an
  "include guard." An include guard is a preprocessor technique that ensures a
  header file is only included once no matter how many times it's requested by the
  preprocessor.

Here's how include guards typically work:

```cpp
#ifndef HEADER_NAME_H
#define HEADER_NAME_H

// declarations and definitions

#endif // HEADER_NAME_H
```

- The `#ifndef` directive checks if `HEADER_NAME_H` (a unique macro name) has
  been defined. If not, it defines `HEADER_NAME_H` and allows the inclusion of
  the header's contents. The next time the preprocessor encounters this header,
  `HEADER_NAME_H` will already be defined, so the contents within the `#ifndef`
  and `#endif` block will be ignored.
- Include guards are standard practice in C++ programming and are essential for
  preventing multiple inclusions of the same header in a single translation
  unit.
- When multiple translation units include the same header, each translation unit
  is compiled separately, so the include guard only prevents multiple inclusions
  within each translation unit. The linker is responsible for handling the
  definitions when the separate translation units are combined into a single
  executable or library, ensuring there are no duplicate symbols.

## Guards for Directives (#include)

Yes, include guards are also relevant for standard library headers like
`<iostream>`. However, standard library implementations handle this internally
so that when you include a standard library header like `<iostream>` in multiple
source files (translation units), each one will only include it once during
compilation. This is to prevent multiple definitions and other issues that might
arise from including the same declarations multiple times in a single
translation unit.

In your example, including `<iostream>` in both `main.cpp` and `lib.cpp` works
without issues:

- `main.cpp` includes `<iostream>`. The preprocessor includes the content of
  `<iostream>` in the translation unit that is being compiled from `main.cpp`.
- `lib.cpp` includes `<iostream>`. The same process occurs separately, as
  `lib.cpp` is another translation unit.

After preprocessing and compilation, both `main.o` and `lib.o` will have their
own compiled code from `<iostream>`. The linker then takes over and ensures that
any standard library code is properly managed, and the final executable has only
one set of definitions for the standard library functions used, regardless of
how many times they were included in different translation units.

The C++ Standard Library and its headers are designed to be included in multiple
translation units; it's a fundamental part of supporting modular compilation.

## Question -1

- Explain more about the translation units
  - Is it possible to make two or more translation units in single project? Assume I am calling them all into main.cpp
  - Yes, it's not only possible but also quite common to have multiple translation
    units in a single C++ project. You typically organize code into multiple source
    files to improve maintainability, encapsulation, and reusability. Here's a
    simple illustration of how you might organize a project:

```cpp
// main.cpp
#include "lib.h"
#include <iostream>

int main() {
    lib_function(); // Function from lib.cpp
    std::cout << "Main function." << std::endl;
    return 0;
}

// lib.cpp
#include "lib.h"
#include <iostream>

void lib_function() {
    std::cout << "Function from lib." << std::endl;
}

// lib.h
#ifndef LIB_H
#define LIB_H

void lib_function(); // Declaration of function from lib.cpp

#endif // LIB_H
```

In this setup:

- `main.cpp` includes `lib.h` to know about `lib_function()` and calls `lib_function()` within `main()`.
- `lib.cpp` defines what `lib_function()` actually does.
- `lib.h` is the header file that declares `lib_function()`.

Each `.cpp` file (main.cpp and lib.cpp) is a separate translation unit, and when
you compile the project, each translation unit will be compiled into an object
file:

- `main.cpp` -> `main.o`
- `lib.cpp` -> `lib.o`

Then, during the linking stage, both object files (`main.o` and `lib.o`) are
linked together to form the final executable. You can compile and link these
using a command-line interface with a compiler like g++. Here's how it might
look:

```sh
g++ -c main.cpp -o main.o
g++ -c lib.cpp -o lib.o
g++ main.o lib.o -o my_program
```

The `-c` flag tells the compiler to generate object files, and the final line
without `-c` links the object files into an executable called `my_program`.

## Question -2

- But I thought if I call lib in main then the result will be a one single big translation unit?
  - It seems there might be a misunderstanding about how the translation unit works
    in relation to including one file within another. Including one file in another
    (such as `lib.h` in `main.cpp`) does not merge the contents of `lib.cpp` into
    the translation unit of `main.cpp`.

Here's what happens when you include `lib.h` in `main.cpp`:

1. **Preprocessing**: The content of `lib.h` is copied into `main.cpp` during
   the preprocessing step. This does not include the actual definitions and
   implementations of functions from `lib.cpp`—only their declarations from
   `lib.h`.
2. **Compilation**: Each `.cpp` file is compiled separately into its own object
   file. `main.cpp` becomes `main.o`, and `lib.cpp` becomes `lib.o`. At this
   point, `main.o` knows that `lib_function()` exists because it's declared in
   `lib.h`, but it doesn't know how it's implemented—that's in `lib.o`.
3. **Linking**: The linker then combines `main.o` and `lib.o` into a single
   executable. The linker resolves the references to `lib_function()` in
   `main.o` by finding its definition in `lib.o`.

So, even though `main.cpp` includes `lib.h`, `main.cpp` and `lib.cpp` remain
separate translation units. They are only brought together into a single,
cohesive program during the linking stage, which is after each translation unit
has been compiled into an object file.

## Question -3

Now, can I say in that case that for every CPP file there is a corresponding
translation unit? If not then what is the reason? Is CPP file can be considered
as a translation unit?

Yes, you can say that for every `.cpp` file, there is a corresponding
translation unit in the context of compiling a C++ program. The `.cpp` file
itself, along with all the content that gets included (`#include`) and expanded
(macros, inline functions, templates, etc.) during the preprocessing step, forms
a single translation unit. So, each `.cpp` file can indeed be considered a
translation unit after preprocessing. Here's why:

- **Preprocessing**: Each `.cpp` file is preprocessed individually. During this
  step, all included headers (`#include`), macros, and conditional compilation
  directives are processed. The result is a single, often much larger, source
  code file that is then ready for compilation. This preprocessed file
  represents the translation unit.
- **Compilation**: The translation unit is compiled into an object file. The
  compiler translates the preprocessed C++ code into assembly, which is then
  turned into machine code, producing an object file (`.o` or `.obj`).

Therefore, the relationship is generally one-to-one: one `.cpp` file is
preprocessed and compiled into one translation unit, which results in one object
file. However, it's worth noting that a translation unit is a conceptual part of
the compilation process and doesn't directly correspond to a physical file you
can see (other than the `.cpp` source file and the resulting `.o` or `.obj`
object file).

## Question -4

Is it possible to show the .i files after the pre processor Show me an easy
hello world example using clang++ command line, and point what kind of flag is
needed?

- The `.i` files are the result of the C preprocessor processing the source files
  (`.cpp`). They contain the expanded source code with all the macros replaced and
  header files included. Here's how you can see the `.i` preprocessed files using
  `clang++`.

First, let's consider a simple "Hello, World!" program. You have two files:
`main.cpp` and `hello.h`.

`hello.h`:

```cpp
#ifndef HELLO_H
#define HELLO_H

void say_hello();

#endif // HELLO_H
```

`main.cpp`:

```cpp
#include "hello.h"
#include <iostream>

void say_hello() {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    say_hello();
    return 0;
}
```

Now, to generate the `.i` preprocessed file using `clang++`, you would use the
`-E` flag, which tells the compiler to stop after the preprocessing stage.
Here's the command you would use in the terminal:

```sh
clang++ -E main.cpp -o main.i
```

- This will create a `main.i` file which contains the result of preprocessing
  `main.cpp`. If you open `main.i`, you will see the contents of `main.cpp` with
  the contents of `hello.h` included inline and all preprocessing directives
  executed. It will also include the content from the standard library headers
  like `<iostream>` that were included in `main.cpp`.

- The `.i` file is not typically used in the compilation process—it's mainly
  useful for debugging preprocessor issues. Normally, preprocessing is just the
  first step of the compilation that happens internally, and the compiler doesn't
  save the intermediate result unless specifically instructed to do so with flags
  like `-E`.


## Question -5
What is the result of main.i show it to me of your previous example?
- The `.i` file resulting from preprocessing `main.cpp` would contain the entire
  contents of `main.cpp` with all `#include` directives replaced by the actual
  content of the included files, macros expanded, and comments removed. This
  file can be quite large due to the inclusion of standard library headers like
  `<iostream>`.

- For the simple `main.cpp` and `hello.h` files provided earlier, the `main.i`
  would look similar to the original `main.cpp`, but with the contents of
  `hello.h` copied into it and the expanded code from `<iostream>` and other
  headers included by it. Here is a simplified example of what the `main.i`
  might look like:

```cpp
// Contents of hello.h inlined (assuming hello.h does not include other headers)
void say_hello();

// ...Lots of system-specific code from including <iostream>...

void say_hello() {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    say_hello();
    return 0;
}

// ...More system-specific code and definitions...
```

- The preprocessor output (`main.i`) would not normally be read by humans due to
  its size and complexity. However, it can be useful for debugging if you need
  to see exactly what the preprocessor is doing with your code.
- The actual content can be thousands of lines long because standard headers
  like `<iostream>` often include other headers, which in turn include even
  more. It's a recursive and expansive inclusion of a large portion of the
  standard library.
