# Memeory Leaking in C++

When dealing with dynamic memory allocation in C++, it's crucial to follow best
practices to avoid memory leaks and undefined behavior. Here are some key
guidelines for safely managing and deleting heap-allocated memory, along with
handling associated pointers:

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Memeory Leaking in C++](#memeory-leaking-in-c)
    - [-](#-)
    - [2. Set Pointers to `nullptr` After Deletion](#2-set-pointers-to-nullptr-after-deletion)
    - [3. Use Smart Pointers](#3-use-smart-pointers)
    - [4. Avoid Owning Raw Pointers in Multiple Places](#4-avoid-owning-raw-pointers-in-multiple-places)
    - [5. Check for `nullptr` Before Deleting](#5-check-for-nullptr-before-deleting)
    - [6. Use RAII (Resource Acquisition Is Initialization)](#6-use-raii-resource-acquisition-is-initialization)
    - [7. Avoid Unnecessary Heap Allocation](#7-avoid-unnecessary-heap-allocation)
    - [8. Be Cautious with Exceptions](#8-be-cautious-with-exceptions)
    - [9. Implement Copy Constructors and Assignment Operators Carefully](#9-implement-copy-constructors-and-assignment-operators-carefully)
    - [10. Use Containers for Dynamic Arrays](#10-use-containers-for-dynamic-arrays)
    - [Problem I faced](#problem-i-faced)
        - [QUESTION-1](#question-1)
        - [ANSWER](#answer)
        - [QUESTION-2](#question-2)
        - [ANSWER-2](#answer-2)
        - [Question-3](#question-3)
        - [ANSWWER-3](#answwer-3)

<!-- markdown-toc end -->


### 1. Match `new` with `delete` and `new[]` with `delete[]`

Always ensure that for every `new` there is a corresponding `delete`, and for
every `new[]` (array allocation), there is a corresponding `delete[]`.

```cpp
int* ptr = new int(10);  // Single object
delete ptr;

int* arr = new int[10];  // Array
delete[] arr;
```

### 2. Set Pointers to `nullptr` After Deletion

After deleting a pointer, set it to `nullptr`. This helps to avoid dangling
pointers and makes it safe to check if the pointer has been deleted.

```cpp
delete ptr;
ptr = nullptr;

delete[] arr;
arr = nullptr;
```

### 3. Use Smart Pointers

Whenever possible, use smart pointers (`std::unique_ptr`, `std::shared_ptr`)
instead of raw pointers. They automatically manage memory, which helps prevent
leaks.

```cpp
#include <memory>

std::unique_ptr<int> ptr = std::make_unique<int>(10);
// No need to manually delete, it's handled automatically
```

### 4. Avoid Owning Raw Pointers in Multiple Places

Don't have multiple raw pointers owning the same resource. If you need shared
ownership, use `std::shared_ptr`. For single ownership, `std::unique_ptr` is
appropriate.

### 5. Check for `nullptr` Before Deleting

If there's any possibility that your pointer could be `nullptr`, check before
deleting. However, note that deleting a `nullptr` is safe and has no effect.

```cpp
if (ptr != nullptr) {
    delete ptr;
    ptr = nullptr;
}
```

### 6. Use RAII (Resource Acquisition Is Initialization)

This principle suggests that resources should be tied to object lifetime. When
an object is destroyed, its destructor should release all resources it owns.
Smart pointers are an implementation of this principle.

### 7. Avoid Unnecessary Heap Allocation

If an object can be allocated on the stack, prefer stack allocation as it's
automatically managed and less error-prone.

### 8. Be Cautious with Exceptions

If your code can throw exceptions, make sure that memory is still correctly
deleted. Smart pointers can be particularly helpful in these cases because they
ensure deletion even if an exception is thrown.

### 9. Implement Copy Constructors and Assignment Operators Carefully

If your class manages a resource, follow the Rule of Three/Five and properly
implement copy constructors, copy assignment operators, and destructors.

### 10. Use Containers for Dynamic Arrays

Instead of using raw arrays (`new[]` / `delete[]`), prefer using standard
library containers like `std::vector` or `std::array`, which handle memory
management for you.

By following these practices, you can significantly reduce the risk of memory
leaks and make your C++ code safer and more robust.

## Problem I faced

### QUESTION-1

- Do I need to free the memory using delete in this case?

```cpp
void with_pointer_1() {
    const int MAX_AGE = 90;
    int* a = new int;  // allocate on the heap the pointer
    *a = 2;
    LOG(INFO) << BLUE << "Dereferencing *a as -> " << RED << *a << RESET;
    a = (int*)&MAX_AGE;  // const int is different from int, thats why you need to cast it back to
                         // similar type (int)
    LOG(INFO) << BLUE << "Memeory Address (pointer) of a is -> " << RED << a << RESET;
}
```

### ANSWER

In the function `with_pointer_1()`, you have a memory leak issue due to not
using `delete` to free the memory allocated with `new`.

Let's break down what's happening in your function:

1. `int* a = new int;` - Here, memory is allocated on the heap for an integer,
   and `a` points to this memory.
2. `*a = 2;` - You store the value `2` in the allocated memory.
3. `a = (int*)&MAX_AGE;` - This line is problematic for two reasons:

   - First, it changes the pointer `a` to point to the address of `MAX_AGE`,
     which is a constant. After this line, you lose the reference to the heap
     memory you allocated with `new`. This results in a memory leak because you
     have no way to `delete` the allocated memory now.
   - Second, casting a `const int` to `int` and modifying it is undefined
     behavior in C++. Even though you are not modifying `MAX_AGE` directly here,
     this kind of casting is generally unsafe and should be avoided.

Because you lose the original reference to the allocated memory, you cannot free
it anymore. To correct this and avoid the memory leak, you should add a `delete`
statement before reassigning `a`, like this:

```cpp
void with_pointer_1() {
    const int MAX_AGE = 90;
    int* a = new int;  // allocate on the heap
    *a = 2;
    LOG(INFO) << BLUE << "Dereferencing *a as -> " << RED << *a << RESET;

    delete a;  // free the allocated memory

    a = (int*)&MAX_AGE;  // reassign a to point to MAX_AGE
    LOG(INFO) << BLUE << "Memory Address (pointer) of a is -> " << RED << a << RESET;
}
```

In the corrected version, the memory allocated on the heap is properly released
with `delete` before reassigning `a` to the address of `MAX_AGE`. It's important
to ensure that every `new` is paired with a `delete` to prevent memory leaks in
your applications.

### QUESTION-2

- Why not putting delete a; in the end of this function ?

### ANSWER-2

Placing `delete a;` at the end of the function `with_pointer_1()` would not
correctly deallocate the memory you allocated with `new`. Here's why:

When you do `a = (int*)&MAX_AGE;`, you change the pointer `a` to point to the
address of `MAX_AGE`, which is a constant integer. By doing this, you lose the
original address that `a` was pointing to (the address of the memory you
allocated with `new`). Without the original address, you cannot free that
allocated memory anymore.

If you then call `delete a;` at the end of the function, you are actually trying
to delete the memory at the address of `MAX_AGE`, not the memory you allocated.
This can lead to undefined behavior since `MAX_AGE` is not dynamically allocated
memory. It's important to only use `delete` on pointers that point to memory
allocated by `new`.

To correctly manage memory in your function, you should `delete` the allocated
memory before reassigning the pointer `a` to a different address:

```cpp
void with_pointer_1() {
    const int MAX_AGE = 90;
    int* a = new int;  // Allocate memory on the heap
    *a = 2;

    // Use the allocated memory...

    delete a;  // Free the allocated memory

    a = (int*)&MAX_AGE;  // Reassign a to point to MAX_AGE

    // Rest of the function...
}
```

This ensures that the memory allocated with `new` is properly freed before you
lose its reference, thus avoiding a memory leak. Remember, it's crucial to
always pair each `new` with a corresponding `delete` at the appropriate place in
your code.

### Question-3

- When you delete the a, what will happen to a itself? I mean is it become a
  null-pointer so that you assigned later without a declaration to
  (int\*)&MAX_AGE?

### ANSWWER-3

When you use `delete` on a pointer in C++, it deallocates the memory that the
pointer was pointing to, but it does not change the value of the pointer itself.
After calling `delete a;`, the pointer `a` still holds the address of the freed
memory, but that memory is no longer valid for use. `a` becomes a "dangling
pointer" at this point.

Here's what happens step-by-step:

1. **Memory Allocation**: `int* a = new int;` allocates memory on the heap, and
   `a` stores the address of this allocated memory.
2. **Using the Memory**: You can use `a` to access and modify this memory.
3. **Deallocating Memory**: `delete a;` deallocates the memory `a` was pointing
   to. The memory is returned to the system, but `a` still holds the same
   address. The content of this memory is now indeterminate, and the program
   should not dereference `a` anymore.
4. **Dangling Pointer**: After deletion, `a` becomes a dangling pointer. It
   points to a memory location that has been deallocated and potentially could
   be used for new allocations by the system.
5. **Reassigning the Pointer**: `a = (int*)&MAX_AGE;` makes `a` point to the
   address of `MAX_AGE`. Now `a` is no longer a dangling pointer, but it points
   to the address of a constant integer.

To make it safer and clearer, it's often recommended to set a pointer to
`nullptr` after deleting the memory it points to. This explicitly marks the
pointer as no longer pointing to valid memory:

```cpp
delete a;
a = nullptr;  // a is now a null-pointer
```

Then, when you reassign `a`, you're assigning a new valid address to it:

```cpp
a = (int*)&MAX_AGE;  // Reassign a to point to MAX_AGE
```

This practice helps prevent accidental usage of dangling pointers and makes your
intentions in the code clearer. However, in your specific example, since `a` is
immediately reassigned to a new address after the `delete` statement, setting it
to `nullptr` is not strictly necessary, but it's still good practice in general.
