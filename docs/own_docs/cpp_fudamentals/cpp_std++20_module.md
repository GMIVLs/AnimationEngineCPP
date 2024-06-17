# Compiling c++ file with std++20 new features

- I tested the compiling with (g++ compiler) on Arch Linux:
```
g++ (GCC) 14.1.1 20240522
```

### Required Steps:

- First make a directory called **gcm.cache** in your project's build directory
myapp
|
|__build
   |
   | gcm.cache

- Compile the standard library required in your program like <iostream> in the build directory.

```sh
g++ -std=c++20 -fmodules-ts -xc++-system-header iostream
```

- Add the compile flag (""-fsmodules-ts"") option to your ""CMakeLists.txt"" file:

```
add_compile_options(-fsmodules-ts)
```

- Write your first program with ""std++20)

```cpp
import <iostream>;

int main(int argc, char* argv[])
   {
      std::cout << "Hello, std++20 world" << std::endl;
      return 0;
   }
```

I hope this will explain how to use the new features in ""std++20"" with the (GCC) compiler on Arch Linux.