// Date.h

#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date(int = 1, int = 1, int = 2000);	// default constructor
	void print();	// print function
	void setDate(int, int, int);	// set month, day, year

	void setMonth(int);		
	void setDay(int);	
	void setYear(int);
	
	int getMonth();	
	int getDay();	
	int getYear();	
					
	void nextDay();

private:
	int month;	// 1 - 12
	int day;
	int year;

	bool leapYear(); // leap year
	int monthDays();
}; // end class Date

#endif