public class Entier{

	public static int charToInt(char t){
		if(t =='0' ||t =='1' ||t =='2' ||t =='3' ||t =='4' ||t =='5' ||t =='6' ||t =='7' ||t =='8' ||t =='9'){

			return t-'0';
		}
		else 
			return -1;

	}

   public static int toPositiveInt(String s){
   		int t = s.length();
   		int chiffre,result=0;
   		 int base = (int)Math.pow(10,t-1);
   		for(int i = 0;i<t;i++){
   			chiffre = charToInt(s.charAt(i));
   			result = result + chiffre*base;
   			base=base/10;
   		}
   		return result;

}

	public static void main(String[] args) {
		toPositiveInt("135");
	
}
}