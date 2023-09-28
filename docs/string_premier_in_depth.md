# String premier in CPP - In depth

## Content

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->

**Table of Contents**

- [String premier in CPP - In depth](#string-premier-in-cpp---in-depth)
  - [Content](#content)
  - [Types of string - Commonly used](#types-of-string---commonly-used)

<!-- markdown-toc end -->

## Types of string - Commonly used

Extended table for `string` in `C++`.

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

- **Size Specified**: This column indicates whether you must specify the size
  of the array/list at compile-time or not. For data structures where the size
  isn't specified at compile-time, it often means the size can be dynamically
  adjusted at runtime.
- **Memory Management**: As previously mentioned, always ensure to release any
  heap-allocated memory to prevent memory leaks.
- **Safety**: Using modern C++ containers is recommended for most use-cases due
  to their safety, flexibility, and the functionalities they provide.

![String in CPP](./images/M01.jpg)

## More details

- I'll add a few more scenarios related to string handling in C++:

| **Type**                               | **Description**                                             | **Define**                                           | **Read**                                    | **Write**                                 | **Allocation**             | **Null-Terminated**        | **Common Practices**                                           |
| -------------------------------------- | ----------------------------------------------------------- | ---------------------------------------------------- | ------------------------------------------- | ----------------------------------------- | -------------------------- | -------------------------- | -------------------------------------------------------------- |
| **String Literal**                     | A sequence of characters surrounded by double quotes.       | `const char* str = "Hello";`                         | `cout << str;`                              | N/A (immutable)                           | Stack                      | Yes                        | Fixed messages, filenames, etc.                                |
| **C-style String (char array)**        | Array of characters ending with a null terminator (`'\0'`). | `char str[6] = "Hello";`                             | `cout << str;`                              | `str[0] = 'h';`                           | Stack                      | Yes                        | Older C++ code; Prefer `std::string` in modern C++.            |
| **`std::string`**                      | Dynamic string class in C++ standard library.               | `std::string str = "Hello";`                         | `cout << str;` or `str.c_str()` for C-style | `str[0] = 'h'; str += " World";`          | Heap (usually)             | N/A                        | Modern C++: safe and dynamic string handling.                  |
| **Pointer to C-style String**          | Points to the first character of a C-style string.          | `const char* ptr = "Hello";`                         | `cout << ptr;`                              | Not directly (points to a string literal) | Stack                      | Yes (if points to literal) | Be cautious with memory management.                            |
| **Array of C-style Strings**           | Array with elements as pointers to C-style strings.         | `const char* arr[] = {"Hello", "World"};`            | `cout << arr[0];`                           | Not directly (contains string literals)   | Stack                      | Yes                        | Older C++: be cautious with memory management.                 |
| **`std::vector<std::string>`**         | Dynamic array of `std::string` objects.                     | `std::vector<std::string> vec = {"Hello", "World"};` | `cout << vec[0];`                           | `vec[0] = "HELLO"; vec.push_back("!");`   | Heap                       | N/A                        | Dynamic list of strings in modern C++.                         |
| **Array of Characters**                | Sequence of characters without null termination.            | `char arr[] = {'a', 'b'};`                           | Using loops (not directly with `cout`)      | `arr[0] = 'A';`                           | Stack                      | No                         | Rare, since without null-termination it's not a proper string. |
| **Dynamic Array of Characters (heap)** | Dynamically allocated array of characters.                  | `char* arr = new char[3]{'a', 'b', '\0'};`           | `cout << arr;`                              | `arr[0] = 'A';`                           | Heap                       | Depends on Initialization  | Requires `delete[]` for deallocation.                          |
| **String View (`std::string_view`)**   | Non-owning reference to a string or a part of a string.     | `std::string_view sv = "Hello";`                     | `cout << sv;`                               | N/A (non-modifiable)                      | Depends on referred string | Depends on referred string | Used for efficient substring operations, available in C++17.   |

**Additional Notes**:

- **`std::string_view`**: This is a lightweight, non-owning reference to a string. It doesn't allocate or deallocate memory, and it's useful when you want to work with substrings without copying. Always ensure that the underlying data outlives the `string_view` to avoid dangling references.

This table should now provide a comprehensive overview of the different ways you can represent and work with strings in C++.
