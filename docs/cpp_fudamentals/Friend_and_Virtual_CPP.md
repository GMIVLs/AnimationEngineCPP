# _What is Friend declaration_

The friend declaration appears in a class body and grants a function or another class access to private and protected members of the class where the friend declaration appears.

___Syntax___

> friend function-declaration	(1)	
> friend function-definition	(2)	
> friend elaborated-class-specifier ;	(3)	
> friend simple-type-specifier ; (4)	(since C++11)
> friend typename-specifier ; (5)

### _Description_

- Designates a function or several functions as friends of this class:
```c++
class Y
{
    int data; // private member
 
    // the non-member function operator<< will have access to Y's private members
    friend std::ostream& operator<<(std::ostream& out, const Y& o);
    friend char* X::foo(int); // members of other classes can be friends too
    friend X::X(char), X::~X(); // constructors and destructors can be friends
};
 
// friend declaration does not declare a member function
// this operator<< still needs to be defined, as a non-member
std::ostream& operator<<(std::ostream& out, const Y& y)
{
    return out << y.data; // can access private member Y::data
}
```
- (only allowed in non-local class definitions) Defines a non-member function, and makes it a friend of this class at the same time. Such non-member function is always inline, unless it is attached to a named module (since C++20).

```c++
class X
{
    int a;
 
    friend void friend_set(X& p, int i)
    {
        p.a = i; // this is a non-member function
    }
public:
    void member_set(int i)
    {
        a = i; // this is a member function
    }
};
```

- Designates the class, struct, or union named by the elaborated-class-specifier (see elaborated type specifier) as a friend of this class. This means that the friend's member declarations and definitions can access private and protected members of this class and also that the friend can inherit from private and protected members of this class. The name of the class that is used in this friend declaration does not need to be previously declared.

- Designates the type named by the simple-type-specifier or typename-specifier as a friend of this class if that type is a (possibly cv-qualified) class, struct, or union; otherwise the friend declaration is ignored. This declaration will not forward declare a new type.

```c++
class Y {};
 
class A
{
    int data; // private data member
 
    class B {}; // private nested type
 
    enum { a = 100 }; // private enumerator
 
    friend class X; // friend class forward declaration (elaborated class specifier)
    friend Y; // friend class declaration (simple type specifier) (since c++11)
};
 
class X : A::B // OK: A::B accessible to friend
{
    A::B mx; // OK: A::B accessible to member of friend
 
    class Y
    {
        A::B my; // OK: A::B accessible to nested member of friend
    };
 
    int v[A::a]; // OK: A::a accessible to member of friend
};
```

###_Notes_
> Friendship is not transitive (a friend of your friend is not your friend).
> Friendship is not inherited (your friend's children are not your friends, and your friends are not your children's friends).
Storage class specifiers are not allowed in friend function declarations. A function that is defined in the friend declaration has external linkage, a function that was previously defined, keeps the linkage it was defined with.
> Access specifiers have no effect on the meaning of friend declarations (they can appear in private: or in public: sections, with no difference).
> A friend class declaration cannot define a new class (friend class X {}; is an error).

When a local class declares an unqualified function or class as a friend, only functions and classes in the innermost non-class scope are looked up, not the global functions:

```c++
class F {};
 
int f();
 
int main()
{
    extern int g();
 
    class Local // Local class in the main() function
    {
        friend int f(); // Error, no such function declared in main()
        friend int g(); // OK, there is a declaration for g in main()
        friend class F; // friends a local F (defined later)
        friend class ::F; // friends the global F
    };
 
    class F {}; // local F
}
```

A name first declared in a friend declaration within a class or class template X becomes a member of the innermost enclosing namespace of X, but is not visible for lookup (except argument-dependent lookup that considers X) unless a matching declaration at namespace scope is provided - see namespaces for details.
Template friends
Both function template and class template declarations may appear with the friend specifier in any non-local class or class template (although only function templates may be defined within the class or class template that is granting friendship). In this case, every specialization of the template becomes a friend, whether it is implicitly instantiated, partially specialized, or explicitly specialized.

