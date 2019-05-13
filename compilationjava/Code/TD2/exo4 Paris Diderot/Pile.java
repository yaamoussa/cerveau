class Pile{
    ElementPile[] elts;
    private int t_reele;
    private static final int MAX = 100;
    private String label;

    Pile(String label){
        elts = new ElementPile[MAX];
        t_reele = 0;
        this.label = label;
    }

    public boolean estVide(){
        return (t_reele == 0);
    }

    public void empile(ElementPile x){
        if(t_reele < MAX){
            elts[t_reele] = x;
            t_reele++;
        }
        else{
            System.out.println("Pile pleine");;
        }
    }

    public ElementPile depile(){
        ElementPile el = elts[t_reele-1];
        t_reele--;
        return el;
    }

    public ElementPile sommet(){
        return elts[t_reele-1];
    }

    public void affiche(){
        for(int i = 0; i < t_reele-1; i++)
            System.out.print(elts[i] + " <-- ");
        System.out.print(elts[t_reele-1] + "\n");
    }

    public String getLabel(){
        return label;
    }
}