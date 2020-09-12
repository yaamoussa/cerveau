typedef struct Phase
{
	int tpExecution;
	int priorite;
	int id;
	int tsoumis;
   struct Phase *suiv;

  int getid();
  int gettmp();
  int gettsm();
  int getprio();
  void settmp(int );
} *pPhase;

pPhase NewPhase(int id,int tmp,int tsm=0,int prio=0);
//pPhase NewPhase();

class  File{
	 pPhase  tete;
	 pPhase  queue;	
	 public :
	  File ();
	  ~File();
	  bool filevide();
	  int emfile_enqueue(int id,int tmpEx,int tsm=0,int prio=0);
	  pPhase  defile_tete();
	  void affiche();

};



	

