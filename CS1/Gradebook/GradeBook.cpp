// GradeBook.cpp
// Member-Function definitions for class GradeBook that uses a switch statement to count A-F grades.

#include <iostream>
using namespace std;

#include "GradeBook.h"

// Constructor initializes courseName with string supplied as argument
GradeBook::GradeBook(string name){
	setCourseName(name);
	aCount = 0;
	bCount = 0;
	cCount = 0;
	dCount = 0;
	fCount = 0;
} // End GradeBook constructor

// Function to set the course name; limits name to 25 or fewer characters
void GradeBook::setCourseName(string name){
	if (name.length() <= 25)
		courseName = name;
	else{
		courseName = name.substr(0, 25);
		cout << "Name \"" << name << "\" exceeds maximum length (25).\n" << "Limiting courseName to first 25 characters.\n" << endl;
	}
} // end function setCourseName

// function to retrieve the courseName
string GradeBook::getCourseName(){
	return courseName;
} // end function to getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage(){
	// this statement calls getCourseName to get the name of the course this GradeBook represents
	cout << "Welcome to the gradebook for \n" << getCourseName() << "!\n" << endl;
} // end function displayMessage

// input arbitrary number of grades from user; update grade counter
void GradeBook::inputGrades(){
	int grade;

	cout << "Enter the letter grades." << endl << "Enter the EOF character to end input." << endl;

	//loop until user types end of-file key seuqence
	while ((grade = cin.get()) != EOF){
		//determine which grade was entered
		switch (grade){
		case 'A':
		case 'a':
			aCount++;
			break;

		case 'B':
		case 'b':
			bCount++;
			break;

		case 'C':
		case 'c':
			cCount++;
			break;

		case 'D':
		case 'd':
			dCount++;
			break;

		case 'F':
		case 'f':
			fCount++;
			break;

		case '\n':
		case '\t':
		case ' ':
			break;

		default:
			cout << "Incorrect letter grade entered. Enter a new grade." << endl;
			break;
		} // end switch
	} // end while
} // end function inputGrades

//display a report based on the grades entered by user
void GradeBook::displayGradeReport(){
	//output summary of results
	cout << "\n\nNumber of students who received each letter grade:"
		<< "\nA: " << aCount
		<< "\nB: " << bCount
		<< "\nC: " << cCount	//display number of A-F grades
		<< "\nD: " << dCount
		<< "\nF: " << fCount
		<< endl;
}// end function displayGradeReport