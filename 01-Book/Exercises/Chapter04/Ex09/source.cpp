/*
 * Subject: Simulate time using struct Time.
 * 
 * Date: December 1, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cin, cout objects declaration.
using namespace std;// for the definition of cin, cout.

///////////////////////////
struct Time // struct tag.
{
	int hours;
	int minutes;
	int seconds;	
};
/////////////////////////


int main()
{
	// declare an object.
	Time time1;
	
	// to read the colon.
	char dummyChar;
	
	// read the time from the user.
	cout << "Enter the current time[12:59:59]: ";
	cin >> time1.hours >> dummyChar >> time1.minutes >> dummyChar >> time1.seconds;
	
	// validate the values.
	if(time1.hours <= 0 || time1.hours > 12 ||
	   time1.minutes < 0 || time1.minutes > 59 ||
	   time1.seconds < 0 || time1.seconds > 59)
	{
		cout << "Invalid value entered.\n";
		exit(1);
	}
	

	// print the time back.
	cout << "You entered: " << time1.hours << ':' << time1.minutes << ':' << time1.seconds << "\n"
		 << "Which it's = " << time1.hours*3600 + time1.minutes*60 + time1.seconds << " seconds.\n\n";
	
	// indicates a successful execution.
	return 0;
	
}