
#include <cstdio>
#include <cstdlib>// ancien <stdlib.h>
#include <iostream>
#include<cstring>
using namespace std ;
#include"Site.h"




int main(int argc, char const *argv[])
{    char * chaine =new char [10];
	 char * mot =new char [10];
	 strcpy(mot,"BBC");
	 strcpy(chaine,"revue");
      Site B;
 		Document *D=creer_Document(2,"journal",9);
    /*  Site  A(B);*/
      B<<D;
      B.afficher_Site();
      if (B%D)
      {
      	/* code */
      	cout<<"D est un document du site"<<endl;
      }

      else cout<<"D n est pas un document du site"<<endl;
   
   /*     B.afficher_Site()*/
        B<< creer_Document(2,chaine,2);
        B=B;
        B.afficher_Site();
 /*     B=B.U_Sites(B);*/
/*     B.insert_Document(2,chaine,9);
     B.insert_Document(2,chaine,9);*/
/*     S1.insert_Document(2,mot,9);*/
 /*    B.afficher_Site();
     B.ajouter_mot(2,mot);
     B.afficher_Site();
    

     cout<<"rechercher un document"<<endl;
     if (B.rechercher_Document(2))
     {

     	/* code */
   /*  	cout<<"Le document de cle "<<2<<"se trouve dans le site"<<endl;
     }

     else cout<<"il ne se trouve pas dans le site"<<endl;
     cout<<"supprimer le document"<<endl;
      B.supprimer_Document(2);

      B.afficher_Site();*/
/*     cout<<"union S et S1"<<endl;
      Site  U,I,D;
      U=S1.U_Sites(S);
      U.afficher_Site();*/
  /*    I=S1.I_Sites(S);
      D=S1.Diff_Sites(S);*/
	return 0;
}