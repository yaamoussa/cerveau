import javax.swing.* ;
// pour JFrame
import java.awt.event.* ; // pour MouseEvent et MouseListener
class MaFenetre extends JFrame implements MouseListener
{ public MaFenetre ()
	// constructeur
	{ setTitle ("Gestion de clics") ;
	setBounds (10, 20, 300, 200) ;
	addMouseListener (this) ;

	// la fenetre sera son propre écouteur
	// d’événements souris
	}
	public void mouseClicked(MouseEvent ev) // méthode gerant un clic souris
	{ System.out.println ("clic dans fenetre") ;
	}
	public void mousePressed (MouseEvent ev) {}
	public void mouseReleased(MouseEvent ev) {}
	public void mouseEntered (MouseEvent ev) {}
	public void mouseExited (MouseEvent ev) {}
}
public class Clic1
{ public static void main (String args[])
	{ MaFenetre fen = new MaFenetre() ;
	fen.setVisible(true) ;
	}
}