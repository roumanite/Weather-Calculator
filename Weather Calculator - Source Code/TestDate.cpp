// -----------------------------------------------------------
//
//	Test file of Date class for Assignment 2
//	Version 1 : 3 March 2018
//	Author    : Madyarini Grace Ariel	
//
//	Testing Notes : Uncomment to test Date class
//	 
// -----------------------------------------------------------

// -- List of included files -- //
#include <iostream>
#include "Date.h"
/*
int main()
{ 
	
	cout << " -- Testing default constructor --\n";
	Date date1;
	cout << "Date set by default constructor             : " << date1 << endl << endl; // Testing overloading operator 

	cout << " -- Testing specific constructor --\n";
	Date date2(1, 2, 2014);
	cout << "Date set by specific constructor (1,2,2014) : " << date2 << endl << endl;

	cout << " -- Testing setDate function --\n";
	date2.setDate(1, 12, 2018);
	cout << "Date set by setDate(1,12,2018)              : " << date2 << endl << endl;

	cout << " -- Testing validity test of day, month, and year --\n";
	Date date3(-1, 32, -900); // Invalid day, month, and year. Should set to default value of 1, 1, and 2000.
	cout << "Date -1/32/-900 is set to        : " << date3 << endl;
	date3.setDate(31, 11, 2018); // November is not until 31
	cout << "Date : 31/11/2018 is set to      : " << date3 << endl;
	date3.setDate(29, 2, 2018); // 2018 is not a leap year
	cout << "Date : 29/2/2018 is set to       : " << date3 << endl << endl;

	cout << " -- Testing accessors --\n";
	cout << "Date : " << date3 << endl;
	cout << "getDay() returns   : " << date3.getDay() << endl;
	cout << "getMonth() returns : " << date3.getMonth() << endl;
	cout << "getYear() returns  : " << date3.getYear() << endl;
	
	cout << " -- Testing overloading of binary operators --\n";
	Date date5(11, 12, 2000);
	Date date6(11, 1, 2001);
	cout << "date5 < date6 returns : " << (date5 < date6) << endl;
	cout << "date5 > date6 returns : " << (date5 > date6) << endl;
	cout << "date5 == date6 returns : " << (date5 == date6) << endl;
	cout << "date5 != date6 returns : " << (date5 != date6) << endl;

	system("PAUSE");
    return 0;
}
*/