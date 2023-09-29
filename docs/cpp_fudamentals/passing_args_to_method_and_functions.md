# Passing args to methods and functions

<!-- vim-markdown-toc GitLab -->

* [Content](#content)
* [Examples](#examples)

<!-- vim-markdown-toc -->

## Content

- Here's a table illustrating the different ways to pass arguments in C++:

| **Method**             | **Description**                                                         | **Example**                                       |
| ---------------------- | ----------------------------------------------------------------------- | ------------------------------------------------- |
| **By Value**           | Passes a copy of the value. Original value remains unchanged.           | `void func(int a) {...}` and `func(val);`         |
| **By Reference**       | Passes the actual variable itself. Changes in function reflect outside. | `void func(int &a) {...}` and `func(val);`        |
| **By Pointer**         | Passes the address of the variable. Can be used to modify the original. | `void func(int *a) {...}` and `func(&val);`       |
| **By Const Reference** | Passes the variable by reference but prevents modification.             | `void func(const int &a) {...}` and `func(val);`  |
| **By Const Pointer**   | Passes the address but prevents modification via the pointer.           | `void func(const int *a) {...}` and `func(&val);` |

- **By Value**: The function gets a copy of the argument. Changes to the
  argument inside the function don't affect the original value.
- **By Reference**: The function gets the actual variable, so changes to the
  argument inside the function will affect the original value.
- **By Pointer**: Similar to passing by reference, but requires de-referencing
  the pointer to access the value. Provides more flexibility (like passing NULL
  pointers) but can be trickier to use correctly.
- **By Const Reference**: Provides the efficiency of passing by reference
  (especially for large objects) without allowing the function to modify the
  value.
- **By Const Pointer**: Pass the address but prevents you from modifying the
  value through the pointer. Useful when you want to indicate that the value
  shouldn't be changed but still need pointer-like behavior.

## Examples

```cpp

#include<iostream>
using namespace std;

// Function that tries to double the value using pass-by-value
void doubleValue(int x) {
    x *= 2;
}

// Function that doubles the value using pass-by-reference
void doubleRef(int &x) {
    x *= 2;
}

// Function that doubles the value using pass-by-pointer
void doublePtr(int *x) {
    *x *= 2;
}

int main() {
    int x = 5;

    cout << "Initial value of x: " << x << endl;

    doubleValue(x);
    cout << "After doubleValue, x: " << x << endl;

    doubleRef(x);
    cout << "After doubleRef, x: " << x << endl;

    x = 5;  // reset x
    doublePtr(&x);
    cout << "After doublePtr, x: " << x << endl;

    return 0;
}
```
