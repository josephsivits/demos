// Date Test.cpp
#include <iostream>
using namespace std;

#include "Date.h" // include definitions of class Date

int main()
{
	const int MAXDAYS = 16;
	Date d(12, 5, 2018); // instantiate object d of class Date

	// output Date object d's value
	for (int loop = 1; loop <= MAXDAYS; ++loop)
	{
		d.print();
		d.nextDay();
	}
	cout << endl;

	//system("pause");
} // end main