#include "Window.hpp"

Window::Window(int width, int height) {
    m_init_width = m_drawing_bounds.w = width;
    m_init_height = m_drawing_bounds.h = height;
    m_drawing_bounds.x = m_drawing_bounds.y = 0;

    m_window = SDL_CreateWindow("pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    SDL_UpdateWindowSurface(m_window);

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
}

SDL_Renderer* Window::get_renderer() {
    return m_renderer;
}

void Window::render_copy(SDL_Texture** texture) {
    SDL_QueryTexture(*texture, NULL, NULL, &m_drawing_bounds.w, &m_drawing_bounds.h);
    SDL_RenderCopy(m_renderer, *texture, NULL, &m_drawing_bounds);
}

void Window::resize() {
    int w, h;
    SDL_GetWindowSize(m_window, &w, &h);
    m_drawing_bounds.x = (w - m_init_width) / 2;
    m_drawing_bounds.y = (h - m_init_height) / 2;
}

void Window::shutdown() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
}