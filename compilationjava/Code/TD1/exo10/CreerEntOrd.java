class CreerEntOrd{
    public static void main(String[] args){
        EntOrd el = new EntOrd(100);
        if(args.length >= 1){
            for(int i = 0; i < args.length; i++)
                el.insertion(Integer.parseInt(args[i]));
            el.afficher();
        }
        else
            System.out.println("Usage : java CreerEntOrd el1 ... eln");
		/*EntOrd e1 = new EntOrd(4);
		EntOrd e2 = new EntOrd(8);
		e1.insertion(50);
		e2.insertion(14);
		e1.insertion(10);
		e2.insertion(4);
		e1.insertion(230);
		e2.insertion(96);
		e2.insertion(50);
		e2.insertion(-98);
		e1.afficher();
		e2.afficher();
		EntOrd e3 = e1.union(e2);
		EntOrd e4 = e1.intersection(e2);
		e3.afficher();
		e4.afficher();
		e3.suppression(14);
		e3.afficher();
		System.out.println(e3.succ(39));
		System.out.println(e3.pred(36));*/
	}
}