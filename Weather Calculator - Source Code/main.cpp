// -----------------------------------------------------------
//
//	Main class for Assignment 2
//	Version 1 : 3 March 2018
//	Author    : Madyarini Grace Ariel
//
// -----------------------------------------------------------

// -- List of included files -- //
#include <iostream>
#include "WeatherCalc.h"

int main()
{
	WeatherCalc calculator;
	calculator.run("data/met_index.txt");

	system("PAUSE");
    return 0;
}
