class TestPile{
    public static void main(String[] args){
        Pile p = new Pile();
        p.empile(new ElementPile(1));
        p.affiche();
        p.empile(new ElementPile(5));
        p.empile(new ElementPile(-5));
        p.affiche();
        p.depile();
        p.affiche();
        System.out.println("Sommet : " + p.sommet());
        p.depile();
        p.affiche();
    }
}