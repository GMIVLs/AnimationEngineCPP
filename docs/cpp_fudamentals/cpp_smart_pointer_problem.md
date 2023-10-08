# _Smart Pointers_
Let me know if this ever happend to you, that you feel like finally ___mastered pointers___ write some code that uses pointers maybe you use ___the heap___ may you don't, run your code and it still crashes anyways you check the syntax of your code and the syntax is definitely right but something about the code isn't, now all because you know how to use pointers ___doesn't mean you're using them correctly___ and it's actually really easy to mess up raw pointers in ___C and C++___ take for example this piece of code:

```c++
int main(int argc, char **argv)
{
    char line[128];
    while(1) {
        printf("[auth = %p, service = %p]\n", auth, service);
        if(fgets(line, sizeof(line), stdin) = NULL) break;

        if(strncmp(line, "auth", 5) = 0) {
            auth = malloc(sizeof(auth));
            memset(auth, 0, sizeof(auth));
            if(strlen(line + 5) < 31) {
                strcpy(auth->name, line + 5);
            }
        }
        if(strncmp(line, "reset", 5) = 0) {
            free(auth);
        }
        if(strncmp(line, "service", 6) = 0) {
            service = strdup(line + 7);
        }
        if(strncmp(line, "login", 5) = 0) {
            if(auth->auth) {
                printf("you have logged in already!\n");
            } else {
                printf("please enter your password\n");
            }
        }
    }
}
```
Here, you see the bug. This bug has a used after free vulnerability where on this line here the code gets freed:
```c++
free(auth);
```
but later on the logic doesn't check for the free and the pointer gets used anyway causing the program to crash.
```c++
if(auth->auth)
```
I used the syntax correctly, I just didn't use ___the pointers correctly___ now I know C++ catches a lot of hate for being a language that kind of puts the whole kitchen sink into the language but it actually has some really elegant solutions for stopping this kind of scenario from happening in the future by using thing called ___"SMART POINTERS"___ that add some really cool functionality but also have some really huge pitfalls that make using pointers easy in some places and harder in others.

