class   Chanteur extends Personne {

    public Chanteur(String nom,String prenom,int age){

    	super(nom,prenom,age,"chanteur");


    }



	public void sePresenter(){

		super.sePresenter();
        System.out.println("Je suis chanteur");

	}


	public void setEdition(String name){
              maisonEdition=name;
	}


	public String getEdition(){
		return maisonEdition;
	}

	private String  maisonEdition=null;
};