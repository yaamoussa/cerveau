import java.util.Scanner;


class IsIpAddress{
    private static final int _0 = 0;
    private static Scanner keyb = new Scanner(System.in);

    public static void main(String[] args) {
        String rep;
        while (true) {
            System.out.print("Une adresse ip : ");
            rep = keyb.nextLine();
            //rep = rep.intern();
            if (rep.equals("fin"))
                break;
            if (isIp(rep) == true)
                System.out.println(rep + " est une adresse ip valid");
            else
                System.out.println(rep + " n'est pas une adresse ip valid");
        }

    }

    public static boolean hasThreeDots(String ip) {
        int i = 0;
        for (int j = 0; j < ip.length(); j++)
            if (ip.charAt(j) == '.')
                i++;
        if (i == 3)
            return true;
        return false;
    } 

    public static boolean startsAndEndsWithNumber(String ip) {
        String number1 = "", number2="";
        int len = ip.split("\\.").length;
        String[] tab;
        if(len >=0 && len < 5){
            tab = ip.split("\\.");
            number1 = tab[0];
            number2 = tab[len-1];
        }

        try{
            int num = Integer.parseInt(number1);
        }catch(NumberFormatException e){
            return false;
        }

        try{
            int num = Integer.parseInt(number2);
        }catch(NumberFormatException e){
            return false;
        }
        return true;
    }

    public static boolean isDigit(char d){
        char[] digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for(int i = 0; i < digits.length; i++)
            if(d == digits[i])
                return true;
        return false;
    }

    public static boolean testDigit(String ip){
        String[] tab = ip.split("\\.");
        int j;
        for(int i = 0; i < tab.length; i++){
            j = 0;
            while(j < tab[i].length()){
                if(isDigit(tab[i].charAt(j)) == false)
                    return false;
                j++;
            }
        }
        return true;
    }

    public static boolean isIp(String ip){
        if(hasThreeDots(ip) && startsAndEndsWithNumber(ip))
            if(testDigit(ip))
                return true;
        return false;
    }
    
}