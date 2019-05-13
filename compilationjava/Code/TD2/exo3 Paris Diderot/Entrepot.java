import java.util.Scanner;

class Entrepot{
    private PileEntrepot ensemble;
    private int nb_perimes;

    public void construitEntrepot(){
        ensemble = new PileEntrepot();
        nb_perimes = 0;
        int nb;
        Scanner keyb = new Scanner(System.in);
        System.out.print("Nombre de produits de l'entrepot = ");
        nb = keyb.nextInt();
        keyb.nextLine();
        for(int i = 0;i < nb; i++){
            String nom;
            double prix;
            int jours;
            System.out.println("Saisie produit " + (i + 1));
            System.out.print("\tnom = ");
            nom = keyb.nextLine();
            System.out.print("\tprix = ");
            prix = keyb.nextDouble();
            System.out.print("\tjours avant peremption = ");
            jours = keyb.nextInt();
            keyb.nextLine();
            ensemble.empile(new Produit(nom, prix, jours));
        }
    }

    public void trie(){
        PileEntrepot B = new PileEntrepot();
        PileEntrepot C = new PileEntrepot();
        while(!ensemble.estVide()){
            if(B.estVide() || ensemble.sommet().joursRestants() < B.sommet().joursRestants()){
                B.empile(ensemble.depile());
                while(!C.estVide())
                    B.empile(C.depile());
            }
            else
                C.empile(B.depile());
        }
        ensemble = B;
    }

    int suppression(){
        int perdus = 0;
        PileEntrepot tmp = new PileEntrepot();
        while(!ensemble.estVide()){
            if(ensemble.sommet().joursRestants() <= 0){
                ensemble.depile();
                perdus++;
            }
            else{
                tmp.empile(ensemble.sommet());
                ensemble.depile();
            }
        }
        ensemble = tmp;
        return perdus;
    }

    public void affiche(){
        ensemble.affiche();
    }

    public static void main(String[] args){
        Entrepot e = new Entrepot();
        e.construitEntrepot();
        System.out.println("============================================================");
        System.out.println("Entrepot initial");
        e.affiche();
        System.out.println("============================================================");
        e.trie();
        System.out.println("============================================================");
        System.out.println("Entrepot trie");
        e.affiche();
        System.out.println("============================================================");
        e.suppression();
        System.out.println("============================================================");
        System.out.println("Suppression des produits perimes");
        e.affiche();
        System.out.println("============================================================");
    }
}