import java.util.Calendar;
import java.util.Scanner;

class Calendrier{
	private static Scanner keyb = new Scanner(System.in);

	public static String theMonth(int month){
    	String[] monthNames = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin",
    		 "Julliet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
    	return monthNames[month];
	}

	public static String theDay(int day){
    	String[] dayNames = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"};
    	return dayNames[day];
	}

	public static void main(String[] args){
		String prenom, nom, month, day_of_week;
		int year, day, heure, minute;
		System.out.print("Quel est votre prenom : ");
		prenom = keyb.nextLine();
		System.out.print("Quel est votre nom : ");
		nom = keyb.nextLine();
		Calendar calendar = Calendar.getInstance();
		year = calendar.get(Calendar.YEAR);
		month = theMonth(calendar.get(Calendar.MONTH));
		day = calendar.get(Calendar.DATE);
		day_of_week = theDay(calendar.get(Calendar.DAY_OF_WEEK) - 1);
		heure = calendar.get(Calendar.HOUR_OF_DAY);
		minute = calendar.get(Calendar.MINUTE);

		System.out.println("Bonjour " + prenom +  " " + nom + ", il est " + heure + "h" + minute + " et nous sommes le " + day_of_week + 
			" " + day + " " + month + " " + year + ".");
	}
}