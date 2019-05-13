class Point{
    private int x;
    private int y;

    public Point(int abs, int ord){
        x = abs;
        y = ord;
    }
/*
    public void afficher(){
        System.out.println("Point[" + x + ", " + y + "]");
    }*/

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
        // super.afficher();
        System.out.println("de :" + couleur + "]");       
    }
}

public class TstPcol4
{ public static void main (String args[])
    { Point p = new Point(0, 0);
      PointColor pc = new PointColor (10, 5, "jaune");
      //  p.afficher();
        pc.afficher();
        p=pc;
     //   p.getCouleur();
        ((PointColor) p).getCouleur();
     //   ((Point) pc).afficher();
    }
}

    

