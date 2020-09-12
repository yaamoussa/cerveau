#include <string>
using namespace std ;
#ifndef TRI_SELECTION_H_INCLUDED
#define TRI_SELECTION_H_INCLUDED


class Tri  {
	virtual void Trier_tab(int ,int *tab )=0;
}


class Tri_Selection{

    public :

    Tri_Selection();
    ~Tri_Selection();
   virtual void Trier_tab(int ,int *tab);
   virtual void affiche_tab(int ,int *tab);

} ;


class Tri_Insertion
{
public:
	Tri_Insertion();
	~Tri_Insertion();
	virtual void Trier_tab(int ,int *);
	
};
#endif