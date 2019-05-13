class Imprimante extends Produit_Informatique{
    private String resolution;
    private double vitesse;
    private String type;

    Imprimante(String ref, String mar, double prix, String date, String type, String resolution, double vitesse){
        super(ref, mar, prix, date);
        this.resolution = resolution;
        this.vitesse = vitesse;
        this.type = type;
    }

    public String resolution(){
        return resolution;
    }

    public void resolution(String autre){
        resolution = autre;
    }

    public String type(){
        return type;
    }

    public void type(String autre){
        type = autre;
    }

    public double vitesse(){
        return vitesse;
    }

    public void vitesse(double autre){
        vitesse = autre;
    }

    public void afficher(){
        System.out.printf("Imprimante de marque %s, de reference %s, de prix %.2f, de date %s, de type %s, de resolution %s et de vitesse %.2f\n"
        , reference(), marque(), prix(), date(), type, resolution, vitesse);        
    }
}