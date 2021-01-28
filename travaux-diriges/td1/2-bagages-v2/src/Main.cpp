#include <iostream>
#include "Consigne.hpp"
using namespace asd2_td1;
using std::cout;
using std::endl;

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

  cons.deposer_dans("banane", 3);
  cons.afficher();

  Bagage bag = cons.retirer(3);
  std::cout << bag << "\n";
  cons.afficher();

  cons.deposer_dans("orange", 2);
  cons.deposer_dans("fraise", 4);
  cons.afficher();

  ////////////////////////////////////////////////////////////////////
  cout << "---------------------------------\n";

  cons.afficherListe();

  ////////////////////////////////////////////////////////////////////
  cout << "---------------------------------\n";
  
  // Déclaration de la variable cons2 de type pointeur sur Consigne et
  // appel du constructeur Consigne prenant en paramètre un entier.
  Consigne* cons2 = new Consigne(n);
    
  // Cet objet est construit dans la mémoire dynamique
  // cet objet doit être détruit explicitement (si on ne le fait
  // alors il y a une fuite de mémoire).

  cons2->deposer_dans("pomme",2);
  cons2->afficher();
  
  // appel explicite du destructeur de l'objet
  delete cons2;
  
  return 0;
}

