// Using generic methods
public class Solution{
    public static void main(String [] args){
        // Sorting an array of objects

        Integer [] intArray = {32,23,14,5};
        Character [] charArray = {'d', 'c', 'b', 'a'};
        Double [] doubleArray = {2.3, 11.6, 1.0,7.1};
        String [] stringArray = {"Why", "Yellow", "Hi", "Apple"};

        System.out.println("Before sort: ");
        Solution.getString(stringArray);
        Solution.sortArray(stringArray);
        System.out.println("After sort: ");
        Solution.getString(stringArray);
    }

    public static <E> void getString(E[] list){
        for(int i = 0 ; i < list.length; i++)
            System.out.print(list[i] + " ");
        System.out.println();
    }

    public static <E extends Comparable<E>> void sortArray(E[] objectArray){
        for(int i = 0; i < objectArray.length; i++){
            E currentMin = objectArray[i];
            int swapIndex = i;
            for(int j = i+1; j < objectArray.length; j++){
                if(currentMin.compareTo(objectArray[j]) > 0){
                    currentMin = objectArray[j];
                    swapIndex = j;
                }
            }

            E temp = objectArray[i];
            objectArray[i] = objectArray[swapIndex];
            objectArray[swapIndex] = temp;
        }
    }
}