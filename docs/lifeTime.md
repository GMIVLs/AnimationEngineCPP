# LifeTime in CPP



## Concept


## Example

- Assume we have the following
```cpp
char* testing_string(){
  const char* ptr = {"Hello my Name is Michael"};
  return ptr;
}

```
- Once we compile, we will get an error message says
```sh
Cannot initialize return object of type `char *`  with an lvalue of type `const char*`
```
- The issues with this code are:
    - Returning a Pointer to a String Literal: While string literals have
    static storage duration (they exist for the lifetime of the program), the
    main issue here is that you're returning a char* (non-const pointer) to a
    const char* (pointer to const data). This can potentially lead to undefined
    behavior if someone tries to modify the content via the returned pointer.
    - Mismatched Return Type: The function is declared to return char* but you're
    returning a const char*. This breaks the const-correctness principle, and
    you're basically allowing potential modification of immutable data.
- To fix it:
    - Correct the Return Type: Since string literals are immutable, you should
    return a pointer that reflects that immutability:

```cpp
const char* testing_string() {
    return "Hello my Name is Michael";
}
```
By doing this, you're indicating that the string returned by the function should not be modified.
