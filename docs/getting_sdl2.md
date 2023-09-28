# SDL2 Library

## changinlog

- `2023-09 23:49`: Updated the `SDL2` and `SDL_image` calling in the `CMakeList.txt`
  The choice here is that we will allow the `brew` to download the dependencies
  for the `SDL2.0` then create links to them in the `dependencies` directory.

## Prepare the SDL2.0 lib

- Simply run the command below which will run the script at `../tools/fetch_dependencies_if_not_existed_macOS.sh`
- Ensure you already have `SDL2` and `SDL_image` and all other extensions (run `brew info sdl2` , also `brew info sdl_image`)

```sh
make fetch_sdl2.0_dependencies
```

- We can also copy the entir directoy for each library, but since we have
  either M1 or Intel build, we will use this approach as it offers more
  flexibility.

## Modification

The header file of `sdl2_image` seems require the `sdl2` location to be known. In that case you have two options

## For sdl2_image

### Option A - not recommended

- Change the sdl_image header file,

1. Go to the location of your `sdl2_image`, which is at `/opt/homebrew/Cellar/sdl2_image/2.6.3_2/include/SDL2/SDL_image.h`
2. Now change the following parts in this file as:

```cpp
// From
//#include "SDL.h"
//#include "SDL_version.h"
//#include "begin_code.h"
// To
#include "/opt/homebrew/Cellar/sdl2/2.28.3/include/SDL2/SDL.h"
#include "/opt/homebrew/Cellar/sdl2/2.28.3/include/SDL2/SDL_version.h"
#include "/opt/homebrew/Cellar/sdl2/2.28.3/include/SDL2/begin_code.h"
#include "/opt/homebrew/Cellar/sdl2/2.28.3/include/SDL2/close_code.h"
```

3. You will be required also to change at the end of this file `SDL_image.h` the following:

```cpp
// From
//#include "close_code.h"
// To
#include "/opt/homebrew/Cellar/sdl2/2.28.3/include/SDL2/close_code.h"
```

4. In your `CMakeLists.txt` you don't need to refer to the link of each header

```cmake
target_include_directories(main PRIVATE
    ${CMAKE_SOURCE_DIR}/dependencies/sdl2/include
    ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/include
)
```

5. How you call the libraries

```cpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
```

### Option B - recommended

- This one is very flexible, as we will match the exact syntax of the
  `SDL_image.h` that downloaded by `homebrew`, therefor, even if you update the
  `SDL2` or any other libraries, you will be always get the latest update.

1. Change the `CMakeLists.txt` section, notice here we are including the
   `symlink` in our dependencies, this will affect the calling in the main.cpp
   (see point .2)

```cmake
target_include_directories(main PRIVATE
    ${CMAKE_SOURCE_DIR}/dependencies/sdl2/include/SDL2
    ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/include/SDL2
)
target_link_libraries(main PRIVATE
    ${CMAKE_SOURCE_DIR}/dependencies/sdl2/lib/libSDL2.dylib
    ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/lib/libSDL2_image.dylib
)
```

2. How you call the libraries

```cpp
#include <SDL.h>
#include <SDL_image.h>
```

- **Note**, As you can see here, the calling is matching the calling at
  `/opt/homebrew/Cellar/sdl2/2.28.3/include/SDL2/` and
  `/opt/homebrew/Cellar/sdl2/2.28.3/lib/libSDL2.dylib`
- It worth to mention that the `libSDL2.dylib` is a simlink for the developer
  library located at same location
  `/opt/homebrew/Cellar/sdl2/2.28.3/lib/libSDL2-2.0.0.dylib`, this also applied to all the other extensions.
