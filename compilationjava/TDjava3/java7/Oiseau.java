class Oiseau extends Animal 
{   
	public Oiseau ( int age,int id,String couleur ){
		super(age,id);
		this.couleur =couleur;
	}

	public void affiche (){

		super.affiche();
		System.out.println("Je appartiens aux  Oiseaux de couleur :"+couleur);
	}

	public String getInfo(){
		return super.toString()+"	Je appartiens aux  Oiseaux de couleur :"+couleur;
	}

	public String moyenExpression (){
		return "Je crie ";
	}

	private String couleur ;
}