#include <iostream>
#include "GameObject.h"


GameObject::GameObject() {
	m_posX = 0;
	m_posY = 0;
	m_Width = 125;
	m_Height = 125;
}

void GameObject::Draw(SDL_Renderer* renderer) {
	SDL_Rect rect = { m_posX, m_posY, m_Width, m_Height };
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}

void GameObject::ChangePos(int posX, int posY) {
	m_posX = posX;
	m_posY = posY;
}