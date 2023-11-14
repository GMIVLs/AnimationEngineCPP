# Smart Pointers

- Here's a table listing the smart pointers available in C++ and their typical use cases:

| **Smart Pointer**   | **Description**                                                                                                                                                                                                                     | **Small Example**                                                                                           |
| ------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------- |
| **std::unique_ptr** | Owns a unique object, i.e., there can be only one `unique_ptr` to the same object. Used when a single ownership model is appropriate. Automatically deletes the object when the `unique_ptr` goes out of scope.                     | `std::unique_ptr<int> p1(new int(42));` OR using `std::make_unique`: `auto p1 = std::make_unique<int>(42);` |
| **std::shared_ptr** | Owns a shared object; the object can be shared among multiple `shared_ptr`s. Maintains a reference count, and deletes the object when the last `shared_ptr` that owns it is destroyed or reset.                                     | `std::shared_ptr<int> p2(new int(42));` OR using `std::make_shared`: `auto p2 = std::make_shared<int>(42);` |
| **std::weak_ptr**   | A companion to `shared_ptr`, doesn't change the reference count. Useful in situations where you want to prevent circular references among `shared_ptr`s. When you need to access the object, it can be converted to a `shared_ptr`. | `std::weak_ptr<int> wp = p2;` (Assuming `p2` is a `shared_ptr<int>`)                                        |
| **std::auto_ptr**   | Deprecated in C++11 and removed in C++17. Was a precursor to `unique_ptr` but had some issues (e.g., unclear ownership transfers). Avoid using.                                                                                     | `std::auto_ptr<int> p3(new int(42));` (Not recommended)                                                     |

**Notes:**

- **std::unique_ptr**: Ensures a single unique ownership, which means the
  object can be owned by only one `unique_ptr` at a time. This makes it efficient
  and lightweight.
- **std::shared_ptr**: Maintains reference counting, making it heavier than
  `unique_ptr`. Use it only when multiple ownership is genuinely required.
- **std::weak_ptr**: Doesn't own the object, so it doesn't affect the reference
  count of a shared object. It's mainly used to break circular references among
  `shared_ptr`s.
- **std::auto_ptr**: Deprecated and should not be used in new code. It was the
  first attempt to provide automatic memory management, but had semantic issues
  especially during copy and assignment.

When possible, prefer using the `std::make_unique` and `std::make_shared` helper functions to create smart pointers, as they are safer and can provide better performance due to optimizations.

## More Details

In C++, there are three types of smart pointers:

1. **std::unique_ptr**: This represents exclusive ownership of an object. A
   `unique_ptr` cannot be copied, which means there can be at most one
   `unique_ptr` pointing to an object at a time. When the `unique_ptr` is
   destroyed, the object it points to is automatically destroyed as well. This is
   useful when you want to ensure that an object is deleted when it is no longer
   needed.

   Example:

   ```cpp
   std::unique_ptr<int> ptr(new int(5)); // create a unique_ptr
   // Or
   auto ptr = std::make_unique<int>(5); // create a unique_ptr using std::make_unique (preferred way)
   ```

2. **std::shared_ptr**: This represents shared ownership of an object. Multiple
   `shared_ptr` instances can point to the same object, and the object will
   only be destroyed when the last `shared_ptr` pointing to it is destroyed. This
   is useful when you want to share an object between multiple parts of your
   program.

   Example:

   ```cpp
   std::shared_ptr<int> ptr1(new int(5)); // create a shared_ptr
   std::shared_ptr<int> ptr2 = ptr1; // both ptr1 and ptr2 now point to the same object
   // Or
   auto ptr = std::make_shared<int>(5); // create a shared_ptr using std::make_shared (preferred way)
   ```

3. **std::weak_ptr**: This is a weak reference to an object that is owned by a
   `shared_ptr`. A `weak_ptr` doesn't contribute to the reference count of a
   `shared_ptr`. This means it doesn't prevent the object from being destroyed.
   You can use it to break cycles in data structures that could cause memory leaks
   with `shared_ptr`.

   Example:

   ```cpp
   std::shared_ptr<int> ptr(new int(5)); // create a shared_ptr
   std::weak_ptr<int> weakPtr = ptr; // create a weak_ptr from a shared_ptr
   // The object ptr points to is still destroyed when ptr is destroyed, despite weakPtr still existing
   ```

These smart pointers are a part of the C++ Standard Library and can help manage
resources, reduce memory leaks, and improve code readability and safety. It's
generally recommended to use smart pointers over raw pointers when you can.
