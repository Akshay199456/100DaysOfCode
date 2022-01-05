import java.util.Scanner; // Scanner is in the java.util package

public class ComputeArea{
	public static void main(String [] args){
		double radius, area;
		// declaring and defining a constant which in Java is indicated with 'final' keyword
		final double PI = 22.0/7.0;

		// Creates Scanner object 
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the radius: ");
		radius = input.nextDouble();

		area = Math.PI * radius * radius;
		System.out.println("The area of the circle is : " + area);

		// Using a final variable
		System.out.println("The value of PI is : " + PI);

		// This results in an integer output even though you are using a division operator
		System.out.println("Result of division: " + 5/2 );

		// This results in a float operation; either one of the operands must be float
		System.out.println("Result of division 2: " + 5.0/2 );

		// Working on type casting
	}
}