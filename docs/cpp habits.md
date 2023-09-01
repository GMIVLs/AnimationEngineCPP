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
