class Monde{
    public static void  main(String[] args){
        Personne p1 = new Personne("Mouhamadou Lamine", "Diakhame", 24, "etudiant");
        Personne p2 = new Personne("Assane", "Ndiaye");
        p1.sePresenter();
        System.out.println();
        p2.sePresenter();
        System.out.println();
        System.out.println("Le nom de la p1 est : " + p1.getNom());

        Chanteur c = new Chanteur("Youssou", "Ndour", 55);
        c.sePresenter();

        Personne p = c;
        p.sePresenter();
        
        Chanteur cc = (Chanteur)p;
        cc.setEdition("SANART");
        System.out.println(cc.getEdition());
    }
}