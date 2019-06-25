// -----------------------------------------------------------
//
//	Implementation file of WeatherCalc class for Assignment 2
//	Version 1 : 3 March 2018
//	Author    : Madyarini Grace Ariel
//
//	Remarks : 
//  - file name, a Vector of Weather objects, year integer, month integer can be 
//   designed as members of the class, but I prefer them not to be because I give
//   freedom for the client to not use the user interface provided by the functions
//   Menu, setOption, setMonthInput, and setYearInput. File name, Vector, year, and month
//   become parameters for the function instead.
//
//	Testing Notes : Uncomment TestWeatherCalc.cpp to test this class
//
// -----------------------------------------------------------

// -- List of included files -- //
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctype.h>
#include <limits>
#include <map>

#include "WeatherCalc.h"

using namespace std;

const string WeatherCalc::monthList[] = {"January", "February", "March", "April", "May", "June", "July", "August", 
										 "September", "October", "November", "December"};
const double WeatherCalc::KILOWATT = 0.001;
const double WeatherCalc::KILOMETER = 0.001;

// -----------------------------------------------------------
// -- Default constructor -- // 
WeatherCalc::WeatherCalc()
{
}

// -----------------------------------------------------------
// -- Destructor -- //
WeatherCalc::~WeatherCalc()
{
}

// -----------------------------------------------------------
// Processes index file
bool WeatherCalc::processFileNames(Vector<string>& fileNames, string fileName)
{
	ifstream inFile;
	string fileItem;

	inFile.open(fileName);

	if(!inFile)
		return false;

	cout << "Processing index file...\n";
	
	while( !inFile.eof() )
	{
		getline(inFile, fileItem, '\n');
		fileItem = "data/" + fileItem;
		fileNames.add(fileItem);
	}
	return true;
}

// -----------------------------------------------------------
// Processes input file which is named fileName. Loads all the records into wMap.
bool WeatherCalc::processInputFile(map<string, Weather>& wMap, string fileName)
{
	// Declaration of ifstream object
	ifstream inFile;

	// Open the file
	inFile.open(fileName);

	cout << "Processing " << fileName << "...\n";

	// If opening the file fails
	if(!inFile)
		return false;

	// If opening the file succeeds
	inFile.ignore(500, '\n'); // ignore column title
	while( !inFile.eof() )
	{
		string line, sDay, sMonth, sYear, sHH, sMM, sSpeed, sSolar, sTemp;
		double speed, solarRad, temp;
		char ch;
		Weather W1;
		ch = inFile.peek();
		if(!isdigit(ch))
			inFile.ignore(500, '\n');
		else
		{
			getline(inFile, sDay, '/');   // get day
			getline(inFile, sMonth, '/'); // get month
			getline(inFile, sYear, ' ');  // get year
			getline(inFile, sHH, ':');    // get hour
			getline(inFile, sMM, ',');    // get minute
		    
			// Get wind speed
			for(int i = 0; i < 9; i++)
				inFile.ignore(50, ',');

			getline(inFile, sSpeed, ',');

			// Get solar radiation
			getline(inFile, sSolar, ',');

			// Get temperature
			for(int i = 0; i < 5; i++)
				inFile.ignore(50, ',');
			
			getline(inFile, sTemp, '\n');

			// Convert string to integer
			if(isNumeric(sDay) && isNumeric(sMonth) && isNumeric(sYear) && isNumeric(sHH) && isNumeric(sMM))
			{
				if(isNumeric(sSpeed) || isNumeric(sSolar) || isNumeric(sTemp))
				{
					int day = 0, month = 0, year = 0, hour = 0, min = 0;
					double speed = -999, sRad = -999, temp = -999; // N/A or invalid values are set to -999
					day   = stoi(sDay); 
					month = stoi(sMonth);
					year  = stoi(sYear);
					hour  = stoi(sHH);
					min   = stoi(sMM);

					if(isNumeric(sSpeed))
						speed = stod(sSpeed);
					if(isNumeric(sSolar))
						sRad  = stod(sSolar);
					if(isNumeric(sTemp))
						temp  = stod(sTemp);

					if(!checkDate(day, month, year)) // if date is invalid
					{
						sDay = "0";
						if(!checkMonth(month))
							sMonth = "0";
						if(!checkYear(year))
							sYear = "0";
					}
					Date date(day, month, year);
					W1.setDate(date);

					Time time(hour, min);
					W1.setTime(time);

					W1.setWindSpeed(speed);
					W1.setSolarRadiation(sRad);
					W1.setTemperature(temp);

					if(sYear.length() < 4)
					{
						int diff = 4 - sYear.length();
						for(int i = 1; i <= diff; i++)
							sYear = "0" + sYear;
					}
					if(sMonth.length() < 2)
						sMonth = "0" + sMonth;

					if(sDay.length() < 2)
						sDay = "0" + sDay;

					if(sHH.length() < 2)
						sHH = "0" + sHH;

					if(sMM.length() < 2)
						sMM = "0" + sMM;
					string key = sYear + "/" + sMonth + "%" + sDay + " " + sHH + ":" + sMM;
					
					wMap.insert(pair<string, Weather> (key, W1));
				}	
			}
		}
	}
	inFile.close();
	return true;
}

