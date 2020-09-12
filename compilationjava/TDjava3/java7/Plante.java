class Plante  
{
	public Plante ( String nom){
		this.nom=nom;
	}
	public void affiche (){
		System.out.println("***************");
		System.out.println("Je suis une plante de type :"+nom);
	}
    public String toString(){
    	return "Je suis une Plante de "+nom;
    }

	private String nom ;

}