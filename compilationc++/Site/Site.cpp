
#include <cstdlib>// ancien
#include <iostream>
#include<cstring>
using namespace std ;
#include"Site.h"
void Document :: afficher_Document(){
	cout<<"cle:"<<cle<<endl;
	cout<<"titre: "<<titre<<endl;
	for(int i=0;i<nb_mots;i++)
	cout<< "liste des mots :"<<mots_cles[i];
    cout<<endl;
}

void Document:: ajouter_mot( const char *mots){
	  int size=strlen(mots);
				    char * nmot=new char [size];
				    strcpy(nmot,mots);
	if(max_mots!=nb_mots){

					 mots_cles[nb_mots]=nmot;
					 nb_mots++;
			}
}

Document * creer_Document(int i,const char *t,int nb){
	cout<<"Appel du constructeur document"<<endl;
	Document * D;
	D=new Document;
	if(D==NULL)  return NULL;

			D->cle=i;
			if (t!=NULL){
				    int size=strlen(t);
				    D->titre=new char [size];
				    strcpy(D->titre,t);
			}
     D->mots_cles=new char* [nb];
     D->max_mots=nb;
     D->nb_mots=0;
			


			return D;
} 



void detruire_Document (Document*D){
	cout<<"Appel du destructeur document"<<endl;
    if (D!=NULL){
    	 if (D->titre) delete D->titre;
    	  if (D->mots_cles) delete D->mots_cles;
    	  delete D;
    }
}



 
 Site:: Site(){
 	cout<<"Appel du constructeur"<<endl;
 	S_longueur=0;
 }


 Site:: ~Site(){

 	cout<<"Appel du destructeur"<<endl;
 	if (D_premier!=NULL){
 		while (D_premier!=NULL){
 			D_courant=D_premier;
 			D_premier=D_courant->suivant;
 			 detruire_Document(D_courant); 
 		}
 	}
 }



 void  Site :: insert_Document(int i,const char *titre,int nb){
 	Document *D=creer_Document(i,titre,nb);
 	if (D==NULL)  cout <<"veuillez verifier votre espace memoire"<<endl;

 	else {
 		     if (D_premier==NULL){
 		     	D_premier=D;
 		     	D_courant=D;
 		     	S_longueur=1;
 		     }

 		     else {
 		     	    D_courant=D_premier;
 		     	    while(D_courant!=NULL&& D_courant->cle!=D->cle)
 		     	            D_courant=D_courant->suivant;


 		     	   if (D_courant==NULL){
 		     	   	D->suivant=D_premier;
 		     	   	D_premier=D;
 		     	   	S_longueur++;
 		     	   } 

 		     	   else cout<<"Document existe deja dans le site"<<endl;
 		     }

 	}
 }

  Site & Site :: operator <<(Document * D){
 

 	
 	 if (D_premier==NULL){
 		     	D_premier=D;
 		     	D_courant=D;
 		     	S_longueur=1;
    }

    else {
 		     	    D_courant=D_premier;
 		     	    while(D_courant!=NULL&& D_courant->cle!=D->cle)
 		     	            D_courant=D_courant->suivant;


 		     	   if (D_courant==NULL){
 		     	   	D->suivant=D_premier;
 		     	   	D_premier=D;
 		     	   	S_longueur++;
 		     	   } 

 		     	   else cout<<"Document existe deja dans le site"<<endl;
    }
  return *this;
 	
 }

 void  Site :: supprimer_Document(int i){
       if (D_premier ==NULL)
       	                      cout<<"le Site est vide"<<endl;
       else {
       	       D_courant=D_premier;
       	       if (D_courant->cle==i){
       	       	D_premier=D_courant->suivant;
       	       	detruire_Document(D_courant);
       	       	S_longueur--;
       	       }
       	       else{
       	       while(D_courant->suivant!=NULL&& D_courant->suivant->cle!=i)
       	       	              D_courant=D_courant->suivant;
       	       if (D_courant->suivant!=NULL)  {
       	       	Document * tmp=D_courant->suivant;
       	       	D_courant->suivant=D_courant->suivant->suivant;
       	       	detruire_Document(tmp);
       	       	cout<<"suppression effectuee "<<endl;
       	       }
       	       else cout<< "le document ne se trouve dans le site"<<endl;
       	   }
       }
 }

 Site & Site ::  operator >>(Document *D){
 	   if (D_premier ==NULL)
       	                      cout<<"le Site est vide"<<endl;
       else {
       	       D_courant=D_premier;
       	       if (D_courant->cle== D->cle){
       	       	D_premier=D_courant->suivant;
       	       	detruire_Document(D_courant);
       	       	S_longueur--;
       	       }
       	       else{
       	       while(D_courant->suivant!=NULL&& D_courant->suivant->cle!=D->cle)
       	       	              D_courant=D_courant->suivant;
       	       if (D_courant->suivant!=NULL)  {
       	       	Document * tmp=D_courant->suivant;
       	       	D_courant->suivant=D_courant->suivant->suivant;
       	       	detruire_Document(tmp);
       	       	cout<<"suppression effectuee "<<endl;
       	       }
       	       else cout<< "le document ne se trouve dans le site"<<endl;
       	   }
       }

 }  

 bool Site :: rechercher_Document(int i) {
            

            if (D_premier==NULL)  return false;

            else {
            	D_courant=D_premier;
            	while(D_courant!=NULL&& D_courant->cle!=i)
            		D_courant=D_courant->suivant;
            	return D_courant!=NULL;
            }
 } 


 bool Site :: operator % (Document*D){

            if (D_premier==NULL)  return false;

            else {
            	D_courant=D_premier;
            	while(D_courant!=NULL&& D_courant->cle!=D->cle)
            		D_courant=D_courant->suivant;
            	return D_courant!=NULL;
            }
 }
