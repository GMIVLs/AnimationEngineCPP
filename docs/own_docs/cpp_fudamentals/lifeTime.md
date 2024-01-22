# LifeTime in CPP

<!-- vim-markdown-toc Marked -->

* [Concept](#concept)
* [Example](#example)

<!-- vim-markdown-toc -->

## Concept

- Lifetime in C++ is crucial for understanding resource management and avoiding issues like memory leaks or undefined behavior. Here's a table that provides an overview:

| **Lifetime Type**            | **Description**                                                                                                      | **Code Example**                                      | **Common Usages**                                                           | **Best Practices**                                                                  |
| ---------------------------- | -------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------- | --------------------------------------------------------------------------- | ----------------------------------------------------------------------------------- |
| **Automatic (Stack)**        | Duration of a function call. Objects are automatically destroyed when they go out of scope.                          | `int x = 10;`                                         | Local variables, function parameters, and references.                       | Utilize for short-lived objects. Avoid returning pointers/references to them.       |
| **Static**                   | Duration of the program. Initialized once and destroyed after `main()` exits.                                        | `static int x = 10;`                                  | Persistent states within functions, class-level variables.                  | Use judiciously to avoid global mutable state.                                      |
| **Dynamic (Heap)**           | Manually managed. Begins when memory is allocated and ends when it's explicitly deallocated.                         | `int* p = new int(10); ... ; delete p;`               | Large objects, objects with uncertain lifetimes, or shared ownership.       | Prefer smart pointers (`std::unique_ptr`, `std::shared_ptr`) over raw pointers.     |
| **Temporary**                | Lives until the end of the full-expression in which they are created.                                                | `int x = f() + g();` (results of `f()` and `g()`)     | Intermediate results in complex expressions.                                | Be cautious when binding temporaries to references. Use `std::move` for efficiency. |
| **Thread Storage Duration**  | Duration of a thread. Variables with this duration exist one-per-thread.                                             | `thread_local int x = 10;`                            | Variables that need to be isolated to a specific thread.                    | Use when needing thread-specific singletons or caches.                              |
| **Reference**                | References don't have their own lifetime; they take on the lifetime of what they reference.                          | `int& ref = x;`                                       | When you need an alias to another object without a new memory location.     | Always ensure that the referred-to object outlives any references to it.            |
| **Managed (Smart Pointers)** | Managed by smart pointers. The object's lifetime ends when no more smart pointers point to it (or explicitly reset). | `std::shared_ptr<int> p = std::make_shared<int>(10);` | When objects need to be shared among parts of code or need custom deleters. | Always prefer smart pointers for dynamic allocation.                                |

**General Notes**:

- For stack-allocated objects, the destructor is called automatically when the
object goes out of scope.
- For dynamically allocated memory, always ensure to deallocate the memory
after use.
- Smart pointers (like `std::unique_ptr` and `std::shared_ptr`) provide
automatic management for dynamic memory, making it easier to manage lifetimes.
- Avoid dangling references and pointers. Always validate the lifetime of
referred or pointed-to objects.
- Understand and leverage move semantics to transfer ownership without
unnecessary copies, especially in modern C++ (C++11 and later).

## Example

- Assume we have the following

```cpp
char* testing_string(){
  const char* ptr = {"Hello my Name is Michael"};
  return ptr;
}

```

- Once we compile, we will get an error message says

```sh
Cannot initialize return object of type `char *`  with an lvalue of type `const char*`
```

- The issues with this code are:
  - Returning a Pointer to a String Literal: While string literals have
    static storage duration (they exist for the lifetime of the program), the
    main issue here is that you're returning a char* (non-const pointer) to a
    const char* (pointer to const data). This can potentially lead to undefined
    behavior if someone tries to modify the content via the returned pointer.
  - Mismatched Return Type: The function is declared to return char* but you're
    returning a const char*. This breaks the const-correctness principle, and
    you're basically allowing potential modification of immutable data.
- To fix it:
  - Correct the Return Type: Since string literals are immutable, you should
    return a pointer that reflects that immutability:

```cpp
const char* testing_string() {
    return "Hello my Name is Michael";
}
```

By doing this, you're indicating that the string returned by the function should not be modified.



Assuming that we comprehend the duration of the current goal for our current
approach to handle all types of theoretical work from home,

Could we also work on the right way once we arrive home and achieve all the goals and handle all the current ideas.




Upon arriving home and achieving all our goals while handling all current ideas,
let us also ensure that we are following proper grammar and spelling to improve
the overall quality of our work.
