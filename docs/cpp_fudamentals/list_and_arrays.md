# Lists and Array in CPP

<!-- vim-markdown-toc Marked -->

* [Intro - methods for creating arrays](#intro---methods-for-creating-arrays)
* [How to loop over a list-array-vector](#how-to-loop-over-a-list-array-vector)
* [C++ Standard Library for Several Containers](#c++-standard-library-for-several-containers)
* [How to create an array in C++](#how-to-create-an-array-in-c++)

<!-- vim-markdown-toc -->

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
