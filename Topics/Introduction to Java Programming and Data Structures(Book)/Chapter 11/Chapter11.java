import java.util.ArrayList;

public class Chapter11 {
    public static void main(String [] args){
        System.out.println("Hello World!");

        // Implementing stack using ArrayList
        Stack object = new Stack();
        object.push(2);
        object.push(3);
        int poppedElement = object.pop();
        object.pop();
        int topElement = object.peek();
        System.out.println("Popped element: " + poppedElement);
        System.out.println("Peeked element: " + topElement);
        System.out.println(object.isEmpty());
        System.out.println(object.stack);
        /*
        // Typecasting: Includign downcasting and upcasting
        // Testing method overriding and method overloading 

        Object gen1 = new GeometricObject("Geo", 123);
        Object gen2 = new Circle("Cir", 36);
        System.out.println((GeometricObject)gen1);
        System.out.println((Circle)gen2);
        */
    }
}

class Stack{
    ArrayList<Integer> stack;

    public Stack(){
        this.stack = new ArrayList<>();
    }

    public void push(int element){
        this.stack.add(element);
    }

    public Integer pop(){
        if(this.stack.isEmpty()){
            return -1;
        }
        return this.stack.remove(this.stack.size() - 1);
    }

    public Integer peek(){
        if(this.stack.isEmpty()){
            return -1;
        }
        return this.stack.get(this.stack.size() - 1);
    }

    public boolean isEmpty(){
        return this.stack.isEmpty();
    }
}



/*
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
*/