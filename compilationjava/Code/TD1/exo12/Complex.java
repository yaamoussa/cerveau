
class Complex {
	private double x;
	private double y;

	public Complex() {
		x = 0;
		y = 0;
	}

	public Complex(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public Complex(String c) {
		this(0.0, 0.0);
		int index = c.indexOf(";");
		if (index == -1) {
			index = c.indexOf(",");
			if (index != -1) {
				x = Double.parseDouble(c.split(",")[0].replace("(", "0"));
				y = Double.parseDouble(c.split(",")[1].replace(")", "0"));
			}
		} else {
			x = Double.parseDouble(c.split(";")[0].replace("(", "0"));
			y = Double.parseDouble(c.split(";")[1].replace(")", "0"));
		}

	}

	public Complex(Complex z) {
		x = z.x;
		y = z.y;
	}


	public double getReelle() {
		return x;
	}

	public double getImaginaire() {
		return y;
	}

	public void setReelle(double x) {
		this.x = x;
	}

	public void setImaginaire(double y) {
		this.y = y;
	}

	public double module(){
		return Math.sqrt(x*x + y*y);
	}

	// Retourne l'argument en radiant
	public double argument(){
		double mod = module();
		if(mod != 0){
			return Math.acos(x / mod);
		}
		return 0;
	}

	public void afficher() {
		System.out.println("(" + x + ", " + y + ")");
	}

	public boolean equal(Complex z) {
		if (x == z.x && y == z.y)
			return true;
		else
			return false;
	}

	public static void main(String[] args) {
		Complex z1 = new Complex();
		z1.setReelle(2.5);
		z1.setImaginaire(3);
		z1.afficher();
		Complex z2;
		z2 = new Complex("(5;3)");
		z2.afficher();
		boolean eq = z1.equal(z2);
		if(eq)
			System.out.println("les deux complexes sont egaux");
		else
			System.out.println("Les deux complexes sont differentes");
	}
}