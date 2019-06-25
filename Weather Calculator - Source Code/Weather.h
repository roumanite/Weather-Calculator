/**
******************************************************************
*
* @class Weather
* @file  Weather.h
* @brief Weather class
* @details Weather class for Assignment 2
* @version 1 
* @date 03/03/2018
* @author Madyarini Grace Ariel
*
* Remarks :
* - Unknown valid values of wind speed and solar radiation 
*   (is it supposed to have negative values?)
*
******************************************************************
*/

#ifndef H_Weather
#define H_Weather

#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"

using namespace std;

class Weather
{
public:
	/**
	* @brief Default Constructor
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	Weather();

	/**
	* @brief Sets the weather attributes all in one function
	* @param d - Day, m - Month, y - Year, hr - Hour, mn - Minute, wS - wind speed, sR - solar radiation, temp - Temperature
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	Weather(int d, int m, int y, int hr, int mn, double wS, double sR, double temp);

	/**
	* @brief Default Destructor
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	~Weather();

	/**
	* @brief Sets the date
	* @param d - Date object
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void setDate(Date d);

	/**
	* @brief Sets the time
	* @param t - Time object
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void setTime(Time t);

	/**
	* @brief Sets the wind speed
	* @param wS - wind speed
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void setWindSpeed(double wS);

	/**
	* @brief Sets the solar radiation
	* @param sR - solar radiation
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void setSolarRadiation(double sR);

	/**
	* @brief Sets the temperature
	* @param temp - Temperature
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void setTemperature(double temp);

	/**
	* @brief Accessor of date variable
	* @return Day object
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	Date getDate() const;

	/**
	* @brief Accessor of time variable
	* @return Time object
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	Time getTime() const;

	/**
	* @brief Accessor of wind speed variable
	* @return Wind speed in decimal format (km/h)
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	double getWindSpeed() const; 

	/**
	* @brief Accessor of solar radiation variable
	* @return Solar radiation in decimal format (W/m^2)
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	double getSolarRadiation() const;

	/**
	* @brief Accessor of temperature variable
	* @return Temperature in decimal format (degrees Celcius)
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	double getTemperature() const;
	bool Weather::operator>(const Weather& otherWeather) const;
	bool Weather::operator<(const Weather&) const;
	bool Weather::operator==(const Weather&) const;
	bool Weather::operator!=(const Weather&) const;
private:
	Date date;
	Time time;
	double windSpeed;
	double solarRadiation;
	double temperature;
};
ostream& operator << (ostream&, const Weather&);
istream& operator >> (istream&, Weather&);
#endif