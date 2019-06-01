import java.util.*;
import java.text.*;

class Evenement implements Comparable <Evenement>
{	private Date date;
	private  String description;
    public  Evenement (String une_date,String des){
    	  description=des;
    	//convertis string to date
    SimpleDateFormat df = new SimpleDateFormat("dd/MM/yyyy");
        try{
           date = df.parse(une_date);
        }
        catch(ParseException e){
            e.printStackTrace();;
        }
    }
	public  int compareTo(Evenement x){
           int rp=0;
            if (date.compareTo(x.date)==0) {
            	if (description.compareTo(x.description)==0) 
            		rp= 0;
            	
            	if (description.compareTo(x.description)>0) 
            		rp= 1;
            	

            	if (description.compareTo(x.description)<0) 
            		rp= -1;
            	

            	
            	
            }
         else{ 
            if (date.compareTo(x.date)>0)
            	rp=1;
            

            if (date.compareTo(x.date)<0) 
            	rp= -1;
        }
            return rp;


	}

    public void afficher (){
    	System.out.println("cet evenment"+description);
    	SimpleDateFormat df=new SimpleDateFormat("dd/mm/yyyy");
    	System.out.println("sera fete le"+df.format(date));
    }
     
}