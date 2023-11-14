# Lvalue and Rvalue

- In C++, lvalues and rvalues are fundamental concepts that pertain to the
  "value category" of expressions. Here's a table outlining the main distinctions
  and their related concepts:

| **Concept** | **Usage**                | **Description**                                                                                                                                            | **Types**             | **Example**                               |
| ----------- | ------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------- | ----------------------------------------- |
| **lvalue**  | Storage location         | Represents an object that occupies a memory location and can appear on the left or right side of an assignment.                                            | Variables, Arrays     | `int x = 10; x = 20;` (x is an lvalue)    |
|             | Addressable              | Its address can be taken using the `&` operator.                                                                                                           |                       | `int* p = &x;`                            |
|             | Modifiable               | Can be modified if it's not declared as `const`.                                                                                                           |                       |                                           |
| **rvalue**  | Temporary Value          | Represents a temporary object that doesn't have a stable storage location. Typically appears on the right side of an assignment but cannot be assigned to. | Literals, Temporaries | `int y = x + 10;` (`x + 10` is an rvalue) |
|             | Not addressable directly | Cannot directly take the address of an rvalue because it doesn't have a stable memory location.                                                            |                       | `int* q = &(x + 10); // Error`            |
| **xvalue**  | "eXpiring" value         | Represents an object about to be moved from or destroyed. Sits between lvalues and rvalues and can be bound to rvalue references.                          | Moved-from objects    | `std::move(x)`                            |
| **glvalue** | Generalized lvalue       | Category that encompasses both lvalues and xvalues.                                                                                                        | lvalues, xvalues      |                                           |
| **prvalue** | Pure rvalue              | Rvalues that aren't xvalues. They are typically temporary objects that don't have identity and can't be moved-from.                                        | Temporaries, Literals | `x + 10`                                  |

**Notes**:

1. **Rvalue References**: C++11 introduced rvalue references (`T&&`) which can
   bind to rvalues. They play a key role in move semantics and perfect
forwarding.
2. **Move Semantics**: Allows resources owned by an rvalue to be moved into an
   lvalue without making a copy. Useful for transferring resources from
temporary objects.
3. **lvalue References**: These are the traditional references (`T&`) which
   bind to lvalues. They can also bind to rvalues if they're `const`, e.g.,
`const T&`.
4. **Categories Expansion**: The concepts of lvalues and rvalues were expanded
   in C++11 with the introduction of xvalues, glvalues, and prvalues to provide
a more detailed classification of expressions, especially to support move
semantics and rvalue references.

- When programming in C++, understanding these concepts is crucial for resource
management, especially when dealing with operations like copy and move
semantics, reference binding, and overloading based on value categories.

