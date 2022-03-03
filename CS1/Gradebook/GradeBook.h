// GradeBook.h
// Definition of class GradeBook that counts A, B, C, D and F grades.
// Member functions are defined in GradeBook.cpp

#include <string>
using namespace std;

// GradeBook class definition
class GradeBook {
public:
	GradeBook(string);

	void setCourseName(string);	// constructor intiializes course name
	string getCourseName();		// function to retrieve course name

	void displayMessage();		// display welcome message
	void inputGrades();			// input arbitrary number of grades from user
	void displayGradeReport();	// display a report based on the grades

private:
	string courseName;		// course name for this GradeBook
	int aCount;			
	int bCount;
	int cCount;				// count for A-F grades
	int dCount;
	int fCount;
};	// end class GradeBook