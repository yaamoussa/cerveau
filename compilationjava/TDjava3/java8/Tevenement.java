class TestEvenement {
	public static void main(String[] args) {
	 Evenement tabaski=new Evenement("la fete de tabaski est une fete musulmane.Dieu avait recommande seuydina brahima d egorge son fils ismaila","12/7/2019");
	 Evenement tamkharit=new Evenement ("une fete musulmane.Elle correspond au fin d'une annee et le debut d 'une autre dans calandrier musulaman ","6/02/2018");


	 Evenement tab=new  Evenement [2];
     tab[1]=tabaski;
     tab[2]=tamkharit;
            for(Evenement e : tab)
                e.afficher();
                System.out.println(tab[1].comparTO(tab[2]));
     

	


}