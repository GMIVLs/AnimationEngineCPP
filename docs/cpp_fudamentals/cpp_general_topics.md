# General Topics in CPP

<!-- vim-markdown-toc Marked -->

* [Introduction](#introduction)
    * [Common keywords in C++](#common-keywords-in-c++)
* [Standard Library in C++](#standard-library-in-c++)
* [Other Concepts](#other-concepts)

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



