# CMake Tips and Tricks

## Recursivly all CPP files

It becomes tedious if we need to add eveytime the files that we create in our project

- Previously in the `CMakeFiles.txt` I used to do the following, which means you have to add each file automatically one by one.

```cmake
set(SOURCES src/main.cpp src/lib/veclib/vector2d.cpp)
```

- Now, I dont need to add these files, and it should be done using

```cmake
file(GLOB_RECURSE SOURCES "src/*.cpp")
```

## Build for give system

```cmake
if(APPLE) #Windows, Web ..etc.
    # you can put the building commands here for the given system
endif
```
