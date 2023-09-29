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
