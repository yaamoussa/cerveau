class Batiment {
	public Batiment (String adres,double surface)
	 {
	 	this.adresse=adres;
	 	this.surfaceHabitable=surface;
	 }
	 public String toString(){
	 	return  " Le Batiment se trouve a :"+ adresse+ "surfaceHabitable :"+surfaceHabitable;
	 }

	 public double getSurfaceHabitable() {
	 	return surfaceHabitable;
	 }
   public double getSurfaceJardin(){ return 0;}//pour le polymorphisme juste
	private  String adresse;
	private double surfaceHabitable;
}