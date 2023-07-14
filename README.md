# Animation Engine CPP
## ChangingLog

## How to build

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

