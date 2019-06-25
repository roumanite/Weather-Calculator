// -----------------------------------------------------------
//
//	Test file of WeatherCalc class for Assignment 2
//	Version 1 : 3 March 2018
//	Author    : Madyarini Grace Ariel	
//
//	Testing Notes : Uncomment to test WeatherCalc class
//	
// -----------------------------------------------------------

// -- List of included files -- //
#include <iostream>
#include "WeatherCalc.h"
/*
int main()
{ 
	WeatherCalc calculator;
	map<string, Weather> wList1;
	cout << " -- Testing processInputFile function --\n";
	cout << "data/MetData_Mar01-2015-Mar01-2016-ALL.csv as filename for processInputFile returns : " << calculator.processInputFile(wList1, "data/MetData_Mar01-2015-Mar01-2016-ALL.csv") << endl;
	cout << "nonexistent.csv as filename for processInputFile returns  : " << calculator.processInputFile(wList1, "nonexistent.csv") << endl << endl;

	cout << " -- Testing Menu function --\n";
	cout << "Invoking Menu shows :\n";
	calculator.Menu();
	cout << endl << endl;

	Vector<Weather> wList2;
	Weather w1(4,5,2013,6,7,70,80,90);
	Weather w2(4,5,2013,16,17,70,120,90);
	wList2.add(w1);
	wList2.add(w2);
	cout << " -- Testing getNumOfSR -- \n";
	cout << "I have this Vector of Weather objects :\n";
	cout << "Index 0 :\n" << wList2[0];
	cout << "Index 1 :\n" << wList2[1];
	cout << "getNumOfSR returns number of data that has solar radiation >=100\n";
	cout << "Set month to 5, year to 2013.\n";
	cout << "getNumOfSR returns : " << calculator.getNumOfSR(wList2) << endl << endl;

	Weather w3(4,5,2013,22,10,70,80,20);
	Weather w4(4,5,2013,23,17,70,120,50);
	wList2.add(w3);
	wList2.add(w4);
	cout << " -- Testing getNumOfData(Vector<Weather>& list, int year, int month) -- \n";
	cout << "I have this Vector of Weather objects named wList2 :\n";
	cout << "Index 0 :\n" << wList2[0] << endl;
	cout << "Index 1 :\n" << wList2[1] << endl;
	cout << "Index 2 :\n" << wList2[2] << endl;
	cout << "Index 3 :\n" << wList2[3] << endl;

	cout << " -- Testing calcAvgSpeed, calcAvgTemp, and calcTotalSRad -- \n";
	cout << "Using the previous Vector (existed data) \n";
	cout << "    calcAvgSpeed(wList2) returns   : " << calculator.calcAvgSpeed(wList2) << endl;
	cout << "    calcAvgTemp(wList2) returns    : " << calculator.calcAvgTemp(wList2) << endl;
	cout << "    calcTotalSRad(wList2) returns  : " << calculator.calcTotalSRad(wList2) << endl << endl;

	cout << "Using an empty Vector\n";
	Vector<Weather> wList3;
	cout << "    calcAvgSpeed(wList3)  returns  : " << calculator.calcAvgSpeed(wList3) << endl;
	cout << "    calcAvgTemp(wList3)   returns  : " << calculator.calcAvgTemp(wList3) << endl;
	cout << "    calcTotalSRad(wList3) returns  : " << calculator.calcTotalSRad(wList3) << endl << endl;
	
	cout << "-- Testing convertTokWh -- \n";
	double testWatt = 120;
	calculator.convertTokWh(testWatt);
	cout << "120 W per 10 min is converted to : " << testWatt << endl << endl;

	cout << "-- Testing convertTokmH -- \n";
	double testConvert = 1;
	calculator.convertTokmH(testConvert);
	cout << "1 m/s is converted to : " << testConvert << endl << endl;

	cout << "-- Test getOptionInput, option1, option2, option3, option4 -- \n";
	cout << "Invoking getOptionInput will show :\n"; 
	int option = calculator.getOptionInput();
	cout << "Return value : " << option << endl << endl;

	nodeBST<WeatherByMonth> wTree;
	map<string, Weather> wList4;
	calculator.processInputFile(wList4, "data/MetData_Mar01-2015-Mar01-2016-ALL.csv");
	calculator.groupMonthly(wTree, wList4);
	cout << "Number of nodes in the tree : " <<  wTree.size() << endl;
	cout << "Passing tree filled by MetData_Mar01-2015-Mar01-2016-ALL.csv to option1, option2, option3, option4 will result in :\n";
	calculator.option1(wTree);
	calculator.option2(wTree);
	calculator.option3(wTree);
	calculator.option4(wTree);
	cout << "Passing map filled by MetData_Mar01-2015-Mar01-2016-ALL.csv to option5 will result in :\n";
	calculator.option5(wList4);
	map<string, Weather> wList5;
	nodeBST<WeatherByMonth> wTree1;
	cout << "\nPassing empty tree to option1, option2, option3, option4 will result in : \n";
	calculator.option1(wTree1);
	calculator.option2(wTree1);
	calculator.option3(wTree1);
	calculator.option4(wTree1);
	cout << "\nPassing empty map to option5 will result in : \n";
	calculator.option5(wList5);

	cout << "\n-- run() is tested in main.cpp -- \n";
	system("PAUSE");
    return 0;
}
*/