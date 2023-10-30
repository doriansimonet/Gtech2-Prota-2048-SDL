#pragma once
class Tile
{
private:
	int m_value;



public:
	Tile();
	void Fuse();
	void Appear();
	int GetValue();
	void NewValue(int val);
	void Times(int val);

};
