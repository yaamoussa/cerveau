class Tri{
    private Pile A;
    private Pile B;
    private Pile C;

    Tri(Pile a, Pile b, Pile c){
        A = a;
        B = b;
        C = c;
    }

    public Pile tri(){
        while(!A.estVide()){
            if(B.estVide() || A.sommet().getVal() < B.sommet().getVal()){
                B.empile(A.depile());
                while(!C.estVide())
                B.empile(C.depile());

            }
            else
                C.empile(B.depile());
        }
        return B;
    }


    public static void main(String[] args){
        Pile A = new Pile();
        int[] tab = {4,3,2,5,8,2,6,9,3};
        for(int i = 0; i < tab.length;i++)
            A.empile(new ElementPile(tab[i]));      
        Pile B = new Pile();
        Pile C = new Pile();
        Tri t = new Tri(A, B, C);
        B = t.tri();
        B.affiche();
    }
}