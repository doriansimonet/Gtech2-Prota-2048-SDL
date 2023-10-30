#include <iostream>
#include <vector> //Ne pas oublier !
#include "Grid.h"
#include <Windows.h>

using namespace std;

//constructeur
Grid::Grid() {

    m_rows = 4;
    m_cols = 4;
    m_grid.resize(m_rows);//me fait 4 tab, on touche vector 
    for (int i = 0; i < m_rows; i++) {
        m_grid[i].resize(m_cols);// me fait 4 int dans mes vector

    }
}

//méthodes
void Grid::Show() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            int value = m_grid[i][j].GetValue();
            if (value == 0) {
                SetConsoleTextAttribute(hConsole, 7);
            }
            if (value == 2) {
                SetConsoleTextAttribute(hConsole, 1);
            }
            if (value == 4) {
                SetConsoleTextAttribute(hConsole, 2);
            }
            if (value == 8) {
                SetConsoleTextAttribute(hConsole, 3);
            }
            if (value == 16) {
                SetConsoleTextAttribute(hConsole, 4);
            }
            if (value == 32) {
                SetConsoleTextAttribute(hConsole, 5);
            }
            if (value == 64) {
                SetConsoleTextAttribute(hConsole, 6);
            }
            if (value == 128) {
                SetConsoleTextAttribute(hConsole, 8);
            }
            if (value == 256) {
                SetConsoleTextAttribute(hConsole, 9);
            }
            if (value == 512) {
                SetConsoleTextAttribute(hConsole, 10);
            }
            if (value == 1024) {
                SetConsoleTextAttribute(hConsole, 11);
            }
            if (value == 2048) {
                SetConsoleTextAttribute(hConsole, 12);
            }
            if (value == 4096) {
                SetConsoleTextAttribute(hConsole, 13);
            }
            if (value < 10) {
                std::cout << "|   " << value << "|";
            }
            if (value >= 10 && value < 100) {
                std::cout << "|  " << value << "|";
            }
            if (value >= 100 && value < 1000) {
                std::cout << "| " << value << "|";
            }
            if (value >= 1000) {
                std::cout << "|" << value << "|";
            }
        }
        std::cout << std::endl;

    }
}

void Grid::Rand() {

    int value = 1;
    int t = 0;
    int tt = 0;
    do {
        t = std::rand() % 4;
        tt = std::rand() % 4;
        value = m_grid[t][tt].GetValue();
        if (value == 0) {
            m_grid[t][tt].Appear();
        }
    } while (value != 0);


}

bool Grid::Move(int direction) {
    bool moved = false;
    int dx = 0, dy = 0;

    if (direction == 1) dx = 1;   // Droite
    else if (direction == 2) dy = 1;  // Bas
    else if (direction == 3) dx = -1;  // Gauche
    else if (direction == 4) dy = -1;  // Haut

    for (int x = 0; x < m_grid.size(); x++) {
        for (int y = 0; y < m_grid.size(); y++) {
            int newX = x + dx;
            int newY = y + dy;

            if (m_grid[x][y].GetValue() != 0) {
                while (newX >= 0 && newX < m_grid.size() && newY >= 0 && newY < m_grid.size()) {
                    if (m_grid[newX][newY].GetValue() == 0) {
                        m_grid[newX][newY].NewValue(m_grid[x][y].GetValue());
                        m_grid[x][y].NewValue(0);
                        x = newX;
                        y = newY;
                        moved = true;
                    }
                    else if (m_grid[newX][newY].GetValue() == m_grid[x][y].GetValue()) {
                        MergeTiles(x, y, newX, newY);
                        moved = true;
                        break;
                    }
                    else {
                        break;
                    }

                    newX += dx;
                    newY += dy;
                }
            }
        }
    }

    return moved;
}

void Grid::MergeTiles(int x1, int y1, int x2, int y2) {
    m_grid[x2][y2].Times(2);
    m_grid[x1][y1].NewValue(0);
}
bool Grid::IsGameOver() {
    // Vérifie si tout les emplacements sont pris
    for (int i = 0; i < m_grid.size(); i++) {
        for (int j = 0; j < m_grid.size(); j++) {
            if (m_grid[i][j].GetValue() == 0) {
                return false;
            }
        }
    }

    // Vérifie s'il y a des mouvements possibles
    for (int i = 0; i < m_grid.size(); i++) {
        for (int j = 0; j < m_grid.size(); j++) {
            int value = m_grid[i][j].GetValue();
            if ((i < m_grid.size() - 1 && m_grid[i + 1][j].GetValue() == value) ||
                (j < m_grid.size() - 1 && m_grid[i][j + 1].GetValue() == value)) {
                return false;
            }
        }
    }

    return true;
}

/*bool Grid::Full() {

}*/
//destructeur
