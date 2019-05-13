
public class EntOrd{
	private int tmax;
	private int courant;
	private int[] elts = null;

	EntOrd(int max){
		tmax = max;
		courant = 0;
		elts = new int[max];
		System.out.println("Creation d'un ensemble ordonne : " + this);
	}

	boolean appartient(int x){
		int i = 0;
		while(i < elts.length && elts[i] != x){
			i++;
		}
		if(i == elts.length)
			return false;
		else
			return true;
	}

	public void insertion(int x){
		if(!appartient(x)){
			if(courant < tmax){
				int i = 0;
				while(i < courant && elts[i] < x)
					i++;
				if(i == courant){
					elts[courant] = x;
				}
				else{
					for(int j = courant; j > i; j--)
						elts[j] = elts[j-1];
					elts[i] = x;
				}
				courant++;
			}
			else
				System.out.println("ensemble plein");
		}
		else
			System.out.println("Element deja present");
	}

	public void suppression(int x){
		int i = 0;
		if(!appartient(x)){
			System.out.println("Impossible de supprimer " + x + " : l'element n'appartient pas au tableau");
			return ;
		}
		while(i < courant && elts[i] != x)
			i++;
		for(int j = i; j < courant; j++)
			elts[j] = elts[j+1];
		courant--;
	}

	public int succ(int x){
		int i = 0;
		while(i < courant && elts[i] <= x)
			i++;
		if(i < courant)
			return elts[i];
		else
			return x;
	}

	public int pred(int x){
		int i = 0;
		int pre = 0;
		while(i < courant && elts[i] < x){
			pre = elts[i];
			i++;
		}
		if(i < courant)
			return pre;
		else
			return x;
	}

	public EntOrd union(EntOrd el){
		EntOrd val = new EntOrd(el.tmax + this.tmax);
		for(int i = 0; i < el.courant; i++)
			val.insertion(el.elts[i]);

		for(int i = 0; i < this.courant; i++)
			val.insertion(this.elts[i]);

		return val;
	}

	public EntOrd intersection(EntOrd el){
		EntOrd val = new EntOrd((el.tmax > this.tmax ? this.tmax : el.tmax));
		for(int i = 0; i < el.courant; i++)
			if(appartient(el.elts[i]))
				val.insertion(el.elts[i]);

		for(int i = 0; i < this.courant; i++)
			if(el.appartient(elts[i]))
				val.insertion(this.elts[i]);

		return val;
	}

	public void afficher(){
		System.out.print("[");
		for(int i = 0; i < courant-1; i++)
			System.out.print(elts[i] + ", ");
		System.out.println(elts[courant-1] + "]");
	}

	public static void main(String[] args){
		EntOrd e1 = new EntOrd(4);
		EntOrd e2 = new EntOrd(8);
		e1.insertion(50);
		e2.insertion(14);
		e1.insertion(10);
		e2.insertion(4);
		e1.insertion(230);
		e2.insertion(96);
		e2.insertion(50);
		e2.insertion(-98);
		e1.afficher();
		e2.afficher();
		EntOrd e3 = e1.union(e2);
		EntOrd e4 = e1.intersection(e2);
		e3.afficher();
		e4.afficher();
		e3.suppression(14);
		e3.afficher();
		System.out.println(e3.succ(39));
		System.out.println(e3.pred(36));
	}

}