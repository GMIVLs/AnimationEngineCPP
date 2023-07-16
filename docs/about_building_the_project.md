## How to build

### Running command

- Both the following commands are for `debugging` mode, and should be run at `root` directory.
  - This command will run the project without optimization.
  - You must provid the directory `build/debug` in your root directory, otherwise it won't work.

```sh
clang++ -std=c++17 -Ilib/veclib -o ./build/debug/main src/main.cpp src/lib/veclib/vector2d.cpp && ./build/debug/main
```

Or use

- This command will run the project with debuging mode and without optimization.

```sh
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build/debug && cd ./build/debug/ && make && ./main && ../../
```

- This command will run the project with `release` mode and with optimization level `3`.

```sh
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build/release && cd ./build/release/ && make && ./main && ../../
```

### clangd server

Every build module using `cmake` you need to remove the simlink of
`compile_commands.json` and create a new simlink to know about the new module
or added `c++` files that you added.

```sh
rm compile_commands.json && ln -s build/debug/compile_commands.json compile_commands.json
```

## Previous build for project intialization

The following command for running the project at first time without any dependencies or modules.

### In Debugging Mode

```sh
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build/debug
```

### In Release Mode

```sh
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build/release
```

## How to build and Run CLI

### In Debugging Mode

```sh
clang++ -std=c++17 -Wall -Wextra -g -o build/Debug/main src/main.cpp && build/debug/main
```

### In Release Mode

```sh
clang++ -std=c++17 -O3 -o build/Release/main src/main.cpp && build/release/main
```
