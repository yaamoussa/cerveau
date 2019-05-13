import java.util.Scanner;
import java.util.Calendar;

public class Calendrier{
	
public static void main(String[] args) {
	String[] mois = {"Janvier", "Fevrier","Mars","Avril","Main","Juin","Juillet","Aout","Septembre",
						"Octobre","Novembre","Decembre"};
	String[] jour = {"Dimanche","Lundi","Mardi","Mercredi","Jeudi","Vendredi","Samedi"};
	String nom;
	String prenom;
	Scanner keyb= new Scanner(System.in);
	Calendar c = Calendar.getInstance();
	System.out.println("Quel est votre nom ?");
	nom = keyb.nextLine();
	System.out.println("Quel est votre prénom");
	prenom = keyb.nextLine();
	//System. out.println("Bonjour "+ prenom+" "+ nom +" "+"bienvenu!");
	//System.out.println("on est le "+ c.get(Calendar.DATE) + c.get(Calendar.MONTH)+ c.get(Calendar.YEAR));
	//System.out.println("il est "+ c.get(Calendar.HOUR_OF_DAY) +"h "+ c.get(Calendar.MINUTE)+"mn " 
	//	+c.get(Calendar.YEAR));
	int i = c.get(Calendar.MONTH);
	int j = c.get(Calendar.DAY_OF_WEEK);
	System. out.println("Bonjour "+ prenom+" "+ nom +" ,il est "+c.get(Calendar.HOUR_OF_DAY) +"h "
		+ c.get(Calendar.MINUTE)+" et nous sommes le "+jour[j-1]+ " "+ j+" " +mois[i] + " "+
		c.get(Calendar.YEAR));

			
		}		
}
