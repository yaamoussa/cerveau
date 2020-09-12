// Visualise les allocations/liberations
// #define PHASE_TRACE

/**
  Constructeur par defaut
*/
Aeroport::Aeroport()
: m_parc()
{}

/**
  Destructeur: il faut le surdefinir afin de liberer les
  instances dynamiques
*/
Aeroport::~Aeroport()
{
  vider();
}

/**
  Charge les donnees du parc de Vehicules depuis un fichier
  @return Vrai si l'operation a ete effectuee
  avec succès, Faux sinon (i.e. fichier inexistant, ...)
  @pre Suppose une ligne par vehicule
*/
bool Aeroport::charger(const string& fn)
{
  ifstream is(fn.c_str());
  if (not is)
  {
    return false;
  }
  // Effectue la lecture du fichier, tantque c'est possible
  char c;
  while (is>>c)
  {
    // Lit les caracteristiques
    switch (c)
    {
      case 'V': case 'v':
        ajouterVoiture(is);
        break;

      case 'A': case 'a':
        ajouterAvion(is);
        break;

      default:
        cerr << "\aOUPS... erreur de donnees!" << endl;
    }

    // Ignore le reste de la ligne
    is.ignore(100, '\n');
  }

  // On pose que c'est OK
  return true;
}

/**
  Accesseur du nombre d'elements
*/
unsigned Aeroport::size() const
{
  return m_parc.size();
}

/**
  Ajoute un vehicule v au parc courant
  ATTENTION Suppose une instance dynamique
*/
void Aeroport::ajouter(Vehicule* v)
{
  m_parc.push_back(v);
}

/**
  Calcule et affiche l'etat du parc p/r à une annee
  @param[in] annee - une annee
*/
void Aeroport::calculer(int annee) const
{
  for (unsigned ix = 0; ix < size(); ++ix)
  {
    m_parc[ix]->afficher();                   //<- POINTEUR

    double argus = m_parc[ix]->eval(annee);   //<- POINTEUR
    cout<<", argus = "<<argus<<endl;
  }
}

/**
  Vide l'ensemble des elements du parc
*/
void Aeroport::vider()
{
  // Libère les instances dynamiques
  #if defined(PHASE_TRACE)
  cout<<"Purge des instances dynamiques...."<<endl;
  #endif
  for (unsigned k = 0; k < size(); ++k)
  {
    delete m_parc[k];
    m_parc[k] = 0;
  }

  // Purge le conteneur
  #if defined(PHASE_TRACE)
  cout<<"Purge du conteneur..."<<endl;
  #endif
  m_parc.clear();
}

/**
  Lit les caracteriques d'une Voiture depuis un flux d'entree
  @param[in,out] is - unflux d'entree
  @return le status du flux (Vrai ou Faux)
*/
bool Aeroport::ajouterVoiture(istream& is)
{
  Vehicule *xx;
  string m; int d; unsigned n, cv; double c, p, km;
  if (is>>m>>d>>p>>c>>n>>cv>>km)
  {
    ajouter( xx = new Voiture(m, d, p, c, n, cv, km) );
  }
  return is.good();
}

/**
  Lit les caracteriques d'un Avion depuis un flux d'entree
  @param[in,out] is - unflux d'entree
  @return le status du flux (Vrai ou Faux)
*/
bool Aeroport::ajouterAvion(istream& is)
{
  Vehicule *xx;
  string m; int d; unsigned mt, hv; double p;
  if (is>>m>>d>>p>>mt>>hv)
  {
    ajouter( xx = new Avion(m, d, p, mt, hv) );
  }
  return is.good();
}
