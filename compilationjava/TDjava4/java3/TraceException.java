class E1 extends Exception {
public E1(String mess) { super(mess); }
}
class E2 extends Exception {
public E2(String mess) { super(mess); }
}

public class TraceException {
	private double x;
	public TraceException (double x) { this.x = x; }
	public double getX() { return x; }
	public void methode1 (double y) throws E2, E1 {
		System.out.println("Debut de methode1");
		if (y == 0)
		throw new  E1("Parametre de methode1 null");
		if (x * y < 0)
		throw new E2("Parametre de signe  opposé à l'attribut");  
		  x = x / y;
		System.out.println("Fin de methode1");
	}

	public void methode2 (double y)  {
		System.out.println("Début de methode2");
		try {System.out.println("Dans methode2 avant appel de methode1"); 
		  	methode1 (y);
			System.out.println("Dans methode2 apres appel de methode1");
		   
		}
		catch (E2 excpt){
				System.out.println(excpt.getMessage());
		}
	/*	catch (E1 excpt){
				System.out.println(excpt.getMessage());
		}
		catch (E1 excpt){
				throw excpt;
		}*/
		System.out.println("Fin de methode2");
	
	}
	
	public static void main(String[] args) throws E1 {
		System.out.println("Debut du main");
		TraceException te = new TraceException
		(Double.parseDouble(args[0]));
		te.methode2(Double.parseDouble(args[1])
		);
	/*	try {
			te.methode1(2);
			java.net.URL url = new java.net.URL("");
		}
			catch (Exception e){}
			catch (E1 e1){}
			catch (E2 e2){}
		
		on obtiendrait une erreur de compilation due à ce que le gestionnaire E2 n’a plus
          désormais aucune chance d’être atteint.
         try {
			te.methode1(2);
			java.net.URL url = new java.net.URL("");
		}
			catch (E1 e1){}
			catch (E2 e2){}
			catch (Exception e){}
		/*on aucun probleme */

		System.out.println("x = " + te.getX());
		
	System.out.println("fin du main");
	     
		
	}
}