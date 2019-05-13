public class Tri{
	private Pile A;
	private Pile B;
	private Pile C;
	public Tri(Pile A,Pile B,Pile C){
		this.A = A;
		this.B = B;
		this.C = C;
	}
	public Pile trier(){
		while(A.PileVide() == false){
			ElementPile el = A.sommet();
			if(B.PileVide() || el.getElement()< B.sommet().getElement()){
				B.empile(A.depile().getElement());
			while(C.PileVide() == false)
				B.empile(C.depile().getElement());
			}
			else
				C.empile(B.depile().getElement());

		}
		return B;
	}
	void afficherTri(){
		B.afficherPile();
	}

public static void main(String[] args) {
	Pile A = new Pile();
	A.empile(4);
	A.empile(3);
	A.empile(2);
	A.empile(5);
	A.empile(8);
	A.empile(2);
	A.empile(6);
	A.empile(9);
	A.empile(3);
	A.afficherPile();

	Pile B = new Pile();
	Pile C = new Pile();
	Tri t = new Tri(A,B,C);
	B = t.trier();
	B.afficherPile();
		A.afficherPile();


	}
}