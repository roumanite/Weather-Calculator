// -----------------------------------------------------------
//
//	Implementation file of Weather class for Assignment 2
//	Version 1 : 3 March 2018
//	Author    : Madyarini Grace Ariel
//
//	Remarks : 
//	- Unknown valid values of wind speed and solar radiation 
//    (is it supposed to have negative values?)
//
//	Testing Notes : Uncomment TestWeather.cpp to test this class
//
// -----------------------------------------------------------

// -- List of included files -- //
#include <iostream>
#include "Weather.h" 

// -----------------------------------------------------------
// -- Default constructor -- // 
Weather::Weather()
{
	windSpeed = 0;
	solarRadiation = 0;
	temperature = 0;
}

// -----------------------------------------------------------
// -- Specific constructor -- //
Weather::Weather(int d, int m, int y, int hr, int mn, double wS, double sR, double temp):date(d, m, y),time(hr, mn)
{
	windSpeed = wS;
	solarRadiation = sR;
	temperature = temp;
}

// -----------------------------------------------------------
// -- Destructor -- //
Weather::~Weather()
{
}

// -----------------------------------------------------------
// -- Mutators -- //
// Sets date value
void Weather::setDate(Date d)
{
	date = d;
}

// -----------------------------------------------------------
// Sets time value
void Weather::setTime(Time t)
{
	time = t;
}

// -----------------------------------------------------------
// Sets wind speed value
void Weather::setWindSpeed(double wS)
{
	windSpeed = wS;
}

// -----------------------------------------------------------
// Sets solar radiation value
void Weather::setSolarRadiation(double sR)
{
	solarRadiation = sR;
}

// -----------------------------------------------------------
// Sets temperature value
void Weather::setTemperature(double temp)
{
	temperature = temp;
}

// -----------------------------------------------------------
// -- Accessors -- //
// Gets date value
Date Weather::getDate() const
{
	return date;
}

// -----------------------------------------------------------
// Gets time value
Time Weather::getTime() const
{
	return time;
}

// -----------------------------------------------------------
// Gets wind speed value
double Weather::getWindSpeed() const
{
	return windSpeed;
}

// -----------------------------------------------------------
// Gets solar radiation value
double Weather::getSolarRadiation() const
{
	return solarRadiation;
}

// -----------------------------------------------------------
// Gets temperature value
double Weather::getTemperature() const
{
	return temperature;
}

// -----------------------------------------------------------
// -- Operators overloading -- //
bool Weather::operator<(const Weather& otherWeather) const
{
	if (date < otherWeather.date)
		return true;
	else if (date == otherWeather.date)
    {
		if(time < otherWeather.time)
			return true;
    }
	return false;
}

// -----------------------------------------------------------
bool Weather::operator>(const Weather& otherWeather) const
{
    return (!(*this < otherWeather));
}

// -----------------------------------------------------------
bool Weather::operator==(const Weather& otherWeather) const
{
	return (date == otherWeather.date && time == otherWeather.time);
}

// -----------------------------------------------------------
bool Weather::operator!=(const Weather& otherWeather) const
{
	return (!(*this == otherWeather));
}

// -----------------------------------------------------------
ostream& operator << (ostream& osObject, const Weather& weather1)
{
	osObject << "Date            : " << weather1.getDate() << endl 
    << "Time            : " << weather1.getTime() << endl
	<< "Wind speed      : " << weather1.getWindSpeed() << endl
	<< "Solar radiation : " << weather1.getSolarRadiation() << endl
	<< "Temperature     : " << weather1.getTemperature() << endl;
	return osObject;
}

// -----------------------------------------------------------
istream& operator >> (istream& isObject, Weather& weather1)
{
	int day, month, year;
	int h, m;
	double windSpd, solarRad, temp;
	isObject >> day >> month >> year >> h >> m >> windSpd >> solarRad >> temp;
	Date date1;
	Time time1;
	date1.setDate(day, month, year);
	time1.setTime(h, m);
	weather1.setDate(date1);
	weather1.setTime(time1);
	weather1.setWindSpeed(windSpd);
	weather1.setSolarRadiation(solarRad);
	weather1.setTemperature(temp);
	return isObject;
}