```c++
class A
{
    template<typename T>
    friend class B; // every B<T> is a friend of A
 
    template<typename T>
    friend void f(T) {} // every f<T> is a friend of A
};
// Friend declarations cannot refer to partial specializations, but can refer to full specializations:
template<class T>
class A {};      // primary
 
template<class T>
class A<T*> {};  // partial
 
template<>
class A<int> {}; // full
 
class X
{
    template<class T>
    friend class A<T*>;  // error!
 
    friend class A<int>; // OK
};
```
When a friend declaration refers to a full specialization of a function template, the keywords inline/constexpr (since C++11)/consteval (since C++20) and default arguments cannot be used:

```c++
template<class T>
void f(int);
 
template<>
void f<int>(int);
 
class X
{
    friend void f<int>(int x = 1); // error: default args not allowed
};
```

A template friend declaration can name a member of a class template A, which can be either a member function or a member type (the type must use elaborated-type-specifier). Such declaration is only well-formed if the last component in its nested-name-specifier (the name to the left of the last ::) is a simple-template-id (template name followed by argument list in angle brackets) that names the class template. The template parameters of such template friend declaration must be deducible from the simple-template-id.

In this case, the member of any specialization of either A or partial specializations of A becomes a friend. This does not involve instantiating the primary template A or partial specializations of A: the only requirements are that the deduction of the template parameters of A from that specialization succeeds, and that substitution of the deduced template arguments into the friend declaration produces a declaration that would be a valid redeclaration of the member of the specialization:

```c++
// primary template
template<class T>
struct A
{ 
    struct B {};
 
    void f();
 
    struct D { void g(); };
 
    T h();
 
    template<T U>
    T i();
};
 
// full specialization
template<>
struct A<int>
{
    struct B {};
 
    int f();
 
    struct D { void g(); };
 
    template<int U>
    int i();
};
 
// another full specialization
template<>
struct A<float*>
{
    int *h();
};
 
// the non-template class granting friendship to members of class template A
class X
{
    template<class T>
    friend struct A<T>::B; // all A<T>::B are friends, including A<int>::B
 
    template<class T>
    friend void A<T>::f(); // A<int>::f() is not a friend because its signature
                           // does not match, but e.g. A<char>::f() is a friend
 
//  template<class T>
//  friend void A<T>::D::g(); // ill-formed, the last part of the nested-name-specifier,
//                            // D in A<T>::D::, is not simple-template-id
 
    template<class T>
    friend int* A<T*>::h(); // all A<T*>::h are friends:
                            // A<float*>::h(), A<int*>::h(), etc
 
    template<class T> 
    template<T U>       // all instantiations of A<T>::i() and A<int>::i() are friends, 
    friend T A<T>::i(); // and thereby all specializations of those function templates
};
```

Default template arguments are only allowed on template friend declarations if the declaration is a definition and no other declarations of this function template appear in this translation unit.
(since C++11)
Template friend operators
A common use case for template friends is declaration of a non-member operator overload that acts on a class template, e.g. operator<<(std::ostream&, const Foo<T>&) for some user-defined Foo<T>.
Such operator can be defined in the class body, which has the effect of generating a separate non-template operator<< for each T and makes that non-template operator<< a friend of its Foo<T>:

___Try this code:___

```c++
#include <iostream>
 
template<typename T>
class Foo
{
public:
    Foo(const T& val) : data(val) {}
private:
    T data;
 
    // generates a non-template operator<< for this T
    friend std::ostream& operator<<(std::ostream& os, const Foo& obj)
    {
        return os << obj.data;
    }
};
 
int main()
{
    Foo<double> obj(1.23);
    std::cout << obj << '\n';
}
// Output: 1.23
```
or the function template has to be declared as a template before the class body, in which case the friend declaration within Foo<T> can refer to the full specialization of operator<< for its T:

___Try this code:___

```c++
#include <iostream>
 
template<typename T>
class Foo; // forward declare to make function declaration possible
 
template<typename T> // declaration
std::ostream& operator<<(std::ostream&, const Foo<T>&);
 
template<typename T>
class Foo
{
public:
    Foo(const T& val) : data(val) {}
private:
    T data;
 
    // refers to a full specialization for this particular T 
    friend std::ostream& operator<< <> (std::ostream&, const Foo&);
 
    // note: this relies on template argument deduction in declarations
    // can also specify the template argument with operator<< <T>"
};
 
// definition
template<typename T>
std::ostream& operator<<(std::ostream& os, const Foo<T>& obj)
{
    return os << obj.data;
}
 
int main()
{
    Foo<double> obj(1.23);
    std::cout << obj << '\n';
}
```

