/*
 * Subject: A function that converts a time to seconds.
 * 
 * Time: January 1, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 8, 2024
 * 
 * */

#include <iostream> // for objects cin, cout declaration.
using namespace std;// for their definition.
/////////////////////////////////////////////
struct Time         // struct tag.
{
	int hours;
	int minutes;
	int seconds;	
};
//////////////////////////////////////////////

// function's prototype.
unsigned long toSeconds(Time);

int main()
{
	// declare an object.
	Time time1;
	
	// to read the colon.
	char dummyChar;
	
	// read the time from the user.
	cout << "Enter the current time[12:59:59]: ";
	cin >> time1.hours >> dummyChar >> time1.minutes >> dummyChar >> time1.seconds;
	
	// valiTime the values.
	if(time1.hours <= 0 || time1.hours > 12 ||
	   time1.minutes < 0 || time1.minutes > 59 ||
	   time1.seconds < 0 || time1.seconds > 59)
	{
		cout << "Invalid value entered t1.\n";
		exit(1);
	}
	

	// print the Time.
	cout << "Your entered:        " << time1.hours << ':' << time1.minutes << ':' << time1.seconds << "\n";
	cout << "Which is in seconds: " << toSeconds(time1) << "\n\n";
	
	
	// indicates a successful execution
	return 0;
}

// function's definition.
unsigned long toSeconds(Time time1)
{
	return time1.hours * 3600 + time1.minutes * 60 + time1.seconds;
}


