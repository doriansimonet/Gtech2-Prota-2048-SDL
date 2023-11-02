// Gtech2_Prota-2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Grid.h"
#include "Window.h"
#include "GameObject.h"
#include <vector> //Ne pas oublier !
#include <conio.h>
#include <SDL.h>

#define KEY_UP 75
#define KEY_DOWN 77
#define KEY_LEFT 72
#define KEY_RIGHT 80



int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";
    srand(time(NULL));

    Grid* tab = new Grid;
    tab->Rand();
    tab->Rand();
    tab->Show();

    Window* window = new Window;
    window->Create(500, 500);
    SDL_Renderer* renderer = window->GetRenderer();
    GameObject* gameobject1 = new GameObject;
    SDL_SetRenderDrawColor(renderer, 47, 43,40, 255);
    SDL_RenderPresent(renderer);
    gameobject1->Draw(renderer);

    SDL_Surface* pSurface = SDL_LoadBMP("img/2048.bmp");
    if (pSurface == NULL)
    {
        std::cout << "Error SDL_LoadBMP :" << SDL_GetError();
        exit(1);
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(renderer, pSurface);
    if (pTexture == NULL)
    {
        std::cout << "Error SDL_CreateTextureFromSurface :" << SDL_GetError();
        exit(1);
    }

    for (int i = 0; i < 500; i += 125) {
        for (int j = 0; j < 500; j += 125) {
            int icase = i - j;
            if (icase < 0) {
                icase = icase * (-1);
            }
            icase = (icase /125);
            if (icase%2 == 0 ) {
                SDL_SetRenderDrawColor(renderer,176, 146, 106,255);
            }
            else {
                SDL_SetRenderDrawColor(renderer, 190, 160, 120, 255);
            }
            
            gameobject1->ChangePos(i, j);
            gameobject1->Draw(renderer);
        }
    }
    SDL_Rect deux = {0,0,125,125};
    SDL_SetRenderTarget(renderer, pTexture); 
    SDL_RenderCopy(renderer, pTexture, NULL, &deux);
    SDL_RenderPresent(renderer);

    while (true) {
        bool badKey = true;
        bool moved = false;
        while (badKey)
        {
            badKey = false;
            int c = 0;
            switch ((c = _getch()))
            {
            case KEY_UP:
                moved = tab->Move(4);
                break;
            case KEY_DOWN:
                moved = tab->Move(2);
                break;
            case KEY_RIGHT:
                moved = tab->Move(1);
                break;
            case KEY_LEFT:
                moved = tab->Move(3);
                break;
            default:
                badKey = true;
                break;
            }


        }
        if (moved) {
            system("cls");
            tab->Rand();
            tab->Show();
            if (tab->IsGameOver()) {
                std::cout << "Game Over!" << std::endl;
                break;
            }
        }



    }

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
