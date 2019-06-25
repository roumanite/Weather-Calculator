// -----------------------------------------------------------
//
//	Implementation file of WeatherByMonth class for Assignment 2
//	Version 1 : 6 April 2018
//	Author    : Madyarini Grace Ariel
//	
//	Testing Notes : Uncomment TestWeatherByMonth.cpp to test this class
//
// -----------------------------------------------------------
// -- List of included files -- //
#include <iostream>
#include "WeatherByMonth.h" 

// -----------------------------------------------------------
// -- Default constructor -- // 
WeatherByMonth::WeatherByMonth()
{
	year    = 0;
	month   = 0;
	avgWS   = -999; // -999 means not available
	avgTemp = -999;
	totalSR = -999;
}

// -----------------------------------------------------------
// -- Specific constructor -- //
WeatherByMonth::WeatherByMonth(int y, int m, double avgwSpeed,  double avg_temp, double totalsolarRad)
{
	setYear(y);
	setMonth(m);
	avgWS = avgwSpeed;
	avgTemp = avg_temp;
	totalSR = totalsolarRad;
}

// -----------------------------------------------------------
// -- Destructor -- //
WeatherByMonth::~WeatherByMonth()
{
}

// -----------------------------------------------------------
// -- Mutators -- //
// Sets year value
void WeatherByMonth::setYear(int y)
{
	if(y >= 1 && y <= 9999)
		year = y;
	else 
		year = 0;
}

// -----------------------------------------------------------
// Sets month value
void WeatherByMonth::setMonth(int m)
{
	if(m >= 1 && m <= 12)
		month = m;
	else
		month = 0;
}

// -----------------------------------------------------------
// Sets average wind speed value
void WeatherByMonth::setAvgWS(double avgwSpeed)
{
	avgWS = avgwSpeed;
}

// -----------------------------------------------------------
// Sets average temperature value
void WeatherByMonth::setAvgTemp(double avg_temp)
{
	avgTemp = avg_temp;
}

// -----------------------------------------------------------
// Sets total solar radiation value
void WeatherByMonth::setTotalSR(double totalsolarRad)
{
	totalSR = totalsolarRad;
}

// -----------------------------------------------------------
// -- Accessors -- //
// Gets year value
int WeatherByMonth::getYear() const
{
	return year;
}

// -----------------------------------------------------------
// Gets month value
int WeatherByMonth::getMonth() const
{
	return month;
}

// -----------------------------------------------------------
// Gets average wind speed value
double WeatherByMonth::getAvgWS() const
{
	return avgWS;
}

// -----------------------------------------------------------
// Gets average temperature value
double WeatherByMonth::getAvgTemp() const
{
	return avgTemp;
}

// -----------------------------------------------------------
// Gets total solar radiation value
double WeatherByMonth::getTotalSR() const
{
	return totalSR;
}

// -----------------------------------------------------------
// -- Operators overloading -- //
bool WeatherByMonth::operator<(const WeatherByMonth& otherWBM) const
{
	if(year < otherWBM.year)
		return true;
	else if(year < otherWBM.year)
	{
		if(month < otherWBM.month)
			return true;
	}
	return false;
}

// -----------------------------------------------------------
bool WeatherByMonth::operator>(const WeatherByMonth& otherWBM) const
{
	return (!(*this < otherWBM));
}

// -----------------------------------------------------------
bool WeatherByMonth::operator==(const WeatherByMonth& otherWBM) const
{
	return (year == otherWBM.year && month == otherWBM.month);
}

// -----------------------------------------------------------
bool WeatherByMonth::operator!=(const WeatherByMonth& otherWBM) const
{
	return (!(*this == otherWBM));
}

// -----------------------------------------------------------
ostream& operator << (ostream& osObject, const WeatherByMonth& wbm)
{
	osObject << "Month                 : " << wbm.getMonth() << endl
	<< "Year                  : " << wbm.getYear() << endl
	<< "Average wind speed    : " << wbm.getAvgWS() << endl
	<< "Average temperature   : " << wbm.getAvgTemp() << endl
	<< "Total solar radiation : " << wbm.getTotalSR() << endl;
	return osObject;	
}

// -----------------------------------------------------------
istream& operator >> (istream& isObject, WeatherByMonth& wbm)
{
	int month, year;
	double avgWS, avgTemp, totalSR;
	isObject >> month >> year >> avgWS >> avgTemp >> totalSR;
	wbm.setMonth(month);
	wbm.setYear(year);
	wbm.setAvgWS(avgWS);
	wbm.setAvgTemp(avgTemp);
	wbm.setTotalSR(totalSR);
	return isObject;
}