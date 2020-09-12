


public class Monde{ 


	public static void main(String[] args) {

	Personne p=new Personne("moussa","diouf");
	Chanteur c=new Chanteur("modou","diouf",12);

	p=c;
	p.sePresenter();

//	System.out.println(p.getNom());

	//System.out.println(p.getEdition());
	
}
}

