/**
******************************************************************
*
* @class WeatherByMonth
* @file  WeatherByMonth.h
* @brief WeatherByMonth class
* @details WeatherByMonth class for Assignment 2 - aggregate Weather of the same month and year
* @version 1 
* @date 06/04/2018
* @author Madyarini Grace Ariel
*
*
******************************************************************
*/

#ifndef H_WeatherByMonth
#define H_WeatherByMonth

#include <iostream>
#include <string>

using namespace std;

class WeatherByMonth
{
public:
	/**
	* @brief Default Constructor
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	WeatherByMonth();

	/**
	* @brief Sets the WeatherByMonth attributes all in one function
	* @param y - Year, m - Month, avgwSpeed - average wind speed, avg_temp - average temperature, totalsolarRad - total solar radiation
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	WeatherByMonth(int y, int m, double avgwSpeed,  double avg_temp, double totalsolarRad);

	/**
	* @brief Default Destructor
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	~WeatherByMonth();

	/**
	* @brief Sets the year
	* @param y - Year
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void setYear(int y);

	/**
	* @brief Sets the month
	* @param m - Month
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void setMonth(int m);

	/**
	* @brief Sets the average wind speed
	* @param avgwSpeed - average wind speed
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void setAvgWS(double avgwSpeed);

	/**
	* @brief Sets the average temperature
	* @param avg_temp - average temperature
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void setAvgTemp(double avg_temp);

	/**
	* @brief Sets the total solar radiation
	* @param totalsolarRad - total solar radiation 
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void setTotalSR(double totalsolarRad);

	/**
	* @brief Accessor of year value
	* @return year in integer format
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	int getYear() const;

	/**
	* @brief Accessor of month value
	* @return month in integer format
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	int getMonth() const;

	/**
	* @brief Accessor of wind speed value
	* @return Wind speed in decimal format (m/s)
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	double getAvgWS() const; 

	/**
	* @brief Accessor of average temperature value
	* @return Average temperature in decimal format (degrees Celcius)
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	double getAvgTemp() const;

	/**
	* @brief Accessor of total solar radiation value
	* @return Total solar radiation in decimal format (W/m^2)
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	double getTotalSR() const;
	bool WeatherByMonth::operator>(const WeatherByMonth& otherWBM) const;
	bool WeatherByMonth::operator<(const WeatherByMonth& otherWBM) const;
	bool WeatherByMonth::operator==(const WeatherByMonth& otherWBM) const;
	bool WeatherByMonth::operator!=(const WeatherByMonth& otherWBM) const;

private:
	int year;
	int month;
	double avgWS;
	double avgTemp;
	double totalSR;
};
ostream& operator << (ostream&, const WeatherByMonth&);
istream& operator >> (istream&, WeatherByMonth&);
#endif