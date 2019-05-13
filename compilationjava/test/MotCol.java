public class MotCol
{ public static void main (String args[])
	{ 	String mot ;
		System.out.print ("donnez un mot : ") ;
		mot = Clavier.lireString() ;
		System.out.println ("voici votre mot en colonne :") ;
		for (int i=0 ; i<mot.length() ; i++) // ou (JDK 5.0) : for (char c : mot)
		System.out.println (mot.charAt(i)) ; //	System.out.println (c) ;
		}
// (voir remarque)
}