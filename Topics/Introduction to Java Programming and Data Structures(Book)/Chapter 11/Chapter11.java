
// Testing method overriding and method overloading 
public class Chapter11 {
    public static void main(String [] args){
        System.out.println("Hello World!");
        GeometricObject geo = new GeometricObject("Geo", 23);
        System.out.println(geo);

        Circle cir =  new Circle("Cir", 36);
        System.out.println(cir);
    }
}

class GeometricObject{
    public String name;
    public int result;

    public GeometricObject(){
        this.name = "";
        this.result = 0;
    }

    public GeometricObject(String name, int result){
        this.name = name;
        this.result = result;
    }

    public String toString(){
        return ("Name in GeometricObject: " + this.name +" Value in GeometricObject: " + this.result);
    }
}

class Circle extends GeometricObject{
    public Circle(String name, int result){
        super(name, result);
    }

    @Override
    public String toString(){
        return ("Name in Circle: " + this.name +" Value in Cicle: " + this.result);
    }
}