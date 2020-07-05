#include "Article.h"
#include <string>
using namespace std ;


class ArticleImporte : public  Article {
	double taux;
	static int nbAImporte;
	public :
	 ArticleImporte (string ,string,int,double);
	 ~ArticleImporte();
	 virtual double calcul_prix();
	 virtual void afficher (ostream &);
	 static int getnb();
};