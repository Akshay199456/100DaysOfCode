/*
	javac Bank.java - compiles the file to find errors
	java Bank - runs the file after errors cleared
*/

import java.io.*;

public class Bank{
	private int amount;
	public static int staticAmount = 300;

	public Bank(){
		// Default constructor
		amount = 0;
	}


	public int getAmount(){
		// Displays amount to the user
		return amount;
	}

	private void setAmount(int value){
		// Sets particular amount in the bank
		amount += value;
	}

	public static int staticGetAmount(){
		return staticAmount;
	}

	public static void main(String [] args){
		Bank money = new Bank();
		System.out.println("Welcome to Akshay Bank!");
		System.out.println("Your current balance is: " + money.getAmount());
		money.setAmount(500);
		System.out.println("After depositing $500, your balance is: " + money.getAmount());
		money.setAmount(-200);
		System.out.println("After withdrawing $200, your balance is: " + money.getAmount());
		System.out.println("Static get amount: " + Bank.staticGetAmount());
	}
}