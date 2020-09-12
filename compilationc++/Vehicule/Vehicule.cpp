/**
  Constructeur normal
*/
Vehicule::Vehicule(const string& m, int d, double p)
: m_marque(m), m_date(d), m_achat(p)
{}

/**
  Destructeur virtuel
*/
Vehicule::~Vehicule()
{}

/**
  Methode d'affichage
*/
void Vehicule::afficher() const
{
  cout<<"Veh"
      <<": m = "<<m_marque
      <<", a = "<<m_date
      <<", achat = "<<m_achat;
}

/**
  Decote p/r a une annee
*/
double Vehicule::decote(int annee) const
{
  return (annee > m_date) ? (annee - m_date) * 0.01 : 0;
}

/**
  Prix de l'argus p/r a une annee.
  Le prix doit rester positif (s'il est negatif: mis a zero)
*/
double Vehicule::eval(int annee) const
{
  double d = decote(annee);
  return max(0.0, (1.0 - d) * m_achat);
}
