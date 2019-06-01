package image;
import java.util.List;
import java.util.Collections;
public class Utilisation{
public static void main(String args[]) {
Utilisation.test();
}
public static void test()
{
Image image = new Image();
image.addItem(new Rectangle(4,5));
image.addItem(new Rectangle(6,7));
image.addItem(new Square(6));
image.addItem(new Triangle(12,8));
System.out.println("TOUT LE MONDE AFFICHE SA TAILLE!");
image.sizeAllItems();
System.out.println("\n \n ON COMPARE SA TAILLE 2 A 2!");
image.compareToAllItems();
List <Forme> items = image.getItems();
Collections.sort(items);
for(Forme item : items)
System.out.println(item);
}
}
