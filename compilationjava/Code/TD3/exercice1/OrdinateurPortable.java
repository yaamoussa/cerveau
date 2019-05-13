class OrdinateurPortable extends Ordinateur{
    private String type_ecran;
    private String taille_ecran;

    OrdinateurPortable(String ref, String mar, double prix, String date, String cpu, double ram, double disque, String se, String type_ecran, String taille_ecran){
        super(ref, mar, prix, date, cpu, ram, disque, se);
        this.type_ecran = type_ecran;
        this.taille_ecran = taille_ecran;
    }

    public String type_ecran(){
        return type_ecran;
    }

    public void type_ecran(String autre){
        type_ecran = autre;
    }

    public String taille_ecran(){
        return taille_ecran;
    }

    public void taille_ecran(String autre){
        taille_ecran = autre;
    }

    public void afficher(){
        System.out.printf("Ordinateur portable de marque %s, de reference %s, de prix %.2f, de date %s, de processeur %s, de RAM %.2f GO, de disque dur %.2f GO, livre avec l'os %s et d'ecran de type %s et de taille  %s\n"
        , reference(), marque(), prix(), date(), processeur(), taille_ram(), taille_disque(), os(), type_ecran, taille_ecran);    
    }
}