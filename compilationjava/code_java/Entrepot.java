import java.util.Scanner;

public class Entrepot{
	private PileEntrepot ensproduit;
	private int nb_produits_perimes;

	public void ConstruitEntrepot(){
		String name; 
		double prix;
		int nb_jour;
		int teste;
		Scanner clavier = new Scanner(System.in);
		nb_produits_perimes = 0;
		ensproduit = new PileEntrepot();

		do{
			System.out.printf("------------------------------------------------------\n");
			System.out.printf("               0 pour quitter\n");
			System.out.printf("               1 pour ajouter un  produit dans l'entrepot\n");
			System.out.printf("------------------------------------------------------\n");
			System.out.printf("Votre choix : ");
			teste = clavier.nextInt();
			clavier.nextLine();
			if(teste != 0){
				System.out.printf("Nom Produit : ");
				name = clavier.nextLine();
				System.out.printf("Prix du Produit : ");
				prix = clavier.nextDouble();
				System.out.printf("Nombre de jour restant Produit : ");
				nb_jour = clavier.nextInt();
				if(nb_jour<=0) nb_produits_perimes++;
				Produit p = new Produit(name,prix,nb_jour);
				ensproduit.empile(p);
				System.out.println(ensproduit.getTaille());

			}
		}while(teste!=0);
	}
		public void trier(){
			PileEntrepot B = new PileEntrepot();
			PileEntrepot C = new PileEntrepot();
				while(ensproduit.PileEntrepotVide() == false){
					Produit el = ensproduit.sommet();
					if(B.PileEntrepotVide() || el.getNbJourRestantProduit()< B.sommet().getNbJourRestantProduit()){
						B.empile(ensproduit.depile());
					while(C.PileEntrepotVide() == false)
						B.empile(C.depile());
					}
					else
						C.empile(B.depile());

				}
				ensproduit = B;
			}


	public double suppression(){
		double somme=0;
		trier();
	
		while(!ensproduit.PileEntrepotVide() && (ensproduit.sommet().getNbJourRestantProduit() <= 0)){
			somme+=ensproduit.sommet().getPrixProduit();
			ensproduit.depile();
		}
			return somme;

	}
	public Entrepot union(Entrepot e){
		Entrepot e1 = new Entrepot();
		while(!ensproduit.PileEntrepotVide() && !e.ensproduit.PileEntrepotVide()){
			if(this.ensproduit.sommet().getNbJourRestantProduit()<e.ensproduit.sommet().getNbJourRestantProduit()){
				if(!e1.ensproduit.appartient(this.ensproduit.sommet())){
					e1.ensproduit.empile(this.ensproduit.sommet());
				}
				ensproduit.depile();
			}

			else {
				if(!e1.ensproduit.appartient(e.ensproduit.sommet())){
					e1.ensproduit.empile(e.ensproduit.sommet());
				}
				e.ensproduit.depile();
			}
		}
			
		while(!e.ensproduit.PileEntrepotVide()){
				if(!e1.ensproduit.appartient(e.ensproduit.sommet())){
						e1.ensproduit.empile(e.ensproduit.sommet());
				}
				e.ensproduit.depile();
		}
		while(!ensproduit.PileEntrepotVide()){
				if(!e1.ensproduit.appartient(ensproduit.sommet())){
						e1.ensproduit.empile(ensproduit.sommet());
				}
				ensproduit.depile();
		}
			return e1;
	}

	public void afficherEntrepot(){
		ensproduit.afficherPileEntrepot();
	}
	
	public static void main(String[] args) {
		Entrepot e = new Entrepot();
		e.ConstruitEntrepot();
		e.trier();
	//	double somme = e.suppression();
	//	System.out.println("La somme est : "+somme);
	//	e.trier();
		e.afficherEntrepot();
		Entrepot e1 = new Entrepot();
		e1.ConstruitEntrepot();
		e1.trier();
		e1.afficherEntrepot();
		Entrepot e2 = new Entrepot();
		e2 = e.union(e1);
		e2.afficherEntrepot();
	}
}