// -----------------------------------------------------------
// Shows user interface of menu options.
void WeatherCalc::Menu()
{
	char superscript = 253;
	cout << "------------------------------------------------------------------------------\n";
	cout << "----------------------Welcome to Weather Data Calculation---------------------\n";
	cout << "------------------------------------------------------------------------------\n";
    cout << "Type 1-4 to choose an option, 5 to exit\n";
	cout << " 1 : Average wind speed and average temperature for a specified month and year\n";
    cout << " 2 : Average wind speed and average ambient air temperature for each month of a specified year.\n";
	cout << " 3 : Total solar radiation in kWh/m" << superscript << " for each month of a specified year.\n";
	cout << " 4 : Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m" << superscript << " for each month of a"
		 << " specified year.\n";
	cout << " 5 : Show the times for the highest solar radiation for a particular day, month, and year.\n\n";
}

// -----------------------------------------------------------
// -- Mutator -- //
// Sets option
int WeatherCalc::getOptionInput()
{
	int option;
	cout << "Your option (1-5, 6 to exit) : ";
	while(true)
    {
        cin >> option;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Input integer only (1-6) : ";
		}
        else if(option < 1 || option > 6)
        {
            cout << "Invalid option. Input option again : ";
        }
		else
			break;
    }
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return option;
}

// -----------------------------------------------------------
// Executes option 1 : calculate and show average wind speed (km/h) and average
// temperature (degrees Celcius) for a specified month and year.
void WeatherCalc::option1(nodeBST<WeatherByMonth>& weatherTree)
{
	cout << " -- Option 1 --\n";
	if(weatherTree.isEmpty())
		cout << "BST is not filled yet.\n";
	else
	{
		cout << fixed << showpoint << setprecision(2);

		// Get user input
		int month = getMonthInput();
		int year  = getYearInput();
		
		WeatherByMonth w1;
		w1.setYear(year);
		w1.setMonth(month);

		bool found = weatherTree.search(w1);
		
		cout << monthList[month-1] << " " << year << " : ";
		if(!found)
			cout << "No data on weather." << endl;
		else
		{
			WeatherByMonth* w2 = weatherTree.getSearch(w1);
			if( (*w2).getAvgWS() == -999)
				cout << "No wind speed data, ";
			else
			{
				double avgWS = (*w2).getAvgWS();
				convertTokmH(avgWS);
				cout << avgWS << " km/h, ";
			}
			if( (*w2).getAvgTemp() == -999)
				cout << "No temperature data" << endl;
			else
				cout << (*w2).getAvgTemp() << " degrees C" << endl;
		}
	}
}

// -----------------------------------------------------------
// Execute option 2 : calculate and show average wind speed (km/h) and average
// temperature (degrees Celcius) for each month of a specified year.
void WeatherCalc::option2(nodeBST<WeatherByMonth>& weatherTree)
{
	cout << " -- Option 2 --\n";
	if(weatherTree.isEmpty())
		cout << "BST is not filled yet.\n";
	else
	{
		cout << fixed << showpoint << setprecision(2);
		double avgSpeed, avgTemp;

		// Get user input
		int year = getYearInput();

		cout << year << endl;

		WeatherByMonth w1;
		w1.setYear(year);

		int flag = 0;

		for(int i = 1; i <= 12; i++)
		{
			w1.setMonth(i);
			if(weatherTree.search(w1))
			{
				flag = 1;
				break;
			}
		}
		
		if(flag == 0)
			cout << "No weather data.\n";
		else
		{
			for(int i = 1; i <= 12; i++)
			{
				cout << monthList[i-1];
				for(int n = 0; n <= (9-monthList[i-1].length()); n++) // neat indentation
					cout << " ";
				cout << " : ";
				w1.setMonth(i);
				if(!weatherTree.search(w1))
					cout << "No weather data.\n";
				else
				{
					WeatherByMonth* w2 = weatherTree.getSearch(w1);
					if( (*w2).getAvgWS() == -999)
						cout << "No wind speed data, ";
					else
					{
						double avgWS = (*w2).getAvgWS();
						convertTokmH(avgWS);
						cout << avgWS << " km/h, ";
					}
					if( (*w2).getAvgTemp() == -999)
						cout << "No temperature data" << endl;
					else
						cout << (*w2).getAvgTemp() << " degrees C" << endl;
				}
			}
		}
	}
}

