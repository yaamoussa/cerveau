class Animaux extends Animal
{   
	private Animal []parc;
	private int t_max;
	private int t_reelle;

	public Animaux (int taille){
		t_max=taille;
		parc[]=new Animal[taille];
		t_reelle=0;
	}
	public void creerAnimal( Animal A){
		if (t_reelle<t_max){  
			parc[t_reelle];
			  t_reelle++;
			}
			 
                
	}

	public void afficher_animaux(){
		if (t_reelle==t_max)
			  {
			  	for(Animal A:parc)
			  		A.affiche();
			  }
		else for (int i=0;i<parc.length;i++)
		             parc[i].affiche();

	}



}