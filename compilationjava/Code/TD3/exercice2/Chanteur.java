class Chanteur extends Personne{
    private String maisonEdition;

    public String getEdition(){
        if(maisonEdition != null)
            return maisonEdition;
        return "";
    }

    public void setEdition(String autre){
        maisonEdition = autre;
    }

    Chanteur(String prenom, String nom, int age){
        super(prenom, nom, age, "chanteur");
    }

    public void sePresenter(){
        super.sePresenter();
        System.out.println(" et je suis chanteur\n");
    }
}