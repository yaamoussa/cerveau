class A 
{void m(A a){System.out.println("m de A"); }
 void m(B b) {System.out.println("m de A version 2");}

void n(A a){System.out.println("n de A"); } 
}

class B extends A 
{void m(A a){System.out.println("m de B");}
void n(B b){System.out.println("n de B");}
}
class Test {
public static void main(String[] argv){
	A a = new B();
	B b = new B();
	A a1 = new A();/*
	a.m(b);// lors de l excution on a trouve la methode dans la classe m() du fait B derive de A 
	a.n(b);//lors de l excution on a trouve la methode dans classe n() du fait n(B n) n etait selectionne lors de la compilation
	b.m(b);b.n(b);//n(B) m(b) etait selectionne lors de la compilation et on a typage statique
	a.m(a1);a.n(a1);//lors de l excution on regarde la methode du type reference ici B et on trouve m(A) qui repond les condition
	a1.m(b); a1.n(b);// une typage  dynamique a eu lieu lors de la passage des  parametre qui permet la verification des condition de selection  
	*/
	a.m(b);// lors de l excution on avait pas trouver m(b) et on avait remonte jusau a A 
	a.n(b);//lors de l excution on a trouve la methode dans classe n() du fait n(B n) n etait selectionne lors de la compilation
	      // on a remonte jusqu a A
	b.m(b);//lors de la compilation m(A) et n(B) etaient selection mais du fait que il ne repndait pas les condition
	         // on a remonte jusqu a A pour trouver m(B)
	b.n(b);//n(B) m(b) etait selectionne lors de la compilation et on a typage statique
	a.m(a1);//on a trouve m(A) dans B qui etait selectionne 
	a.n(a1);//lors de l excution on regarde la methode du type reference ici B et on n a pas trouve n(A) qui repond les condition
	       //on a remonte jusqu a A
	a1.m(b); a1.n(b);// du fait de l ambiguite cause par m(A) et m(B) parce que sont presque les memes du fait de la typage dynamique
	}
}