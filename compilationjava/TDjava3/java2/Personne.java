public class Personne {



  public  Personne(String nom,String prenom,int age ){
           this.nom=nom;
           this.prenom=prenom;
           this.age=age;
           

    }


  public   Personne(String nom,String prenom){
    	this.nom=nom;
    	this.prenom=prenom;
    }

  public Personne(String nom,String prenom,int age,String profession){
    	this.age=age;
    	this.nom=nom;
    	this.prenom=prenom;
    	this.profession=profession;
    }


  public String getNom(){
  	return nom;
  }


  public  void sePresenter(){
          if(age!=1)
          	          System.out.println("Je m "+"'" +"appelle" +  prenom  + nom +","+age);
          else        System.out.println("Je m "+"'" +"appelle" +  prenom +  nom );

        


    }
	private 
	   int age=1;
	   String nom;
	   String prenom;
	   String profession =null;

};