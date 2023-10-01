# OOP in CPP - Details

## Content

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->

**Table of Contents**

- [OOP in CPP - Details](#oop-in-cpp---details)
  - [Content](#content)
    - [Method to create an object from a class](#method-to-create-an-object-from-a-class)
    - [Common Code Practice](#common-code-practice)
  - [Demo](#demo)
  - [Components and keywords Primer](#components-and-keywords-primer)
  - [Typical Class with all possible keywords](#typical-class-with-all-possible-keywords)

<!-- markdown-toc end -->

### Method to create an object from a class

- Creating objects from a defined class in C++ can be done in various ways.
  Here's a table listing some of the common ways to create an object, including
  those involving the `explicit` keyword:

| **Method**                               | **Description**                                               | **Example**                                                                       |
| ---------------------------------------- | ------------------------------------------------------------- | --------------------------------------------------------------------------------- |
| **Stack Allocation**                     | Objects are created on the stack.                             | `ClassName obj;`                                                                  |
| **Heap Allocation**                      | Objects are created on the heap using `new`.                  | `ClassName* obj = new ClassName();`                                               |
| **With Arguments (Constructor)**         | Using a parameterized constructor.                            | `ClassName obj(arg1, arg2);`                                                      |
| **Copy Constructor**                     | Create an object as a copy of another object.                 | `ClassName obj2(obj1);`                                                           |
| **Move Constructor**                     | Transfers ownership of resources from one object to another.  | `ClassName obj2(std::move(obj1));`                                                |
| **Uniform Initialization (since C++11)** | Using curly braces for initialization.                        | `ClassName obj{};` or `ClassName obj{arg1, arg2};`                                |
| **Initializer List (since C++11)**       | Initialize with an initializer list (if supported).           | `std::vector<int> vec = {1, 2, 3};`                                               |
| **Copy Assignment**                      | Assigning the value of one object to another.                 | `obj2 = obj1;`                                                                    |
| **Move Assignment**                      | Transfer resources from one object to another via assignment. | `obj2 = std::move(obj1);`                                                         |
| **Explicit Constructor**                 | Constructor that can't be used for implicit conversions.      | `explicit ClassName(int a);` and `ClassName obj(5);` but NOT `ClassName obj = 5;` |

- When using the `explicit` keyword with constructors, it prevents the compiler
  from using that constructor for implicit conversions. This is useful to avoid
  unintended or surprising type conversions.

### Methods for creating class in CPP

- Classes are fundamental in C++, allowing for the creation of user-defined data
  types. Here's an overview of various ways to define and utilize classes,
  including commonly associated keywords:

| **Method**                          | **Description**                                                                                         | **Example**                                                                                           |
| ----------------------------------- | ------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------- |
| **Basic Class**                     | The simplest way to define a class.                                                                     | `class MyClass { public: int x; };`                                                                   |
| **Private Members**                 | By default, members are private in a class. Useful for encapsulation.                                   | `class MyClass { int x; public: int getX() { return x; } };`                                          |
| **Public Members**                  | Accessible from outside the class.                                                                      | `class MyClass { public: int x; };`                                                                   |
| **Protected Members**               | Accessible by subclasses and the class itself, but not outside.                                         | `class MyClass { protected: int x; };`                                                                |
| **Constructors**                    | Special methods to initialize the object.                                                               | `class MyClass { public: MyClass() { x = 0; } int x; };`                                              |
| **Destructors**                     | Special methods called when the object is destroyed.                                                    | `class MyClass { public: ~MyClass() { /* cleanup code */ } };`                                        |
| **Static Members**                  | Members shared by all instances of the class.                                                           | `class MyClass { public: static int x; }; int MyClass::x = 0;`                                        |
| **Const Members**                   | Methods that do not modify any member variables.                                                        | `class MyClass { public: int getValue() const { return x; } int x; };`                                |
| **Friend Functions**                | Functions that can access private and protected members of the class.                                   | `class MyClass { friend void friendFunction(MyClass &obj); private: int x; };`                        |
| **Nested Classes**                  | A class defined inside another class.                                                                   | `class Outer { class Inner { int y; }; };`                                                            |
| **Inheritance**                     | Allows a class to inherit members from another class.                                                   | `class Base { }; class Derived : public Base { };`                                                    |
| **Virtual Functions**               | Functions meant to be overridden in derived classes. Enables polymorphism.                              | `class Base { public: virtual void func(); }; class Derived : public Base { void func() override; };` |
| **Pure Virtual & Abstract Classes** | If a class contains at least one pure virtual function, it becomes abstract and cannot be instantiated. | `class AbstractBase { public: virtual void func() = 0; };`                                            |
| **Final Keyword**                   | Prevents a class from being derived from or a virtual function from being overridden.                   | `class FinalClass final { }; class Base { virtual void func() final; };`                              |
| **Explicit Constructors**           | Prevents unwanted implicit conversions.                                                                 | `class MyClass { public: explicit MyClass(int a); };`                                                 |

**Notes**:

- **Encapsulation**: One of the key features of classes, allowing data (attributes) and functions (methods) to be bundled together. Using private and protected members helps in achieving this.
- **Polymorphism**: Through the use of virtual functions, C++ enables dynamic polymorphism where the correct function related to the derived class object is called even when accessed using a base class pointer/reference.
- **Inheritance**: Allows for creating a new class that is based on an existing class. The new class inherits attributes and behavior (methods) from the existing class.
- **Friend Functions**: Though it breaks the encapsulation principle, it's sometimes useful for operator overloading or certain specific scenarios where an external function needs to access the private members.
- **Explicit Constructors**: Useful to avoid accidental type conversions that might lead to bugs.

When designing classes in C++, always aim for strong encapsulation, clear interfaces, and prefer composition over inheritance when extending functionalities.

### Common Code Practice

- When you create a class you must provide a `consturctor` and `destructor`, but why?
  - Its important when you create an object on stack, the destructor will not
    be called, but if you want create your object on the `heap`, then you must
    free its memeory.

## Demo

- The following code shows that allocation on the heap should be always
  accompanied by a `destructor` which will free the object in memeory once it
  goes out of the scope.

```cpp
class Entity {
public:
  std::string object_name;
  Entity(std::string object_name) : object_name(object_name) {

    std::cout << "Created Entity:" << object_name << std::endl;
  }
  // This destructor is called once we go out of the scope
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

## Components and keywords Premier

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

## How to allow the constructor to accept assignment for x and y and if not then they will be zero?

You can modify the constructor of the `Vector2D` class to accept default
arguments which would be `0` in case the user doesn't provide any. Here's how
to do it:

```cpp
template <class T>
class Vector2D {
public:
    T x, y;
    Vector2D(T x = T(), T y = T()) : x(x), y(y) {}  // Constructor with default arguments

    // remaining class methods...
};
```

Now you can create `Vector2D` objects in several ways:

```cpp
Vector2D<float> vec1;  // x and y are 0.0f
Vector2D<float> vec2(1.2f);  // x is 1.2f, y is 0.0f
Vector2D<float> vec3(1.2f, 3.4f);  // x is 1.2f, y is 3.4f
```

In the code above, `T()` is used to provide a default value for the type `T`.
For numeric types like `int`, `float`, `double` etc., `T()` gives `0` or `0.0f`
etc. It gives an empty string for `std::string`, and so on. It's essentially
the same as default-constructing an instance of the type `T`.

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

## Static variable with class

```cpp
#include <iostream>
#include <string>

class Employee {
private:
    std::string name;
    int id;
    static int count;  // Static variable to count the number of Employee objects

public:
    // Constructor
    Employee(const std::string& empName, int empId) : name(empName), id(empId) {
        count++;
    }

    // Destructor
    ~Employee() {
        count--;
    }

    // Method to display employee information
    void displayInfo() const {
        std::cout << "Employee ID: " << id << std::endl;
        std::cout << "Employee Name: " << name << std::endl;
    }

    // Static method to display the number of Employee objects
    static void displayCount() {
        std::cout << "Total employees: " << count << std::endl;
    }
};

int Employee::count = 0;  // Initialize the static variable

int main() {
    Employee e1("Alice", 101);
    Employee e2("Bob", 102);

    e1.displayInfo();
    e2.displayInfo();

    Employee::displayCount();  // Display total number of Employee objects

    return 0;
}
```
