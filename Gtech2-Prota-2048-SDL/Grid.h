#pragma once
#include "Tiles.h"
#include <vector> //Ne pas oublier !

class Grid
{
private:
	int m_rows;
	int m_cols;
	Tile m_tile;
	std::vector<std::vector<Tile>> m_grid;



public:
	Grid();
	void Show();
	void Rand();
	bool Move(int direction);
	void MergeTiles(int x1, int y1, int x2, int y2);
	bool IsGameOver();
};
