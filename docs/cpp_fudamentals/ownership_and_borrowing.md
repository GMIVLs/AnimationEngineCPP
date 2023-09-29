# OwnerShip and Borrowing

- Certainly, understanding ownership in C++ is vital to prevent memory leaks
and ensure proper resource management. Here's a table detailing the primary
ownership models in C++:

| **Ownership Type**                       | **Description**                                                                                                                                                | **Code Example**                                          | **Common Usages**                                                                    | **Best Practices**                                                                                       |
| ---------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------- | ------------------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------- |
| **Raw Pointer**                          | Traditional C++ pointers that can point to allocated memory but don't manage the memory's lifecycle.                                                           | `int* p = new int(5);`                                    | Older C++ code; low-level programming.                                               | Always pair `new` with `delete`; avoid manual memory management in high-level code.                      |
| **Stack Ownership**                      | Variables created on the stack are automatically destroyed when they go out of scope.                                                                          | `int i = 5;`                                              | Local variables, small objects.                                                      | Prefer stack allocation for small objects and primitives.                                                |
| **Unique Ownership (`std::unique_ptr`)** | Smart pointer that owns a dynamically allocated object exclusively. The object is deleted automatically when the `unique_ptr` is destroyed.                    | `std::unique_ptr<int> p = std::make_unique<int>(5);`      | When only one owner should manage the object's lifecycle.                            | Prefer `std::make_unique` to create a `unique_ptr`. Avoid raw pointer use for ownership.                 |
| **Shared Ownership (`std::shared_ptr`)** | Smart pointer that can have multiple owners. Uses reference counting to automatically delete the managed object when the last `shared_ptr` to it is destroyed. | `std::shared_ptr<int> p = std::make_shared<int>(5);`      | When multiple parts of code need to share ownership.                                 | Prefer `std::make_shared` for efficiency. Be cautious of cyclic references.                              |
| **Weak Ownership (`std::weak_ptr`)**     | Companion to `shared_ptr` that doesn't participate in ownership. Used to break cyclic references.                                                              | `std::weak_ptr<int> w = p;` (where `p` is a `shared_ptr`) | To observe or cache objects owned by `shared_ptr` without extending their lifetimes. | Use with `shared_ptr` to avoid cycles. Always check if it's expired before use.                          |
| **Reference**                            | Alias for another variable. Doesn't own the referred variable.                                                                                                 | `int& ref = i;`                                           | When you want an alias to an existing object without copying.                        | Don't use references for ownership. Ensure the referred object outlives the reference.                   |
| **Reference Counting**                   | Mechanism (often in conjunction with smart pointers) that tracks the number of references to a resource, deleting it when the count drops to zero.             | (Implicit in `std::shared_ptr`)                           | Managing resources shared by multiple owners.                                        | Mostly abstracted by `shared_ptr`. Be cautious of cyclic references.                                     |
| **Move Semantics**                       | Transfer of ownership from one entity to another, leaving the original in a valid but unspecified state.                                                       | `std::vector<int> v2 = std::move(v1);`                    | Efficiently transferring resources, especially in function returns or assignments.   | Use `std::move` cautiously. After moving from an object, avoid using it except to assign or destruct it. |

**General Notes**:

- Always prefer smart pointers (`std::unique_ptr`, `std::shared_ptr`) over raw
pointers for ownership.
- The stack is efficient and automatically managed, so prefer stack allocation
when feasible.
- Move semantics, introduced in C++11, provide efficient ways to transfer
ownership without unnecessary deep copies.
- Raw pointers should be reserved for non-owning scenarios or interfaces with C
libraries.

