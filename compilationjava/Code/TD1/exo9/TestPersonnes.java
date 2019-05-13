import java.util.Scanner;
public class TestPersonnes{
	private static Scanner keyb = new Scanner(System.in);
	public static void main(String[] args){
		double[] nombres = {14500, 40000};
		// double[] nombres = new double[2];
		// nombres[0] = 14500;
		// nombres[1] = 40000;
		Personne p1 = new Personne("Mouhamadou Lamine Diakhame", 24, nombres);
		Personne p2 = new Personne("Modou Ndiaye", 18, nombres);
		p1.diviserParDeux();
		p1.afficher();
		p2.afficher();
	}
}

public class TestPersonnes{
	private static Scanner keyb = new Scanner(System.in);
	public static void main(String[] args){
		Personne p1 = new Personne();
		p1.afficher();
		Personne p2 = new Personne(p1);
		p2.afficher();
		Personne p3 = new Personne("Mouhamadou Lamine Diakhame", 24);
		p3.afficher();

	}
}