package image;
import java.util.List;
import java.util.ArrayList;
import java.lang.Comparable;
public class Image{
List<Forme> items = new ArrayList<Forme>();
public List <Forme> getItems() {
return items;
}
public void addItem(Forme x){
items.add(x);
}
public void sizeAllItems() {
Forme item;
}
if (items.size() == 0)
System.out.println("Rien dans l'image");
else {
for (int i = 0;i < items.size();i++) {
item = items.get(i);
// on affiche la taille représenté par un double
System.out.println( item.size());
}
}
// ON COMPARE LES TAILLES 2 à 2
public void compareToAllItems() {
Forme item1, item2;
if (items.size() == 0)
System.out.println("Rien dans l'image");
else {
for (int i = 0;i < items.size() -1;i++) {
item1 = items.get(i);
item2 = items.get(i+1);
// ON COMPARE LES TAILLES 2 à 2
int resultat = item1.compareTo(item2);
switch(resultat)
{
case -1: System.out.println(item1.toString() + "<" +
item2.toString() ); break;
case 0: System.out.println(item1.toString() + "=" +
item2.toString() ); break;
case 1: System.out.println(item1.toString() + ">" +
item2.toString() ); break;
default: System.out.println("LE PIRE EST ARRIVE!"); break;
}
}
}
}
}