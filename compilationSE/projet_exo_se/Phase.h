typedef struct Phase
{
	int tpExecution;
	int priorite;
	int id;
   struct Phase *suiv;

} *pPhase;


pPhase NewPhase(int id,int tmp ,int prio);
pPhase NewPhase(int tmp);
//pPhase NewPhase();

class  File{
	 pPhase  tete;
	 pPhase  queue;	
	 public :
	  File ();
	  ~File();
	  bool filevide();
	  int emfile_enqueue(int tmpEx);
	  pPhase  defile_tete();
	  void affiche();

};


class TabPhase
{   int max;
	int nbPh;
	pPhase tab;

public:
	 TabPhase(int);
	~TabPhase();
	
};


