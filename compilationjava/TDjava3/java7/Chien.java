class Chien extends Mammifere implements Carnivore
{
	 public Chien (int age ,int id,String nom ,String couleur,String sexe)
	 {   
	 	super(age,id,nom);
	 	this.couleur=couleur;
	 	this.sexe=sexe;
	 }
	 public void affiche (){
	 	System.out.println("***************");
         super.affiche();
	 	System.out.println("J'appartiens Chien de couleur :"+couleur +"et de sexe "+sexe);
	 }
    public   String getInfo(){
    	return super.toString()+"J'appartiens Chien de couleur :"+couleur +"et de sexe "+sexe;
    }

     public  String moyenExpression  (){
     	return  super.moyenExpression()+ "<<J'aboie >>";
     }
    public void manger(Animal x){
		/*StringBuffer  class= new StringBuffer x.getClass();*/
		System.out.println("Je mord "+x.getClass());
	}
   
	private String couleur;
	private String sexe;
}