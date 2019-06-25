// -----------------------------------------------------------
//
//	Test file of Time class for Assignment 2
//	Version 1 : 3 March 2018
//	Author    : Madyarini Grace Ariel	
//
//	Testing Notes : Uncomment to test Time class
//	
// -----------------------------------------------------------

// -- List of included files -- //
#include <iostream>
#include "Time.h"
/*
int main()
{ 
	cout << " -- Testing default constructor --\n";
	Time time1;
	cout << "Time set by default constructor         -> " << time1 << endl << endl; // Testing overloading operator 

	cout << " -- Testing specific constructor --\n";
	Time time2(2,56);
	cout << "Time set by specific constructor (2:56) -> " << time2 << endl << endl;

	cout << " -- Testing setHour and setMinute functions --\n";
	time2.setHour(20);
	time2.setMinute(45);
	cout << "Time set by setHour(20) and setMinute(45) -> " << time2 << endl << endl;

	cout << " -- Testing setTime function --\n";
	time2.setTime(3,40);
	cout << "Time set by setTime(3, 40)                -> " << time2 << endl << endl;

	cout << " -- Testing validity test of day, month, and year --\n";
	Time time3(-1, -59); // Invalid hour and minute
	cout << "Time -1 : -59 is set to          -> " << time3 << endl;
	time3.setTime(1, 60); // Minute is until 59
	cout << "Time 1:60 is set to              -> " << time3 << endl;
	time3.setHour(24); // Hour is 00 until 23
	time3.setMinute(56);
	cout << "Time 24:56 is set to             -> " << time3 << endl << endl;

	cout << " -- Testing accessors --\n";
	cout << "Time -> " << time3 << endl;
	cout << "getHour()   returns : " << time3.getHour() << endl;
	cout << "getMinute() returns : " << time3.getMinute() << endl;
	
	cout << " -- Testing overloading of binary operators --\n";
	time1.setTime(11, 13);
	time2.setTime(23, 14);
	cout << "time1 < time2 returns : " << (time1 < time2) << endl;
	cout << "time1 > time2 returns : " << (time1 > time2) << endl;
	cout << "time1 == time2 returns : " << (time1 == time2) << endl;
	cout << "time1 != time2 returns : " << (time1 != time2) << endl;

	system("PAUSE");
    return 0;
}
*/