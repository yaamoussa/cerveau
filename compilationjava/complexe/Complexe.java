
import java.util.Arrays;
import java.util.List;

public class Complexe {
	private double real ;
	private double imag  ;//real, imag sont des variables d'instances



/*les constructeur de la classe*/

	public Complexe() {
	} // on utilise la valeur par défaut 0.0  + i0.0

	public Complexe(double real, double imag) {
	  this.real = real;
	  this.imag = imag;
	}


	public Complexe(String [] chaine) {

	  this.real = Integer.parseInt(chaine[0]);
	  this.imag = Integer.parseInt(chaine[1]);
	}
	public Complexe (String  chaine) {

		String tab [];
		tab=chaine.split(",");

	  this.real = Double.parseDouble(tab[0]);
	  this.imag = Double.parseDouble(tab[1]);
	}
    public void setRel(double re){
		this.real=re;
	}
	public void setImg(double im){
				this.imag=im;
	}
			
	public double getRel(){
		return this.real;
	}
	public double getImg(){
				return this.imag;
	}

	public Complexe multiply(Complexe c) {
	  Complexe product = new Complexe();
	  product.real = (real * c.real) - (imag * c.imag);
	  product.imag = (real * c.imag) + (imag * c.imag);
	  return product;
	}



	public static Complexe multiply( Complexe c,Complexe z) {
	  Complexe product = c.multiply(z);
	  return product;
	}


	

	public void conjugate() {imag = -imag;}

	public static void conjugate(Complexe c) {c.conjugate();}


	public Complexe add(Complexe c) {
	  //le résultat est aussi un complexe, il faut donc introduire une autre variable de type Complexe
	  Complexe sum = new Complexe();
	  sum.real = real + c.real;
	  sum.imag = imag + c.imag;
	  return sum;
	}


	public static Complexe add(Complexe c ,Complexe z) {
	  //le résultat est aussi un complexe, il faut donc introduire une autre variable de type Complexe
	  Complexe sum = c.add(z);
	 
	  return sum;
	}

    public double module (){ return   Math.sqrt(this.real*this.real+this.imag*this.imag);}

    public  static double  mudule (Complexe c ){
         return   c.module();
    }

    public  double argument (){

    	if (real==0 &&imag==0)  return 0;

    	  double cos =  real/ this.module();
    	  /*  recuperation de l angle */
    	  return  Math.acos(cos);
    }

     public static double argument ( Complexe c){
     	return c.argument();
     }

	public String toString() {
          // exemple de la méthode prépondérante
		if (imag>=0)
	return real + "+i" + Math.abs(imag);
	else
	return real + "-i" + Math.abs(imag);
	}

	public  void affiche()
	{   
		System.out.println(" ("+ real + "," +imag +")");

	}

	public boolean equal  (Complexe c)
	{
		return (real==c.real && imag==c.imag);
	}
}
