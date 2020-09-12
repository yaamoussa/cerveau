class Homme extends Mammifere implements  Omnivore ,Herbivore ,Carnivore
{
	public Homme(){}
	public Homme (int age,int id,String nom ,String sexe){
		super(age,id,nom);
		this.sexe=sexe;
	}
	public void affiche (){
		super.affiche();
		System.out.println("Je suis un "+sexe);
	}

	public String getInfo(){
		if (sexe==null) return super.toString()+ "Je suis un etre  Humain";
		if (sexe=="femme") return super.toString()+"Je suis une "+sexe;
		return super.toString()+"Je suis un "+sexe;
		
	}

    public  String moyenExpression(){
    	return super.moyenExpression()+ " ,<<Je parle >>";
    }
    /* Premiere methode */
    public void manger(Animal x){
		/*StringBuffer  class= new StringBuffer x.getClass();*/
		System.out.println("Je dechire "+x.getClass());
	}
     public void manger(Plante x){
		/*StringBuffer  class= new StringBuffer x.getClass();*/
		System.out.println("Je broute"+x.getClass());
	}

	public void manger (Animal x,Plante y){
		System.out.println("Je dechire "+x.getClass()+"et je broute"+y.getClass());
	}
   
	public String sexe;
}