class ParseInt{
    public static void main(String[] args){
        System.out.println(toPositiveInt("102"));
    }

    public static int charToInt(char lettre){
        //return Character.getNumericValue(lettre);
        // Or
        if(lettre >= 0 && lettre <= '9')
            return lettre - '0';
        return Integer.MAX_VALUE;
    }

    public static int toPositiveInt(String s){
        int mult = (int)Math.pow(10, (s.length()-1));
        int result = 0;
        for(int i = 0; i < s.length();i++){
            int k = charToInt(s.charAt(i));
            result = result + mult * k;
            mult /= 10;
        }
        return result;
    }


}