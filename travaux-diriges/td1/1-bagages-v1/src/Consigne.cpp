#include <cassert>
#include <iostream>
#include "Consigne.hpp"

namespace asd2_td1 {

Consigne::Consigne(size_t n)
{
  assert(n >= 1);

  tab_ = new Casier[n+1];
  n_ = n;
  nlibre_ = n;

  for (int i=1; i<=n; ++i)
  {
    tab_[i].numero = i;
    tab_[i].libre = true;
  }
}

Consigne::~Consigne()
{
  delete[] tab_;
}

size_t Consigne::taille() const
{
  return n_;
}

bool Consigne::est_libre(size_t i) const
{
  assert(i>=1 && i<=taille());

  return tab_[i].libre;
}

void Consigne::deposer_dans(Bagage b, size_t i)
{
  assert(i>=1 && i<=taille());

  tab_[i].bag = b;
  tab_[i].libre = false;
  nlibre_ = nlibre_-1;
}

Bagage Consigne::retirer(size_t i)
{
  assert(i>=1 && i<=taille() && !est_libre(i));

  Bagage b = tab_[i].bag;
  tab_[i].libre = true;
  nlibre_ = nlibre_+1;
  return b;
}

bool Consigne::est_pleine() const
{
  return nlibre_ == 0;
}

size_t Consigne::deposer(Bagage b)
{
  assert(!est_pleine());

  size_t i = 1;
  bool trouve = false;

  while (!trouve)
  {
    if (tab_[i].libre)
      trouve = true;
    else
      i = i+1;
  }

  deposer_dans(b,i);
  return i;
}

void Consigne::afficher() const
{
  for (int i=1; i<=n_; ++i)
    std::cout << tab_[i].numero
	      << ":"
	      << (tab_[i].libre ? "*" :
		                  tab_[i].bag)
              << " ";

  std::cout << "\n";
}

} // namespace asd2_td1