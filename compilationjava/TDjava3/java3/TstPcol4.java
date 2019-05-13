class Point{
    private int x;
    private int y;

    public Point(int abs, int ord){
        x = abs;
        y = ord;
    }

    public void afficher(){
     System.out.println("Point[" + x + ", " + y + "]");
    }
 /*   public String toString(){
        return "Pont [" + x+","+y+"]";
    }*/
    public boolean equals(Point a)
    {
        return x==a.x && y==a.y;
    }
}

class PointColor extends Point{
    private String couleur;
   
    public PointColor(int abs,int ord ,String couleur){
        super(abs,ord);
        this.couleur=couleur;
    }

    public String getCouleur(){
        return couleur;
    }

    public void afficher(){
         super.afficher();
        System.out.println("de :" + couleur + "]");       
    }
    public String toString(){
        return super.toString()+couleur;
    }
    public boolean equals(PointColor a)
    {
        return equals(a) +couleur==a.couleur;
    }
}

public class TstPcol4
{ public static void main (String args[])
    { Point p = new Point(0, 0);
      PointColor pc = new PointColor (10, 5, "jaune");
      //p.afficher();
        pc.afficher();
        p=pc;
        p.afficher();
      //Object o=p;
    /*    String chaine=o.toString();
     //  p.getCouleur();
      // ((PointColor) p).getCouleur();
      // ((Point) pc).afficher();
       System.out.println(p);
       System.out.println(o);
       System.out.println(chaine);
       System.out.println ("p = " + p.toString()) ;
     //   System.out.println(pc);
      System.out.println ((new Point(10, 10)).equals(new Point(10, 10)));*/
    Point p1 = new PointColor (0, 0, "rouge");
    Point p2 = new PointColor (0, 0, "rouge");
    System.out.println("p1 égal à p2 ? " + p1.equals(p2));
    System.out.println("p1 égal à p2 ? " +  p2.equals((Object) p2));//ici equals se contente de comparerer seulement les adresses
    }
}

    

