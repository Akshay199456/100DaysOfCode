import java.util.Date;

public class Chapter9 {
    public static void main(String [] args){
        Circle object = new Circle();
        object.printRadius();
        System.out.println(new Date().getTime());
    }

}

class Circle{
    int radius;
    Circle(){
        this(25);
    }

    Circle(int radius){
        this.radius = radius;
    }

    void printRadius(){
        System.out.println("Radius: " + this.radius);
    }
}