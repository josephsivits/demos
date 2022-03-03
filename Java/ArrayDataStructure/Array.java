/*

Please use a one-dimensional array to solve the following problem:
Please write an application that inputs five numbers, each of wiich is between 10 and 100, inclusive.
As each number is read, please display it only if it is not a duplicate of a number already read.
Please provide for the "worst case," in which all five numbers are different.
Please use the smallest possible array to solve this problem.
Please  display the complete set of unique values input after the inpust each new value.
Please do it in calling an object.

*/
import java.util.Scanner; // to  input from user

public class Array {

	private int[] javaArray = new int[30];
	private int size = 0;

	public void printArr(int s) {
		for(int i = 0; i < s; i++) {
			System.out.print(javaArray[i] + " ");
			if(i % 6 == 5) System.out.println(); // prints into 6 column rows
		} // end for loop
		System.out.println();
	} // end method printArr

	public boolean inArray(int x) {
		int s = getSize();
		for(int i = 0; i < s; i++) {
			if(javaArray[i] == x) {
				System.out.println(x + " has already been entered");
				 return true;
			} // end if
		} // end for
		return false;
	} // end method inArray

	public void insertArray(int x, int i) {
		javaArray[i] = x;
	} // end method insertArray

	public static boolean inRange(int x) {
		if(x > 100 || x < 10) {
			System.out.println("ERROR: " + x + " NOT IN RANGE (10-100 INCLUSIVE)");
			return false;
		}
		return true;
	} // end method inRange

	public void setSize(int s) {
		this.size = s;
	} // end method setSize

	public final int getSize() {
		return this.size;
	} // end method getSize
}
