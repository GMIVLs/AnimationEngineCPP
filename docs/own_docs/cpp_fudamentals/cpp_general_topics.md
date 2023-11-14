# General Topics in CPP

<!-- vim-markdown-toc Marked -->

* [Introduction](#introduction)
    * [Common keywords in C++](#common-keywords-in-c++)
* [Standard Library in C++](#standard-library-in-c++)
* [Other Concepts](#other-concepts)
* [What are the uses of C++ static keyword](#what-are-the-uses-of-c++-static-keyword)
* [Is it bad to intialize variables with Null inside the function signature?](#is-it-bad-to-intialize-variables-with-null-inside-the-function-signature?)
* [What is static keyword?](#what-is-static-keyword?)
* [What is itoa and other similar keywords ?](#what-is-itoa-and-other-similar-keywords-?)

<!-- vim-markdown-toc -->

## Introduction

### Common keywords in C++

- Creating a table with _all_ commonly used keywords in C++ would be quite
  extensive. However, I can provide a concise table highlighting some of the most
  frequently used ones. Here we go:

| **Keyword**                      | **Description**                                                                    | **Small Example**                                             |
| -------------------------------- | ---------------------------------------------------------------------------------- | ------------------------------------------------------------- |
| `auto`                           | Deduces the type of a variable from its initializer.                               | `auto x = 42;`                                                |
| `const`                          | Indicates the variable is constant and cannot be changed.                          | `const int x = 10;`                                           |
| `static`                         | Indicates a local variable should retain its value between function calls.         | `static int count = 0;`                                       |
| `extern`                         | Declares a variable without defining it (typically for global variables).          | `extern int x;` (Defined elsewhere)                           |
| `inline`                         | Suggests to the compiler to compile a function inline.                             | `inline int add(int a, int b) { return a + b; }`              |
| `virtual`                        | Allows a function in a base class to be overridden in a derived class.             | `virtual void display();`                                     |
| `override`                       | Indicates a virtual function should override a virtual function in the base class. | `void display() override;`                                    |
| `final`                          | Prevents subclasses or virtual method overrides.                                   | `class FinalClass final {};`                                  |
| `public`, `private`, `protected` | Access specifiers in classes or structs.                                           | `class MyClass { private: int x; public: int getX(); }`       |
| `class`                          | Defines a new type.                                                                | `class MyClass {};`                                           |
| `struct`                         | Similar to `class`, but members are public by default.                             | `struct Point { int x, y; };`                                 |
| `enum`                           | Defines an enumeration.                                                            | `enum Color { RED, GREEN, BLUE };`                            |
| `namespace`                      | Groups a set of global classes, objects, and functions under a single name.        | `namespace MyNamespace { int x; }`                            |
| `typedef`                        | Creates an alias for an existing type.                                             | `typedef long int bigInt;`                                    |
| `using`                          | Introduces a namespace member, or creates type aliases (alternative to `typedef`). | `using bigInt = long int;`                                    |
| `return`                         | Exits a function, optionally returning a value.                                    | `int add(int a, int b) { return a + b; }`                     |
| `if`, `else`                     | Conditional branching.                                                             | `if(x > y) { /*...*/ } else { /*...*/ }`                      |
| `for`, `while`, `do`             | Loop constructs.                                                                   | `for(int i = 0; i < 10; ++i) { /*...*/ }`                     |
| `switch`, `case`                 | Multi-way branching based on a constant-expression.                                | `switch(x) { case 1: /*...*/ break; }`                        |
| `break`, `continue`              | Control the flow inside loops and switch statements.                               | `while(true) { if(error) break; }`                            |
| `new`, `delete`                  | Allocate and deallocate memory dynamically.                                        | `int* p = new int[10]; delete[] p;`                           |
| `try`, `catch`, `throw`          | Exception handling constructs.                                                     | `try { /*...*/ } catch (const std::exception& e) { /*...*/ }` |

- This table is not exhaustive, as C++ has many keywords. Still, the above
  captures a good chunk of the commonly used ones. Remember, understanding how
  and when to use each keyword is essential to writing efficient and clear C++
  code.

## Standard Library in C++

- An overview table of some of the major components or modules in the C++
  standard library and their primary purposes. If you have a specific component
  in mind, I can then provide more detailed information on it.

| **Component**     | **Primary Purpose**                                                                        | **Example Methods/Functions**                  |
| ----------------- | ------------------------------------------------------------------------------------------ | ---------------------------------------------- |
| **`<iostream>`**  | Input/Output stream operations.                                                            | `cin`, `cout`, `cerr`, `clog`                  |
| **`<string>`**    | String manipulation and operations.                                                        | `length()`, `substr()`, `find()`, `replace()`  |
| **`<vector>`**    | Dynamic array implementation.                                                              | `push_back()`, `pop_back()`, `size()`, `at()`  |
| **`<list>`**      | Double-linked list implementation.                                                         | `push_front()`, `pop_front()`, `size()`        |
| **`<map>`**       | Associative container - stores key-value pairs.                                            | `insert()`, `find()`, `begin()`, `end()`       |
| **`<set>`**       | Collection of unique keys.                                                                 | `insert()`, `find()`, `begin()`, `end()`       |
| **`<algorithm>`** | Collection of algorithms for operations like searching, sorting, manipulating ranges, etc. | `sort()`, `find()`, `copy()`, `for_each()`     |
| **`<thread>`**    | Multi-threading operations.                                                                | `thread`, `join()`, `detach()`                 |
| **`<mutex>`**     | Synchronization primitives like mutexes.                                                   | `lock()`, `unlock()`, `try_lock()`             |
| **`<memory>`**    | Memory management utilities like smart pointers.                                           | `make_shared()`, `make_unique()`, `allocator`  |
| **`<chrono>`**    | Date and time utilities and high-resolution timers.                                        | `system_clock`, `duration`, `time_point`       |
| **`<fstream>`**   | File stream operations for reading/writing files.                                          | `ifstream`, `ofstream`, `getline()`, `write()` |
| **`<cmath>`**     | Mathematical operations and functions.                                                     | `sqrt()`, `sin()`, `cos()`, `tan()`            |
| **`<numeric>`**   | Numeric operations for sequences.                                                          | `iota()`, `accumulate()`, `inner_product()`    |
| ...               | ...                                                                                        | ...                                            |

- This table only scratches the surface. There are many more headers and
  functionalities in the C++ standard library. If you're interested in a specific
  module or need more in-depth information about a particular component, please
  let me know!

## Other Concepts

Certainly! Let's delve into some other key C++ concepts:

**1. Scope and Storage Duration**

| **Concept**             | **Scope**       | **Description**                                                                 | **Code Example**                        | **Common Usages**                         | **Best Practices**                                        |
| ----------------------- | --------------- | ------------------------------------------------------------------------------- | --------------------------------------- | ----------------------------------------- | --------------------------------------------------------- |
| **Local Variables**     | Block-scope     | Exist only within the block (e.g., function) where they're defined.             | `{ int x = 10; }`                       | Function parameters, loop variables.      | Limit their use to their intended scope.                  |
| **Global Variables**    | File-scope      | Accessible from the point of declaration to the end of the file.                | `int globalVar = 100;`                  | Constants, shared resources.              | Use sparingly; prefer class encapsulation.                |
| **Static Variables**    | Block-scope     | Retain their value between function calls.                                      | `void func() { static int count = 0; }` | Counting function calls, singletons.      | Understand their lifetime extends to program termination. |
| **Namespace Variables** | Namespace-scope | Variables declared within a namespace. Access scope is controlled by namespace. | `namespace MyNS { int var = 42; }`      | Grouping related variables and functions. | Use to avoid global variable pollution.                   |

**2. Function Types and Binding**

| **Concept**          | **Type**      | **Description**                                                                                | **Code Example**                           | **Common Usages**                          | **Best Practices**                                        |
| -------------------- | ------------- | ---------------------------------------------------------------------------------------------- | ------------------------------------------ | ------------------------------------------ | --------------------------------------------------------- |
| **Regular Function** | Early Binding | Standard function, binding to a call at compile-time.                                          | `void func() { ... }`                      | General-purpose functions.                 | Use for most scenarios where polymorphism isn't required. |
| **Virtual Function** | Late Binding  | Declared in a base class and can be overridden by derived classes. Binding occurs at run-time. | `virtual void func() { ... }`              | Polymorphism, object-oriented programming. | Declare as `override` in derived classes for clarity.     |
| **Inline Function**  | Early Binding | Suggests to the compiler to expand the function inline, avoiding function-call overhead.       | `inline void fastFunc() { ... }`           | Performance-critical, small functions.     | Use judiciously; not all marked get inlined.              |
| **Lambda Function**  | Early Binding | Anonymous function objects, often used for short-lived operations.                             | `auto lambda = [](int x) { return x*x; };` | STL algorithms, short callbacks.           | Keep lambdas concise; avoid long or complex lambdas.      |

**3. Type Qualifiers**

| **Concept**  | **Qualifier** | **Description**                                                                                  | **Code Example**                        | **Common Usages**                                      | **Best Practices**                               |
| ------------ | ------------- | ------------------------------------------------------------------------------------------------ | --------------------------------------- | ------------------------------------------------------ | ------------------------------------------------ |
| **const**    | `const`       | Denotes that the value of the variable shouldn't change after initialization.                    | `const int x = 10;`                     | Immutable variables, function parameters.              | Use to indicate and enforce immutability.        |
| **volatile** | `volatile`    | Indicates that a variable can be changed externally, preventing the compiler from optimizing it. | `volatile int counter;`                 | Hardware registers, signal handlers.                   | Use sparingly; mostly for low-level programming. |
| **mutable**  | `mutable`     | Allows a member of an object to be modified even if the object is a `const` object.              | `class MyClass { mutable int cache; };` | Cache variables, lazy evaluation inside const methods. | Use judiciously; understand its implications.    |

These tables give a high-level view of some essential concepts in C++. As
always, while these tables provide a guideline, the application of these
concepts requires a deeper understanding of the specific problem and context in
real-world scenarios.

## What are the uses of C++ static keyword

The `static` keyword in C++ has several different uses depending on the context
it's used in. Here are the primary uses of the `static` keyword:

1. **Static Variables in Functions**:

   - When used inside a function, the `static` keyword applied to a local
     variable makes that variable retain its value across multiple function
     calls. It's initialized only once, when the program starts, and its value
     persists between function calls.

2. **Static Variables in Classes/Structs**:

   - Inside a class or struct, the `static` keyword applied to a member
     variable makes it shared among all instances of that class or struct. It's
     also sometimes referred to as a "class variable" or "static member."

3. **Static Member Functions**:

   - A member function declared as `static` belongs to the class itself, not to
     any instance of the class. It can be called without creating an instance of
     the class and operates on class-level data.

4. **Static Local Functions**:

   - A local function declared as `static` is only accessible within the
     translation unit (source file) it's defined in. It can't be linked to from
     other translation units.

5. **Static Data Members in Classes (C++17 and later)**:

   - Starting from C++17, static data members of classes can be defined inside
     the class and must be initialized outside the class definition. They are
     shared among all instances of the class and can be useful for maintaining
     class-level information.

6. **Static Assertions (C++11 and later)**:

   - In C++11 and later, the `static_assert` keyword is used to perform
     compile-time assertions. It helps ensure that certain conditions are met at
     compile time, or it triggers a compilation error.

7. **Static Initialization Order (C++ Static Initialization Fiasco)**:
   - The order in which global or static objects are initialized across
     different translation units isn't guaranteed. This can lead to
     initialization order problems, often referred to as the "static
     initialization order fiasco." Techniques like the Singleton pattern or using
     local static variables inside functions can help mitigate these issues.

These are some of the main uses of the `static` keyword in C++. Each use serves
a specific purpose and contributes to different aspects of the language, such
as variable lifetime, member functions, memory management, and compile-time
checks.

## Is it bad to intialize variables with Null inside the function signature?

In C++, it's perfectly fine to provide default values for function parameters.
This allows for a function to be called with fewer arguments than it has
parameters, and in such cases, the missing arguments are initialized to their
corresponding default values.

But, it's important to note that the way you provide these default values might
differ based on the type of parameter. For instance, you would typically
initialize a pointer with `nullptr` (not `NULL`, which is more of a C-style),
an integer with 0, and so on.

Here's an example:

```cpp
void foo(int* ptr = nullptr, int val = 0) {
    // Your code here
}
```

In this case, if you call `foo()` without any arguments, `ptr` will be
`nullptr` and `val` will be `0`. Also, while this can make your code more
flexible, it can also make it harder to understand if not used judiciously, as
it's not immediately clear when looking at a function call what values the
missing arguments will have. So, it's generally a good idea to use default
arguments sparingly and only when it really makes sense to do so.

## What is static keyword?

The `static` keyword in C++ has different meanings depending on the context in
which it's used.

**1. Inside a function:** If a variable is declared as `static` inside a
function, it maintains its value between function calls. Normally, a local
variable in a function is destroyed as soon as the function ends. But a static
local variable remains in memory while the program is running. For example:

```cpp
void count() {
    static int calls = 0;  // this variable will not be destroyed after the function ends
    calls++;
    cout << "This function has been called " << calls << " times.\n";
}
```

**2. Outside of a function (at file scope):** When `static` is used in the
global scope (outside all functions), it means that the variable or function
with this keyword is only visible in the file it is declared in, not in other
files, even if you include the header of the file. This can be used to hide
implementation details of a module.

```cpp
static int hiddenVariable;  // this variable cannot be accessed from other files

static void hiddenFunction() {  // this function cannot be accessed from other files
    // implementation
}
```

**3. Inside a class:** When `static` is used in a class:

- For member variables: A `static` member variable is shared by all objects of
  the class, i.e., all objects of the class will have the same value for this
  variable. It is not tied to a particular object of the class but rather belongs
  to the class itself.

```cpp
class MyClass {
public:
    static int sharedVariable;
};
// Define and initialize static member outside the class
int MyClass::sharedVariable = 0;
```

- For member functions: A `static` member function can be called even without
  an object of the class, and it can only access `static` member variables of the
  class (since it does not have an object context).

```cpp
class MyClass {
public:
    static int sharedVariable;

    static void modifySharedVariable(int newVal) {
        sharedVariable = newVal;
    }
};
// Define and initialize static member outside the class
int MyClass::sharedVariable = 0;
```

Here, `MyClass::modifySharedVariable(5);` would be a valid call even without
any `MyClass` object.

## What is itoa and other similar keywords ?

The `itoa` function is a standard library function in C (not included in C++)
that converts an integer to a string. `itoa` stands for "integer to ASCII".
It's often found in older C code and non-standard C++ code. Its prototype is:

```c
char* itoa(int value, char* str, int base);
```

Here, `value` is the integer that you want to convert to a string. `str` is the
string buffer where the converted string will be stored, and `base` is the
number base for the conversion.

For equivalent functionality in C++, you can use the `std::to_string` function,
which converts various data types to a string, like so:

```cpp
std::string str = std::to_string(12345);
```

Similar to `itoa`, there are a number of other functions that convert different types to strings in C:

1. `ltoa`: Converts a long integer to a string.
2. `ultoa`: Converts an unsigned long integer to a string.
3. `lltoa`: Converts a long long integer to a string.
4. `ulltoa`: Converts an unsigned long long integer to a string.

In C++, you can use `std::to_string` for these conversions as well. It is
overloaded to support `int`, `long`, `long long`, `unsigned long`, `unsigned
long long`, `float`, `double`, and `long double`.
