// -----------------------------------------------------------
//
//	Implementation file of Time class for Assignment 2
//	Version 1 : 3 March 2018
//	Author    : Madyarini Grace Ariel
//
//	Remarks : 
//		- Valid value for hour is 00 until 23. 
//		- Valid value for minute is 00 until 59.
//	
//	Testing Notes : Uncomment TestTime.cpp to test this class.
//
// -----------------------------------------------------------

// -- List of included files -- //
#include <iostream>
#include <string>
#include "Time.h" 

// -----------------------------------------------------------
// -- Default constructor -- // 
Time::Time()
{
	hour   = 0;
	minute = 0;
}

// -----------------------------------------------------------
// -- Specific constructor -- //
Time::Time(int h, int m)
{
	setHour(h);
	setMinute(m);
}

// -----------------------------------------------------------
// -- Destructor -- //
Time::~Time()
{
}

// -----------------------------------------------------------
// -- Mutators -- //
// Accepts an hour value and validates it.
// If it is 0-23, the hour private variable is updated.
// Otherwise, set hour to 0.
void Time::setHour(int h)
{
	if(h < 0 || h > 23)
		hour = 0;
	else
		hour = h;
}

// -----------------------------------------------------------
// Accepts a minute value and validates it.
// If it is 0-59, the minute private variable is updated.
// Otherwise, set minute to 0.
void Time::setMinute(int m)
{
	if(m < 0 || m > 59)
		minute = 0;
	else
		minute = m;
}

// -----------------------------------------------------------
// Accepts hour and value and validates them.
// Uses the setHour and setMinute functions.
void Time::setTime(int h, int m)
{
	setHour(h);
	setMinute(m);
}

// -----------------------------------------------------------
// -- Accessors -- //
// Gets hour value
int Time::getHour() const
{
	return hour;
}

// -----------------------------------------------------------
// Gets minute value
int Time::getMinute() const
{
	return minute;
}

// -----------------------------------------------------------
// -- Operators overloading -- //
bool Time::operator<(const Time& otherTime) const
{
	int testH = hour;
	int otherTestH = otherTime.hour;

	if(hour == 0)
		testH = 24;
	if(otherTime.hour == 0)
		otherTestH = 24;

	if(testH < otherTestH)
		return true;
	else if(testH == otherTestH)
	{
		if(minute < otherTime.minute)
			return true;
	}
	return false;
}

bool Time::operator>(const Time& otherTime) const
{
	return (!(*this < otherTime));
}

bool Time::operator==(const Time& otherTime) const
{
	return (hour == otherTime.hour && minute == otherTime.minute);
}

// -----------------------------------------------------------
bool Time::operator!=(const Time& otherTime) const
{
	return (!(*this == otherTime));
}

// -----------------------------------------------------------
ostream& operator << (ostream& osObject, const Time& time1)
{
	if(time1.getHour() < 10)
		osObject << "0" << time1.getHour();
	else
		osObject << time1.getHour();

	osObject << " : ";

	if(time1.getMinute() < 10)
		osObject << "0" << time1.getMinute();
	else
		osObject << time1.getMinute();
	return osObject;
}

// -----------------------------------------------------------
istream& operator >> (istream& isObject, Time& time1)
{
	int hour, minute;
	isObject >> hour >> minute;
	time1.setHour(hour);
	time1.setMinute(minute);
	return isObject;
}
