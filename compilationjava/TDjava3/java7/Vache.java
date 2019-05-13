class Vache extends Mammifere implements Herbivore
{
	public Vache (int age,int id,String nom,String sexe){
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
		System.out.println("Je broute"+x.getClass());
	}
	private String sexe;
}