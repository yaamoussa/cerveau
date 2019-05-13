public class PileEntrepot{
	private final static int taille_max = 100;
	private int taille_reelle;
	public Produit tab[];

	public PileEntrepot(){
		tab = new Produit[taille_max];
		taille_reelle = 0;
	}

	public int  getTaille(){
		return taille_reelle;
	}
	public boolean PileEntrepotVide(){
		return(this.taille_reelle == 0);
	}
	public void empile(Produit p){
	
		if(taille_reelle < taille_max){
			tab[taille_reelle] = p;
			taille_reelle++;
		}
		else 
			System.out.println("Pile pleine\n");
		}


	public Produit depile(){
		Produit s ;
		if(taille_reelle > 0){
			s=tab[taille_reelle-1];
			taille_reelle = taille_reelle-1;
			return s;
		}
		else
			return null;

	}
	public boolean appartient(Produit p){
	if(taille_reelle==0) return false;
	int i = 0;
	while (i < taille_reelle  && tab[i] != p){
		i++;
	}
	if (i >= taille_reelle)
		return false;
	else
		return true;

	}

	public Produit sommet(){
		 return(tab[taille_reelle-1]);
		
	}

	public void afficherPileEntrepot(){
		for (int i = taille_reelle-1; i >=0;i--){
			tab[i].afficherProduit();
		}
		
	}


}