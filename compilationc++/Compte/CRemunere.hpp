#ifndef CBREMUNERE_CLASS
#define CBREMUNERE_CLASS

#include "CBancaire.hpp"
class CRemunere : public CBancaire
{
  typedef CBancaire super;
  public:
    CRemunere();
    CRemunere(const string& num, double mt, double taux);
    void fixerTaux(double mt);
    void calculerInterets();
    void retirer(double mt);
    void afficher() const;
  private:
    double m_taux;
};
#include "CRemunere.cpp"
#endif
