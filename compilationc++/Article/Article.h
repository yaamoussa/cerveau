
#include <string>
using namespace std ;
#ifndef ARTICLE_H_INCLUDED
#define ARTICLE_H_INCLUDED

class Article {
	protected :
	string numref;
    string designation;
    int prix_achat;
    static int nbArticle;
    public:
    	Article (string ,string,int );
    	virtual ~ Article();
    	int getPrix();
    	virtual double calcul_prix();
    	virtual void afficher(ostream &);
    	static int getnb();

};

 ostream& operator <<(ostream& sortie ,Article & );// pour gerer le retour du fichoer flot

#endif