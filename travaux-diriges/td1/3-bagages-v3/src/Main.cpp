#include <iostream>
#include "Consigne.hpp"
using namespace std;
using namespace asd2_td1;

int main(void)
{
  size_t n = 5;

  // Déclaration de la variable cons de type Consigne et
  // appel du constructeur Consigne prenant en paramètre
  // un entier.
  Consigne cons(n);

  // Cet objet est construit dans la mémoire automatique
  // de la fonction main et cet objet sera donc détruit
  // automatiquement à la fin de l'exécution de main (par
  // appel du destructeur).

  cons.afficher();
  cons.afficherListe();
  cout << endl;

  cons.deposerBis("banane");
  cons.afficher();
  cons.afficherListe();
  cout << endl;

  cons.deposerBis("poire");
  cons.afficher();
  cons.afficherListe();
  cout << endl;
  
  return 0;
}

