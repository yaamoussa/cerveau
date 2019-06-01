package image;
// Comparables par leur taille
// ON RAJOUTE UNE CLASSE TRIANGLE SANS DEVOIR MODIFIER LA CLASSE IMAGE
public class Triangle extends Forme {
private double base;
private double hauteur ;
public Triangle(double base, double hauteur) {
this.base = base;
this.hauteur= hauteur;
}
public double size() {
return .5 * (base*hauteur);
}
@Override
public String toString() {
return "Triangle [taille =" + this.size() + "]";
}
}