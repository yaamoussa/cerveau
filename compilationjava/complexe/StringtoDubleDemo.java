import java.util.Arrays;
import java.util.List;


/**
 * Java Program to convert String to double in Java and vice-versa.
 *
 * @author WINDOWS 8
 */

public class StringToDoubleDemo{
 
 
    public static void main(String args[]){
     
        // let's first start converting String to double
        // there are three ways to convert a String to double in Java
        // parseDouble(), valueOf() and Double() constructor
     
        // Using parseDouble() to parse String to double in Java
        String number = "6.24";
        double d = Double.parseDouble(number);
        System.out.println("String " + number +" is parse to double value : " + d);
     
     
        // now let's use Double.valueOf() method to get double from String
        String str = "8.23";
        double value = Double.valueOf(str);
        System.out.println("String to double conversion using valueOf : " + value);
     
     
        // another way is by using Double wrapper class constructor
        // though it will return Double value, autoboxing will convert
        // it to double primitive value
        String floating = "122.44";
        double converted = new Double(floating);
        System.out.println("Double value " + converted + " created from String " + floating );
     
     
        // Now let's do opposite by converting a double value to String in Java
        // again there are three way to get a String value from double
        // by String concatenation, valueOf() and toString() method
     
        // Simplest way to convert a double to String
        double pie = 3.14;
        String parsed = "" + pie;
        System.out.println("Double value : " + pie + " String value : " + parsed);
     
        // you can also use String.valueOf() to convert double to String
        double myValue = 88.22;
        String doubled = String.valueOf(myValue);
        System.out.println("Double value " + myValue + " converted to String : " + doubled);
     
        // another way to get String from double is by using Double.toString() in Java
        Double code = new Double(5543.3);
        String decode = code.toString();
        System.out.println("double : " + code + " String : " + decode);
    }
 
}


