import java.util.*;

public class Etudiant{
	public String nom;
	private String numIns;

	public Etudiant(String nom){
		this.nom=nom;
	}

	public String getNumIns(){ return this.numIns;}
	public void setNumIns(String numIns){
		if(numIns==null || numIns.length() != 11) return;
		this.numIns=numIns;
	}

	public void afficher(){
		System.out.println("etudiant: "+nom);
	}

	public static void main(String args[]){
		Etudiant e1;
		e1=new Etudiant("ndeye khady aidara");
		e1.afficher();
	}

}