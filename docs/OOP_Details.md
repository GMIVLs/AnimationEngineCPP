# OOP in CPP - Details

## Content
<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [OOP in CPP - Details](#oop-in-cpp---details)
    - [Content](#content)
        - [Common Code Practice](#common-code-practice)
    - [Demo](#demo)
    - [Components and keywords Primer](#components-and-keywords-primer)
    - [Typical Class with all possible keywords](#typical-class-with-all-possible-keywords)

<!-- markdown-toc end -->


### Common Code Practice

- When you create a class you must provide a `consturctor` and `destructor`, but why?
  - Its important when you create an object on stack, the destructor will not
    be called, but if you want create your object on the `heap`, then you must
    free its memeory.

## Demo

```cpp
class Entity {
public:
  std::string object_name;
  Entity(std::string object_name) : object_name(object_name) {

    std::cout << "Created Entity:" << object_name << std::endl;
  }
  ~Entity() { std::cout << "Destroyed Entity:" << object_name << std::endl; }
};

int main(int argc, char *argv[]) {

  {
    // create enitity object on the stack
    Entity e1("e1"); // create entity object on the heap
    Entity *e2 = new Entity("e2"); // You can also use Entity* e2 = new Entity(std::string("e2"));
  }

  std::cin.get();


```

## Components and keywords Primer

Here's a relatively contrived class that showcases a variety of C++ keywords
commonly used in class definitions: Now, let's create a table explaining the
various keywords used:

| **Keyword** | **Description**                                                                         | **Common Code Practices & Usages**                                                                         |
| ----------- | --------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------- |
| `class`     | Declares a class type.                                                                  | Class names typically start with an uppercase letter.                                                      |
| `private`   | Access modifier; members declared `private` cannot be accessed outside of the class.    | Default access level for class members; used to encapsulate and protect data.                              |
| `public`    | Access modifier; members declared `public` can be accessed from any function.           | Used for member functions and data members that need to be accessed outside the class.                     |
| `explicit`  | Specifies that a constructor or conversion function doesn't allow implicit conversions. | Prevents unintended type conversions, especially useful for constructors that take one argument.           |
| `friend`    | Gives a function or another class access to private and protected members of the class. | Used sparingly; when necessary, allows external functions/classes to interact with private/protected data. |
| `noexcept`  | Specifies that a function doesn't throw exceptions.                                     | Provides a guarantee about exception safety, useful for move constructors/assignment operators.            |
| `operator=` | Overloads the assignment operator.                                                      | Enables custom behavior when assigning objects.                                                            |

- **Note:** The above class and table only cover a subset of C++ keywords
  related to class definitions. There are many other C++ keywords and
  class-related features not shown here.

## Typical Class with all possible keywords

```cpp
#include <iostream>

class MyClass;

class AnotherClass {
public:
    // Friend function
    friend void AccessPrivateDataOfMyClass(const MyClass& obj);
};

class MyClass {
private:
    int privateData;

public:
    // Constructor with default argument
    MyClass(int data = 0) : privateData(data) { }

    // Copy constructor
    MyClass(const MyClass& other) : privateData(other.privateData) { }

    // Move constructor
    MyClass(MyClass&& other) noexcept : privateData(other.privateData) {
        other.privateData = 0;
    }

    // Explicit constructor
    explicit MyClass(double data) : privateData(static_cast<int>(data)) { }

    // Destructor
    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
    }

    // Copy assignment operator
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            privateData = other.privateData;
        }
        return *this;
    }

    // Move assignment operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            privateData = other.privateData;
            other.privateData = 0;
        }
        return *this;
    }

    // Friend function (declared in AnotherClass)
    friend void AnotherClass::AccessPrivateDataOfMyClass(const MyClass& obj);
};

void AnotherClass::AccessPrivateDataOfMyClass(const MyClass& obj) {
    std::cout << "Private data: " << obj.privateData << std::endl;
}

int main() {
    MyClass obj1;
    MyClass obj2(10);
    MyClass obj3 = obj2;
    MyClass obj4(std::move(obj3));
    MyClass obj5(3.5);  // This will call the explicit constructor
    AnotherClass::AccessPrivateDataOfMyClass(obj2);
    return 0;
}

```
