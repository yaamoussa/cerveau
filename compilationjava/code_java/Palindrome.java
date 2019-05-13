
public class Palindrome{
	public static boolean cmpCharAt(String s,int i, int j){
		if(s.charAt(i) == s.charAt(j))
			return true;
		else
			return false;
	}

	public static boolean palin(String s){
		int i = 0;
		int n=s.length()-1;
		while(i < s.length()){
			if(!cmpCharAt(s,i,n))
				return false;
			i++;
			n=n-1;
		}
		return true;
	}

	public static boolean palinRec(String s, int i,int j){
		if(i == j )
			return true; 
		if(!cmpCharAt(s,i,j))
				return false;
		if(i < s.length())
			palinRec(s, i+1, j-1);
		return true;
	}

	 public static void main(String[] args) {
	
		/*boolean b = palin(args[0]);
		if(b == true)
			System.out.println("palindrome");
		else
			System.out.println("not palindrome");*/
		int i = Integer.parseInt(args[1]);
		int j = Integer.parseInt(args[2]);

		boolean b = palinRec(args[0],i,j);
		if(b == true)
			System.out.println("palindrome");
		else
			System.out.println("no palindrome");
	 	
		
	}
}