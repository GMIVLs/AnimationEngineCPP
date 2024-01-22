# Lists and Array in CPP
<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Lists and Array in CPP](#lists-and-array-in-cpp)
    - [Intro - methods for creating arrays](#intro---methods-for-creating-arrays)
    - [How to loop over a list-array-vector](#how-to-loop-over-a-list-array-vector)
    - [C++ Standard Library for Several Containers](#c-standard-library-for-several-containers)
    - [How to create an array in C++](#how-to-create-an-array-in-c)
    - [what is {} for element storing is it a set or array or what](#what-is--for-element-storing-is-it-a-set-or-array-or-what)
    - [Declare an array](#declare-an-array)
    - [More in depth](#more-in-depth)
        - [Key Points](#key-points)
        - [Q1: For std::vector should I add the keyword “new” or it will managed automatically? Can you give me the common coding practice?](#q1-for-stdvector-should-i-add-the-keyword-new-or-it-will-managed-automatically-can-you-give-me-the-common-coding-practice)
        - [Example Usage of `std::vector`](#example-usage-of-stdvector)
        - [Key Points:](#key-points)
    - [Table for Similar memory managed containers](#table-for-similar-memory-managed-containers)
        - [Key Points:](#key-points-1)

<!-- markdown-toc end -->


## Intro - methods for creating arrays

- Arrays and lists can be created in various ways in C++, both in traditional C-style and in modern C++ style. Here's a table summarizing those:

| **Type**                  | **Storage Location** | **Description**                                   | **Example**                                      |
| ------------------------- | -------------------- | ------------------------------------------------- | ------------------------------------------------ |
| **C-style Static Array**  | Stack                | Fixed-size array declared at compile time.        | `int arr[5] = {1, 2, 3, 4, 5};`                  |
| **C-style Dynamic Array** | Heap                 | Array whose size is determined at runtime.        | `int* arr = new int[5]; ... delete[] arr;`       |
| **C++ std::array**        | Stack                | Fixed-size array with size known at compile time. | `std::array<int, 5> arr = {1, 2, 3, 4, 5};`      |
| **C++ std::vector**       | Heap (usually)       | Dynamic array that can grow/shrink at runtime.    | `std::vector<int> vec = {1, 2, 3, 4, 5};`        |
| **C++ std::list**         | Heap (usually)       | Doubly-linked list.                               | `std::list<int> lst = {1, 2, 3, 4, 5};`          |
| **C++ std::forward_list** | Heap (usually)       | Singly-linked list.                               | `std::forward_list<int> flst = {1, 2, 3, 4, 5};` |

**Notes**:

1. **C-style Static Array**: It's a basic fixed-size array defined on the
   stack. You need to know its size at compile time. The array will be
   destroyed automatically when it goes out of scope.
2. **C-style Dynamic Array**: Uses pointers. You determine the size at runtime
   and must manually manage memory using `new` and `delete`.
3. **C++ std::array**: A container that encapsulates fixed-size arrays. Offers
   benefits over C-style static arrays like bounds checking with the `at()`
   function.
4. **C++ std::vector**: Dynamic array. Its size can change at runtime. It's one
   of the most used containers in C++ because of its flexibility and ease of
   use.
5. **C++ std::list**: Doubly-linked list. Useful when you frequently need to
   insert or delete elements in the middle.
6. **C++ std::forward_list**: Singly-linked list. Uses less memory than
   `std::list` but you can't access elements backwards.

For the C++ style containers (`std::array`, `std::vector`, `std::list`,
`std::forward_list`), you will need to include the respective headers
(`<array>`, `<vector>`, `<list>`, `<forward_list>`) to use them.

## How to loop over a list-array-vector

- Iterating over various types of containers in C++ can be achieved through different methods. Here's a table detailing how to loop over elements in several standard C++ containers, along with descriptions, examples, and the versions of C++ in which they are supported:

| **Container**          | **Method**        | **Description**                                                | **Example**                                                                                                   | **C++ Version**                               |
| ---------------------- | ----------------- | -------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------- | --------------------------------------------- |
| **Array**              | Range-based `for` | Directly iterate over elements of a fixed-size array.          | `int arr[5] = {1, 2, 3, 4, 5}; for(int i : arr) { cout << i << ' '; }`                                        | C++11 onwards                                 |
| **C-Style Array**      | Traditional `for` | Use an index-based loop for a pointer or C-style array.        | `int arr[] = {1, 2, 3}; for(int i=0; i<3; ++i) { cout << arr[i] << ' '; }`                                    | All versions                                  |
| **std::vector**        | Range-based `for` | Directly iterate over elements of a vector.                    | `vector<int> v = {1, 2, 3}; for(int i : v) { cout << i << ' '; }`                                             | C++11 onwards                                 |
| **std::vector**        | `iterator`        | Use iterators provided by vector for traversal.                | `for(auto it = v.begin(); it != v.end(); ++it) { cout << *it << ' '; }`                                       | All versions                                  |
| **std::list**          | Range-based `for` | Directly iterate over elements of a list.                      | `list<int> l = {1, 2, 3}; for(int i : l) { cout << i << ' '; }`                                               | C++11 onwards                                 |
| **std::list**          | `iterator`        | Use iterators provided by list for traversal.                  | `for(auto it = l.begin(); it != l.end(); ++it) { cout << *it << ' '; }`                                       | All versions                                  |
| **std::map**           | Range-based `for` | Directly iterate over key-value pairs in a map.                | `map<int, string> m = {{1,"a"}, {2,"b"}}; for(auto& [k,v] : m) { cout << k << ':' << v << ' '; }`             | C++11 for loop, C++17 for structured bindings |
| **std::map**           | `iterator`        | Use iterators to traverse key-value pairs in a map.            | `for(auto it = m.begin(); it != m.end(); ++it) { cout << it->first << ':' << it->second << ' '; }`            | All versions                                  |
| **std::unordered_map** | Range-based `for` | Directly iterate over key-value pairs in an unordered map.     | `unordered_map<int, string> um = {{1,"a"}, {2,"b"}}; for(auto& [k,v] : um) { cout << k << ':' << v << ' '; }` | C++11 for loop, C++17 for structured bindings |
| **std::unordered_map** | `iterator`        | Use iterators to traverse key-value pairs in an unordered map. | `for(auto it = um.begin(); it != um.end(); ++it) { cout << it->first << ':' << it->second << ' '; }`          | All versions                                  |

**Notes**:

1. **Range-based for loops**: Introduced in C++11, they allow for a more
   concise way of iterating over containers.
2. **Structured Bindings**: Introduced in C++17, they allow you to unpack the
   key-value pairs in maps directly in the range-based for loop.
3. **Iterators**: Are the traditional way of looping over elements in most of
   the STL containers.

Always remember to include the appropriate headers for the containers you're
using (`<array>`, `<vector>`, `<list>`, `<map>`, `<unordered_map>`, etc.).

## C++ Standard Library for Several Containers

The C++ Standard Library (`std` namespace) provides a variety of container
classes, each designed for different use-cases. Here's a simplified overview of
some commonly used container types, presented in table form:

| **Data Structure**               | **Description**                                                               | **Memory Profile**                                                        | **Example Usage**                                |
| -------------------------------- | ----------------------------------------------------------------------------- | ------------------------------------------------------------------------- | ------------------------------------------------ |
| `std::array<T, N>`               | Fixed-size array. Stores `N` elements of type `T`.                            | Contiguous memory, no overhead.                                           | `std::array<int, 3> arr = {1, 2, 3};`            |
| `std::pair<T1, T2>`              | Stores exactly two values.                                                    | Contiguous memory for the two elements.                                   | `std::pair<int, char> p(1, 'a');`                |
| `std::list<T>`                   | Doubly-linked list.                                                           | Each node contains an element of type `T` and two pointers (prev & next). | `std::list<int> lst = {1, 2, 3};`                |
| `std::vector<T>`                 | Dynamic array.                                                                | Pointer to dynamic memory, size, and capacity.                            | `std::vector<int> vec = {1, 2, 3};`              |
| `std::map<Key, Value>`           | Balanced binary tree (often a red-black tree).                                | Nodes containing key-value pairs, pointers to children.                   | `std::map<char, int> m; m['a'] = 1;`             |
| `std::unordered_map<Key, Value>` | Hash table.                                                                   | Buckets with lists/chains for collision resolution.                       | `std::unordered_map<char, int> um; um['a'] = 1;` |
| `std::set<Key>`                  | Like `std::map`, but only keys.                                               | Nodes containing keys, pointers to children.                              | `std::set<int> s = {1, 2, 3};`                   |
| `std::unordered_set<Key>`        | Like `std::unordered_map`, but only keys.                                     | Buckets with lists/chains for collision resolution.                       | `std::unordered_set<int> us = {1, 2, 3};`        |
| `std::deque<T>`                  | Double-ended queue.                                                           | Can grow/shrink from both ends; often uses blocks of memory.              | `std::deque<int> dq = {1, 2, 3};`                |
| `std::stack<T>`                  | LIFO data structure. Uses another container underneath (e.g., vector, deque). | Depends on the underlying container.                                      | `std::stack<int> st; st.push(1);`                |
| `std::queue<T>`                  | FIFO data structure. Uses another container underneath (e.g., list, deque).   | Depends on the underlying container.                                      | `std::queue<int> q; q.push(1);`                  |
| `std::priority_queue<T>`         | Heap-based priority queue. Uses a vector by default.                          | Depends on the underlying container, often a dynamic array.               | `std::priority_queue<int> pq; pq.push(1);`       |

- Note: The memory profiles provided are very high-level. The exact memory
  layout can differ based on system, compiler, and standard library version. The
  representations above are simplifications meant to convey the conceptual
  differences.

## How to create an array in C++

Creating arrays or lists in C++ can be done in multiple ways, each having its
own set of advantages and trade-offs. Here's an exhaustive table of possible
methods:

| **Type/Method**          | **Description**                          | **Memory**   | **Mutable** | **R/W** | **Size Specified** | **Example**                                                  | **Usage & Common Practices**                                       |
| ------------------------ | ---------------------------------------- | ------------ | ----------- | ------- | ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------------ |
| C-style array            | Fixed-size, contiguous block of memory.  | Stack        | Yes         | R/W     | Yes (`[N]`)        | `int arr[3] = {1, 2, 3};`                                    | Prefer `std::array` or `std::vector` for safety and flexibility.   |
| Dynamic C-style array    | Dynamically-allocated array.             | Heap         | Yes         | R/W     | No (`[]`)          | `int* arr = new int[3]; arr[0] = 1;`                         | Use with caution; must manually manage memory with `delete[]`.     |
| `std::array<T, N>`       | Fixed-size, stack-allocated.             | Stack        | Yes         | R/W     | Yes (`<T, N>`)     | `std::array<int, 3> arr = {1, 2, 3};`                        | Preferred over C-style array for fixed-size lists.                 |
| `std::vector<T>`         | Dynamic array with auto-resizing.        | Heap & Stack | Yes         | R/W     | No (at creation)   | `std::vector<int> vec = {1, 2, 3};`                          | Most common dynamic list in C++; handles memory management.        |
| `std::list<T>`           | Doubly-linked list.                      | Heap         | Yes         | R/W     | No (at creation)   | `std::list<int> lst = {1, 2, 3};`                            | Use when frequent insertions/deletions are required in the middle. |
| Pointer to C-style array | Points to the first element of an array. | Depends      | Depends     | R/W     | Depends            | `int nums[3] = {1, 2, 3}; int* p = nums;`                    | Raw pointers can be error-prone; prefer modern alternatives.       |
| Array of pointers        | Array where each element is a pointer.   | Stack        | Yes         | R/W     | Yes (`[N]`)        | `int* arr[3]; for(int i=0; i<3; i++) arr[i] = new int(i+1);` | Use when needing an array of objects on the heap.                  |

**Notes:**

- **Heap & Stack for `std::vector`**: The `std::vector` object metadata (like
  size, capacity) resides on the stack, while the actual data is stored on the
  heap.
- **Mutable**: All the array types/lists mentioned in C++ are mutable by
  default. However, their mutability can be restricted using the `const`
  qualifier.
- **R/W**: All the array types/lists mentioned are readable and writable.
- **Memory Management**: Always ensure to release any heap-allocated memory to
  avoid memory leaks. For C-style dynamic arrays, use `delete[]` and for
  individual heap allocations use `delete`.
- **Safety**: Using modern C++ containers like `std::vector` or `std::array` is
  recommended for most use-cases due to their safety, flexibility, and the added
  functionalities they provide.
- **Size Specified**: This column indicates whether you must specify the size
  of the array/list at compile-time or not. For data structures where the size
  isn't specified at compile-time, it often means the size can be dynamically
  adjusted at runtime.
- **Memory Management**: As previously mentioned, always ensure to release any
  heap-allocated memory to prevent memory leaks.
- **Safety**: Using modern C++ containers is recommended for most use-cases due
  to their safety, flexibility, and the functionalities they provide.

## what is {} for element storing is it a set or array or what

In C++, `{}` is known as the list initialization (or uniform initialization)
syntax. It was introduced in C++11 to initialize objects.

- When you see something like this:

```cpp
int arr[] = {1, 2, 3};
```

`{1, 2, 3}` is an initializer list which is being used to initialize the array `arr`.

Similarly, when you see:

```cpp
std::vector<int> vec = {1, 2, 3};
```

`{1, 2, 3}` is an initializer list which is being used to initialize the vector `vec`.

So, `{}` is not a data type, but a way to initialize objects of various types
such as arrays, vectors, sets, etc. The actual type of the data being stored
depends on the type of the object being initialized.

In the case of:

```cpp
std::vector<std::vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

Here, `{1, 2, 3}`, `{4, 5, 6}`, and `{7, 8, 9}` are initializer lists being
used to initialize the inner vectors, and the outer `{...}` is an initializer
list to initialize the outer vector. This results in a 2D vector, which you can
think of as a matrix.

## Declare an array

C++ provides various ways to declare a list (or a sequence) of elements. Here
are some common ones:

1. **C-style Array**: An array is a simple, fixed-size list that contains
   elements of the same type.

   ```cpp
   int arr[3] = {1, 2, 3};  // Array of 3 integers
   ```

2. **std::array**: It's a container in the Standard Library that encapsulates
   fixed size arrays. It's more efficient and safer than C-style arrays.

   ```cpp
   std::array<int, 3> arr = {1, 2, 3};  // Array of 3 integers
   ```

3. **std::vector**: It's a dynamic array, it can grow and shrink at runtime.

   ```cpp
   std::vector<int> vec = {1, 2, 3};  // Vector of integers
   ```

4. **std::list**: It's a doubly-linked list that allows fast insertions and
   deletions at both its beginning and its end.

   ```cpp
   std::list<int> lst = {1, 2, 3};  // List of integers
   ```

5. **std::forward_list**: It's a singly-linked list, and unlike std::list,
   allows for fast insertions and deletions at its beginning only.

   ```cpp
   std::forward_list<int> fwd_lst = {1, 2, 3};  // Forward list of integers
   ```

6. **std::deque**: A double-ended queue that allows fast insertions and
   deletions at both its beginning and its end.

   ```cpp
   std::deque<int> dq = {1, 2, 3};  // Deque of integers
   ```

7. **std::initializer_list**: It's a lightweight array-like container used for
   list-initialization of objects.

   ```cpp
   std::initializer_list<int> init_list = {1, 2, 3};  // Initializer list of integers
   ```

8. **std::set or std::multiset**: They're associative containers that contain
   sorted sets of unique and non-unique elements, respectively.

   ```cpp
   std::set<int> set = {1, 2, 3};  // Set of unique integers
   std::multiset<int> mset = {1, 1, 2, 2, 3, 3};  // Multiset of integers
   ```

9. **std::unordered_set or std::unordered_multiset**: They're associative
   containers that contain unsorted sets of unique and non-unique elements,
   respectively.

   ```cpp
   std::unordered_set<int> uset = {1, 2, 3};  // Unordered set of unique integers
   std::unordered_multiset<int> umset = {1, 1, 2, 2, 3, 3};  // Unordered multiset of integers
   ```

Each of these methods has its use cases, advantages, and drawbacks. Which one you choose depends on the requirements of your specific application.

## More in depth

Constructing arrays or lists in C++ can be done in various ways, each
with different implications for memory allocation and management. Below is a
table illustrating different methods of constructing arrays and lists, including
stack and heap allocations, using built-in arrays, pointers, dynamic arrays, and
C++ Standard Library containers like `std::vector` and `std::array`.

| Method                         | Declaration Example                                                            | Storage Location | Description                                                                                                                                                    |
| ------------------------------ | ------------------------------------------------------------------------------ | ---------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Static Array                   | `int arr[5] = {1, 2, 3, 4, 5};`                                                | Stack            | Fixed-size array. Size must be known at compile-time.                                                                                                          |
| Dynamic Array (C-Style)        | `int* arr = new int[5];`                                                       | Heap             | Dynamically allocated array. Size can be determined at runtime. Requires manual memory management with `new[]` and `delete[]`.                                 |
| std::vector                    | `std::vector<int> vec = {1, 2, 3, 4, 5};`                                      | Heap             | Dynamic size array, part of the C++ Standard Library. Automatically manages memory.                                                                            |
| std::array                     | `std::array<int, 5> arr = {1, 2, 3, 4, 5};`                                    | Stack            | Fixed-size array, part of the C++ Standard Library. Offers benefits of standard containers (like iterators). Size must be known at compile-time.               |
| Array via Pointer              | `int* arr = new int[5]{1, 2, 3, 4, 5};`                                        | Heap             | Pointer to a dynamically allocated array. Allows for runtime determination of size. Requires manual memory management.                                         |
| C-Style String (as char array) | `char arr[] = "Hello";`                                                        | Stack            | Character array initialized with a string literal.                                                                                                             |
| std::initializer_list          | `std::initializer_list<int> il = {1, 2, 3, 4, 5};`                             | Stack            | Allows creation of an array-like object with a fixed set of values. Often used in function parameter passing.                                                  |
| std::list                      | `std::list<int> lst = {1, 2, 3, 4, 5};`                                        | Heap             | Part of the C++ Standard Library, representing a doubly-linked list. Offers efficient insertions and deletions at any position.                                |
| Multidimensional Array         | `int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};`                                      | Stack            | A static multidimensional array. Fixed sizes for each dimension must be known at compile-time.                                                                 |
| Dynamic Multidimensional Array | `int** arr = new int*[2];` for rows, then for each row: `arr[i] = new int[3];` | Heap             | A dynamically allocated multidimensional array. Allows different sizes for each row and runtime size determination. Requires complex manual memory management. |

### Key Points

- **Static vs Dynamic**: Static arrays (`int arr[5];`) are allocated on the
  stack, have fixed size, and are automatically managed. Dynamic arrays (`new int[5];`) are allocated on the heap, can have variable size, but require
  manual memory management.
- **Standard Library Containers**: Containers like `std::vector` and `std::list`
  handle memory management automatically and provide additional functionality
  over built-in arrays.
- **Use Cases**: The choice between these methods depends on the specific
  requirements of your application, such as the need for dynamic resizing
  (`std::vector`), fixed size (`std::array`, static array), or specific data
  structure behavior (like `std::list` for linked lists).
- **Memory Management**: Always be mindful of memory management, especially with
  dynamic allocation to avoid memory leaks and other related issues.

### Q1: For std::vector should I add the keyword “new” or it will managed automatically? Can you give me the common coding practice?

When using `std::vector` in C++, you do not need to use the `new` keyword. The
memory management for `std::vector` is handled automatically. `std::vector`
internally manages a dynamically allocated array to store its elements and
automatically handles resizing and reallocation as needed.

Here's the common coding practice for using `std::vector`:

### Example Usage of `std::vector`

```cpp
#include <vector>
#include <iostream>

int main() {
    // Declare and initialize a vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    // Add an element to the end
    vec.push_back(6);
    // Access elements
    std::cout << "First element: " << vec[0] << std::endl;
    // Iterate over the vector
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

### Key Points:

1. **No `new` Required**: The `std::vector` object is declared like a regular
   variable. Its constructor handles the allocation of its internal array.
2. **Automatic Memory Management**: `std::vector` automatically manages the
   memory of its internal array. It deallocates the memory when the vector goes
   out of scope or is explicitly destroyed.
3. **Dynamic Resizing**: `std::vector` automatically resizes itself as elements
   are added or removed. Methods like `push_back()` and `erase()` are used for
   these operations.
4. **Random Access**: Elements in a `std::vector` can be accessed directly using
   the subscript operator `[]`.
5. **Iteration**: You can iterate over the elements of a `std::vector` using a
   range-based for loop or iterators.
6. **Custom Types**: `std::vector` can store objects of any type, including
   user-defined types.

- Using `std::vector` is recommended over plain arrays or dynamic arrays in most
  cases because of its flexibility and the fact that it eliminates many of the
  common errors associated with manual memory management.

## Table for Similar memory managed containers

Make a table for data containers like vector which will be managed automatically
without a need for dellocate and no require to use “new” when creating them.
Certainly! Here's a table summarizing various data containers in C++ that are
managed automatically, where you don't need to deal with manual memory
allocation or deallocation, and there's no requirement to use `new` when
creating instances of these containers.


| Container         | Description                                                                                            | Declaration Example                            | Key Characteristics                                                     |
|-------------------|--------------------------------------------------------------------------------------------------------|------------------------------------------------|-------------------------------------------------------------------------|
| `std::vector`     | Dynamic array that can resize itself as needed.                                                        | `std::vector<int> vec = {1, 2, 3, 4, 5};`      | Random access, dynamic resizing, contiguous storage.                   |
| `std::list`       | Doubly-linked list allowing efficient insertion and removal from anywhere in the list.                  | `std::list<int> lst = {1, 2, 3, 4, 5};`        | Efficient insertions and deletions, non-contiguous storage.            |
| `std::deque`      | Double-ended queue allowing insertion and removal at both ends.                                        | `std::deque<int> dq = {1, 2, 3, 4, 5};`        | Random access, efficient insertions/removals at both ends.             |
| `std::array`      | Fixed-size array, wrapper around plain array with added standard container functionality.              | `std::array<int, 5> arr = {1, 2, 3, 4, 5};`    | Fixed size, stack allocated, random access.                            |
| `std::forward_list` | Singly-linked list allowing efficient insertion and removal from the front.                          | `std::forward_list<int> fl = {1, 2, 3, 4, 5};` | Efficient insertions and deletions at the front, non-contiguous storage.|
| `std::set`        | Collection of unique elements, automatically ordered.                                                  | `std::set<int> st = {5, 3, 1, 4, 2};`          | Unique elements, ordered, efficient lookup and insertion.              |
| `std::map`        | Collection of key-value pairs, automatically ordered by keys, keys are unique.                         | `std::map<int, std::string> mp;`               | Unique keys, ordered by keys, direct element access via keys.          |
| `std::unordered_set` | Collection of unique elements, hashed into unordered buckets.                                        | `std::unordered_set<int> us = {5, 3, 1, 4, 2};` | Unique elements, unordered, efficient in terms of average speed.       |
| `std::unordered_map` | Collection of key-value pairs, hashed into unordered buckets, keys are unique.                       | `std::unordered_map<int, std::string> um;`     | Unique keys, unordered, direct element access via keys, fast average speed. |
| `std::stack`      | Adapts a container to provide stack (LIFO) operations.                                                  | `std::stack<int> stk;`                         | Provides stack operations, can adapt various container types.          |
| `std::queue`      | Adapts a container to provide queue (FIFO) operations.                                                  | `std::queue<int> que;`                         | Provides queue operations, can adapt various container types.          |
| `std::priority_queue` | Adapts a container to provide priority queue operations, with elements sorted by priority.          | `std::priority_queue<int> pq;`                 | Elements sorted by priority, efficient access to largest element.      |

### Key Points:

- **Automatic Memory Management**: All these containers handle memory allocation
  and deallocation automatically.
- **No `new` Required**: Instances of these containers can be declared like
  regular variables.
- **Versatility and Safety**: These containers offer a safe and versatile way to
  handle collections of elements, each suited for specific needs (like
  `std::list` for frequent insertions/deletions, `std::vector` for random
  access, etc.).
- **Standard Library Integration**: Being part of the C++ Standard Library,
  these containers integrate well with other standard features and algorithms.
