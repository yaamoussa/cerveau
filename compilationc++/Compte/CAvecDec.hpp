#ifndef CBAVECDECOUVERT_CLASS
#define CBAVECDECOUVERT_CLASS

#include "CBancaire.hpp"
class CAvecDecouvert : public CBancaire
{
  typedef CBancaire super;
  public:
    CAvecDecouvert();
    CAvecDecouvert(const string& num, double mt, double dmax);
    void fixerDMax(double mt);
    void retirer(double mt);
    void afficher() const;
  private:
    double m_dmax;
};
#include "CAvecDec.cpp"
#endif
