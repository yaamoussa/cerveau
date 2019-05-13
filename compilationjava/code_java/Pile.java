public class Pile{
	private final static int taille_max = 50;
	private int taille_reelle;
	public ElementPile tab[];
	public Pile(){
		tab = new ElementPile[taille_max];
		taille_reelle = 0;
	}
	public boolean PileVide(){
		return(this.taille_reelle == 0);
	}
	public void empile(int x){
		ElementPile el = new ElementPile(x);
		if(taille_reelle < taille_max){
			tab[taille_reelle] = el;
			taille_reelle++;
		}
		else 
			System.out.println("Pile pleine\n");
		}


	public ElementPile depile(){
		ElementPile s;
		if(taille_reelle > 0){
			s=tab[taille_reelle-1];
			taille_reelle = taille_reelle-1;
			return s;
		}
		else
			return null;

	}

	public ElementPile sommet(){
		return(tab[taille_reelle-1]);
	}

	public void afficherPile(){
		System.out.printf("Pile=[");
		for(int i = 0;i < taille_reelle-1; i++){
			tab[i].afficher();
			System.out.printf(",");

		}
		tab[taille_reelle-1].afficher();
		System.out.printf("]");
		System.out.println("\n");
	
}
	public static void main(String[] args) {
		Pile p = new Pile();
		p.empile(12);
		p.empile(5);
		p.empile(15);
		p.empile(100);
		p.afficherPile();
		p.depile();
		p.empile(200);
		p.afficherPile();

		ElementPile s = p.sommet();
		System.out.println(s.getElement());

	}


}