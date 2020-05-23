import java.util.HashMap;
import java.util.Map;

// Working on Chapter 21
public class Solution {
    public static void main(String [] args){
        String element = "This is this america";
        Map<String, Integer> map = new HashMap<String, Integer>();
        generateMap(element.toLowerCase(), map);
        printMap(map);
    }

	private static void generateMap(String element, Map<String, Integer> map) {
        String [] wordTokens = element.split(" ");
        for(String token: wordTokens){
            if(!map.containsKey(token))
                map.put(token, 1);
            else
                map.put(token, map.get(token) + 1);
        }
    }
    
    private static void printMap(Map<String, Integer> map){
        for(Map.Entry<String, Integer> iterator: map.entrySet()){
            System.out.println("Key: " + iterator.getKey() + " Value: " + iterator.getValue());
        }
    }
}