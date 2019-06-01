#include <iostream>
#include "Phase.h"


int Phase:: gettmp(){
    return tpExecution;
}
int Phase:: getid(){
    return id;
}
int Phase :: gettsm(){
    return tsoumis;
}

int  Phase:: getprio(){
    return priorite;
}

void Phase :: settmp(int tmp)
{
    tpExecution=tmp;
}


pPhase  NewPhase(int id,int tmp,int tsm ,int prio){
    pPhase  NPhase=new Phase;
    if (NPhase!=NULL){
    NPhase->tpExecution=tmp;
    NPhase->id=id;
    NPhase->priorite=prio;
    NPhase->suiv=NULL;
    NPhase->tsoumis=tsm;
    return NPhase;
    }
    else return NULL;
}

bool File :: filevide(){
    return tete==NULL;
} 

File ::  File ()
{
    // vide
}

File :: ~File(){
      if (!filevide()){
          while(!filevide()){
            Phase *tmp=tete;
            tete=tmp->suiv;
            delete tmp;
          }

      }

} 


int File::emfile_enqueue( int id,int tmpEx,int tsm,int prio)
{
    int rp=-1;
     pPhase p_nouveau= NewPhase(id,tmpEx,tsm,prio);
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
