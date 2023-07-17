# SDL2 Library
The choice here is that we will allow the `brew` to download the dependencies
for the `SDL2.0` then create links to them in the `dependencies` directory.

## Prepare the SDL2.0 lib
Simply run the command below which will run the script at `../tools/fetch_dependencies_if_not_existed_macOS.sh`

```sh
make fetch_sdl2.0_dependencies
```
- We can also copy the entir directoy for each library, but since we have
either M1 or Intel build, we will use this approach more safer.

