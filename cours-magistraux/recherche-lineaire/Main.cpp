#include <iostream>
#include "Main.h"

using namespace std;

int main() {
    int result = 0;
    const int tailleTableau = 11;
    int tableau[tailleTableau] = {3, 5, 7, 7, 10, 13, 16, 17, 22, 27, 31};

    result = rechercheLineaire(tableau, tailleTableau, 27);
    cout << result << endl;
}

int rechercheLineaire(int tab[], int taille, int e) {
    int i = 0;
    int res = 0;

    while (res == 0 && i < taille) {
        if (tab[i] == e) {
            res = i;
        } else {
            i++;
        }
    }
    return res;
}

  
