#pragma once
#include <SDL.h>
class GameObject
{
private:
	SDL_Surface* m_surface;
	SDL_Texture* m_texture;

public:
	GameObject(SDL_Surface* surface, SDL_Texture* texture);
};