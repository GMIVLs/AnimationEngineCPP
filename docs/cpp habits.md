# Habits You Need to Ditch in C++
---
#### **Introduction**
Welcome to the list of newbie C++ habits, C++ is an incredibly complex language with a lot of history, so whether you need to get actual programming with you really needs to look out for these things or whether you just want to improve your code a little bit, **_let's get started._**

1. Using Namespace std, people generally use it to save typing like **cout** instead of **std::cout** or **string** instead of **std::string**. If it's limited to just a single function that might not be that bad but, let's be honest it's usually used at the global level even worse, if you do this in a header file then you also force this choice upon every one uses your code.
> Please don't do this in a header file.
> Consider just using the names that you,
> actually use.
> ~~using namespace std;~~

```c++
#include <iostream>
using namespace std;
int main(int argc , char ** argv){
    string s {"Hello World...!"};
    cout << s << endl;
    return 0;
}
```
**_instead use like:_**
```c++
#include <iostream>

using std::cout, std::string, std::endl;
int main(int argc , char ** argv){
    string s{"Hello World...!"};
    cout << s << endl;
    return 0;
}
```
2. Using **std::endl** , especially in a loop you probably meant to just print out a new line but, **endl** dose more than that it also flushes the buffer which takes extra time, instead just use a newline character **\n**.

> Consider not use cout << "Hello World" << ~~endl~~;
> Instead use cout << "Hello World\n";
```c++
#include ...

void print_range(int start, int end){
    for (auto i = start; i != end; ++i)
        std::cout << i << std::endl;
}
void print_range(int start, int end){
    for (auto i = start; i != end; ++i)
        std::cout << i << '\n';
}
```
3. Using a **for loop** by index when a range-based for loop expresses the intent better, in this case, I don't really care at all about the index. Instead, use a range-based for loop. There's no index so, one less chance for an accidental typo of off by one error.

> Consider not use a **for loop by index**.
> Instead, use a **range-based for loop**.

```c++
#include ...

void train_model(const std::vector<int> &data, auto &model){
    for (std::size_t i = 0; i < data.size(); ++i)
        model.update(data[i]);
}
void train_model(const std::vector<int> &data, auto &model){
    for (const auto &x: data)
        model.update(x);
}
```
4. Using a **loop** when **standard algorith** already exists to do what you're trying to do. There's some simple thing that you want to do like find the index of the first positive number in vector. It's so simple though you decided to just write it by yourself. Instead, consider if there's an algorithm that already does what you're to do. In this case, we can use **std::find_if** to find where the first positive element is.
> First, looking for standard algorithm,
> to do what you need.
> Before writing your's code.
```c++
void know_your_algorithms() {
    const std::vector<int> data = {-1, -3, -5, 8, 15, -1};
    std::size_t first_pos_idx;
    for (std::size_t i = 0; i < data.size(); ++i) {
        if (data[i] > 0){
            first_pos_idx = i;
            break;
        }
    }
}

void know_algorithms() {
    const std::vector<int> data = {-1, -3, -5, 8, 15, -1};
    const auto is_positive = [](const auto &x) { return x > 0; };
    auto first_pos_it = std::find_if(
            data.cbegin(),
            data.cend(),
            is_positive);
}
```
5. Using a **C style array** when you could have used a **standard arry**. C style arrays often decay into pointers and require you to pass the length of the array along with the array itself. This is just another opportunity to make a **_typo_**. Instead use a standard array.

```c++
void f(int *arr, int n){
    // Whatever
}
void using_c_array() {
    const int n = 256;
    int arr[n] = {0};

    f(arr, n);
}

template<std::size_t size>
void better_f(std::array<int, size> &arr) {
    //Whatever
}
void using_c_array() {
    const int n = 256;
    std::array<int, n> arr{};

    better_f(arr);
}
```

6. Any use of **reinterpret_cast**. Pretty much the only thing you're allowed to do with an object that you got from reinterpret cast is to reinterpret cast it back to the original type. Almost everything else is undefined behavior, and yes the same goes for C-style casting. Famous Quake three algorithm for computing the inverse square root, reinterpreting the bytes of a float as a long is actually undefined behavior. You're always allowed to reinterpret cast the address of an object as a **character type**. This allows you to inspect or print out the bytes taht make up the object, so you cas see its memory laout. However, **as of C++ 20**, this use of reinterpret cast is also not necessary, **bit_cast** interprets the bytes of one object as a different type. In this case, I can cast any object to an array of bytes of the same size.

