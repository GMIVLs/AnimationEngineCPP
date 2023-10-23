# SDL2 Run on GPU

It's possible to utilize SDL2 in combination with the GPU for
rendering, especially for intensive 2D graphics. SDL2 provides
hardware-accelerated rendering through its `SDL_Renderer` API, which uses the
GPU to perform rendering operations when available.

Here's a breakdown of how you can use SDL2 with GPU acceleration:

1. **Hardware-Accelerated Renderer**: When creating a renderer with SDL2, you
   can specify the `SDL_RENDERER_ACCELERATED` flag. This tells SDL2 to create a
   hardware-accelerated renderer, which uses the GPU when possible.

   ```cpp SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
   SDL_RENDERER_ACCELERATED);
   ```

2. **V-Sync**: If you also want to enable V-Sync to cap the frame rate and
   prevent screen tearing, you can use the `SDL_RENDERER_PRESENTVSYNC` flag:
   00

   ```cpp SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
   SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   ```

3. **Textures over Surfaces**: For GPU-accelerated rendering, you should prefer
   `SDL_Texture` over `SDL_Surface`. Textures can be loaded into GPU memory,
   making them much faster to draw when using a hardware-accelerated renderer.

   To convert an `SDL_Surface` to `SDL_Texture` for rendering:

   ```cpp SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,
   surface);
   ```

## Regarding the Apple M1 chip:

- The M1 is Apple's ARM-based chip that has integrated GPU cores. It's quite
  powerful and can definitely handle intensive 2D graphics.

- If you're developing on an M1 Mac, ensure you have the latest SDL2 libraries
  that are compatible with the ARM architecture of the M1.

- SDL2 has support for Metal, which is Apple's graphics and compute API. This
  means SDL2 can take advantage of the M1's GPU capabilities via Metal for
  rendering.

The SDL2 offers hardware-accelerated rendering for 2D graphics, if
you need more control over the GPU, especially for 3D graphics or custom
shaders, you might want to consider combining SDL2 with a graphics API like
OpenGL, Vulkan, or Metal. SDL2 can be used to create a window and handle input,
while the graphics API manages the rendering.
