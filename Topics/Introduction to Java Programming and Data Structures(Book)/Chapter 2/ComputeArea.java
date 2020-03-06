import java.util.Scanner; // Scanner is in the java.util package

public class ComputeArea{
	public static void main(String [] args){
		double radius, area;
		final double PI = 22.0/7.0;

		// Creates Scanner object 
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the radius: ");
		radius = input.nextDouble();

		area = Math.PI * radius * radius;
		System.out.println("The area of the circle is : " + area);

		System.out.println("The value of PI is : " + PI);
	}
}