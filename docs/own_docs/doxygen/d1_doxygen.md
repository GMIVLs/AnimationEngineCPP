# Doxygen

Doxygen is the de facto standard tool for generating documentation from
annotated C++ sources, but it also supports other popular programming languages
such as C, Objective-C, C#, PHP, Java, Python, IDL (Corba, Microsoft, and
UNO/OpenOffice flavors), Fortran, and to some extent D. Doxygen also supports
the hardware description language VHDL.

## Usage

### Running doxygen

I run the command inside the project to generate the `dcofig` file and I have
edited some configurations to match our expected documentation that we will
generate during the workflow.

- this will be generate only once,

```sh
doxygen -g dconfig
```

- I also adjusted the dconfig to fit our needs

  1. I added the name of the project, the version and also swithcing YES the inline sources and sources.
  2. We add the documentations for our functions to be generated, using the follwoing form.

     - You will add the documentation using the `//!` a head of each comment that
       you will add to a class, method, function, structs ..etc. (see the example
       below)
     - Its ok to use other documentation formating such as `///`, `//! ****` blocks, ..etc. not structly to use `//!` only!

```cpp
//! Add your documentation here in this format
void my_function(std::string my_string){
    return std::string("This is just a test ...")
}
```

3. For generating the documentation, Run the command:

```sh
doxygen dconfig ./build/debug/main
```

- Currently, I used the best configurations for our repo, you can check all the
  options that I selected by reviewing the "../../dconfig" file.

## Installing doxygen

### macOS

1. Use the following link

```sh
git clone --depth=1 https://github.com/doxygen/doxygen.git
cd doxygen
```

2. After that you can use

```sh
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
```

**NOTE**: Incase you have an old `bison`, then you need to do the following, (then restart your terminal session)

```sh
brew install bison
ln -s /opt/homebrew/Cellar/bison/3.8.2/bin/bison /usr/local/bin/

# Now check after restart your terminal
bison --version
# I am running:
bison (GNU Bison) 3.8.2
Written by Robert Corbett and Richard Stallman.
```

- To force a fresh build after an earlier check-out simple remove the build
  directory and redo the steps above.

3. After the binaries have been built, you can use

```sh
make install
#to install them.
```

- I got

```sh
doxygen --version
1.10.0 (e29c4a5e86941ed6b6c2437fcdf82263a2679268)

```

## Reference

- [Getting starting with doxygen](https://www.doxygen.nl/manual/starting.html)
- [docblocks](https://www.doxygen.nl/manual/docblocks.html)
- [Doxygen - Documentation for your program - Avery](https://www.youtube.com/watch?v=44Ja2X_fzv4)