> Consider not use ~~interpret_cast~~
> instead, use it to cast an object to char
> or use bit_cast introduced in c++ 20.

```c++
void any_use_of_reinterpret_cast() {
    long long x = 0;
    auto xp = reinterpret_cast<char *>(x);
    auto x2 = reinterpret_cast<long long>(xp);
}

void any_cast_of_reinterpret_cast() { // C-style casting
    float y = .123f;
    long i = *(long *) &y; // Sorry famous Quake III inv_sqrt code
    // ...
    y = *(float *) &i;
}

template<typename T>
void print_bytes(const T &input) {
    auto *bytes = reinterpret_cast<const std::byte *>(&input); // cast an object as a character type alwasy allowed

    // print out bytes one at a time
}

template<typename T>
void print_bytes(const T &input) {
    using bytearray = std::array<std::byte, sizeof(T)>;
    const auto &bytes = std::bit_cast<bytearray, T>(input); // bit_cast interpret the bytes of one object as different type **(c++ 20)**.

    // print out bytes one at a time
}
```

7. **Casting away const**. This function takes in a map that maps strings to the number of times that they've occurred. It takes two words and then returns back to you whichever one has a higher count. The first way you might try to implement this is by looking up the counts of the two words, and then if the first count is bigger than the second then returning the first word. If I try to compile this, I get a weird error message telling me that the method isn't marked const, and that's how we ended up with this code. I know that I'm not modifying the map. Right?
The correct thing to do this case **is not to cast awsy const**. But to instead, **use the _at_ method, at is a const version of operator square bracket that throws if the word isn't in the map. But you might ask: Why don't they just add a const version so that this would compile?

> Consider not use ~~const_cast~~
> instead use, .at method.

```c++
const std::string &
more_frequent(const std::unordered_map<std::string, int>) &word_counts,
              const std::string &word1,
              const std::string &word2) {
    auto &counts = const_cast<std::unordered_map<std::string, int> &>(word_counts);
    return word_counts[word1] > word_counts[word2] ? word1 : word2;
              }

const std::string &
more_frequent(const std::unordered_map<std::string, int>) &word_counts,
              const std::string &word1,
              const std::string &word2) {
    return word_counts.at(word1) > word_counts.at(word2) ? word1 : word2;
              }
```

8. **Not Knowing map bracket inserts element**. This brings us to not knowing that operator square brackets inserts the element into the map if it doesn't already exist. That's right, simply trying to look up this word in the map actually inserts it with a count of zero into the map.

> The square brackets insert the element
> into the map if it not already exist.

```c++
...
return word_counts[word1] > word_counts[word2] ? word1 : word2;

```

9. **Ignoring const correctness**. This function loops over a vector simply printing out each element one element per line. It  doesn't modify the vector. So, we could and should mark the vector const. This is doubly important for a function parameter, so that the caller knows that they can use this function without their vector being modified.

```c++
void print_vec_one_per_line(std::vector<int> &arr) {
    for (const auto &x: arr) {
        std::cout << x << '\n';
    }
}

void print_vec_one_per_line(const std::vector<int> &arr) {
    for (const auto &x: arr) {
        std::cout << x << '\n';
    }
}
```

10. Not knowing about **string literal lifetimes**. String literals like this one are guaranteed to live for the entire life of a program. So, it's perfectly fine to return this, even though it looks like it's a reference to a local variable.

> string literal lifetime must knowing.

```c++
const char *string_literal_lifetimes() {
    return "string literals";
}
```

11. Using **structured bindings**. Here we have a map of color names to their hex values. Then we just loop over all the pairs and print out the name and hex value. It would be a lot more readable if we could refer to these things as name and hex rather that pair.first and pair.second. Well, that's exactly what a structured binding lets us do. We grab the pair by reference. Then, the structured binding introduce name and hex as names for the first and second elements of the pair. Structured bindings can also be used with your own types if the members are public. The names get assigned to the variables according to the order of their declarations.

> Consider not using structured bindings
> Instead, use two parameters with loop.

