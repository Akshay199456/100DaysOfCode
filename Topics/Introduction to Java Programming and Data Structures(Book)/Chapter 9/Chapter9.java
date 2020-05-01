import java.util.Date;

public class Chapter9 {
    public static void main(String [] args){
        Circle object = new Circle(10);
        object.printRadius();
        System.out.println(new Date().getTime());
    }

}

class Circle{
    int radius = 0;
    Circle(){
    }

    Circle(int radius){
        this.radius = radius;
    }

    void printRadius(){
        System.out.println("Radius: " + this.radius);
    }
}