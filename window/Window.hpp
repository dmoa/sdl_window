#pragma once

#include <SDL2/SDL.h>

class Window {
public:
    Window(int width, int height);
    SDL_Renderer* get_renderer();
    void render_copy(SDL_Texture** texture);
    void resize();
    void shutdown();
private:
    int m_init_width;
    int m_init_height;
    SDL_Rect m_drawing_bounds;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
};
