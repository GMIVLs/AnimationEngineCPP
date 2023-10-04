# How to load environment variables

## Steps

1. You will need to install a utility called `direnv`, - [direnv](https://direnv.net), simple for macOS use `brew install direnv`.
2. In the root directory of your project create a file called `.envrc`.
3. You can put in this file the following environment variables

```cpp
export PROJECT_DIR="/Users/<user_name>/Path/to/AnimationEngineCPP"
export HOMEBREW_DIR="/opt/homebrew/Cellar"
export HOME="/Users/<user_name>/"
```

4. The prompt will ask you to `allow direnv`.

5. If you want to use the env variables call them in `main.cpp`

```cpp
#include <cstdlib> // <- Added for getenv

// Get the PROJECT_DIR environment variable value
const char *projectDir = getenv("PROJECT_DIR");
// Construct the path to the image
std::string imagePath = std::string(projectDir) + "/assets/M01.png";

```
