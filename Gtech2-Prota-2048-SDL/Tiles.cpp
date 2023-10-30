#include <iostream>
#include "Tiles.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

//constructeur
Tile::Tile() {
    m_value = 0;
}

//méthodes
void Tile::Fuse() {

}

void Tile::Appear() {
    int t = std::rand() % 10;
    if (t == 0) {
        m_value = 4;
    }
    else {
        m_value = 2;
    }


}



int Tile::GetValue() {
    return m_value;
}

void Tile::NewValue(int val) {
    m_value = val;
}

void Tile::Times(int val) {
    m_value *= val;
}