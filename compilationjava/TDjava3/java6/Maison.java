class Maison extends Batiment
{
	public Maison ( String adres,double surb,int nb ,double surj){
		super(adres,surb);
	 	this.nbPieces=nb;
	 	this.surfaceJardin=surj;
	 }
	public String toString ()
	{
		return  "Maison "+super.toString()+ " "+ "nombre de pieces: "+nbPieces +" " +"surface Jardin :"+surfaceJardin +"ha";
	}
	public double getSurfaceJardin(){
		return surfaceJardin;
	}
    public  double Impot( ){
    	return TauxA*getSurfaceHabitable()+TauxB*surfaceJardin;
    }
	private int nbPieces;
	private double surfaceJardin;

}