#pragma once
#include <SDL.h>
class Window
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

public:
	Window();
	void Create();
};