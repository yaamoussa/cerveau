import java.util.Scanner;
import java.util.Calendar;


public class Date{		

	public static String getCurrentDate(){
		String[] mois = {"Janvier", "Fevrier","Mars","Avril","Main","Juin","Juillet","Aout","Septembre",
							"Octobre","Novembre","Decembre"};
		String[] jour = {"Dimanche","Lundi","Mardi","Mercredi","Jeudi","Vendredi","Samedi"};
		
		Calendar c = Calendar.getInstance();
		int i = c.get(Calendar.MONTH);
		int j = c.get(Calendar.DAY_OF_WEEK);
		int k = c.get(Calendar.YEAR);
		int n = c.get(Calendar.DAY_OF_MONTH);

		String s1 = Integer.toString(j);
		String s2 = Integer.toString(k);

		String chaine = jour[j-1]+","+n+" "+mois[i]+" "+s2;

		return chaine;			
		}

		public static void main(String[] args) {
				System.out.println(getCurrentDate());
	}

	

}