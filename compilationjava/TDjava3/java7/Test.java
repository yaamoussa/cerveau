public  class Test 
{
	public static void main(String[] args) {
	//A/*nimal	A=new Animal (1,1);
	//	A.affiche();
	//lante P=new Plante("arbre");
	//	P.affiche();
	//iseau O=new Oiseau(3,2,"rouge");
		//O.affiche();
		Aigle	Ai=new Aigle (2,3,"noir","femelle",45);
		//Ai.affiche();
		Chien C=new Chien(5,2,"vici","blanc","male"); 
		Vache V=new Vache (4,5,"toto","femelle");
	//ammifere M=new Mammifere(3,2,"vi");
	//	M.affiche();
		Lapin L=new Lapin(6,5,"toto","male");
	//	L.affiche();
	Homme H=new Homme(7,3,"khara","homme");
	//	H.affiche();
/*    L.manger( new Plante("herb")  );
    C.manger(new Oiseau (4,6,"blanc"));
    Ai.manger(new Oiseau(6,8,"noir"));
    V.manger(new Plante("verte"));*/

    /* Dans un premier temps */
		// H.manger(V) ; 
		// H.manger(new Plante("salade"));
  /* Deuxieme methode*/
		// H.manger(V,new		Plante ("salade"));  

	//System.out.println(A);
/*	//	System.out.println(Ai.getClass());
		Animal parc[]=new Animal [6];
		Animal mami[]=new Animal[3];
		parc[0]=O;
		parc[1]=Ai;
		parc[2]=C;
		parc[3]=L;
		parc[4]=H;
		parc[5]=M;
	
*/       
		Carnivore tabCar[]=new Carnivore [3];
		tabCar[0]=Ai;
		tabCar[1]=C;
		tabCar[2]=H;

		for (int i=0;i<tabCar.length;i++)
			  tabCar[i].manger(new Lapin(3,4,"long","male"));

		Herbivore tabHer[]=new Herbivore [3];
		tabHer[0]=V;
		tabHer[1]=L;
		tabHer[2]=H;

		for (int i=0;i<tabHer.length;i++)
			  tabHer[i].manger(new Plante ("salade"));


	}
}