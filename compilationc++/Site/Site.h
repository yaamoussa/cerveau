#ifndef SITE_H_INCLUDED
#define SITE_H_INCLUDED


struct Document {
	int cle ;
	char * titre;
	int max_mots;
	int nb_mots;
	char ** mots_cles; 
	Document *suivant;
	void ajouter_mot(const  char *);
	void afficher_Document();
};


Document * creer_Document(int ,const char*,int nb=0 );
void detruire_Document(Document*);

class Site{
	int S_longueur;
	Document * D_premier;
	Document *D_courant;

    public:
    	Site();
    	~Site();
    	void insert_Document(int,const char*,int nb=0);
    	void supprimer_Document(int);
    	bool rechercher_Document(int);
    	void ajouter_mot(int , const char *);// ajouter un mot a un document  donne
    	Site  U_Sites( Site&);
    	Site  I_Sites( Site&);
    	Site  Diff_Sites(Site & );
    	Site & operator =(Site &);
    	Site & operator <<(Document*);
    	Site & operator >> (Document *);
    	bool  operator % (Document *);
    	void afficher_Site();
    	Site (Site&);

};


/*
class  Document {
    protected:
	int cle ;
	char * titre;
	int max_mots;
	int nb_mots;
	char ** mots_cles;
	public :
	    Document();
	    ~Document();
	void ajouter_mot(char *);
	void afficher_Document();
};



class Site{
	int S_longueur;
	Document **tab;

    public:
    	Site();
    	~Site();
    	void insert_Document(int,const char*,int nb=0);
    	void supprimer_Document(int);
    	bool rechercher_Document(int);
    	void ajouter_mot(int ,const char *);// ajouter un mot a un document  donne
    	Site  U_Sites( Site&);
    	Site  I_Sites( Site&);
    	Site  Diff_Sites(Site & );
    	Site & operator =(Site &);
    	Site & operator <<(Document*);
    	Site & operator >> (Document *);
    	bool  operator % (Document *);
    	void afficher_Site();
    	Site (Site&);

};
*/



#endif

