import java.text.DateFormat;
import java.text.ParseException;
import java.util.Date;
import java.text.SimpleDateFormat;  

class Produit_Informatique{

    private String reference;
    private String marque;
    private double prix;
    private DateFormat df;
    private Date date;

    Produit_Informatique(String ref, String mar, double prix, String une_date){
        reference = ref;
        marque = mar;
        this.prix = prix;
        df = new SimpleDateFormat("dd/MM/yyyy");
        try{
           date = df.parse(une_date);
        }
        catch(ParseException e){
            e.printStackTrace();;
        }
    }


    public String reference(){
        return reference;
    }

    public void reference(String autre){
        reference = autre;
    }

    public String marque(){
        return marque;
    }

    public void marque(String autre){
        marque = autre;
    }

    public double prix(){
        return prix;
    }

    public void prix(double autre){
        prix = autre;
    }

    public String date(){
        return df.format(date);
    }

    public void date(String autre){
        try{
            date = df.parse(autre);
         }
         catch(ParseException e){
             e.printStackTrace();;
         }
    }

    public void afficher(){
        System.out.printf("Produit informatique de marque %s, de reference %s, de prix %.2f et de date %s\n", 
        marque, reference, prix, date());
    }


}