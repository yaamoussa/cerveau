package image;
// Comparables par leur taille
public class Rectangle extends Forme {
private double largeur ;
private double longueur ;
public Rectangle(double largeur, double longueur) {
this.largeur = largeur;
this.longueur = longueur;
}
public double size() {
return largeur*longueur;
}
}
@Override
public String toString() {
return "Rectangle [taille =" + this.size() + "]";
}