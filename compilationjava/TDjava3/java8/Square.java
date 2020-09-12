package image;
public class Square extends Rectangle {
public Square(double largeur) {
super(largeur, largeur);
}
@Override
public String toString() {
return "Carre [taille =" + this.size() + "]";
}
}