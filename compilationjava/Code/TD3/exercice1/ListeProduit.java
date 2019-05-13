class ListeProduit{
    private Produit_Informatique[] liste;
    private int t_max;
    private int t_reelle;

    ListeProduit(int max){
        t_max = max;
        liste = new Produit_Informatique[max];
        // t_reelle = 0;
    }

    public void ajouter(Produit_Informatique p){
        if(t_reelle < t_max){
            liste[t_reelle] = p;
            t_reelle++;
        }
    }

    public void supprimer(String reference){
        if(t_reelle > 0){
            int i = 0;
            while(i < t_reelle && !liste[i].reference().equals(reference))
                i++;
            
            for(int j = i; j < t_reelle-1; j++)
                liste[j] = liste[j+1];
            t_reelle = t_reelle - 1;
        }
    }

    public void afficher_liste(){
        if(t_reelle == t_max)
            for(Produit_Informatique p : liste)
                p.afficher();
        else
            for(int i = 0; i < t_reelle; i++)
                liste[i].afficher();
    }
}