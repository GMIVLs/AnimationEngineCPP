# Operators in depth

## The operator (::)

The `::` symbol in C++ is known as the "scope resolution operator". Here's a table outlining its usages:

| **Usage**                         | **Description**                                                                        | **Example**                                                                                             | **Best Practice**                                                                                                                                 |
| --------------------------------- | -------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Global Namespace**              | Accesses a global variable/function, typically when a local variable hides it.         | `int x = 10; void func() { int x = 5; ::x = 20; }`                                                      | Only use when necessary to differentiate between global and local variables. Avoid having too many global variables in the first place.           |
| **Class Static Members**          | Accesses static members of a class.                                                    | `class MyClass { static int x; }; int MyClass::x = 10;`                                                 | Always initialize static members (especially if they have non-trivial types). It's usually done in a source (`.cpp`) file.                        |
| **Outside Class Definition**      | Defines a member function outside the class definition.                                | `class MyClass { void func(); }; void MyClass::func() { }`                                              | Keep the implementation and declaration separate. Implement member functions outside the class in the source files.                               |
| **Nested Class or Enum**          | Accesses a nested class or enum inside another class.                                  | `class Outer { class Inner { }; }; Outer::Inner obj;`                                                   | Use nested classes and enums only when the inner type has strong dependencies with the enclosing class and doesn't make sense in a broader scope. |
| **Unambiguous Base Class Member** | Specifies which base class's member to use in case of multiple inheritance.            | `struct A { void func(); }; struct B { void func(); }; struct C : A, B { void func() { A::func(); } };` | Use sparingly. Multiple inheritance can be tricky. Prefer composition or interfaces (pure virtual classes) when possible.                         |
| **Global Namespace Specifier**    | Accesses the global namespace. Useful when working with libraries having common names. | `namespace lib { void func() { } } void func() { lib::func(); }`                                        | When using libraries, prefer using namespace qualifiers to prevent clashes and ambiguities. Avoid `using namespace` in header files.              |
| **Template Resolution**           | Forces the compiler to treat the name as a template.                                   | `template<class T> void func(T) { } template<> void func<>(int) { }`                                    | Use when you want to provide explicit specializations for templates. Be sure to test thoroughly, as template code can have complex interactions.  |
| **Name Qualification**            | Specifies a particular namespace or class to which an identifier belongs.              | `namespace NS { int x; } int x = NS::x;`                                                                | Use namespaces to organize code and avoid name clashes. Always qualify names when it's unclear or ambiguous which version you're referring to.    |

- The `::` operator is fundamental in C++ to define and access specific parts
  of code within their defined scopes. Using it effectively helps manage the
  complexities of C++'s rich feature set and avoids ambiguities in the code.
  Always aim for clarity when using the scope resolution operator.

## Binary Operators

Here's a continuation of the table, now including all of C++'s binary operators:

| **Operator** | **Usage** | **Description**                                                                                                | **Example**                              | **Command/Effect**                                                 |
| ------------ | --------- | -------------------------------------------------------------------------------------------------------------- | ---------------------------------------- | ------------------------------------------------------------------ | --------------- | ------------------ | ---------------------------------- |
| `<<`         | `x << n`  | **Left Shift**: Shifts the bits of `x` to the left by `n` positions. Rightmost `n` bits are filled with zeros. | `int x = 5; int result = x << 2; // 20`  | `0101` shifted left by 2 positions becomes `10100`                 |
| `>>`         | `x >> n`  | **Right Shift**: Shifts bits of `x` to the right by `n` positions. Behavior depends on sign of `x` and type.   | `int x = 20; int result = x >> 2; // 5`  | `10100` shifted right by 2 positions becomes `0101`                |
| `&`          | `x & y`   | **Bitwise AND**: Performs a bitwise AND operation on the operands.                                             | `int result = 5 & 3; // result is 1`     | `0101` AND `0011` results in `0001`                                |
| `            | `         | `x                                                                                                             | y`                                       | **Bitwise OR**: Performs a bitwise OR operation on the operands.   | `int result = 5 | 3; // result is 7` | `0101` OR `0011` results in `0111` |
| `^`          | `x ^ y`   | **Bitwise XOR**: Performs a bitwise exclusive OR operation on the operands.                                    | `int result = 5 ^ 3; // result is 6`     | `0101` XOR `0011` results in `0110`                                |
| `~`          | `~x`      | **Bitwise NOT**: Flips all the bits of the operand.                                                            | `int result = ~5; // platform-dependent` | Flips each bit of `0101`, result might be `1010` for an 8-bit int. |
| `+`          | `x + y`   | **Addition**: Adds two numbers.                                                                                | `int result = 5 + 3; // result is 8`     | Adds 5 and 3, results in 8                                         |
| `-`          | `x - y`   | **Subtraction**: Subtracts second operand from the first.                                                      | `int result = 5 - 3; // result is 2`     | Subtracts 3 from 5, results in 2                                   |
| `*`          | `x * y`   | **Multiplication**: Multiplies two numbers.                                                                    | `int result = 5 * 3; // result is 15`    | Multiplies 5 by 3, results in 15                                   |
| `/`          | `x / y`   | **Division**: Divides the first operand by the second.                                                         | `int result = 5 / 3; // result is 1`     | Divides 5 by 3, results in 1 (integer division)                    |
| `%`          | `x % y`   | **Modulo**: Returns the remainder of the division of the first operand by the second.                          | `int result = 5 % 3; // result is 2`     | Divides 5 by 3, remainder is 2                                     |

