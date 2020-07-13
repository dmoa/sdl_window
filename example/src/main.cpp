#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Window.hpp"


int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO))
        SDL_Log(SDL_GetError());
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
        SDL_Log(IMG_GetError());

    Window window(500, 376);

    SDL_Texture* image = IMG_LoadTexture(window.get_renderer(), "image.png");
    if (!image)
        SDL_Log(IMG_GetError());

    SDL_Event event;
    const Uint8* keys_down = SDL_GetKeyboardState(NULL);

    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                        window.resize();
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        quit = true;
                    break;
                default: break;
            }
        }


        SDL_SetRenderDrawColor(window.get_renderer(), 0, 0, 0, 255);
        SDL_RenderClear(window.get_renderer());
        SDL_SetRenderDrawColor(window.get_renderer(), 255, 255, 255, 255);

        window.render_copy(&image);

        SDL_RenderPresent(window.get_renderer());
    }

    window.shutdown();
    IMG_Quit();
    SDL_Quit();
    return 0;
}