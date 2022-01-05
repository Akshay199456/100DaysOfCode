// Completed Chapter 13

// Testing out abstract methods and classes
// Working on interfaces
abstract class GeometricObject{
    public String toString(){
        return("This is a geometric object");
    }

    public abstract double getArea();
    public abstract double getVolume();
}


class Circle extends GeometricObject{
    private double radius;

    public Circle(){
        this.radius = 0;
    }

    public Circle(double radius){
        this.radius = radius;
    }

    public double getArea(){
        return Math.PI * this.radius * this.radius;
    }

    public double getVolume(){
        return (Math.pow(this.radius, 3) * Math.PI * 4) / 3;
    }
}


public class Solution {
    
    public static void main(String [] args){
        System.out.println("Hello World!");
        GeometricObject obj = new Circle(1);
        System.out.println("Area of circle: " + obj.getArea());
        System.out.println("Volume of circle: " + obj.getVolume());
    }
}