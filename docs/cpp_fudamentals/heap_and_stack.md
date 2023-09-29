# Heap and Stack

## All methods to clean a heap memory

- Managing dynamically allocated memory (objects on the heap) is crucial in
  C++. Here's a table that outlines the different ways to deallocate or clean up
  heap-allocated objects:

| **Method**          | **Description**                                                                                                  | **Example**                                                                          | **Best Practices**                                                                                                        |
| ------------------- | ---------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------- |
| **delete**          | Used to deallocate memory that was allocated with `new` for single objects.                                      | `int* p = new int; delete p;`                                                        | Always set the pointer to `nullptr` after `delete` to avoid dangling pointers.                                            |
| **delete[]**        | Used to deallocate memory that was allocated with `new[]` for arrays.                                            | `int* arr = new int[10]; delete[] arr;`                                              | Same as `delete`: always set the pointer to `nullptr` afterwards.                                                         |
| **Destructor**      | A special class method that is invoked when an object goes out of scope or is explicitly deleted.                | `class MyClass { ~MyClass() { /* cleanup */ } };`                                    | Useful to release resources (like heap memory) associated with an object.                                                 |
| **std::unique_ptr** | Smart pointer that owns a heap-allocated object and deletes it when the `unique_ptr` goes out of scope.          | `std::unique_ptr<int> p(new int);`                                                   | Avoids manual memory management. When the `unique_ptr` is destroyed, it automatically deletes the associated heap object. |
| **std::shared_ptr** | Smart pointer that can have multiple owners. The heap object is deleted when the last `shared_ptr` is destroyed. | `std::shared_ptr<int> p1(new int); std::shared_ptr<int> p2 = p1;`                    | Reference counting ensures object is deleted only after last reference is gone. Prefer `std::make_shared` for allocation. |
| **std::weak_ptr**   | A non-owning smart pointer. Doesn't affect the reference count of a `shared_ptr`.                                | `std::weak_ptr<int> wp = p1;`                                                        | Useful in situations where circular references might occur with `shared_ptr`. Doesn't prevent object from being deleted.  |
| **Custom Deleter**  | Provide custom deletion logic for smart pointers.                                                                | `auto deleter = [](int* p) { delete p; }; std::shared_ptr<int> p(new int, deleter);` | For special cleanup needs with smart pointers, like custom memory pools or specific deletion routines.                    |

**Important Points**:

1. **Ownership**: With raw pointers, you need to manually manage ownership.
   With smart pointers, ownership semantics are clearer (`unique_ptr` has
   unique ownership, `shared_ptr` can have shared ownership).
2. **Dangling Pointers**: After deallocating memory using `delete` or
   `delete[]`, always set the pointer to `nullptr` to prevent accidental access
   to now-deallocated memory.
3. **Avoid Manual Management**: Whenever possible, prefer to use smart pointers
   like `std::unique_ptr` and `std::shared_ptr` over raw pointers. They provide
   automatic memory management, making the code safer against memory leaks and
   other memory-related issues.
4. **Custom Deleters**: They allow you to provide specific logic for
   deallocating memory or resources when using smart pointers. Useful in
   scenarios where the default `delete` isn't suitable.

- To utilize smart pointers, remember to include the `<memory>` header.

## List all data structures in CPP allocated on heap vs on stack

In C++, you have control over whether you want to allocate memory on the stack
or on the heap. This applies to almost any type of data structure, including
both built-in types (like `int`, `double`, `array`, etc.) and user-defined
types (like classes and structs).

Here's a list of some common data structures in C++, and examples of how you
could allocate them on the stack or on the heap:

1. **Arrays**:

   - Stack: `int arr[10];`
   - Heap: `int* arr = new int[10];`

2. **Standard Library Containers (like `std::vector`, `std::list`, `std::map`, etc.)**:

   - Stack: `std::vector<int> vec(10);`
   - Heap: `std::vector<int>* vec = new std::vector<int>(10);`

