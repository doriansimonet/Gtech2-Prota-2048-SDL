#include <iostream>
#include "GameObject.h"

GameObject::GameObject(SDL_Surface* surface, SDL_Texture* texture) {
	m_surface = surface;
	m_texture = texture;
}