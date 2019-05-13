class Util
{ static void raz (int t[] [])
	{ int i, j ;
		for (i= 0 ; i<t.length ; i++)
		//
		for (j=0 ; j< t[i].length ; j++)
		//
		t[i] [j] = 0 ;
	}

static void affiche (int t[] [])
	{ int i, j ;
	for (i= 0 ; i<t.length ; i++)
		{ /*System.out.print ("ligne de rang " +i + " = ") ;*/
		for (j=0 ; j<t[i].length ; j++);// pour utiliser for... each
		System.out.print (+t[i] [j] + " ");// voir paragraphe suivant
		System.out.println() ;
		}
	}
/*
static void affiche (int t[] [])
{ int i, j ;
   int numLigne = 0 ;

     for (int[] ligne : t)
        {// pour le numero de ligne
			
			System.out.print ("ligne " + numLigne++ + " = ") ;
			for (int v : ligne)
			System.out.print (v + " ") ;
			System.out.println() ;
		}
    }*/
}



public class Tab2ind1
	{ public static void main (String args[])
			{ int t[] [] = { {1, 2, 3}, {11, 12}, {21,22, 23, 24} } ;
			System.out.println ("t avant raz : ") ;
			Util.affiche(t) ;
			Util.raz(t) ;
			System.out.println ("t apres raz : ") ;
			Util.affiche(t) ;
			}
}