___Example___
Stream insertion and extraction operators are often declared as non-member friends:

Try this code

```c++
#include <iostream>
#include <sstream>
 
class MyClass
{
    int i;                   // friends have access to non-public, non-static
    static inline int id{6}; // and static (possibly inline) members
 
    friend std::ostream& operator<<(std::ostream& out, const MyClass&);
    friend std::istream& operator>>(std::istream& in, MyClass&);
    friend void change_id(int);
public:
    MyClass(int i = 0) : i(i) {}
};
 
std::ostream& operator<<(std::ostream& out, const MyClass& mc)
{
    return out << "MyClass::id = " << MyClass::id << "; i = " << mc.i;
}
 
std::istream& operator>>(std::istream& in, MyClass& mc)
{
    return in >> mc.i;
}
 
void change_id(int id) { MyClass::id = id; }
 
int main()
{
    MyClass mc(7);
    std::cout << mc << '\n';
//  mc.i = 333*2;  // error: i is a private member
    std::istringstream("100") >> mc;
    std::cout << mc << '\n';
//  MyClass::id = 222*3;  // error: id is a private member
    change_id(9);
    std::cout << mc << '\n';
}
/*
Output:
MyClass::id = 6; i = 7
MyClass::id = 6; i = 100
MyClass::id = 9; i = 100
*/
```

#_What is virtual Function Specifier_

The virtual specifier specifies that a non-static member function is virtual and supports dynamic dispatch. It may only appear in the decl-specifier-seq of the initial declaration of a non-static member function (i.e., when it is declared in the class definition).

___Explanation___

