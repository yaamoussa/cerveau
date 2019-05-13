public class EnumLire
{ public static void main (String args[])
	{ String chJour ;
		System.out.print("Donnez un jour de la semaine : ");
		chJour = Clavier.lireString () ;
		{
		// première démarche : provoque une exception si la valeur de chJour
		//ne représente pas une valeur de type Jour
		Jour courant = Jour.valueOf (chJour) ;
		// ou : Jour courant = Enum.valueOf (chJour) ;
		int numJour = courant.ordinal();
		System.out.println("Methode 1 : " + courant + " est le jour de rang "
		+ numJour);
		// deuxième démarche
		for (Jour j : Jour.values())
			{ if (chJour.equals(j.toString() ) )
				{ numJour = j.ordinal() ;
				System.out.println("Methode 2 : " + courant
				+ " est le jour de rang " + numJour);
				}
			}
		}
	}
}
enum Jour { lundi, mardi, mercredi, jeudi, vendredi, samedi, dimanche }