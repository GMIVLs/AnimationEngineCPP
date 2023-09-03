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
