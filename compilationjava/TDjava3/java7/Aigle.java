class Aigle extends Oiseau implements Carnivore
{
	public Aigle (int age,int id ,String couleur,String sexe ,double poids){
           super(age,id,couleur);
           this.poids=poids;
           this.sexe=sexe;
	}
	public void affiche(){  

		super.affiche();
		System.out.println(" et de famille d'Aigle de poids:"+poids+"de sexe:"+sexe);
	}

	public String getInfo (){
		return super.toString()+ "et de famille d'Aigle de poids:"+poids+"de sexe:"+sexe;
	}
   
     public  String moyenExpression(){
     	return super.moyenExpression()+", <<Je glatit>>";
     }
		public void manger(Animal x){
		/*StringBuffer  class= new StringBuffer x.getClass();*/
		System.out.println("Je déchire "+x.getClass());
	}

	private double poids;
	private String sexe;
}