class Personne{
    private String prenom;
    private String nom;
    private int age;
    private String profession;

    Personne(String prenom, String nom, int age){
        this.prenom = prenom;
        this.nom = nom;
        this.age = age;
        this.profession = "";
    }

    Personne(String prenom, String nom, int age, String profession){
        this.prenom = prenom;
        this.nom = nom;
        this.age = age;
        this.profession = profession;
    }

    Personne(String prenom, String nom){
        this.prenom = prenom;
        this.nom = nom;
        this.age = -1;
        this.profession = "";
    }

    public void sePresenter(){
        System.out.printf("Je m'appelle %s %s", prenom, nom);
        if(age != -1)
            System.out.printf(", j'ai %d ans", age);
    }

    public String getNom(){
        return nom;
    }
}