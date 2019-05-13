                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 class TestProduit{
    public static void main(String[] args){
        Produit_Informatique p = new Produit_Informatique("PIH48552", "HP",  250000, "14/9/2016");
        // p.afficher();

        ScannerInformatique sc = new ScannerInformatique("HTG48552", "HP",  250000, "14/9/2016", "145*85", 40);
        // sc.afficher();

        Imprimante im = new Imprimante("IM48552", "HP",  250000, "14/9/2016","Laser", "85*96", 52);
        // im.afficher();

        Ordinateur or = new Ordinateur("OR48552", "HP",  250000, "14/9/2016", "Intel core I5", 4, 500, "Ubuntu 18.04");
        // or.afficher();

        OrdinateurBureau orb = new OrdinateurBureau("ORB4885552", "HP", 250000, "14/9/2016", "Intel core I5", 4, 500, "Ubuntu 18.04", "NVIDIA");
        // orb.afficher();

        OrdinateurPortable orp = new OrdinateurPortable("YGU630052",  "HP", 250000, "14/9/2016", "Intel core I5", 4, 500, "Ubuntu 18.04", "LED", "15*17");
        // orp.afficher();

        ListeProduit liste = new ListeProduit(5);
        liste.ajouter(or);
        liste.ajouter(im);
        liste.ajouter(sc);
        liste.ajouter(p);

        liste.afficher_liste();
        System.out.println("\n\nTest suppresion\n\n");
        liste.supprimer(p.reference());
        liste.afficher_liste();
    }
}