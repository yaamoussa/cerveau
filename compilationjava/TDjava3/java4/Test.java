public class Test {
    public static void afficherTabPoints(Point[] tabPoints) {
        for (int i = 0; i < tabPoints.length; i++)
            System.out.println(tabPoints[i] + ",");
    }

    public static void trouverBornes(Point borneInfs, Point borneSups, Point[] tabPoints) {
        /************* premiere maniere pour regler le probleme *******************/
        /*****utilise un variable local pour trouver les bornes et affecte la modification */
        /****on s appuie sur la transmission de la référence d’un objet*/
         Point borneInf = new Point(0, 0);
        Point borneSup = new Point(0, 0);
        for (int i = 0; i < tabPoints.length; i++) {
            if (borneInf.x > tabPoints[i].x)
                borneInf = tabPoints[i];
            if (borneSup.x < tabPoints[i].x)
                borneSup = tabPoints[i];
        }
        System.out.println("Test : " + borneInf.x);
        System.out.println("Test : " + borneInf.y);
        System.out.println("Test : " + borneSup.x);
        System.out.println("Test : " + borneSup.y);
        borneInfs.Pointaffect(borneInf);
        borneSups.Pointaffect(borneSup);
    }
    /***deuxieme maniere pour resoudre le probleme*/
    /*** on  cinde la methode en deux : trouverborneinf et trouverbornesup ****/
    /*** on s appuie sur la notion de retour de referance:ici valeur de retour  ***/

    public static Point trouverBorneInf(Point borneInf, Point[] tabPoints) {
        for (int i = 0; i < tabPoints.length; i++) {
            if (borneInf.x > tabPoints[i].x)
                borneInf = tabPoints[i];
        }

        return borneInf;
    }

    public static Point trouverBorneSup(Point borneSup, Point[] tabPoints) {
        for (int i = 0; i < tabPoints.length; i++) {
            if (borneSup.x < tabPoints[i].x)
                borneSup = tabPoints[i];
        }

        return borneSup;
    }

    public static void main(String[] args) {
      /*  Point borneInf = new Point(0, 0);
        Point borneSup = new Point(0, 0);*/
        Point[] tabPoints = new Point[4];
        tabPoints[0] = new Point(100, 100);
        tabPoints[1] = new Point(10, 10);
        tabPoints[2] = new Point(150, 150);
        tabPoints[3] = new Point(-5, -5);
        Point borneInf=tabPoints[0];
        Point borneSup=tabPoints[1];
        afficherTabPoints(tabPoints);
        trouverBornes(borneInf, borneSup, tabPoints);
    /*  borneInf = trouverBorneInf(borneInf, tabPoints);
        borneSup = trouverBorneSup(borneSup, tabPoints);*/
        System.out.println("Borne Inf:" + borneInf + "; Borne Sup: " + borneSup);
    }


    /***1---> on attendait voir les valeur modifiees **/
    /***2---> on a propose les deux manieres dessus   en s appuyant sur la notion de transmision 
    d objet et de valeur de retour d une methode */
}