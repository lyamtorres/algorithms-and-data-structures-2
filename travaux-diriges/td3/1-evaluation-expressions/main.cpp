#include <iostream>
#include <string>

using namespace std;

string liste[] = {"3", "5", "+", "2", "*"};

class Pile {
public:    
    int sommet;
    int tab[5];

    Pile() {
        sommet = 0;
        for (int i = 0; i < 5; i++) {
            tab[i] = 0;
        }
    }

    bool estVide() {
        if (sommet == 0)
            return true;
        else 
            return false;
    }

    bool estPleine() {
        if (sommet == 5)
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
        for (int i = 0; i < 5; i++) {
            cout << tab[i] << endl;
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
    string ch;
    int i, x, y;

    p.afficher();
   
/*     for (int i = 0; i <= p.sommet; i++) {
        ch = p.tab[i];
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
    }
    p.afficher(); */
}