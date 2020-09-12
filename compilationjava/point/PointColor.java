public class PointColor extends Point{
private String couleur;
public PointColor (int abs,int ord,String color)
{
	super(abs,ord);
	couleur=color;
}
public String getCouleur (){ return couleur; }
public void afficher (){ super.afficher();
                      System.out.println(" de couleur "+couleur);
       }
}


