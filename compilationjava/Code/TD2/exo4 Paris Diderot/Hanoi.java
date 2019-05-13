class Hanoi{
    private Pile A;
    private Pile B;
    private Pile C;
    private int n;

    public Hanoi(int n){
        this.n = n;
        A = new Pile("A");
        B = new Pile("B");
        C = new Pile("C");

        for(int i = n; i > 0; i--)
            A.empile(new ElementPile(i));
    }

    public void affiche(){
        A.affiche();
    }

    private void deplace (Pile a, Pile b, Pile c, int n) {
        if (n > 0) {
            deplace(a, c, b, n-1);
            System.out.println("Deplacement disque " + a.sommet().getVal() + " de " +
            a.getLabel() + " vers " + c.getLabel());
            b.empile(a.depile());
            deplace(c, b, a, n-1);
        }
        A = B;
    }

    public void joue () {
        deplace (A, B, C, n);
    }

    public static void main(String[] args){
        if(args.length < 1){
            System.out.println("Usage : java Hanoi nombreDisques");
            return;
        }
        Hanoi h = new Hanoi(Integer.parseInt(args[0]));
        h.joue();
        h.affiche();
    }
}