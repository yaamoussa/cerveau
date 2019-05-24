
#include <iostream>
#include "Phase.h"
 
pPhase NewPhase(int tmp){
    pPhase  NPhase=new Phase;
    if (NPhase!=NULL){
    NPhase->tpExecution=tmp;
    NPhase->suiv=NULL;
    return NPhase;
    }
    else return NULL;
}
 // NewPhase(){}
pPhase NewPhase(int id,int tmp ,int prio){
    pPhase  NPhase=new Phase;
    if (NPhase!=NULL){
    NPhase->tpExecution=tmp;
    NPhase->id=id;
    NPhase->priorite=prio;
    NPhase->suiv=NULL;
    return NPhase;
    }
    else return NULL;
}
bool File :: filevide(){
    return tete==NULL;
} 
File ::  File ()
{}

File :: ~File(){
      if (!filevide()){
          while(!filevide()){
            Phase *tmp=tete;
            tete=tmp->suiv;
            delete tmp;
          }

      }

} 


int File::emfile_enqueue( int tmpEx)
{
    int rp=-1;
     pPhase p_nouveau=NewPhase(tmpEx);
    if (  p_nouveau!= NULL)
    {
        if (!filevide())
        {
            tete=p_nouveau;
            queue=p_nouveau;

        }
        else
        {
            queue->suiv=p_nouveau;
        }

        rp=0;
    }

    return rp;
}



pPhase File:: defile_tete()
{   
    pPhase tmp=NULL;
    
    /* On teste si la file n'est pas vide. */
    if (!filevide())
    {
        tmp=tete;
        tete=tmp->suiv;
    }
    return tmp;
}


void File :: affiche()
{    pPhase courant=tete;
    if ( courant!=NULL)
    {
        /* code */
        printf("%d\n", courant->tpExecution);
    }
    while ((!filevide() )&& (courant=courant->suiv))
    {
        printf("%d\n",courant->tpExecution);
 
    }
}



TabPhase:: TabPhase (int taille){
     max=taille;
     tab=new NewPhase[taille];
     nbPh=0;

}

TabPhase :: ~TabPhase(){
    if (tab)
         delete [] tab
}