Virtual functions are member functions whose behavior can be overridden in derived classes. As opposed to non-virtual functions, the overriding behavior is preserved even if there is no compile-time information about the actual type of the class. That is to say, if a derived class is handled using pointer or reference to the base class, a call to an overridden virtual function would invoke the behavior defined in the derived class. Such a function call is known as virtual function call or virtual call. Virtual function call is suppressed if the function is selected using qualified name lookup (that is, if the function's name appears to the right of the scope resolution operator ::).

___Try this code___

```c++
#include <iostream>
 
struct Base
{
    virtual void f()
    {
        std::cout << "base\n";
    }
};
 
struct Derived : Base
{
    void f() override // 'override' is optional
    {
        std::cout << "derived\n";
    }
};
 
int main()
{
    Base b;
    Derived d;
 
    // virtual function call through reference
    Base& br = b; // the type of br is Base&
    Base& dr = d; // the type of dr is Base& as well
    br.f(); // prints "base"
    dr.f(); // prints "derived"
 
    // virtual function call through pointer
    Base* bp = &b; // the type of bp is Base*
    Base* dp = &d; // the type of dp is Base* as well
    bp->f(); // prints "base"
    dp->f(); // prints "derived"
 
    // non-virtual function call
    br.Base::f(); // prints "base"
    dr.Base::f(); // prints "base"
}
```

In detail
If some member function vf is declared as virtual in a class Base, and some class Derived, which is derived, directly or indirectly, from Base, has a declaration for member function with the same
name
parameter type list (but not the return type)
cv-qualifiers
ref-qualifiers
Then this function in the class Derived is also virtual (whether or not the keyword virtual is used in its declaration) and overrides Base::vf (whether or not the word override is used in its declaration).
Base::vf does not need to be accessible or visible to be overridden. (Base::vf can be declared private, or Base can be inherited using private inheritance. Any members with the same name in a base class of Derived which inherits Base do not matter for override determination, even if they would hide Base::vf during name lookup.)

```c++
class B
{
    virtual void do_f(); // private member
public:
    void f() { do_f(); } // public interface
};
 
struct D : public B
{
    void do_f() override; // overrides B::do_f
};
 
int main()
{
    D d;
    B* bp = &d;
    bp->f(); // internally calls D::do_f();
}
```

For every virtual function, there is the final overrider, which is executed when a virtual function call is made. A virtual member function vf of a base class Base is the final overrider unless the derived class declares or inherits (through multiple inheritance) another function that overrides vf.

```c++
struct A { virtual void f(); };     // A::f is virtual
struct B : A { void f(); };         // B::f overrides A::f in B
struct C : virtual B { void f(); }; // C::f overrides A::f in C
 
struct D : virtual B {}; // D does not introduce an overrider, B::f is final in D
 
struct E : C, D          // E does not introduce an overrider, C::f is final in E
{
    using A::f; // not a function declaration, just makes A::f visible to lookup
};
 
int main()
{
    E e;
    e.f();    // virtual call calls C::f, the final overrider in e
    e.E::f(); // non-virtual call calls A::f, which is visible in E
}
//If a function has more than one final overrider, the program is ill-formed:
struct A
{
    virtual void f();
};
 
struct VB1 : virtual A
{
    void f(); // overrides A::f
};
 
struct VB2 : virtual A
{
    void f(); // overrides A::f
};
 
// struct Error : VB1, VB2
// {
//     // Error: A::f has two final overriders in Error
// };
 
struct Okay : VB1, VB2
{
    void f(); // OK: this is the final overrider for A::f
};
 
struct VB1a : virtual A {}; // does not declare an overrider
 
struct Da : VB1a, VB2
{
    // in Da, the final overrider of A::f is VB2::f
};

```

A function with the same name but different parameter list does not override the base function of the same name, but hides it: when unqualified name lookup examines the scope of the derived class, the lookup finds the declaration and does not examine the base class.

```c++
struct B
{
    virtual void f();
};
 
struct D : B
{
    void f(int); // D::f hides B::f (wrong parameter list)
};
 
struct D2 : D
{
    void f(); // D2::f overrides B::f (doesn't matter that it's not visible)
};
 
int main()
{
    B b;
    B& b_as_b = b;
 
    D d;
    B& d_as_b = d;
    D& d_as_d = d;
 
    D2 d2;
    B& d2_as_b = d2;
    D& d2_as_d = d2;
 
    b_as_b.f();  // calls B::f()
    d_as_b.f();  // calls B::f()
    d2_as_b.f(); // calls D2::f()
 
    d_as_d.f();  // Error: lookup in D finds only f(int)
    d2_as_d.f(); // Error: lookup in D finds only f(int)
}
//If a function is declared with the specifier override, but does not override a virtual function, the program is ill-formed:
struct B
{
    virtual void f(int);
};
 
struct D : B
{
    virtual void f(int) override;  // OK, D::f(int) overrides B::f(int)
    virtual void f(long) override; // Error: f(long) does not override B::f(int)
};
//If a function is declared with the specifier final, and another function attempts to override it, the program is ill-formed:
struct B
{
    virtual void f() const final;
};
 
struct D : B
{
    void f() const; // Error: D::f attempts to override final B::f
};
```
(since C++11)

Non-member functions and static member functions cannot be virtual.
Function templates cannot be declared virtual. This applies only to functions that are themselves templates - a regular member function of a class template can be declared virtual.
Virtual functions (whether declared virtual or overriding one) cannot have any associated constraints.

```c++
struct A
{
    virtual void f() requires true; // Error: constrained virtual function
};
```
A consteval virtual function must not override or be overidden by a non-consteval virtual function.
(since C++20)

Default arguments for virtual functions are substituted at the compile time.
Covariant return types
If the function Derived::f overrides a function Base::f, their return types must either be the same or be covariant. Two types are covariant if they satisfy all of the following requirements:
both types are pointers or references (lvalue or rvalue) to classes. Multi-level pointers or references are not allowed.
the referenced/pointed-to class in the return type of Base::f() must be an unambiguous and accessible direct or indirect base class of the referenced/pointed-to class of the return type of Derived::f().
the return type of Derived::f() must be equally or less cv-qualified than the return type of Base::f().
The class in the return type of Derived::f must be either Derived itself, or must be a complete type at the point of declaration of Derived::f.
When a virtual function call is made, the type returned by the final overrider is implicitly converted to the return type of the overridden function that was called:

```c++
class B {};
 
struct Base
{
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual B* vf4();
    virtual B* vf5();
};
 
class D : private B
{
    friend struct Derived; // in Derived, B is an accessible base of D
};
 
class A; // forward-declared class is an incomplete type
 
struct Derived : public Base
{
    void vf1();    // virtual, overrides Base::vf1()
    void vf2(int); // non-virtual, hides Base::vf2()
//  char vf3();    // Error: overrides Base::vf3, but has different
                   // and non-covariant return type
    D* vf4();      // overrides Base::vf4() and has covariant return type
//  A* vf5();      // Error: A is incomplete type
};
 
int main()
{
    Derived d;
    Base& br = d;
    Derived& dr = d;
 
    br.vf1(); // calls Derived::vf1()
    br.vf2(); // calls Base::vf2()
//  dr.vf2(); // Error: vf2(int) hides vf2()
 
    B* p = br.vf4(); // calls Derived::vf4() and converts the result to B*
    D* q = dr.vf4(); // calls Derived::vf4() and does not convert the result to B*
}
```

###___Virtual destructor___

Even though destructors are not inherited, if a base class declares its destructor virtual, the derived destructor always overrides it. This makes it possible to delete dynamically allocated objects of polymorphic type through pointers to base.

```c++
class Base
{
public:
    virtual ~Base() { /* releases Base's resources */ }
};
 
class Derived : public Base
{
    ~Derived() { /* releases Derived's resources */ }
};
 
int main()
{
    Base* b = new Derived;
    delete b; // Makes a virtual function call to Base::~Base()
              // since it is virtual, it calls Derived::~Derived() which can
              // release resources of the derived class, and then calls
              // Base::~Base() following the usual order of destruction
}
```

Moreover, if the destructor of the base class is not virtual, deleting a derived class object through a pointer to the base class is undefined behavior regardless of whether there are resources that would be leaked if the derived destructor is not invoked, unless the selected deallocation function is a destroying operator delete (since C++20).
A useful guideline is that the destructor of any base class must be public and virtual or protected and non-virtual, whenever delete expressions are involved, e.g. when implicitly used in std::unique_ptr (since C++11).
During construction and destruction
When a virtual function is called directly or indirectly from a constructor or from a destructor (including during the construction or destruction of the class’s non-static data members, e.g. in a member initializer list), and the object to which the call applies is the object under construction or destruction, the function called is the final overrider in the constructor’s or destructor’s class and not one overriding it in a more-derived class. In other words, during construction or destruction, the more-derived classes do not exist.
When constructing a complex class with multiple branches, within a constructor that belongs to one branch, polymorphism is restricted to that class and its bases: if it obtains a pointer or reference to a base subobject outside this subhierarchy, and attempts to invoke a virtual function call (e.g. using explicit member access), the behavior is undefined:

```c++
struct V
{
    virtual void f();
    virtual void g();
};
 
struct A : virtual V
{
    virtual void f(); // A::f is the final overrider of V::f in A
};
 
struct B : virtual V
{
    virtual void g(); // B::g is the final overrider of V::g in B
    B(V*, A*);
};
 
struct D : A, B
{
    virtual void f(); // D::f is the final overrider of V::f in D
    virtual void g(); // D::g is the final overrider of V::g in D
 
    // note: A is initialized before B
    D() : B((A*) this, this) {}
};
 
// the constructor of B, called from the constructor of D 
B::B(V* v, A* a)
{
    f(); // virtual call to V::f (although D has the final overrider, D doesn't exist)
    g(); // virtual call to B::g, which is the final overrider in B 
 
    v->g(); // v's type V is base of B, virtual call calls B::g as before
 
    a->f(); // a’s type A is not a base of B. it belongs to a different branch of the
            // hierarchy. Attempting a virtual call through that branch causes
            // undefined behavior even though A was already fully constructed in this
            // case (it was constructed before B since it appears before B in the list
            // of the bases of D). In practice, the virtual call to A::f will be
            // attempted using B's virtual member function table, since that's what
            // is active during B's construction)
}
```