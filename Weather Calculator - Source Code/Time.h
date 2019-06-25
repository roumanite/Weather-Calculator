/**
**************************************************************************************************************
*
* @class Time
* @file  Time.h
* @brief A Time class with hour and minute attributes. Time in here does not mean duration but time of clock.
* @details Time Class for Assignment 2
* @version 1 
* @date 03/03/2018
* @author Madyarini Grace Ariel
*
*
* Remarks :
* - Valid value for hour is 00 until 23. 
* - Valid value for minute is 00 until 59.
*
**************************************************************************************************************
*/
#ifndef H_TIME
#define H_TIME

#include <iostream>

using namespace std;

class Time
{
public:
	
	/**
	* @brief Default Constructor
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	Time();

	/**
	* @brief Specific Constructor
	* @param h - Hour
	* @param m - Minute
	* @pre hour and minute values must be valid (hour 0-23, minute 0-59)
	* @post hour and minute values are updated
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	Time(int h, int m);

	/**
	* @brief Default Destructor
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	~Time();

	/**
	* @brief Mutator of hour variable
	* @param h - Hour
	* @pre hour value must be valid (0-23)
	* @post hour value is updated
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void setHour(int h);

	/**
	* @brief Mutator of minute variable
	* @param m - Minute
	* @pre minute value must be valid (0-59)
	* @post minute value is updated
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void setMinute(int m);

	/**
	* @brief Mutator of hour and minute variables
	* @param h - Hour
	* @param m - Minute
	* @pre hour value must be valid (0-23)
	* @post hour value is updated
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void setTime(int h, int m);
	
	/**
	* @brief Accessor of hour variable
	* @return Hour value in integer format
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	int getHour() const ; 

	/**
	* @brief Accessor of minute variable
	* @return Minute value in integer format
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	int getMinute() const;

	bool operator<(const Time&) const;
	bool operator>(const Time&) const;
	/**
	* @brief Overloading of binary operator '=='
	* @return true if the left operand is the same time with the right operand
	* @date 03/21/2018
	* @author Madyarini Grace Ariel
	*/
	bool operator==(const Time&) const;

	/**
	* @brief Overloading of binary operator '!='
	* @return true if the left operand is not the same time with the right operand
	* @date 03/21/2018
	* @author Madyarini Grace Ariel
	*/
	bool operator!=(const Time&) const;
private:
	int hour;
	int minute;
};
ostream& operator << (ostream&, const Time&);
istream& operator >> (istream&, Time&);
#endif