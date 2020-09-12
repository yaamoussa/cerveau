#include <iostream>
using namespace std ;
#include "Tri_insertion.h"


Tri_Insertion :: Tri_Insertion(){

}


Tri_Insertion:: ~Tri_Insertion(){
	
}


void Tri_Insertion :: Tri_tab(int n,int*tab){
	int cle,i,j;
  for (int i = 1; i < n; ++i)
  {
  	
     
    /*memorisation de la valeur de la cle=t[i]*/
    /* code */
  	cle=tab[i];
     j=i-1;// l'indice de son precedent

     /*décaler vers la droite les éléments de T[0]..T[i-1] qui sont plus grands que x en partant de T[i-1]*/

     while(j>=0,tab[j]>cle){
     	tab[j+1]=tab[j]//decalage vers la droite
     	j=j-1;//passe a la valeur suivante

     }
     
     /*inserer la valeur de la cle a sa bonne place indice j*/
     tab[j]=cle;


  }



}



  void Tri_Insertion::affiche_tab(int n ,int *tab){
  	
     /* affichage valeurs triées */
     int k;
       cout << "\n---- valeurs triées ----\n" ;
for ( k=0 ; k<n ; k++)
              cout<< tab[k];

  }
