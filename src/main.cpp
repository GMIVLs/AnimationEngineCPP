#include "lib/veclib/Vector_2d.h"
#include <SDL.h>
#include <SDL_image.h>
#include <cmath>
#include <cstdlib> // <- Added for getenv
#include <iostream>

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    SDL_Log("SDL_image could not initialize! SDL_image Error: %s\n",
            IMG_GetError());
    SDL_Quit();
    return 1;
  }

  SDL_Window *window =
      SDL_CreateWindow("SDL Image Display", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
  if (!window) {
    SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 1;
  }
  // Get the PROJECT_DIR environment variable value
  const char *projectDir = getenv("PROJECT_DIR");
  // Construct the path to the image
  std::string imagePath = std::string(projectDir) + "/assets/M01.png";

  SDL_Texture *texture = IMG_LoadTexture(renderer, imagePath.c_str());
  if (!texture) {
    SDL_Log("Unable to create texture from image! SDL_image Error: %s\n",
            IMG_GetError());
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  bool quit = false;
  SDL_Event e;

  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();

  // Lets add a unit test for the vector
  // Vector_2d<double> my_vector = Vector_2d(10.0, 10.0);
  double a = 10.0;
  double b = 20.0;
  for (size_t i = 0; i < 10; i++) {
    a = a + i;
    b = b + i;
    Vector_2d<double> my_vector(a, b);
    my_vector.display();
  }

  return 0;
}
