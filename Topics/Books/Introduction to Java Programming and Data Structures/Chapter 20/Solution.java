import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

// Working on Chapter 20
public class Solution {
    public static void main(String [] args){
        /*
        // Testing binary search
        List<Integer> list = Arrays.asList(1,2,3,4,5,6);
        System.out.println(Collections.binarySearch(list, 0));
        System.out.println("Hello world!");

        // Queue interface
        Queue<Integer> queue = new LinkedList<>();
        queue.add(2);
        queue.add(3);
        queue.add(4);
        queue.add(5);
        queue.add(6);
        while(!queue.isEmpty()){
            System.out.println("Element: " + queue.poll());
        }
        */

        Stack<Double> numberStack = new Stack<>();
        Stack<Character> operatorStack = new Stack<>();

        String expression = "(51+(54*(3+2)))";
        double finalResult = generateStacks(numberStack, operatorStack, expression);
        System.out.println("Final result: " + finalResult);
        // System.out.println("Number stack: " + Arrays.toString(numberStack.toArray()));
        // System.out.println("Operator stack: " + Arrays.toString(operatorStack.toArray()));
    }

    public static double calculateValue(double element1, double element2, char operator){
        double result = 0;
        System.out.println("Element 1: " + element1 + " Element 2: " + element2 + " Operator: " + operator);
        if(operator == '+')
            result = element1 + element2;
        else if(operator == '-')
            result = element1 - element2;
        else if(operator == '/')
            result = element1 / element2;
        else if(operator == '*')
            result = element1 * element2;
        System.out.println("Result: " + result);
        return result;
    }


    public static double generateStacks(Stack<Double> numberStack, Stack<Character> operatorStack, String expression){
        StringBuffer buffer = new StringBuffer();
        for(int i = 0; i < expression.length(); i++){
            char currentChar = expression.charAt(i);
            if(Character.isDigit(currentChar))
                buffer.append(Character.toString(currentChar));
            else{
                if(currentChar != ')'){
                    if(buffer.length() > 0)
                        numberStack.add(Double.parseDouble(buffer.toString()));
                    operatorStack.add(currentChar);

                    System.out.println("Current symbol: " + currentChar + " Value: " +buffer.toString());
                    buffer.delete(0, buffer.length());  
                }
                else{
                    if(buffer.length() > 0){
                        numberStack.add(Double.parseDouble(buffer.toString()));
                        buffer.delete(0, buffer.length());
                    }
                    numberStack.add(calculateValue(numberStack.pop(), numberStack.pop(), operatorStack.pop()));
                    operatorStack.pop();
                    System.out.println("Index: " + i + " Number stack: " + Arrays.toString(numberStack.toArray()));
                    System.out.println("Operator stack: " + Arrays.toString(operatorStack.toArray()));
                }
            }
        }
        return numberStack.pop();
    }
}