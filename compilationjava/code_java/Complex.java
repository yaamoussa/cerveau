
class Complex{
	public int x ;
	public int y ;

	public Complex(){
		x=0;
		y=0;
	}
	public Complex(int x,int y){
		this.x = x;
		this.y = y;
	}

	public Complex(String s){
		x=Integer.parseInt(s.charAt(1)+"");
		y=Integer.parseInt(s.charAt(3)+"");

	}

	public Complex(Complex z){
		x=z.x;
		y=z.y;	
	}

	public void afficher(){
		System.out.println(x+"+"+y+"i");
	}
	public int  getRelle(){
		return x;
	}
	public int getIm(){
		return y;
	}

	public void setRelle(int x){
		this.x = x;
	}
	public void setIm(int y){
		this.y = y;
	}
	public void aff(){
		System.out.println("("+x+","+y+")");
	}

	public boolean equal(Complex z){
		if(x == z.x && y == z.y)
			return true ;
		else
			return false;
		}

	public static void main(String[] args) {
		Complex z;
		z=new Complex();
		Complex z1;
		z1 = new Complex(4,6);
		Complex z2;
		z2 = new Complex("(5,3)");
		z2.afficher();
		z1.afficher();
		Complex z3;
		z3 = new Complex("(8;2)");
		z3.afficher();
		Complex z4 = new Complex(z3);
		z4.aff();
		if(z3.equal(z4))
			System.out.println("egaux");
		else System.out.println("non egaux");




	}
	



}