**Notes**:

1. **Division by Zero**: Both the `/` and `%` operators will cause undefined
   behavior if the second operand is zero.
2. **Bitwise Operations**: The bitwise operations (`&`, `|`, `^`, `~`, `<<`,
   `>>`) operate on the individual bits of their operands.
3. **Signedness**: The behavior of the shift operators and the `~` operator can
   vary depending on whether the operands are signed or unsigned. Always be
   cautious and understand the context in which you're using them.
4. **Operator Overloading**: C++ allows user-defined types (e.g., classes) to
   provide custom implementations for these operators. This means they can
   perform different operations when used with objects of those types.

## Usage of Modulo operators \%

- The modulo operator `%` in C++ is primarily used to calculate the remainder
  of integer division. However, it has a wide variety of applications due to this
  basic functionality. Here's a table illustrating some common use cases:

| **Usage**                           | **Example**                                                   | **Description**                                                                                                                                                             |
| ----------------------------------- | ------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Basic Remainder Calculation         | `int result = 11 % 3; // result is 2`                         | Directly computes the remainder of 11 divided by 3. The result is `2` because 11 divided by 3 gives a quotient of `3` with a remainder of `2`.                              |
| Looping/Cycling over Array Elements | `int arr[5]; int i = 7; int pos = i % 5; // pos is 2`         | If you need to access elements in a cyclic manner, the modulo operator can be used. Here, accessing the 7th element of a 5-element array actually accesses the 2nd element. |
| Datetime (Hours)                    | `int hours = 26; int dayHours = hours % 24; // dayHours is 2` | For time representation, if you exceed 24 hours, the modulo can be used to determine the hour of the next day. Here, 26 hours is equivalent to 2 hours into the next day.   |
| Datetime (Minutes, Seconds)         | `int mins = 130; int hourMins = mins % 60; // hourMins is 10` | Similarly, for minutes or seconds, exceeding 60 can be wrapped using modulo. Here, 130 minutes is 2 hours and 10 minutes.                                                   |
| Checking for Even/Odd Numbers       | `bool isEven = (num % 2 == 0);`                               | The modulo operator can determine if a number is even or odd. If a number modulo 2 is `0`, it's even; otherwise, it's odd.                                                  |
| Ensuring Values within a Range      | `int val = -3; int positiveVal = (val + N) % N;`              | If you want to ensure a number stays within a specific range (0 to N-1), modulo can be helpful, especially when dealing with negative numbers.                              |

**Notes**:

1. **Be Cautious with Negative Numbers**: The behavior of the modulo operator
   with negative operands can differ between programming languages. In C++, `-3
% 5` will yield `-3`, not `2`. If you want a "positive" result, you might need
   to adjust the operand or the result as shown in the last usage example.
2. **Non-Integer Types**: In C++, the modulo operator is defined only for
   integral types. It's not directly applicable to floating-point types,
   although libraries or custom logic can be used to achieve similar effects.
3. **Zero Division**: Just like with division, using the modulo operator with a
   denominator of `0` will result in undefined behavior in C++. Always ensure
   your denominator is non-zero.
