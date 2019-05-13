class PileEntrepot{
    private Produit[] elts;
    private int t_reele;
    private static final int MAX = 100;

    PileEntrepot(){
        elts = new Produit[MAX];
        t_reele = 0;
    }

    public boolean estVide(){
        return (t_reele == 0);
    }

    public void empile(Produit x){
        if(t_reele < MAX){
            elts[t_reele] = x;
            t_reele++;
        }
        else{
            System.out.println("Pile pleine");;
        }
    }

    public Produit depile(){
        Produit el = elts[t_reele-1];
        t_reele--;
        return el;
    }

    public Produit sommet(){
        return elts[t_reele-1];
    }

    public void affiche(){
        for(int i = 0; i < t_reele; i++)
            System.out.print(elts[i]);
    }
}