3. **Classes/Structs**:

   - Stack: `MyClass obj;`
   - Heap: `MyClass* obj = new MyClass();`

4. **Strings**:
   - Stack: `std::string str;`
   - Heap: `std::string* str = new std::string();`

Note that when you allocate memory on the heap (using `new`), it's your
responsibility to deallocate it when you're done using it (using `delete`). If
you forget to do this, it can lead to memory leaks.

On the other hand, when you allocate memory on the stack, it automatically gets
deallocated when it goes out of scope. This makes memory management easier, but
it also means that stack-allocated memory can't be used to persist data beyond
the lifetime of the current scope.

Remember that `std::vector` and other Standard Library containers automatically
manage their own memory, so even when you allocate them on the stack, they can
still hold large amounts of data that's actually stored on the heap. So, you
get the convenience of stack allocation (automatic lifetime management) with
the flexibility of heap allocation (dynamic size).

Finally, note that some types, like `std::array`, are intended to be allocated
on the stack, and don't have a straightforward way to be allocated on the heap.
Conversely, things like `std::shared_ptr` or `std::unique_ptr` are designed to
manage heap-allocated memory.

## Keyword New and allocations on the heap

In C++, there are two common ways to allocate memory on the heap:

1. **new**: This is the most common way. It allocates memory and calls the
   constructor for the object.

```cpp
int* i = new int(5); // allocate an int on the heap with a value of 5
```

2. **malloc**: This is a C library function also available in C++. It allocates
   a block of memory of the specified size and returns a pointer to it, but
   does not call the constructor.

```cpp
int* i = (int*)malloc(sizeof(int)); // allocate an int on the heap, not initialized
```

In modern C++, it's recommended to use `new` over `malloc`, as `new` is
type-safe, calls constructors, and is more flexible with C++ types.

In addition to `new`, in modern C++, you could use smart pointers like
`std::unique_ptr` or `std::shared_ptr`, which automatically manage memory
deallocation, reducing the risk of memory leaks.

For example:

```cpp
std::unique_ptr<int> i(new int(5));  // Using new
// or even better:
auto i = std::make_unique<int>(5);   // Using std::make_unique
```

In this case, `i` will automatically be deallocated when it goes out of scope.
This makes your code safer and easier to maintain by reducing manual memory
management.

## Can I allocate on heap of multi dimensional array without using new keyword.

In C++, the `new` keyword is typically used to allocate memory on the heap.
However, there are other ways to allocate memory on the heap that don't
directly involve `new`. One alternative is to use `malloc()`, `calloc()`, and
`realloc()`, which are part of the C standard library (included via `#include
<cstdlib>` or `#include <stdlib.h>` in C++). These functions allow you to
allocate and deallocate memory on the heap. Here's an example of how you could
use `malloc()` to allocate a 2D array on the heap:

```cpp
#include <cstdlib>

int main() {
    int rows = 5;
    int cols = 10;

    // Allocate memory for the rows
    int** arr = (int**)malloc(rows * sizeof(int*));

    // For each row, allocate memory for the columns
    for(int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    // Don't forget to free the memory!
    for(int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
```

Please note that while `malloc` and its associated functions are available in
C++, they're considered more C-style and their usage is generally discouraged
in C++ where `new` and `delete` (or smart pointers) are preferred. They do not
call constructors and destructors, which makes them unsuitable for non-trivial
types. If you don't want to use `new` directly, but want the benefits it
provides (like constructors and destructors being automatically called), you
can use `std::vector` or other similar containers, which handle memory
management for you:

```cpp
#include <vector>

int main() {
    int rows = 5;
    int cols = 10;

    // Create a 2D vector (a vector of vectors)
    std::vector<std::vector<int>> vec(rows, std::vector<int>(cols));

    // You don't need to worry about freeing the memory

    return 0;
}
```

This creates a 2D array (in the form of a `std::vector`) on the heap. When
`vec` goes out of scope, its destructor is called, which automatically frees
the memory it was using. This helps prevent memory leaks, which can be a common
issue when manually managing memory.
