# Passing args to methods and functions

<!-- vim-markdown-toc GitLab -->

* [Content](#content)
* [Request](#request)
* [Examples](#examples)
* [Example](#example)
* [Passing of an array of arrays of int 32 using pointers and using references](#passing-of-an-array-of-arrays-of-int-32-using-pointers-and-using-references)

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

## Request

An example in CPP of passing by value and passing by reference and passing by
pointer for function and check about the passed variable before and after if u
change its state inside the function Lets use simple function to double the
value of the passed variable Sure, let's start with a variable `x` and we'll
pass it to different functions that attempt to double its value using
pass-by-value, pass-by-reference, and pass-by-pointer. We'll print the value of
`x` before and after calling each function to see the effect.

Here is the C++ code:

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

When you run this program, you will see that `x` is not changed by
`doubleValue` (pass-by-value), because it's working on a copy of `x`. However,
`x` is indeed doubled by `doubleRef` (pass-by-reference) and `doublePtr`
(pass-by-pointer), because they're working on the original `x` itself.

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

## Example

Sure, let's define a function `doubleValue` that doubles a value.

First, let's look at how to pass a variable by pointer:

```cpp
void doubleValue(int* p) {
    *p *= 2;
}

int main() {
    int x = 5;
    doubleValue(&x);
    // Now, x is 10
    return 0;
}
```

- In this example, we are passing the address of the variable `x` to the
  function. The function then accesses the value at this address using the
  dereference operator `*` and doubles it.

Now, let's look at how to pass a variable by reference:

```cpp
void doubleValue(int& ref) {
    ref *= 2;
}

int main() {
    int x = 5;
    doubleValue(x);
    // Now, x is 10
    return 0;
}
```

- In this case, we're passing `x` directly to the function. Inside the function,
  `ref` behaves as if it was `x` itself, so when we modify `ref`, we are actually
  modifying `x`. The main difference is that when passing by pointer, you need to
  handle the address of a variable (which involves using the address-of operator
  `&` and the dereference operator `*`). When passing by reference, you can work
  with the variable as if it was passed by value, but any changes you make to the
  parameter will affect the original variable. It's often considered more
  idiomatic in C++ to pass by reference when you can.

## Passing of an array of arrays of int 32 using pointers and using references

In C++, arrays decay to pointers when passed to a function. Therefore, you
can't pass a multi-dimensional array (an array of arrays) to a function by
reference directly as you might expect.

Let's say you have a 2D array with fixed size, you can pass it to a function by
reference like this:

```cpp
void processArray(int (&arr)[3][3]) {
    // Do something with arr
}

int main() {
    int array[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    processArray(array);
    return 0;
}
```

In this example, `processArray` takes a reference to a 2D array of ints. The
size of the array dimensions (3x3) is part of the function's parameter type.
However, passing multi-dimensional arrays to functions can become complicated
because the size of all but the first dimension must be known at compile-time.
You could also pass it by pointer like this:

```cpp
void processArray(int* arr[3]) {
    // Do something with arr
}

int main() {
    int* array[3];
    int arr1[3] = {1, 2, 3};
    int arr2[3] = {4, 5, 6};
    int arr3[3] = {7, 8, 9};

    array[0] = arr1;
    array[1] = arr2;
    array[2] = arr3;

    processArray(array);
    return 0;
}
```

In this example, `processArray` takes a pointer to an array of int pointers. In
many situations, it might be more practical to use a container class like
`std::array` or `std::vector`, as they can be passed to functions by reference
more easily and provide other benefits like bounds-checking and dynamic
resizing (for `std::vector`).
