class Point
{ public Point (int x, int y)
{ this.x = x ; this.y = y ;
}
public void deplace (int dx, int dy)
{ x += dx ; y += dy ;
}
public void affiche ()
{ System.out.println ("Je suis en " + x + " " + y) ;
}
private int x, y ;
}

class Pointcol extends Point
{ public Pointcol (int x, int y, byte couleur)
	{ super (x, y) ;
	// obligatoirement comme première instruction
	this.couleur = couleur ;
	}
public void affiche ()
	{ super.affiche() ;
	System.out.println (" et ma couleur est : " + couleur) ;
	}
private byte couleur ;
}


/*public class Poly
{ public static void main (String args[])
	{ 	Point p = new Point (3, 5) ;
		p.affiche() ; // appelle affiche de Point
		Pointcol pc = new Pointcol (4, 8, (byte)2) ;
		p = pc ;
		// p de type Point, reference un objet de type Pointcol
		p.affiche() ; // on appelle affiche de Pointcol
		p = new Point (5, 7) ; // p reference a nouveau un objet de type Point
		p.affiche() ; // on appelle affiche de Point
	}

}*/



public class TabHeter
{ public static void main (String args[])
	{	 Point [] tabPts = new Point [4] ;
		tabPts [0] = new Point (0, 2) ;
		tabPts [1] = new Pointcol (1, 5, (byte)3) ;
		tabPts [2] = new Pointcol (2, 8, (byte)9) ;
		tabPts [3] = new Point (1, 2) ;
		for (int i=0 ; i< tabPts.length ; i++) tabPts[i].affiche() ;
	}
}