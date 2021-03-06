#ifndef CONSIGNE_H
#define CONSIGNE_H

#include <string>

namespace asd2_td1 {

typedef std::string Bagage;

class Consigne {
public:
  Consigne(size_t n);
  ~Consigne();

  size_t taille() const;
  bool est_libre(size_t i) const;
  void deposer_dans(Bagage b, size_t i);
  Bagage retirer(size_t i);
  bool est_pleine() const;
  size_t deposer(Bagage b);
  size_t deposerBis(Bagage b);

  void afficher() const;
  void afficherListe() const;

private:
  struct Casier {
    size_t numero;
    bool libre;
    Bagage bag;
  };

  struct MaillonCasier {
    Casier *casier;
    MaillonCasier *suivant;
  };

  struct ListeCasiers {
    MaillonCasier *tete;
  };

  Casier *tab_;
  size_t n_;
  size_t nlibre_;
  ListeCasiers liste_;
};

} // namespace asd2_td1

#endif