// -----------------------------------------------------------
// Execute option 3 : calculate and show total solar radiation in kWh/m^2 for each month of a specified year.
void WeatherCalc::option3(nodeBST<WeatherByMonth>& weatherTree)
{
	cout << " -- Option 3 --\n";
	if(weatherTree.isEmpty())
		cout << "BST is not filled yet.\n";
	else
	{
		cout << fixed << showpoint << setprecision(2);
		char superscript = 253;

		// Get user input
		int year = getYearInput();

		cout << year << endl;

		WeatherByMonth w1;
		w1.setYear(year);

		int flag = 0;

		for(int i = 1; i <= 12; i++)
		{
			w1.setMonth(i);
			if(weatherTree.search(w1))
			{
				flag = 1;
				break;
			}
		}
		
		if(flag == 0)
			cout << "No weather data.\n";
		else
		{
			for(int i = 1; i <= 12; i++)
			{
				cout << monthList[i-1];
				for(int n = 0; n <= (9-monthList[i-1].length()); n++)
					cout << " ";
				cout << " : ";
				w1.setMonth(i);
				if(!weatherTree.search(w1))
					cout << "No weather data.\n";
				else
				{
					WeatherByMonth *w2 = weatherTree.getSearch(w1);
					double totalSR = (*w2).getTotalSR();
					if(totalSR == -999)
						cout << "No solar radiation data with value >= 100 W/m" << superscript << endl;
					else
					{
						convertTokWh( totalSR );
						cout << totalSR << " kWh/m" << superscript << endl;
					}
					
				}
			}
		}
	}
}

// -----------------------------------------------------------
// Execute option 4 : calculate average wind speed (km/h), average temperature (degrees Celcius) and total solar
// radiation (kWh/m^2) for each month of a specified year. 
void WeatherCalc::option4(nodeBST<WeatherByMonth>& weatherTree)
{
	cout << " -- Option 4 --\n";
	if(weatherTree.isEmpty())
		cout << "BST is not filled yet.\n";
	else
	{
		double totalSR;
		int year = getYearInput(), count;
		ofstream outFile;
		outFile << fixed << showpoint << setprecision(2);
		outFile.open("WindTempSolar.csv");
		outFile << year << endl;
		WeatherByMonth w1;
		w1.setYear(year);
		for(int i = 1; i <= 12; i++)
		{
			outFile << monthList[i-1] << ", ";
			w1.setMonth(i);
			if(!weatherTree.search(w1))
				outFile << "No weather data.\n";
			else
			{
				WeatherByMonth *w2 = weatherTree.getSearch(w1);
				
				if( (*w2).getAvgWS() == -999)
					outFile << "No wind speed data, ";
				else
				{
					double avgWS = (*w2).getAvgWS();
					convertTokmH(avgWS);
					outFile << avgWS << ", ";
				}
				if( (*w2).getAvgTemp() == -999)
					outFile << "No temperature data, ";
				else
					outFile << (*w2).getAvgTemp() << ", ";
				if( (*w2).getTotalSR() == -999)
					outFile << "No solar radiation data with value >= 100 W/m^2";
				else
				{
					totalSR = (*w2).getTotalSR();
					convertTokWh(totalSR);
					outFile << totalSR << endl;
				}
			}
		}
		outFile.close();
		cout << "\"WindTempSolar.csv\" is successfully processed.\n";
	}
}

