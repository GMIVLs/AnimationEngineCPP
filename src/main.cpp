#include "lib/veclib/vector2d.h"
#include <SDL2/SDL.h>
#include <algorithm>
#include <iostream>
/****************************************************
//  How to  Draw a line in SDL2 :
//  https://wiki.libsdl.org/SDL_RenderDrawLine     */
//  SDL2 Library is up and running with MacOSX    */
/****************************************************/
int main(int argc, char *argv[]) {

  std::cout << "Adding the Makefile to my current module ..." << std::endl;
  std::cout << "This is first test for our lib" << std::endl;
  vector_engine::vector2d vec1(3.0, 4.0);
  // Use the print method to display the vector */
  vec1.print(vec1);
  // Create another vector2d object */
  vector_engine::vector2d vec2(1.0, 2.0);
  // Add the two vectors and print the result */
  vector_engine::vector2d sum = vec1 + vec2;
  sum.print(sum);
  // Subtract the two vectors and print the result */
  vector_engine::vector2d diff = vec1 - vec2;
  diff.print(diff);
  // Multiply the two vectors and print the result */
  vector_engine::vector2d prod = vec1 * vec2;
  prod.multi_print(prod);
  // Get a new vector from the user and print it */
  // vector_engine::vector2d vec3 = vec3.vector_input(); */
  // vec3.print(vec3); */
  if (SDL_Init(SDL_INIT_VIDEO) == 0) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
      SDL_bool done = SDL_FALSE;
      while (!done) {
        SDL_Event event;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 100, 200, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
        SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
        SDL_RenderDrawLine(renderer, 340, 240, 320, 200);
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
          if (event.type == SDL_QUIT) {
            done = SDL_TRUE;
          }
        }
      }
    }

    if (renderer) {
      SDL_DestroyRenderer(renderer);
    }
    if (window) {
      SDL_DestroyWindow(window);
    }
  }
  SDL_Quit();
  return 0;
}
