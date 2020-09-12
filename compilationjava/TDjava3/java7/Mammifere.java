class  Mammifere extends Animal 
{  
	public Mammifere (){ }
    public Mammifere (int age,int id,String nom){
    	  super(age,id);
    	  this.nom=nom;
    }
    public  void affiche()
    {     super.affiche();
    	System.out.println("J'appartiens a la famille des Mammiferes et je m'appelle : "+nom);
    }

    public String getInfo (){
    	if (nom==null) return super.toString();
    	return super.toString()+"J'appartiens a la famille des Mammiferes et j'ai : "+nom;
    }


     public  String moyenExpression(){
     	return "je crie ";
     }

    private String nom ;

}