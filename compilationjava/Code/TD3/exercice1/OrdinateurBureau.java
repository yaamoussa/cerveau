class OrdinateurBureau extends Ordinateur{
    private String carte_graphique;

    OrdinateurBureau(String ref, String mar, double prix, String date, String cpu, double ram, double disque, String se, String graphique){
        super(ref, mar, prix, date, cpu, ram, disque, se);
        carte_graphique = graphique;
    }

    public String carte_graphique(){
        return carte_graphique;
    }

    public void carte_graphique(String autre){
        carte_graphique = autre;
    }

    public void afficher(){
        System.out.printf("Ordinateur de bureau de marque %s, de reference %s, de prix %.2f, de date %s, de processeur %s, de RAM %.2f GO, de disque dur %.2f GO, livre avec l'os  %s et de carte graphique %s\n"
        , reference(), marque(), prix(), date(), processeur(), taille_ram(), taille_disque(), os(), carte_graphique);    
    }
}