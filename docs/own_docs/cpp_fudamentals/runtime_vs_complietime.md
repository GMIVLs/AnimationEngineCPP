# Run time vs Complie time

- Understanding the distinction between compile-time and run-time in C++ is
  crucial. Here's a table illustrating these concepts:

| **Concept**                   | **Time**     | **Description**                                                                                                  | **Code Example**                                               | **Common Usages**                              | **Best Practices**                                         |
| ----------------------------- | ------------ | ---------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------- | ---------------------------------------------- | ---------------------------------------------------------- |
| **Literal Constants**         | Compile-time | Values known at compile-time.                                                                                    | `const int x = 10;`                                            | Setting fixed values or configurations.        | Avoid magic numbers; use named constants.                  |
| **`constexpr`**               | Compile-time | Enables the definition of constants or functions whose values/results are computable at compile-time.            | `constexpr int square(int x) { return x*x; }`                  | Performance optimizations, array sizes.        | Use `constexpr` to enforce compile-time evaluation.        |
| **Templates**                 | Compile-time | Mechanism to write generic code. Types are deduced at compile-time.                                              | `template<typename T> T max(T a, T b) { ... }`                 | Generic programming, STL containers/functions. | Ensure broad template type applicability.                  |
| **Static Memory Allocation**  | Compile-time | Fixed-size memory allocation, typically on the stack. Size must be known at compile time.                        | `int arr[10];`                                                 | Local variables, class members.                | Monitor stack usage to prevent overflow.                   |
| **Static Assertions**         | Compile-time | Asserts conditions during compilation.                                                                           | `static_assert(sizeof(int) == 4, "Int size is not 4 bytes!");` | Ensuring platform/code assumptions.            | Use to catch violations of assumptions early.              |
| **Dynamic Memory Allocation** | Run-time     | Memory allocation determined at run-time, typically on the heap.                                                 | `int* arr = new int[size];`                                    | Flexible data structures, long-lived objects.  | Pair `new` with `delete`; prefer smart pointers.           |
| **Function Calls**            | Run-time     | Execution of function logic occurs during run-time, unless inlined or evaluated at compile-time via `constexpr`. | `int y = square(x);`                                           | Most of the program's logic.                   | Use function calls to modularize code.                     |
| **I/O Operations**            | Run-time     | Interactions with external systems, like reading/writing files or console operations.                            | `std::cin >> x; std::cout << x;`                               | User input/output, file handling.              | Error handling and validation for I/O operations.          |
| **Variable Values**           | Run-time     | Value of a variable (unless `constexpr`) which might be determined at run-time.                                  | `int x; std::cin >> x;`                                        | Almost everywhere in the program.              | Always initialize variables.                               |
| **Pointers and References**   | Run-time     | Pointing or referring to memory locations which might be determined at run-time.                                 | `int* p = &x;`                                                 | Dynamic data structures, polymorphism.         | Avoid dangling pointers/references.                        |
| **Dynamic Type Checking**     | Run-time     | Checking type at run-time, often in polymorphism scenarios.                                                      | `if (auto derived = dynamic_cast<Derived*>(basePtr)) { ... }`  | Inheritance hierarchies, polymorphic calls.    | Use sparingly; prefer static (compile-time) type checking. |

**General Notes**:

- Compile-time operations are determined when the code is compiled. They can
  help optimize performance since decisions and evaluations are made upfront.
- Run-time operations happen when the program is executed. These offer
  flexibility but can introduce overhead.
- Modern C++ (C++11 and beyond) introduces more compile-time features (like
  `constexpr`) to help with optimization.
- Be conscious of the trade-offs between compile-time and run-time choices,
  especially in performance-critical applications.
