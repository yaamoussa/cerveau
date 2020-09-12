

public class Produit  {
	private String ref;
	private String marq;
	private Date date ;
	private double prix;

	public Produit (String ref, String mar,Date date,double prix)
	{
		this.ref=ref;
		this.marq=mar;
		this.date=date;
		this.prix=prix;
	}

	public void  affiche()
	{
		System.out.println("le produit ")
	}

}