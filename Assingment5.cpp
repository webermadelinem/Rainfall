//  This program reads from a file a starting month name, an ending month name, and then the monthly rainfall for each month during
//  that period. It calculated the rainfall amounts and reports the total rainfall and average rainfall. 
//  Title: Programming Lab 5
//  Author: Madeline Weber
//  Date: September 22, 2022

#include <iostream>
#include <cmath>
#include <fstream> 		// Needed to use files
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	// Declare variables 
	ifstream inputFile;				// File stream object
	string startingMonth, endingMonth;
	double value, average, total;
	int count;
	total = 0.0, average = 0.0; 	// Initilaze variables
	
	cout << "This program reads and sums the total monthly rainfall and average monthly rainfall during a period of time. \n";
	cout << "\n";
	// Open the input file
	inputFile.open("rainfall.txt");
	inputFile >> startingMonth;
	inputFile >> endingMonth;
	
	if ( !inputFile ) 				// If the file could not be found and opened
	{
		cout << "Error opening the file. \n";
	}
	else 							// The file sucessfully opened, process it
	{
	while ( inputFile >> value )
	{
		total += value;
		count++;
	}
	
	average = ( total / count );
	cout << fixed << showpoint << setprecision(2);
	cout<< "Between " << startingMonth << " and " << endingMonth << ", the total rainfall was " << total 
	<< " inches and the average monthly rainfall was " << average << " inches.";		
	}
	
	inputFile.close();
	return 0;
}
