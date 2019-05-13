class Ordinateur extends Produit_Informatique{
    private String processeur;
    private double taille_ram;
    private double taille_disque;
    private String os;

    Ordinateur(String ref, String mar, double prix, String date, String cpu, double ram, double disque, String se){
        super(ref, mar, prix, date);
        taille_ram = ram;
        taille_disque = disque;
        processeur = cpu;
        os = se;
    }

    public String processeur(){
        return processeur;
    }

    public void processeur(String autre){
        processeur = autre;
    }

    public String os(){
        return os;
    }

    public void os(String autre){
        os = autre;
    }

    public double taille_ram(){
        return taille_ram;
    }

    public void taille_ram(double autre){
        taille_ram = autre;
    }

    public double taille_disque(){
        return taille_disque;
    }

    public void taille_disque(double autre){
        taille_disque = autre;
    }

    public void afficher(){
        System.out.printf("Ordinateur de marque %s, de reference %s, de prix %.2f, de date %s, de processeur %s, de RAM %.2f GO, de disque dur %.2f GO et livre avec l'os  %s\n"
        , reference(), marque(), prix(), date(), processeur, taille_ram, taille_disque, os);        
    }
}