```c++
void loop_map_items() {
    std::unordered_map<std::string, std::string> colors = {
        {"RED", "#FF0000"},
        {"GREEN", "#00FF00"},
        {"BLUE", "#0000FF"}
    };
    for (const auto &pair: colors){
        std::cout << "name: " << pair.first << ", hex" << pair.second << '\n';
    }
}

void loop_map_items() {
    std::unordered_map<std::string, std::string> colors = {
        {"RED", "#FF0000"},
        {"GREEN", "#00FF00"},
        {"BLUE", "#0000FF"}
    };
    for (const auto &[name, hex]: colors){
        std::cout << "name: " << name << ", hex" << hex << '\n';
    }
}
```

also structured bindings.

```c++
struct S {
    int a;
    std::string s;
};
S get_S();
void use_S() {
    const auto [name_for_a, name_for_s] = get_S();
}
```

12. Out-params instead of returning a struct, using multiple out parameters when you want to return multiple things from a function. Instead, create a basic struct and give those things names. Then, you can return the multiple values that you wanted to by returning the struct instead. The caller can even make it look like it was multiple values returned by using structured bindings.

> Consider, not use function return multiple things.
> Instead, use struct and give those things names.

```c++
void get_values_out_params(const int n, int &out1, int &out2) {
    // do stuff
    out1 = n;
    out2 = n+1;
}

struct Values {
    int x, y;
};

Values
get_values_return_struct(const int n) {
    return {n, n+1};
}

void use_values(){
    auto [x, y] = get_values_return_struct(2);
}
```

13. Doing work at runtime that could have been done at compile time. Here's a function that gives the formula for the sum of the first n integers. Sometimes, the parameters might be know at compile-time and you could do the calculation ahead of time. Go ahead and let the compiler know that it's totally fine to compute this ahead of time.

> Consider, not doing work at runtime
> that can done on compile time.

```c++
int sum_of_1_to_n(const int n) {
    return n * (n+1) / 2;
}

void uses_sum() {
    const int limit = 1000;
    auto triangle_n = sum_of_1_to_n(limit);
    // use triangle_n...
}
```

```c++
constexpr int sum_of_1_to_n(const int n) {
    return n * (n+1) / 2;
}
```

14. Forgetting to mark destructors virtual. If a derived class gets deleted through a pointer to this base class, then the derived class destructor will not be called only the base classes destructor will be called. Here, I have a class that derives from the base that doesn't have a virtual destructor. This function expects a pointer to the base class. It uses some base functionality and then deletes the pointer when it's done. This will happen automatically since I'm using a unique pointer. But the same would be true if you just took in a normal pointer and then manually called delete. If you pass a pointer to an instance of this derived type, then the wrong destructor gets called at the end. To make sure the correct destructor is called even through a pointer to a base class, you need to make the function virtual. It's also good practice to explicitly mark the derived classes destructor as override.

> Be carefull to mark destructor of,
> pointer class virtually.

```c++
class BaseWithNonvirtualDestructor {
public:
    void foo() {
        std::cout << "do foo\n";
    }
    ~BaseWithNonvirtualDestructor() {
        std::cout << "called base destructor\n";
    }
};

class Derived : public BaseWithNonvirtualDestructor {
public:
    ~Derived() {
        std::cout << "called derived destructor\n";
    }
};
void consume_base(std::unique_ptr<BaseWithNonvirtualDestructor> p) {
    p->foo();
    // deletes p when done
}
```
to ensure that the correct destructor called
```c++
class BaseWithNonvirtualDestructor {
public:
    void foo() {
        std::cout << "do foo\n";
    }
    virtual ~BaseWithNonvirtualDestructor() {
        std::cout << "called base destructor\n";
    }
};

class Derived : public BaseWithNonvirtualDestructor {
public:
    ~Derived() override {
        std::cout << "called derived destructor\n";
    }
};
void consume_base(std::unique_ptr<BaseWithNonvirtualDestructor> p) {
    p->foo();
    // deletes p when done
}
```

15. Thinking that class members are initalized in the order they appear in the initializer list. Reading left to right this looks fine. The actual order that members are initialized in is the order that they're declared in. First, we initialize end as start plus size but this m start is garbage. It hasn't been initialized yet. We can of course fix this by declaring start first instead. Or, since start is also a parameter to the function, we could just define the end variable in terms of the start parameter

```c++
class View {
public:
    View(char *start, std::size_t size) : m_start{start}, m_end{m_start + size} {

    }
private:
    char *m_end;
    char *m_start;
};
```
correct this by

```c++
class View {
public:
    View(char *start, std::size_t size) : m_start{start}, m_end{m_start + size} {

    }
private:
    char *m_start;
    char *m_end;
};
```
