// -----------------------------------------------------------
//
//	Implementation file of Date class for Assignment 2
//	Version 1 : 3 March 2018
//	Author    : Madyarini Grace Ariel
//
//	Remarks : 
// - There is no setDay, setMonth, and setYear mutator methods as
//   a date needs to be validated all at once since they are all
//   related (January is until 31st, February in leap year is until 29, etc.)
//	
//	Testing Notes : Uncomment TestDate.cpp to test this class
//
// -----------------------------------------------------------

// -- List of included files -- //
#include <iostream>
#include <string>
#include "Date.h" 

// -----------------------------------------------------------
// -- Default constructor -- // 
Date::Date()
{
	// Default values for day, month, and year. Set to 0 so when a user outputs the values, they are
	// aware that the value is not valid / not set yet. 
	day   = 0;
	month = 0;
	year  = 0;
}

// -----------------------------------------------------------
// -- Specific constructor -- //
Date::Date(int d, int m, int y)
{
	setDate(d, m, y);
}

// -----------------------------------------------------------
// -- Destructor -- //
Date::~Date()
{
}

// -----------------------------------------------------------
// -- Mutator -- //
// Sets the day, month, and year value
void Date::setDate(int d,int m, int y)
{
	// Default values for day, month, and year.
	day   = 0;    // if the day is not in the range of 1-31, day is set to default value 0
	month = 0;    // if the year is not in the range of 1-9999, year is set to default value 0
	year  = 0; // if month is not in the range of 1-12, month is set to default value 0

	if(d > 0 && d <= 31) 
		day = d;
	
    if(y >0 && y <= 9999) 
		year = y;

    if(m >= 1 && m <= 12) 
    {
		month = m;
		if(month == 4 || month == 6 || month == 9 || month == 11) // day is until 30
		{
			if(day > 30)
				day = 0; 
        }
        else if(month == 2)
        {
			if(year%4 == 0 && year%100 != 0 || year%400 == 0) // leap year
			{
				if(day > 29)
					day = 0; // invalid day          
			}
			else // not leap year
			{
				if(day > 28)
					day = 0; // invalid day
			}
		}          
	}
}

// -----------------------------------------------------------
// -- Accessors -- //
// Gets the day value
int Date::getDay() const
{
	return day;
}

// -----------------------------------------------------------
// Gets the month value
int Date::getMonth() const
{
	return month;
}

// -----------------------------------------------------------
// Gets the year value
int Date::getYear() const
{
	return year;
}

// -----------------------------------------------------------
// -- Operators overloading -- //
bool Date::operator<(const Date& otherDate) const
{
	if(year < otherDate.year)
		return true;
	else if(year == otherDate.year)
	{
		if(month < otherDate.month)
			return true;
		else if(month == otherDate.month)
		{
			if(day < otherDate.day)
				return true;
		}
	}
	return false;
}

// -----------------------------------------------------------
bool Date::operator>(const Date& otherDate) const
{
	return (!(*this < otherDate));
}

// -----------------------------------------------------------
bool Date::operator==(const Date& otherDate) const
{
	return (year == otherDate.year && month == otherDate.month && day == otherDate.day);
}

// -----------------------------------------------------------
bool Date::operator!=(const Date& otherDate) const
{
	return (!(*this == otherDate));
}

// -----------------------------------------------------------
ostream& operator << (ostream& osObject, const Date& date1)
{
	osObject << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear();
	return osObject;
}

// -----------------------------------------------------------
istream& operator >> (istream& isObject, Date& date1)
{
	int day, month, year;
	isObject >> day >> month >> year;
	date1.setDate(day, month, year);
	return isObject;
}

