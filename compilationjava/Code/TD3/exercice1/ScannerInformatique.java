class ScannerInformatique extends Produit_Informatique{
    private String resolution;
    private int nb_pages;

    ScannerInformatique(String ref, String mar, double prix, String date, String resolution, int nb_pages){
        super(ref, mar, prix, date);
        this.resolution = resolution;
        this.nb_pages = nb_pages;
    }

    public String resolution(){
        return resolution;
    }

    public void resolution(String autre){
        resolution = autre;
    }

    public int nb_pages(){
        return nb_pages;
    }

    public void nb_pages(int autre){
        nb_pages = autre;
    }

    public void afficher(){
        System.out.printf("ScannerInformatique de marque %s, de reference %s, de prix %.2f, de date %s, de resolution %s et de nombre de pages %d\n"
        , reference(), marque(), prix(), date(), resolution, nb_pages);        
    }
}