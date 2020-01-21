 import java.util.*;
 import java.io.*;

class QueueTester{
	public static void main(String [] args){
		ArrayList<Integer> queue = new ArrayList<>();
		
		// Inserting elements into queue
		for(int i=0; i<5; i++)
			queue.add(i);

		for(int i=0; i<queue.size(); i++){
			System.out.println("Value: " + i);
		}
	}
}