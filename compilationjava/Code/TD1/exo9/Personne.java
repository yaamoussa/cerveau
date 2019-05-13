public class Personne{
	private String nom;
	private int age;
	private double[] comptes = null;
	Personne(String leNom, int age, double[] comptes){
		System.out.println("Creation d'une nouvelle personne " + this);
		nom = leNom;
		this.age = age;
		this.comptes = comptes.clone();
	}
	public void afficher(){
		System.out.println("\n\n**********************************************************");
		System.out.println("\tNom : " + nom);
		System.out.println("\tAge : " + age + " ans");
		for(int i = 0; i  < comptes.length; i++)
			System.out.println("\tSolde compte " + (i+1) + " : " + comptes[i]);
		System.out.println("\n\n**********************************************************\n\n");
	}

	public void diviserParDeux(){
		for(int i = 0; i < comptes.length; i++)
			comptes[i] = comptes[i] / 2;
	}
}


public class Personne{
	private String nom;
	private int age;
	
	Personne(String leNom, int age){
		System.out.println("Constructeur Personne(String, int) :  " + this);
		nom = leNom;
		this.age = age;
	}

	Personne(){
		this("Mamadou", 30);
		System.out.println("Constructeur par defaut Personne() :  " + this);
	}

	Personne(Personne p){
		System.out.println("Constructeur de recopie Personne(Personne) :  " + this);
		nom = p.nom;
		age = p.age;
	}
	public void afficher(){
		System.out.println("\n\n**********************************************************");
		System.out.println("\tNom : " + nom);
		System.out.println("\tAge : " + age + " ans");
		System.out.println("\n\n**********************************************************\n\n");
	}

}