// -----------------------------------------------------------
// Execute option 5 : Show times of the highest solar radiation of a Date given
void WeatherCalc::option5(map<string, Weather>& wMap)
{
	char superscript = 253;
	cout << " -- Option 5 --\n";
	string date = getDateInput();
	cout << "Date : " << date << endl;
    string compareKey = date.substr(6) + "/" + date.substr(3,2) + "%" + date.substr(0,2) + " ";

	map<string, Weather>::iterator it = wMap.begin();
	nodeBST<double> solarRadiation;
	Vector<Weather> vDate;
	while(it != wMap.end())
	{
		string s = it->first;
		size_t found = s.find(" ");
		string key = s.substr(0, found+1);
		if(key == compareKey)
		{
			if(it->second.getSolarRadiation() != -999)
			{
				vDate.add(it->second);
				solarRadiation.insert(it->second.getSolarRadiation());
			}
		}
		it++;
	}
	if(!solarRadiation.isEmpty())
	{
		double* max = solarRadiation.getMax();
		cout << "High solar radiation for the day : " << (*max) << " " << "W/m" << superscript << endl << endl;
		cout << "Time : \n";
		for(int i = 0; i < vDate.getSize(); i++)
		{
			if(vDate[i].getSolarRadiation() == *max)
				cout << vDate[i].getTime() << endl;
		}
	}
	else
		cout << "No solar radiation data of this date.";
	cout << endl;
	
}
// -----------------------------------------------------------
// Get month input and check for validity. If not valid, prompts again until valid. 
int WeatherCalc::getMonthInput()
{
	int month;
	cout << "Month (1-12) : ";
	while(true)
    {
        cin >> month;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Input integer only (1-12) : ";
		}
        else if(!checkMonth(month))
        {
            cout << "Invalid month. Input month again (1-12) : ";
        }
		else
			break;
    }
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return month;
}

// -----------------------------------------------------------
// Get year input and check for validity. If not valid, prompts again until valid. 
int WeatherCalc::getYearInput()
{
	int year;
	cout << "Year : ";
	while(true)
    {
		cin >> year;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Input integer only (1-9999) : ";
		}
        else if(!checkYear(year))
        {
            cout << "Invalid year. Input year again (1-9999) : ";
        }
		else
			break;
    }
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return year;
}

// -----------------------------------------------------------
// Get date input and check for validity. If not valid, prompts again until valid. 
string WeatherCalc::getDateInput()
{
	string dateInput = "";
	cout << "Input date with the format d/m/yyyy : ";
	getline(cin, dateInput);
	bool validSep = true;
	string sDay = "", sMonth = "", sYear = "", test = "";
	
	while(true)
	{
		if(dateInput.length() > 10 || dateInput.length() < 8)
		{
			cout << "Input must be 8-10 characters. Input date again (d/m/yyyy) : ";
			getline(cin, dateInput);
		}
		else 
		{
			char ch1 = dateInput.at(1);
			char ch2 = dateInput.at(2);
			char ch3 = dateInput.at(3);
			char ch4 = dateInput.at(4);
			char ch5 = dateInput.at(5);
			
			if(dateInput.length() == 10) // dd/mm/yyyy
			{
				if(ch2 == '/' && ch5 == '/')
				{
					sDay   = dateInput.substr(0, 2);
					sMonth = dateInput.substr(3, 2);
					sYear  = dateInput.substr(6);
				}
				else
					validSep = false;
			}
			else if(dateInput.length() == 9) // dd/m/yyyy or d/mm/yyyy
			{
				bool condition1 = (ch1 == '/' && ch4 == '/'), condition2 = (ch2 == '/' && ch4 == '/');
				if(condition1)
				{
					sDay   = dateInput.substr(0,1);
					sMonth = dateInput.substr(2,2);
					sYear  = dateInput.substr(5);
				}
				else if(condition2)
				{
					sDay   = dateInput.substr(0,2);
					sMonth = dateInput.substr(3,1);
					sYear  = dateInput.substr(5);
				}
				else
					validSep = false;
			}
			else
			{
				if(ch1 == '/' && ch3 == '/')
				{
					sDay   = dateInput.substr(0,1); 
					sMonth = dateInput.substr(2,1);
					sYear  = dateInput.substr(4);
				}	
				else
					validSep = false;
			}
			if(!validSep)
			{
				cout << "Invalid input. Input date again (d/m/yyyy) : ";
				getline(cin, dateInput);
			}
			else
			{
				int flag = 1;
				test = sDay + sMonth + sYear;
				for(int i = 0; i < test.length(); i++)
				{
					char ch = test.at(i);
					if( !isdigit(ch) )
					{
						flag = 0;
						break;
					}
				}
				if(flag == 0)
				{
					cout << "Input d, m, yyyy as positive integers only. Input date again (d/m/yyyy) : ";
					getline(cin, dateInput);
				}
				else
				{
					int day   = stoi(sDay);
					int month = stoi(sMonth);
					int year  = stoi(sYear);
					if(checkDate(day, month, year))
					{
						if(ch1 == '/' && ch4 == '/')
							dateInput = "0" + dateInput;
						else if(ch2 == '/' && ch4 == '/')
							dateInput = dateInput.substr(0,3) + "0" + dateInput.substr(3);
						else if(ch1 == '/' && ch3 == '/')
							dateInput = "0" + dateInput.substr(0,2) + "0" + dateInput.substr(2);
						return dateInput;
					}
					else
					{
						cout << "Invalid date. Input date again (d/m/yyyy) : ";
						getline(cin, dateInput);
					}
				}
			}
		}
	}
}

