#pragma once
#include <SDL.h>
class GameObject
{
private:
	int m_posX;
	int m_posY;
	int m_Width;
	int m_Height;

public:
	GameObject();
	void Draw(SDL_Renderer* Renderer);
	void ChangePos(int posX, int posY);
};

