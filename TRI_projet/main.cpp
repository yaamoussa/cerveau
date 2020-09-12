#include <string>
#include<iostream>
using namespace std;
#include"Tri_Selection.h"
#include"Tri_insertion.h"


int main(int argc, char const *argv[])
{
	



	int tab[4];
	     tab[0]=20;
	     tab[1]=3;
	     tab[2]=0;
	     tab[3]=7;
          for (int i=0;i<4;i++)
		   cout<< tab[i];
		 Tri_Selection selection;
		 Tri_Insertion insertion;

		 selection.Trier_tab(4,tab);
		 selection.affiche_tab (4,tab);

		 insertion.Trier_tab(4,tab);
		 insertion.affiche_tab (4,tab);

	return 0;
}