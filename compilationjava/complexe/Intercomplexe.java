public class Intercomplexe {
  public static void main(String[] args) {

	Complexe a = new Complexe(3.0,2.0); // Nombre complexe 3+2i
	Complexe b = new Complexe(1.0,-4.0);// nombre complexe 1-4i
	Complexe z = new Complexe("(2;4)"); 
/*	System.out.println("Za="+a); // On affiche a en utilisant a.toString()
	
	System.out.println("Zb="+b); // On affiche b en utilisant b.toString()

*/
	   a.affiche();
	   b.affiche();
	   z.affiche();

	Complexe sum1 = b.add(a); // ajoute a à b
	Complexe sum2=Complexe.add(a,b);
        
	System.out.println("Za+Zb="+sum1); // On affiche la somme
    System.out.println("za+zb ="+ sum2);
	Complexe product1 = b.multiply(a); // b * a
	Complexe product2=Complexe.multiply(b,a);
   	System.out.println("Zb*Za="+product1);
   	System.out.println("Zb*Za="+product2);
	a.conjugate(); // Complexe conjugé de a
	System.out.println("Conjugé de Za="+a);
	System.out.println("module de a ="+ a.module());
	//System.out.println("module de a ="+ Complexe.module(a));
	System.out.println("argument de a ="+ a.argument());
	System.out.println("argument de a ="+ Complexe.argument(a));


	}
}
// Ci-dessous à mettre dans un autre fichier intitulé Complex.java