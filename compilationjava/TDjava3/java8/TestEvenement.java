
import java.lang.Comparable;
class TestEvenement {
	public static void main(String[] args) {
	 Evenement tabaski=new Evenement("12/7/2019","y");
	 Evenement tamkharit=new Evenement ("12/07/2019","y6");
         tamkharit.afficher();
         tabaski.afficher();
         System.out.println(tabaski.compareTo(tamkharit));
         Evenement tab[]=new Evenement[2];
     
    }
	


}