

public class TestBatiment
{   
	public 	static double surfaceHabitableTotale(Batiment[] tabBat){
		double surtotale=0.0;
		for (int i=0;i<tabBat.length;i++)
			    surtotale +=tabBat[i].getSurfaceHabitable();
			return surtotale;
	}
	public static double surfaceJardinTotale(Batiment[] tabBat){
		double surtotale =0.0;
		for (int i=0;i<tabBat.length;i++)
	 if ( tabBat[i] instanceof Maison)
		 	                  surtotale +=tabBat[i].getSurfaceJardin();
		 	             
		return surtotale;

	}

	public static void main(String[] args) {


	Batiment b=new Batiment("thiaroye",35555);
		//System.out.println(b);
	Maison  m=new Maison ("yeumbeul",8888,3,885);
	//System.out.println(m);
//ystem.out.println(m.getSurfaceJardin());
	Immeuble i=new Immeuble("fass mboa ",999,9);
//	System.out.println(i);
	Batiment tab [];
	tab=new Batiment[3];
	tab[0]=b;
	tab[1]=new Maison ("yeumbeul",8888,3,885); ;
	tab[2]=i;

System.out.println("**********************************");
System.out.println(tab[1].getSurfaceJardin ()); 

	/*for (int j=0;j<tab.length;j++){
	 System.out.println(	tab[j] instanceof Maison);
		// System.out.println(tab[j]);
	}*/
   System.out.println(	"surfaceJardinTotale:"+surfaceJardinTotale(tab)) ;
   System.out.println("**********************************");

	System.out.println(	"surfaceHabitableTotale	:"+surfaceHabitableTotale(tab) ) ;
	System.out.println(m.Impot(5.6,1.6) ) ;

	}
	
}