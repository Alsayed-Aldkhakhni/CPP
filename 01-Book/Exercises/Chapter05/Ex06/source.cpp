/*
 * Subject: Functions that exchange between seconds and time structure.
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
///////////////////////////////////
struct Time         // struct tag.
{
	int hours;
	int minutes;
	int seconds;	
};
///////////////////////////////////
// functions' prototype.
unsigned long toSeconds(Time);
Time toTime(unsigned long);

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
	
	// call both functions.
	unsigned long seconds = toSeconds(time1);
	Time time2 = toTime(seconds);
	
	// print the Time.
	cout << "Your entered:        " << time1.hours << ':' << time1.minutes << ':' << time1.seconds << "\n";
	cout << "Convert to time:     " << time2.hours << ':' << time2.minutes << ':' << time2.seconds << "\n";
	cout << "Which is in seconds: " << seconds << "\n\n";
	
	// indicates a successful execution
	return 0;
}

// functions' definition.
unsigned long toSeconds(Time time1)
{
	return time1.hours * 3600 + time1.minutes * 60 + time1.seconds;
}

Time toTime(unsigned long seconds)
{
	Time time3;
	
	// assign the hours.
	time3.hours = seconds / 3600;

	// get the minutes.
	time3.minutes = (seconds - time3.hours * 3600) / 60;
	
	// get the seconds.
	time3.seconds = seconds - (time3.hours * 3600 + time3.minutes * 60);
	
	// return the processed variable
	return time3;
}


