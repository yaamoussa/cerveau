class ElementPile{
    private int val;
    
    ElementPile(){
        val = 0;
    }

    ElementPile(int val){
        this.val = val;
    }

    public int getVal(){
        return val;
    }

    public void setVal(int val){
        this.val = val;
    }

    public String toString(){
        return Integer.toString(val);
    }
}