Site Site:: U_Sites(Site & S) {
   	Document *tmp;

	if (S_longueur<S.S_longueur){
		S.S_longueur=S.S_longueur+S_longueur;
		D_courant=D_premier;
		while(D_courant!=NULL){
			tmp=D_courant;
			/* chainage*/
			tmp->suivant=S.D_premier;
			S.D_premier=tmp;
			/*passe au  suivant*/
			D_courant=D_courant->suivant;

		}
		return *this;
	}

	else{
		    S_longueur=S_longueur+S.S_longueur;
		    S.D_courant=S.D_premier;	
		    while(S.D_courant!=NULL){
		    	tmp=S.D_courant;
		    	/*chainage*/
		    	tmp->suivant=D_premier;
		    	D_premier=tmp;
		    	/*passe au suivant*/
		    	S.D_courant=S.D_courant->suivant;

		    }

          return S;

		}

}

Site  Site :: Diff_Sites(Site & S) {
	Site Dif;
	Document * tmp;
    D_courant=D_premier;
    while(D_courant!=NULL){
    	if (! (S.rechercher_Document(this->D_courant->cle)))
    	{
    		/* chainage */
    		tmp=D_courant;
    		tmp->suivant=Dif.D_premier;
    		Dif.D_premier=tmp;

    	}
       /*passe au suivant*/
    	D_courant=D_courant->suivant;
    }
  return Dif;

}

Site  Site:: I_Sites(Site & Sit){
	Site I;
	Document  *D_tmp;

	D_courant=D_premier;
	Sit.D_courant=Sit.D_premier;

	while(D_courant!=NULL && Sit.D_courant!=NULL){
		if (Sit.rechercher_Document(Sit.D_courant->cle)&& rechercher_Document(this->D_courant->cle)){
			/*copier dans le site I -->intersection des 2 sites*/
			D_tmp=D_courant;
			D_tmp->suivant=I.D_premier;
			I.D_premier=D_tmp;
			

		}
		/*passe au suivant*/
		D_courant=D_courant->suivant;
	}
  return I;

}


Site :: Site (Site & S){
    cout<<"Appel du  constructeur de recopie "<<endl;
	S_longueur=S.S_longueur;
	S.D_courant=S.D_premier;
	while(S.D_courant!=NULL){
		/*recupere Document */
		Document * D_tmp=creer_Document(S.D_courant->cle,S.D_courant->titre,S.D_courant->max_mots);
		for(int i=0;i<S.D_courant->nb_mots;i++)
			D_tmp->mots_cles[i]=S.D_courant->mots_cles[i];
		/*chainage Document */
		D_tmp->suivant=D_premier;
		D_premier=D_tmp;
		/*passe au suivant */
		D_courant=D_courant->suivant;
	}

}

void Site :: ajouter_mot(int i,const char * mot){
	D_courant=D_premier;
	while (D_courant!=NULL&& D_courant->cle!=i)
		  D_courant=D_courant->suivant;

		if (D_courant!=NULL)
		{
			/* code */
			D_courant->ajouter_mot(mot);
		}

}

void Site:: afficher_Site(){
	D_courant=D_premier;
	if (D_courant==NULL)  cout<< "Site vide"<<endl;
	while(D_courant!=NULL){
		D_courant->afficher_Document();
		D_courant=D_courant->suivant;
	}
} 


Site& Site:: operator =(Site & S){
	cout<<"Appel de l operator ="<<endl;
	if (this==&S)  
	
	{
	  	/* code */
		return *this;	
	}
	/*liberation de l ancier espace*/
	if (D_premier!=NULL){
 		while (D_premier!=NULL){
 			D_courant=D_premier;
 			D_premier=D_courant->suivant;
 			 detruire_Document(D_courant); 
 		}
 	}
    /*copier des donnes*/
    S_longueur=S.S_longueur;

    while(S.D_courant!=NULL){
		/*recupere Document */
		Document * D_tmp=creer_Document(S.D_courant->cle,S.D_courant->titre,S.D_courant->max_mots);
		for(int i=0;i<S.D_courant->nb_mots;i++)
			D_tmp->mots_cles[i]=S.D_courant->mots_cles[i];
		/*chainage Document */
		D_tmp->suivant=D_premier;
		D_premier=D_tmp;
		/*passe au suivant */
		D_courant=D_courant->suivant;
	}
    
    return *this;

}
