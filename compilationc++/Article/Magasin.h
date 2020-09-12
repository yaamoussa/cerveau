#include "Article.h"


class Magasin {
	int A_max;
	int A_ajoute;
	Article **A_M;
   public: 
   	    Magasin (int);
   	    ~Magasin();
   	    void Ajouter_Article(Article *);
   	    void afficher_Magasin();
   	    double Prix_total();
   	    
};