public class CreerEntOrd{
 public static void main(String[] args) {
	 	/*EntOrd e;
	 	e=new EntOrd(10);
	 	e.insertion(1);
	 	e.insertion(12);
	 	e.insertion(120);
	 	e.insertion(6);
	 	//e.suppression(12);
	 	e.afficher();
	 	EntOrd e1;
	 	e1=new EntOrd(5);
	 	e1.insertion(10);
	 	e1.insertion(120);
	 	e1.insertion(12);
	 	e1.insertion(150);
	 	e1.afficher();
	 	EntOrd e3;
	 	e3=e.intersection(e1);
	 	e3.afficher();
		EntOrd e2;
	 	System.out.println();
	 	e2=e.union(e1);
	 	e2.afficher();

	 	int x=e.succ(10);
	 	System.out.println(x);
	 	int y=e.pred(10);
	 	System.out.println(y);*/
	 	EntOrd e;
	 	e=new EntOrd(10);
	 	for(int i=0;i<args.length;i++){
	 		int n=Integer.parseInt(args[i]);
	 		e.insertion(n);
	 	}
	 	e.afficher();
	}

}