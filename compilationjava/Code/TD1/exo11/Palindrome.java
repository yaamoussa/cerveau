import java.util.Scanner;


class Palindrome{
	private static Scanner keyb = new Scanner(System.in);

	public static boolean cmpCharAt(String s, int i, int j){
		if(s.charAt(i) == s.charAt(j))
			return true;
		else
			return false;
	}

	public static boolean palin(String s){
		int i = 0, j = s.length()-1;
		while(j >= 0){
			if(s.charAt(i) == s.charAt(j)){
				i++;
				j--;
			}
			else
				return false;
		}
		return true;
	}

	public static boolean palinRec(String s, int i, int j){
		if(i == j)
			return true;
		if(!cmpCharAt(s, i, j))
			return false;
		if(i < s.length() && j >= 0)
			palinRec(s, i+1, j-1);
		return true;
	}

	 public static void main(String[] args) {
	 	if(args.length > 0){
	 		for(String s : args){
	 			if(palin(s))
					System.out.println(s + "  est un palindrome");
				else
					System.out.println(s + " n'est pas un palindrome");
	 		}
	 	}
	 	else{
	 		String response;
	 		System.out.println("Entrez un mot pour tester si c'est un palindrome ou q pour quitter");
	 		do{
	 			System.out.print("Un mot : ");
	 			response = keyb.nextLine();
	 			response = response.intern();
	 			if(response.equals("q"))
	 				break;
	 			
	 			if(palin(response))
					System.out.println(response + "  est un palindrome");
				else
					System.out.println(response + " n'est pas un palindrome");

	 		}while(response != "q");
	 	}
	}
}