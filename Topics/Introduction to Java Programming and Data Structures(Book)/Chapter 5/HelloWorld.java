import java.util.Scanner;

class HelloWorld{
	public static void main(String [] args){
		int sum = 0;
		Scanner input = new Scanner(System.in);

		// Testing input and output redirections by reading from and to a file
		while(input.hasNext())
			sum += input.nextInt();
		System.out.println("The sum of the integers: " + sum);
	}
}