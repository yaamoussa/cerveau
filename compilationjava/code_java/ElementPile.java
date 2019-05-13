public class ElementPile{
	private int x;
	public ElementPile(int x){
		this.x = x;
	}
	public ElementPile(){
		this.x = 0;
	}
	public int  getElement(){
		return this.x;
	}
	public  void setElement(int val){
		this.x = val;

	}
	public void afficher(){
		System.out.printf("%d",x);
	}

}