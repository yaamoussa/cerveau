

#include "Article.h"

#include<string>
using namespace std;



class  ArticleLocal :public Article {
	int coute ;
    static  int nbAlocal;
	public :
	           ArticleLocal (string,string,int,int );
	           ~ArticleLocal();
	       virtual    void afficher(ostream &);
	       virtual     double calcul_prix();
	     static  int getnb();
};

