package image;
// LA CLASSE FORME EST ABSTRAITE CAR ELLE N'A PAS DEFINIE LA METHODE size()
// DE L'INTERFACE MEASURABLE
public abstract class Forme implements Comparable<Forme>{
/** @return -1, 0, 1 if this is <, = or > than x */
public int compareTo(Forme x) {
if (this.size() < x.size()) {
return -1 ;
}
if (this.size() > x.size()) {
return 1 ;
}
return 0 ;
}
}