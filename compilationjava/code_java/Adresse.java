  public class Adresse{

	 public static boolean isAdresseIp(String chaine){
		String tab[];
		tab = chaine.split("\\.");
		if(tab.length == 4){
			int i=0;
			while(i<tab.length){
				String parse=tab[i];
				int j = 0;
				while(j<parse.length()){
					if((Character.isDigit(parse.charAt(j))))
						j++;
				}
				if(j >= tab[i].length())
					i++;
			}
				if(i >=tab.length)
					return true;
				else return false;
		}
		else return false;
	}
			
public static void main(String[] args) {
	 boolean b = isAdresseIp("212.85.134.152");
	if (b == true)
		System.out.println("c'est une adresse ip");
	else
		System.out.println("non");
}

	
}