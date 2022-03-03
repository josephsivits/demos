//Date.cpp
// Member-function definitions for class Date

#include <iostream>
using namespace std;

#include "Date.h"

Date::Date(int m, int d, int y)
{
	setDate(m, d, y);
} // end Date constructor

void Date::setDate(int mo, int dy, int yr)
{
	setMonth(mo);
	setDay(dy);
	setYear(yr);
} // end function setDate

void Date::setDay(int d)
{
	if (month == 2 && leapYear())
		day = (d <= 29 && d >= 1) ? d : 1;
	else
		day = (d <= monthDays() && d >= 1) ? d : 1;
} // end function setDay

void Date::setMonth(int m)
{
	month = m <= 12 && m >= 1 ? m : 1;
}	// end function setMonth

void Date::setYear(int y)
{
	year = y >= 1900 ? y : 1900;
} // end function setYear

int Date::getDay() 
{
	return day;
} // end function getDay

int Date::getMonth()
{
	return month;
} // end function getMonth

int Date::getYear()
{
	return year;
} // end function getYear

void Date::print()
{
	cout << month << '-' << day << '-' << year << '\n'; 
} // end function print

void Date::nextDay()
{
	(day > monthDays()) ? ++month, day = 1 : day++;
	setDate(month, day, year);

}

bool Date::leapYear()
{
	if (getYear() % 400 == 0 || (getYear() % 4 == 0 && getYear() % 100 != 0))
		return true;
	else
		return false;
}

int Date::monthDays()
{
	const int days[12] =
		{ 31, 28, 31, 30, 31, 31 , 30, 31, 30, 31 };

	return getMonth() == 2 && leapYear() ? 29 : days[getMonth() - 1];
} // end function monthDays