Let's talk about those scenarios, now here is an example of C++ code where we create an example class, the class's name is dog and it has a method speak and a method that's a Setter of set name that sets the dog's name.
```c++
#include <iostream>
#include <memory>
#include <cstring>

class Dog {
    public:
        void speak();
        void setName(std::string);
    private:
        std::string name;
};
void Dog::setName(std::string input) {
    this->name = input;
}
void Dog::speak() {
    std::cout << "bork bork i am " << this->name << std::endl;
    return;
}
void do_something_with_the_dog(Dog *d) {
    d->setName("highhigh");
    d->speak();
}
int main(int argc, char **argv)
{
    Dog *ralf = new Dog();
    do_something_with_the_dog(ralf);
    ralf->setName("asdfasdf");
    ralf->speak();

    return 0;
}
```
We have the functions defined here reset the name and then when we talk we say ___bork bork___ I'm the dog, um and so this is the example that people typically show to show why you should ___never use raw pointers in C++___ so we create a new dog and set the dog pointer named __Ralph__ and then later we call the function ___do_something_with_the_dog___ where we say the pass object set it's name to "high high" and then speak so if we go ahead and compile it and run it, it actually behaves as expected no issues so far, but what if there was logic in this code where we do something to the dog and eventually we say delete ___d___
```c++
void do_something_with_the_dog(Dog *d) {
    d->setName("highhigh");
    d->speak();
    delete(d);
}
```
but later on in the code when we talk about the dog or do something else with it outside of that function we don't check the value of the pointer to see if it's ___NULL___ or freed and then eventually we run into a crashing state right where we could say bork bork I am high high this first part run but later on in the program because this pointer Ralph is no longer valid it crashes the program.
Instead of using a raw pointer in C++, we can use the smart pointer concept. Here we're going to create what is called a ___unique pointer___
```c++
int main(int argc, char **argv)
{
    std::unique_ptr<Dog> ralf = std::make_unique<Dog>();
    do_something_with_the_dog(ralf);
    ralf->setName("asdfasdf");
    ralf->speak();

    return 0;
}
```
___Unique pointer,___ literally is as it sounds a pointer to an object that is unique meaning no one else is allowed to point to that object we make a unique pointer of a type dog with pointer name ralf and then we call standard make unique on dog to invoke the object constructor and make the object right and then we can just pass the ralf pointer like a regular pointer we can call set name on it and speak, and we can compile and run it.
We get kind of that expected behavior right bork bork I am asdfasdf, now the things start to get a little weird with unique pointers and you start trying to use it in other places in your program, it's represents not only a pointer that is unique to an object that points to that object, but it also represents ___who owns that object___ and in programming when we say who owns a thing we're talking about ___whow was responsible for destroying the object.___ when you're done using it right to prevent that use after free scenario and to prevent memory leaks right now as programmed by passing in ralf which is a unique to a function that expects a dog pointer a raw C pointer as input we will get a pretty nasty compilation error because these types just don't match up so by now changing the parameter type from a dog raw pointer to a unique pointer.
```c++
void do_something_with_the_dog(std::unique_ptr<Dog> d) {
    d->setName("highhigh");
    d->speak();
}
```
Would you think that this would work but this is also another problem and it goes against the unique pointer constrcut, if we compile this what's happening here actually passing the value of the unique pointer ralf by value right we are making a copy of the unique pointer and that in itself is not very unique right. I'm now at the same time have two copies of the same pointer and the C++ compiler will not allow me to do that to pass ownership of the object from our main function to do something with the dog function.
We have to do what is called move we will literally standard move ralf the dog to this function and now this function is responsible for controlling it so if we compile that we get no errors:
```c++
int main(int argc, char **argv)
{
    std::unique_ptr<Dog> ralf = std::make_unique<Dog>();
    do_something_with_the_dog(std::move(ralf));
    ralf->setName("asdfasdf");
    ralf->speak();
    return 0;
}
```
but when we run this we did crash again and I want to see if you guys understand why we crashed??
As I saied before ownership is the idea of who is responsible for destroying the object we moved ownership of ralf to our function do something with the doe then we called setName on ralf and called speak also, and because we did not return ralf object it went out of scope so that C++ smart pointer freed ralf from our code then continued and later on in the code we tried to use function in an object that had been freed and we crashed the program just like befor.
This first part pointer started to get a little weird right because now essentially every time I want to use a smart pointer I have to say that this is no longer a void function this is a standard unique pointer to a dog, and we're going to say that it returns this and we're going to say that it return d, and we'll say that ralf now equals itself after the move so it does something with the dog what we move ralf into we pull ralf back out and now the program doesn't crash.
```c++
std::unique_ptr<Dog> do_something_with_the_dog(std::unique_ptr<Dog> d) { // here
    d->setName("highhigh");
    d->speak();
    return(d); // here is the change
}
```
and change the main function:
```c++
int main(int argc, char **argv)
{
    std::unique_ptr<Dog> ralf = std::make_unique<Dog>();
    ralf = do_something_with_the_dog(std::move(ralf)); // here is the change
    // also can use the get() method
    // do_something_with_the_dog(ralf.get());
    ralf->setName("asdfasdf");
    ralf->speak();
    return 0;
}
```
It runs twice but this is kind of gross right this code is not very good to look at it's kind of counfusing and typically when you have a function that does something you want to return the result of the thing but if I have to move ralf out of the function every time now every time I want to use a unique pointer it makes it very ugly to do so one way we can deal with this problem with the unique pointer where we have to pass it around and move it and then unmoves it is to use the get method from the unique pointer so the get method in the unique pointer actually returns a raw pointer to the thing that the unique pointer controls.
You're probably thinking well then doesn't that defeat the entire purpose of the unique pointer and yes it does but what you can do with it, actually there's a couple ways you can work around it to make the unique raw pointer work right so here i say ralf get which again returns the raw pointer to ralf what we can do is in our function that uses that raw pointer we can set the raw pointer to a constant which essentially locks down what the pointer is able to do and it doesn't allow us to modify our class variable now that adds some future complications where now dog speak has to be declared as a const function that guarantees we don't actully modify the class we have to also put that in the declaration right here but with that all done we can go ahead and compile thsi and eventually we can actually use the raw pointer to do certian things with the class while also retaining ownership in the main function now an even easier way to do this is just to treat this that way.
```c++
void do_something_with_the_dog(Dog *d) const {
    d->speak();
    return;
}
```
I think you should treat it all the time generally which is the use of the other class call a ___shared pointer (std::shared_ptr<Type>)___ so if you have a shared pointer dog d it's a still a void we'll clean up our constants here and then we will also say d setName to asked as this will be not a unique it'll be a make shared and will set this to a shared pointer and then we will just pass ralf and that should work.
```c++
void do_something_with_the_dog(std::shared_ptr<Dog> d) {
    d->setName("hihihihi");
    d->speak();
    return;
}
// and should use std::shared_ptr in main function
int main(int argc, char **argv)
{
    std::shared_ptr<Dog> ralf = std::make_shared<Dog>();
    do_something_with_the_dog(ralf); // here is the change
    ralf->setName("asdfasdf");
    ralf->speak();
    return 0;
}
```
What happens here is we essentially create a shared pointer which is a unique pointer that can have multiple copies of itself as we create the second copy of ralf all that happens is that the reference counter inside the shared pointer goes up by one and that reference counter is used here to denote that we have a pointer that now has two places that are using it when d goes out of scope the shared pointer copy that we made is deleted and we still retain ownership of the object here in main then ralf continues and we call the extra functions here and things are good.

## _REFERENCES_

1. [youtube](https://www.youtube.com/watch?v=tSIBKys2eBQ)
