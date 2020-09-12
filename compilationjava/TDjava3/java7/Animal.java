 abstract class Animal 
{  

	public Animal (){}
	 public Animal ( int age,int id){
	 	this.identifiant=id;
	 	this.age=age;
	 }

     public  void affiche(){
     	System.out.println("***************");
     	System.out.println("Je suis un Animal de  "+age+" et mon identifiant est :"+identifiant);
     }
   /*  public String toString (){
     	if (age==0)     return "Je suis un animal ";
     	return "Je suis un Animal age de "+age+"  et mon identifiant est :"+identifiant;
    
     }*/

     public String getInfo (){
     	return toString();
     }

        public  abstract String moyenExpression ();
  /*   public static void afficherAnimaux(Animal tab []){
     	for (int i=0;i<tab.length;i++){
     		System.out.println(((Object)tab[i]));
			System.out.println(	tab[i].moyenExpression());
     	}*/
/*/*/

     private int identifiant ;
     private int age;
}