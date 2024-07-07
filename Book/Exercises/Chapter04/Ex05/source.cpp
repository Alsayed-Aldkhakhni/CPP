/* *
 * Subject: Simulate a date using Date structure.
 * 
 * Date: December 12, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 7, 2024
 * 
 * */

#include <iostream> // for objects cin and cout declaration.
using namespace std;// for their definition.

struct Date         // structure tag.
{
	short day;
	short month;
	short year;
};

int main()
{
	Date date1;
	char dummy;
	
	// read the date.
	cout << "Enter your favorite date[mm/dd/yy]: ";
	cin >> date1.month >> dummy >> date1.day >> dummy >> date1.year;
	
	// simple validation.
	if(date1.year <= 0 || (date1.day <= 0 || date1.day > 31) || (date1.month <= 0 || date1.month > 12))
	{
		cout << "Invalid value(s) entered.\n";
		exit(1);
	}

	// print the date.
	cout << "Your entered: " << date1.month << '/' << date1.day << '/' << date1.year << "\n\n";
	
	// indicates a successful execution.
	return 0;
}


