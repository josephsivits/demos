//GradeBookTest.cpp
//Create GradeBook object, input grades and display grade report

#include "GradeBook.h"

int main(){
	GradeBook myGradeBook("CSC-2410 CS1");

	myGradeBook.displayMessage();
	myGradeBook.inputGrades();
	myGradeBook.displayGradeReport();
	
	system("pause");
	return 0;
}