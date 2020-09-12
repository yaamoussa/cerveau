public class EnumComp
{ public static void main (String args[])
	{ Jour courant ;
	courant = Jour.mardi ;
	if (courant == Jour.dimanche)
	System.out.println ("On se repose") ;
	else System.out.println ("On bosse") ;
	if (courant.equals(Jour.dimanche)) System.out.println ("On se repose") ;
	else System.out.println ("On bosse") ;
	if (courant.compareTo (Jour.samedi) < 0)
	System.out.println ("Ce n’est pas encore le week-end") ;
	if (courant.ordinal() < 5)
	System.out.println ("on est encore en semaine") ;
	System.out.println ("rang du jour dans la semaine (lundi=1) : "
	+ (courant.ordinal()+1) ) ;
	}
}
enum Jour { lundi, mardi, mercredi, jeudi, vendredi, samedi, dimanche }