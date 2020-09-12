class Immeuble extends Batiment 
{
	public Immeuble( String adres,double sur,int nba)
	{
		super(adres,sur);
		this.nbAppart=nba;

	} 
	public String toString()
	{
		return "Immeuble de: "+nbAppart +"appartements" +super.toString();
	}
	private int nbAppart ;
}