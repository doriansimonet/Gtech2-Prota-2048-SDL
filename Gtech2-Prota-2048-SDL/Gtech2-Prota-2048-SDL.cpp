// Gtech2_Prota-2048.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Grid.h"
#include <vector> //Ne pas oublier !
#include <conio.h>
#include <SDL.h>

#define KEY_UP 75
#define KEY_DOWN 77
#define KEY_LEFT 72
#define KEY_RIGHT 80



int main()
{
    std::cout << "Hello World!\n";
    srand(time(NULL));

    Grid* tab = new Grid;
    tab->Rand();
    tab->Rand();
    tab->Show();

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
