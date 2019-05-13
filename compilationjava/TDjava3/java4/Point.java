class Point {
    public int x, y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
   public void Pointaffect(Point a){
         this.x=a.x;
         this.y=a.y;
     }

    public String toString() {
        return "Point[" + this.x + ", " + this.y + "]";
    }
}