// -----------------------------------------------------------
// Check whether month is valid (1-12). Returns true if valid.
bool WeatherCalc::checkMonth(int month) const
{
	return (month >= 1 && month <= 12);
}

// -----------------------------------------------------------
// Check whether year is valid (1-9999). Returns true if valid.
bool WeatherCalc::checkYear(int year) const
{
	return (year >= 1 && year <= 9999);
}

// -----------------------------------------------------------
// Check whether Date integers are valid (e.g. February leap year is until 29)
bool WeatherCalc::checkDate(int d, int m, int y) const
{
	bool isValid = true;
	if(d <= 0 || d > 31 || y <= 0 || y > 9999 || m < 1 || m > 12 ) 
		isValid = false;
	else
	{
		if(m == 4 || m == 6 || m == 9 || m == 11) // day is until 30
		{
			if(d > 30)
				isValid = false;
        }
        else if(m == 2)
        {
			if(y%4 == 0 && y%100 != 0 || y%400 == 0) // leap year
			{
				if(d > 29)
					isValid = false;
			}
			else // not leap year
			{
				if(d > 28)
					isValid = false;
			}
		}          
	}
	return isValid;
}

// -----------------------------------------------------------
// Get number of data of solar radiation that is more than 100 W/m^2 in the Vector
int WeatherCalc::getNumOfSR(Vector<Weather>& list)
{
	int counter = 0;
	for(int i = 0; i < list.getSize(); i++)
	{
		if(list[i].getSolarRadiation() >= 100)
			counter++;		
	}	
	return counter;
}

// -----------------------------------------------------------
// Calculate average wind speed (km/h) of data in the Vector
double WeatherCalc::calcAvgSpeed(Vector<Weather>& list)
{
	if(list.getSize() == 0)
		return -1;
	else
	{
		int counter = 0;
		for(int i = 0; i < list.getSize(); i++)
		{
			if(list[i].getWindSpeed() == -999)
				counter++;
		}
		if(counter == list.getSize())
			return -999;
		else
		{
			double sum = 0;
			for(int i = 0; i < list.getSize(); i++)
			{
				if(list[i].getWindSpeed() != -999)
					sum += list[i].getWindSpeed();
			}
			int num = list.getSize() - counter;
			return sum/num;
		}
	}
}

// -----------------------------------------------------------
// Calculate average temperature (degrees Celcius) of data in the Vector
double WeatherCalc::calcAvgTemp(Vector<Weather>& list)
{
		if(list.getSize() == 0)
			return -1; // return -1 if there is no data
		else
		{
			int counter = 0;
			for(int i = 0; i < list.getSize(); i++)
			{
				if(list[i].getTemperature() == -999)
					counter++;
			}
			if(counter == list.getSize())
				return -999;
			else
			{
				double sum = 0;
				for(int i = 0; i < list.getSize(); i++)
				{
					if(list[i].getTemperature() != -999)
						sum += list[i].getTemperature();
				}
				int num = list.getSize() - counter;
				return sum/num;
			}
		}
}

// -----------------------------------------------------------
// Calculate total solar radiation (W/m^2) of data in the Vector 
double WeatherCalc::calcTotalSRad(Vector<Weather>& list)
{
	if(list.getSize() == 0)
		return -1;
	else
	{
		int count = getNumOfSR(list);
		if(count == 0)
			return -999; // return -999 if there is no solar radiation >= 100 W/m^2 of the year and month
		else
		{
			double sum  = 0;
			for(int i = 0; i < list.getSize(); i++)
			{
				if(list[i].getSolarRadiation() >= 100)
					sum += list[i].getSolarRadiation();
			}
			return sum;
		}
	}
}


