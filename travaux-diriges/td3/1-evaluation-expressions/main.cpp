#include <iostream>
#include <string>

using namespace std;

string liste[] = {"3", "5", "+", "2", "*"};

class Pile {
public:    
    int sommet;
    int taille;
    int tab[5];

    Pile() {
        sommet = -1;
        taille = 5;
        for (int i = 0; i < taille; i++) {
            tab[i] = 0;
        }
    }

    bool estVide() {
        if (sommet == -1)
            return true;
        else 
            return false;
    }

    bool estPleine() {
        if (sommet == 4)
            return true;
        else
            return false;
    }

    void empiler(int valeur) {
        if (estPleine()) {
            cout << "La pile est pleine !";
        } else {
            sommet++;
            tab[sommet] = valeur;
        }
    }

    int depiler() {
        if (estVide()) {
            cout << "La pile est vide !";
            return 0;
        } else {
            int valeurDepilee = tab[sommet];
            tab[sommet] = 0;
            sommet--;
            return valeurDepilee;
        }
    }

    void afficher() {
        for (int i = taille - 1; i >= 0; i--) {
            if (tab[i] != 0)
                cout << "|" << tab[i] << "|" << endl;
            else
                cout << "| |" << endl;
        }
    }
};

bool estEntier(string str) {
   for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
         return false;
      return true;
}

int chaineVersEntier(string chaine) {
    return stoi(chaine);
}

int main() {
    Pile p;
    string ch = "3";
    int i, x, y;
   
    for (int i = 0; i <= p.taille - 1; i++) {
        ch = liste[i];
        if (estEntier(ch)) {
            p.empiler(chaineVersEntier(ch));
        } else {
            x = p.depiler();
            y = p.depiler();
            if (ch == "+") {
                p.empiler(x + y);
            } else {
                p.empiler(x * y);
            }
        }
        cout << endl;
        cout << "Pile au tour " << i << "\n\n";
        p.afficher();
        cout << endl;
    }
}