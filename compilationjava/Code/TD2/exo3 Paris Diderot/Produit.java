class Produit{
    private String nom;
    private double prix;
    private int jours_restants;

    Produit(String nom, double prix, int jours_restants){
        this.nom = nom;
        this.prix = prix;
        this.jours_restants = jours_restants;
    }

    public int joursRestants(){
        return jours_restants;
    }

    public double getPrix(){
        return prix;
    }

    public String getNom(){
        return nom;
    }

    public String toString(){
        return "Produit = " + nom + ", " + "prix = " + prix + " nombres de jours avant peremption = " + jours_restants + "\n";
    }

}