// -----------------------------------------------------------
// Convert Watt per 10 min to Kilowatt per hour
void WeatherCalc::convertTokWh(double &WPer10Min)
{
	WPer10Min = WPer10Min * KILOWATT / 6;
}

// -----------------------------------------------------------
// Convert meter per second to kilometer per hour
void WeatherCalc::convertTokmH(double &MPerS)
{
	MPerS = MPerS * KILOMETER * 3600;
}

// -----------------------------------------------------------
// Run everything in order. 
void WeatherCalc::run(string indexFileName)
{
	// Declaration of variables
	string fileName;

	bool indexSucceed;
    bool fileSucceed;
	Vector<string> fileList;
	
	while(indexFileName != "6")
	{	
		if( indexFileName == "not set")
		{
			cout << "Enter a filename for your index file, include the directory and .txt\n";
			cout << "For example, data/met_index.txt (or type 6 to exit) : ";
			getline(cin, indexFileName);
		}

		indexSucceed = processFileNames(fileList, indexFileName);

		if(!indexSucceed)
		{
			cout << "Error opening the file. Enter another filename, include the directory and .txt (or type to exit) : ";
			getline(cin, indexFileName);
		}
		else
			break;
	}
	int counter = 0;
	map<string, Weather> wMap;
	for(int i = 0; i < fileList.getSize(); i++)
	{
		fileSucceed = processInputFile(wMap, fileList[i]);
		cout << "     ";
		if(fileSucceed)
		{
			cout << "File " << i + 1 << " is successfully processed.\n";
			counter++;
		}
		else
			cout << "File " << i + 1 << " cannot be processed.\n";
	}
	if(counter == 0)
		cout << "All files cannot be processed.\n";
	else
	{
		if(counter == fileList.getSize())
			cout << "All files are successfully processed.\n";
		else
			cout << (fileList.getSize() - counter) << " file(s) cannot be processed.\n";
		
		nodeBST<WeatherByMonth> weatherTree; 
		
		groupMonthly(weatherTree, wMap);
	
		Menu();
		int option = getOptionInput();
		while(option != 6)
		{
			if(option == 1)
				option1(weatherTree);
			else if(option == 2)
				option2(weatherTree);
			else if(option == 3)
				option3(weatherTree);
			else if(option == 4)
				option4(weatherTree);
			else if(option == 5)
				option5(wMap);
			cout << endl;
			option = getOptionInput();
		}
	}
	cout << "--------------------------------END OF PROGRAM--------------------------------\n";
}

// -----------------------------------------------------------
// Checks whether a string is able to be converted to double format
bool WeatherCalc::isNumeric(const string s) const
{
	if(s.length() == 0)
		return false;
	else
	{
		int count = 0;
		for(string:: const_iterator it = s.begin(); it != s.end(); it++) 
		{
			if(*it == '+' || *it == '-')
			{
				if(it != s.begin())
					return false;
			}
			else if(*it == '.')
			{
				count++;
				if(count>1)
					return false;
			}
			else if(!isdigit(*it))
				return false;
		}
		return true;
	}
}

// -----------------------------------------------------------
// To aggregate Weather objects inside a Map to WeatherByMonth objects in a BST.
void WeatherCalc::groupMonthly(nodeBST<WeatherByMonth>& weatherTree, map<string, Weather>& wMap)
{
	int sum = 0, i = 0;
	map<string, Weather>::iterator it = wMap.begin();
	while(it != wMap.end())
	{
		string s = it->first;
		size_t found = s.find("%");
		string key = s.substr(0, found+1);
		Vector<Weather> vMonth;
		while(it != wMap.end())
		{
			string compare = it->first.substr(0, found+1);
			if(key == compare)
			{
				vMonth.add(it->second);
				it++;
			}
			if(key != compare || it == wMap.end())
			{
				size_t found2 = key.find("/");
				int year = stoi(key.substr(0, found2));
				string m = key.erase(0, found2+1);
				int month = stoi(m.substr(0, m.length()-1));
				double avgSpd = calcAvgSpeed(vMonth);
				double avgTemp = calcAvgTemp(vMonth);
				double totalSR = calcTotalSRad(vMonth);
				WeatherByMonth w1;
				w1.setAvgWS(avgSpd);
				w1.setAvgTemp(avgTemp);
				w1.setTotalSR(totalSR);
				w1.setYear(year);
				w1.setMonth(month);
				weatherTree.insert(w1);
				break;
			}
		}
	}
}



