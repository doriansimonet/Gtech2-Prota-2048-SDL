#include <iostream>
#include "Window.h"

Window::Window() {
	m_window = NULL;
	m_renderer = NULL;
}

void Window::Create() {
	m_window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		500, 500, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

}