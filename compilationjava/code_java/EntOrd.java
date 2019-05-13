import java.util.*;

public class EntOrd{
	private int taille_max;
	private int[] t;
	private int indice_courant;

	public EntOrd(int taille_max){
		this.taille_max = taille_max;
		t = new int[taille_max];
		indice_courant = 0;

	}
	public void insertion(int x){
		if(!appartient(x)){
				if(indice_courant<taille_max){
					int i = 0;
					while(i < indice_courant && t[i] < x)
						i++;
					if(i == indice_courant)
						t[i] = x;
					else{
						for(int j=indice_courant;j>i;j--)
							t[j]=t[j-1];
						t[i] = x;
					}
					indice_courant++;
			}
	}
			
}

	public void suppression(int x){
		int i = 0;
		while(i < indice_courant && t[i] != x)
			i++;
		if(i < indice_courant){
			for(int j = i; i < indice_courant;i++)
				t[j]=t[j+1];
			indice_courant--;
		}
		else System.out.println("cet élement ne se trouve pas dans le tableau.");
	}
	
	public boolean appartient(int x){
		int i = 0;
		while(i < indice_courant && t[i] != x)
			i++;
		if(i >=indice_courant)
			return false;
		else return true;

	}

	public int succ(int x){
		int i = 0;
		while(i<indice_courant && t[i] <= x)
			i++;
		return t[i];
	}

	public int pred(int x){
		int i = indice_courant-1;
		while(i>=0 && t[i]>=x)
			i--;
		return t[i];
	}

	public EntOrd union(EntOrd e1){
		int max=this.taille_max+e1.taille_max;
		EntOrd e2;
		e2 = new EntOrd(max);
		int i = 0;
		while(i < this.indice_courant){
			e2.insertion(this.t[i]);
			i++;
		}
		int j = 0;
		while(j < e1.indice_courant ){
			e2.insertion(e1.t[j]);
			j++;
		}
		return e2;
	}

	public EntOrd intersection(EntOrd e1){
		int min;
		if(this.taille_max <e1.taille_max)
			min=this.taille_max;
		else
			min=e1.taille_max;
		EntOrd e2;
		e2 = new EntOrd(min);
	for(int i=0;i<indice_courant;i++)
		if(e1.appartient(t[i]))
			e2.insertion(t[i]);
	for(int i=0;i<e1.indice_courant;i++)
		if(appartient(e1.t[i]))
			e2.insertion(e1.t[i]);
	return e2;
	}
	public void afficher(){
		if(indice_courant>1){
			System.out.print("E=[");
			for(int i = 0;i<indice_courant-1;i++)
				System.out.print(t[i]+",");
			System.out.print(t[indice_courant-1]+"]");
	}
				System.out.println();

	}
}
	
