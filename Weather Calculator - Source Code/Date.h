/**
*****************************************************************************
*
* @class Date
* @file  Date.h
* @brief A Date class with day, month, and year attributes
* @details Date Class for Assignment 2
* @version 1 
* @date 03/03/2018
* @author Madyarini Grace Ariel
*
*
* Remarks :
* - There is no setDay, setMonth, and setYear mutator methods as
*   a date needs to be validated all at once since they are all
*   related (January is until 31st, February in leap year is until 29, etc.)
*
*****************************************************************************
*/

#ifndef H_Date
#define H_Date

#include <iostream>

using namespace std;

class Date
{
public:
	/**
	* @brief Default Constructor that sets day to 0, month to 0, year to 0
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	Date();

	/**
	* @brief Specific Constructor that sets day, month, and year all in one function
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	Date(int day, int month, int year);

	/**
	* @brief Default Destructor
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	~Date();

	// Mutators ---------
	/**
	* @brief Mutator of day, month, and year variables
	* @param day - Day
	* @param month - Month
	* @param year - Year
	* @pre day, month, and year must be valid
	* @post day, month, and year values are updated
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	void setDate(int day, int month, int year);
	
	// Accesors
	/**
	* @brief Accessor of day variable
	* @return Day value in integer format
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	int getDay() const; 

	/**
	* @brief Accessor of month variable
	* @return Month value in integer format
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	int getMonth() const;

	/**
	* @brief Accessor of year variable
	* @return Year value in integer format
	* @date 03/03/2018
	* @author Madyarini Grace Ariel
	*/
	int getYear() const;

	/**
	* @brief Overloading of binary operator '<'
	* @return true if the left operand is a date earlier than the right operand
	* @date 03/21/2018
	* @author Madyarini Grace Ariel
	*/
	bool operator<(const Date&) const;

	/**
	* @brief Overloading of binary operator '>'
	* @return true if the left operand is a date later than the right operand
	* @date 03/21/2018
	* @author Madyarini Grace Ariel
	*/
	bool operator>(const Date&) const;

	/**
	* @brief Overloading of binary operator '=='
	* @return true if the left operand is the same date with the right operand
	* @date 03/21/2018
	* @author Madyarini Grace Ariel
	*/
	bool operator==(const Date&) const;

	/**
	* @brief Overloading of binary operator '!='
	* @return true if the left operand is not the same date with the right operand
	* @date 03/21/2018
	* @author Madyarini Grace Ariel
	*/
	bool operator!=(const Date&) const;
private:
	int day;
	int month;
	int year;
};
ostream& operator << (ostream&, const Date&);
istream& operator >> (istream&, Date&);
#endif
