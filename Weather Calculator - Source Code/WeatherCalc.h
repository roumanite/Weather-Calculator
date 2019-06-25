/**
*******************************************************************************************
*
* @class Weather.h
* @file WeatherCalc.h
* @brief A weather data calculation class
* @details Weather Data Calculation class for Assignment 2
* @version 1 
* @date 03/03/2018
* @author Madyarini Grace Ariel
*
* Remarks :
* - file name, a Vector of Weather objects, year integer, month integer can be 
*   designed as members of the class, but I prefer them not to be because I give
*   freedom for the client not to use the user interface provided by the functions
*   Menu, setOption, setMonthInput, and setYearInput. File name, Vector, year, and month
*   become parameters for the function instead.
*
*******************************************************************************************
*/

#ifndef H_WEATHERCALC
#define H_WEATHERCALC

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include "Date.h"
#include "Time.h"
#include "Vector.h"
#include "Weather.h"
#include "WeatherByMonth.h"
#include "WeatherCalc.h"
#include "nodeBST.h"

using namespace std;

class WeatherCalc
{
public:
	/**
	* @brief Default Constructor
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	WeatherCalc();

	/**
	* @brief Default Destructor
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	~WeatherCalc();

	/**
	* @brief Processes file names into a Vector. 
	* @param fileNames - Vector of file names, fileName - Name of file to be processed.
	* @return Returns true if succeed and false if not succeed.
	* @pre filename must be correct and include directory if it is in a folder
	* @post Vector is filled with file names from fileName
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	bool processFileNames(Vector<string>& fileNames, string fileName);

	/**
	* @brief Processes the data inside the file into a Map. 
	* @param wMap - Map of Weather objects, fileName - Name of file to be processed.
	* @return Returns true if succeed and false if not succeed.
	* @pre filename must be correct and include directory if it is in a folder
	* @post Map is filled with Weather objects from fileName
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	bool processInputFile(map<string, Weather>& wMap, string fileName);
	
	/**
	* @brief Gives the user interface by showing menu options to select. 
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void Menu();

	/**
	* @brief Prompts for option
	* @return Option number
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	int getOptionInput();

	/**
	* @brief Execute option 1 : calculate and show average wind speed and average
	* temperature for a specified month and year.
	* @param weatherTree - Tree of WeatherByMonth objects
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void option1(nodeBST<WeatherByMonth>& weatherTree);

	/**
	* @brief Execute option 2 : calculate and show average wind speed and average
	* temperature for each month of a specified year.
	* @param weatherTree - Tree of WeatherByMonth objects
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void option2(nodeBST<WeatherByMonth>& weatherTree);

	/**
	* @brief Execute option 3 : calculate and show total solar radiation in kWh/m^2 for each
	* month of a specified year.
	* @param weatherTree - Tree of WeatherByMonth objects
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void option3(nodeBST<WeatherByMonth>& weatherTree);

	/**
	* @brief Execute option 4 : calculate average wind speed, average temperature and total solar
	* radiation in kWh/m^2 for each month of a specified year. 
	* @param weatherTree - Tree of WeatherByMonth objects
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void option4(nodeBST<WeatherByMonth>& weatherTree);

	/**
	* @brief Execute option 5 : Show times of the highest solar radiation of a Date given
	* @param weatherMap - Map of Weather objects
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void option5(map<string, Weather>& weatherMap);

	/**
	* @brief Get count of objects that have solar radiation more than 100 W/m^2 
	* @param weatherList - Vector of Weather objects
	* @return Count in integer format
	* @pre Vector must be filled
	* @post number of data of interest is returned
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	int getNumOfSR(Vector<Weather>& list);

	/**
	* @brief Calculate average wind speed.
	* @param weatherList - Vector of Weather objects
	* @pre Vector must be filled
	* @post number of data of interest is returned
	* @return Average wind speed in km/h decimal value format
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	double calcAvgSpeed(Vector<Weather>& list);

	/**
	* @brief Calculate average temperature.
	* @param weatherList - Vector of Weather objects
	* @pre Vector must be filled
	* @post number of data of interest is returned
	* @return Average temperature in degrees Celcius decimal value format
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	double calcAvgTemp(Vector<Weather>& list);

	/**
	* @brief Calculate total solar radiation.
	* @param weatherList - Vector of Weather objects
	* @pre Vector must be filled
	* @post number of data of interest is returned
	* @return total solar radiation in kWh/m^2 decimal value format
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	double calcTotalSRad(Vector<Weather>& list);

	/**
	* @brief Convert a number in Watt per 10 minutes to kilowatt per hour. 
	* @param WPer10Min - A number that is in Watt per 10 minutes decimal value format.
	* @pre the parameter intended is indeed in Watt per 10 minutes measurement
	* @post value updated to kWh
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void convertTokWh(double &WPer10Min);

	/**
	* @brief Convert a number in meter per second to kilometer per hour
	* @param MPerS - A number that is in meter per second format.
	* @pre the parameter intended is indeed in meter per second measurement
	* @post value updated to km per h
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	void convertTokmH(double &MPerS);

	/**
	* @brief Convenient function for any user to put in his or her program so that there is no worries in the order
	* of executing all the functions above. 
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void run(string indexFileName = "not set");

	/**
	* @brief To aggregate Weather objects inside a Map to WeatherByMonth objects in a BST.
	* @param weatherTree - BST to be filled, wMap - contains the data to be grouped
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void groupMonthly(nodeBST<WeatherByMonth>& weatherTree, map<string, Weather>& wMap);
private:
	const static string monthList[];
	const static double KILOWATT;
	const static double KILOMETER;

	/**
	* @brief A helper method for option1(), option2(), option3(), option4(). Gets and validates month input.
	* @return Month in integer format
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	int getMonthInput();

	/**
	* @brief A helper method for option1(), option2(), option3(), option4(). Gets and validates year input.
	* @return Year in integer format.
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	int getYearInput();

	/**
	* @brief A helper method for option5(). Gets and validates Date input (d/m/yyyy).
	* @return Date in string format.
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	string getDateInput();

	/**
	* @brief A helper method for option1(), option2(), option3(), option4(). Gets and validates month integer.
	* @param month - Month
	* @return Boolean true if the month is in the range 1-12.
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	bool checkMonth(int month) const;

	/**
	* @brief A helper method for option1(), option2(), option3(), option4(). Gets and validates year integer.
	* @param year - Year
	* @return Boolean true if the year is in the range 1-9999
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	bool checkYear(int year) const;

	/**
	* @brief A helper method for option5(). Gets and validates Date integers.
	* @param d - Day, m - Month, y - Year
	* @return Boolean true if the Date is valid 
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	bool checkDate(int d, int m, int y) const;

	/**
	* @brief A helper method for processInputFile(). Check whether a string is able to be converted to double format. 
	* @param s - string to be checked
	* @return Boolean true if the string is numeric
	* @date 06/04/2018
	* @author Madyarini Grace Ariel
	*/
	bool isNumeric(const string s) const;
};
#endif