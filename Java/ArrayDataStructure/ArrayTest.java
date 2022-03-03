 /*

Please use a one-dimensional array to solve the following problem:
XX Please write an application that inputs five numbers, each of which is between 10 and 100 inclusive.
XX As each number is read, please display it only if it is not a duplicate of a number already read.
XX Please provide for the "worst case," in which all five numbers are different.
XX Please use the smallest possible array to solve this problem.
XX Please display the complete set of unique values input after the input each new value.
XX Please do it in calling an object.

*/

import java.util.Scanner;

public class ArrayTest {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.println("Array class in Java\nby Joseph Sivits\n");

		System.out.print("Enter the size of the array: ");
		int size = input.nextInt();
		while(size <= 0) {
			System.out.println("ERROR: " + size + " is out of bounds! (Try a number greater than 1)\n");
			System.out.println("Enter the size of the array: ");
			size = input.nextInt();
		}

		Array myArray = new Array();
		myArray.setSize(size);
		int arrSize = 0;
		while(arrSize < size) {
			System.out.print("\nEnter number: ");
			int userInput = input.nextInt();
			// check for if user input is in range
			if(!myArray.inRange(userInput))
				continue;
			// check for redundancy
			if(myArray.inArray(userInput))
				continue;
			// add to the array
			myArray.insertArray(userInput, arrSize);
			myArray.printArr(++arrSize);
		} // end while
	} // end method main
} // end class ArrayTest
