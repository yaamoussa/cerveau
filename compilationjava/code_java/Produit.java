public class Produit{
	private String nom;
	private double prix;
	private int nb_jour_restant;

	public Produit(String nom,double prix,int nb_jour_restant){
		this.nom = nom;
		this.prix = prix;
		this.nb_jour_restant = nb_jour_restant;

	}
	
	public String getNomProduit(){
		return this.nom;
	}
	public double  getPrixProduit(){
		return this.prix;
	}

	public int  getNbJourRestantProduit(){
		return this.nb_jour_restant;
	}
	
	public void afficherProduit(){
		System.out.printf("\n------------------------------------------------------\n");
		System.out.printf("NOM PRODUIT:%s\n",nom);
		System.out.printf("PRIX PRODUIT:%s\n",prix);
		System.out.printf("NB_JOUR_RESTANT PRODUIT:%d \n",nb_jour_restant);
		System.out.printf("\n------------------------------------------------------\n");
	}

}


