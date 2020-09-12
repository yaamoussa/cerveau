class Lapin extends Mammifere implements Herbivore
{
	public Lapin (int age,int id,String nom,String sexe){
		super(age,id,nom);
		this.sexe=sexe;
	}
	public void affiche(){

		super.affiche();
		System.out.println("Je suis particulierement un  Lapin et de sexe :  "+sexe);
	}
	public String toString(){
		return super.toString()+"Je suis particulierement un  Lapin et de sexe :  "+sexe;
	}
	public String  moyenExpression(){
        return super.moyenExpression()+" <<Je clapit>>";
	}

	public void manger(Plante x){
		/*StringBuffer  class= new StringBuffer x.getClass();*/
		System.out.println("Je grignotte "+x.getClass());
	}
	private String sexe;
}