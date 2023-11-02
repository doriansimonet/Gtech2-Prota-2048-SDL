#include <iostream>
#include "Window.h"
#include "GameObject.h"

Window::Window() {
	m_window = NULL;
	m_renderer = NULL;
}

void Window::Create(int width, int height) {
	m_window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

}

SDL_Renderer* Window::GetRenderer() {
	return m_renderer;
}

