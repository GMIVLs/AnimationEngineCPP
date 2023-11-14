# Moving Semantics

Move semantics, introduced in C++11, is a way to transfer resources from one
object to another without the overhead of deep copying. The main mechanism
behind move semantics is the rvalue reference (`T&&`). Here's a table
explaining its various usages and related concepts:

| **Concept**                  | **Description**                                                                                       | **Small Example**                                                                | **Common Usages**                                                                 |
| ---------------------------- | ----------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------- | --------------------------------------------------------------------------------- |
| **Move Constructor**         | Constructs an object by acquiring the resources of another object rather than copying them.           | `cpp class MyClass { public: MyClass(MyClass&& other) {...} }; `                 | Creating a new object by transferring resources from a temporary.                 |
| **Move Assignment Operator** | Assigns resources from one object to another by moving instead of copying.                            | `cpp class MyClass { public: MyClass& operator=(MyClass&& other) {...} }; `      | Transferring resources between existing objects.                                  |
| `std::move()`                | Casts an object to an rvalue reference, enabling move semantics.                                      | `cpp MyClass obj1; MyClass obj2 = std::move(obj1); `                             | Explicitly signaling that an object's resources can be transferred.               |
| **Rvalue Reference**         | A type of reference that can bind to temporary objects.                                               | `cpp void foo(MyClass&& obj) {...} `                                             | Function overloading based on whether an argument is a temporary.                 |
| `std::forward<T>()`          | Perfect forwarding utility to pass an argument as either lvalue or rvalue based on its original type. | `cpp template<typename T> void wrapper(T&& arg) { foo(std::forward<T>(arg)); } ` | Forwarding arguments in template functions without changing their value category. |

**Notes**:

1. **Destructive Transfer**: When performing a move operation, it's common
   practice to leave the moved-from object in a valid but unspecified state.
For example, if you're moving from a dynamic array, you might set the source
object's pointer to `nullptr` after the move.
2. **Move vs. Copy**: If an object supports both move and copy semantics, move
   operations are preferred when working with rvalues (like temporaries), while
copy operations are used with lvalues.
3. **Perfect Forwarding**: Perfect forwarding with `std::forward<T>()` allows a
   function template to forward an argument to another function while retaining
the argument's original lvalue/rvalue nature.
4. **Automatic Move**: In many cases, the compiler can automatically use move
   semantics to eliminate unnecessary deep copies, especially with return
values or when throwing exceptions.

Using move semantics can significantly improve performance, especially for
objects that manage heavy resources, like dynamic memory, file handles, or
network sockets.

