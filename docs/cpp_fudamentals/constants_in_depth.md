# Constants usages and meaning

<!-- vim-markdown-toc GitLab -->

* [Examples](#examples)

<!-- vim-markdown-toc -->

The `const` keyword in C++ is versatile and can be used in various scenarios.
Here's a table detailing its common usages:

| **Usage**                        | **Description**                                                                                                  | **Example**                                           | **Common Practice**                                                              |
| -------------------------------- | ---------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------- | -------------------------------------------------------------------------------- |
| **Basic Constant**               | Declares a variable as constant. Its value can't be modified after initialization.                               | `const int MAX_SIZE = 100;`                           | Use when you want to make sure a variable remains unchanged.                     |
| **Pointer to Constant**          | The data pointed to can't be changed, but the pointer can point elsewhere.                                       | `const int* ptr = &someVar;`                          | Useful when passing data to a function and you want to ensure it's not modified. |
| **Constant Pointer**             | The pointer can't be changed to point elsewhere, but the data it points to can be changed.                       | `int* const ptr = &someVar;`                          | Used when you want a pointer to always point to a specific memory location.      |
| **Constant Pointer to Constant** | Neither the pointer can be changed to point elsewhere nor the data it points to can be modified.                 | `const int* const ptr = &someVar;`                    | Guarantees both data and pointer address remain constant.                        |
| **Member Function as const**     | Declares that the member function won't modify any member variables of the class (except ones marked `mutable`). | `int getValue() const { return value; }`              | Declare member functions as `const` when they don't modify class state.          |
| **Member Variable as const**     | Declares a class member variable that can't be modified after construction.                                      | `class Example { const int id; ... };`                | Can be used for values that shouldn't change after object creation, like ID.     |
| **const in Function Parameters** | Pass parameters as `const` to ensure they are not modified within the function.                                  | `void func(const int& val);`                          | Ensures function doesn't modify the passed data, useful with references.         |
| **const Return Type**            | Return a constant value, so the caller can't modify it directly (common with operator overloads).                | `const int MyClass::func() { return 42; }`            | Prevents misuse, like directly modifying a returned value from a function.       |
| **const with Iterators**         | Makes the iterator behave as a read-only iterator. Data it points to can't be modified.                          | `std::vector<int>::const_iterator itr = vec.begin();` | Useful when iterating through a container without modifying its elements.        |

**Key Takeaways**:

1. **Read `const` with Pointers Right-to-Left**: For example, `const int* ptr` reads as "ptr is a pointer to an int that is constant".
2. **Member Functions**: Use `const` for member functions to indicate they won't change the state of the object.
3. **Method Arguments**: When passing by reference, use `const` if you don't intend to modify the argument to prevent accidental modifications.
4. **Iterators**: Using `const` iterators is a good way to ensure that you don't inadvertently modify container elements.

Applying the `const` keyword properly in C++ can lead to safer and more readable code.

## Examples

When you use `const` before a variable declaration in C++, it means that you
can't modify the variable's value after it's set. In the case of `const char*`,
you're saying that the characters being pointed to cannot be modified, but the
pointer itself can be.

In your example:

```cpp
const char *my_string = "This is as close to a string primitive as you can get";
```

- `my_string` is a pointer to a constant character (or an array of characters
  in this case, which is a string literal). This means that you can't use
  `my_string` to modify the characters it points to:

```cpp
my_string[0] = 't'; // This is an error.
```

- However, you can change what `my_string` points to:

```cpp
my_string = "This is another string";
```

Now, `my_string` points to a different string literal.

- If you want to make sure that the pointer itself can't be changed either,
  you'd put the `const` after the `*`:

```cpp
char const * my_string = "This is as close to a string primitive as you can get";
```

- Now, you can't change the characters that `my_string` points to, and you
  can't change what `my_string` points to.
- It's worth noting that string literals are stored in read-only memory in C++,
  so attempting to modify them (without the `const` keyword) is undefined
  behavior, meaning it may work on some compilers and crash on others. It's good
  practice to always use `const` with string literals to avoid this undefined
  behavior.
