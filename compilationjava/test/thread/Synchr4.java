 public class Synchr4
{ public static void main (String args[])
	{ Nombres nomb = new Nombres() ;
	Thread calc = new  ThrChange (nomb) ;
	Thread aff = new ThrAff (nomb) ;
	System.out.println ("Suite de carres - tapez retour pour arreter") ;
	calc.start() ; aff.start() ;
	Clavier.lireString() ;
	calc.interrupt() ; aff.interrupt() ;
	}
}

class Nombres
{	 public synchronized void calcul() throws InterruptedException
	{ 	if (!pret)
			{ n++ ;
			carre = n*n ;
			pret = true ;
			notifyAll() ;
			}
		else wait() ;
	}
	public synchronized void affiche ()
		{ 	try
				{ 	if (pret)
						{ System.out.println (n + " a pour carre " + carre) ;
						notifyAll() ;
						pret = false ;
						}
					else wait () ;
				}
			catch (InterruptedException e) {}
		}
	public boolean pret ()
		{ return pret ;
		}
	private int n=1, carre ;
	private boolean pret = false ;
}
class ThrChange extends Thread
{ 	public ThrChange (Nombres nomb)
		{ this.nomb = nomb ;
		}
	public void run ()
	{ try
		{ while (!interrupted())
			{ nomb.calcul() ;
			sleep (5) ;
			}
		}
	catch (InterruptedException e) {}
	}
	private Nombres nomb ;
}

class ThrAff extends Thread
{ 	public ThrAff (Nombres nomb)
		{ this.nomb = nomb ;
		}
	public void run ()
		{ 	try
			{ while (!interrupted())
				{ nomb.affiche() ;
				sleep (2) ;
				}
			}
		catch (InterruptedException e) {}
		}
	private Nombres nomb ;
}