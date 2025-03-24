/*
 * Subject: Add two times Simulated by struct Time.
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
	Time time1, time2;
	
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
		cout << "Invalid value entered t1.\n";
		exit(1);
	}
	
	// read the time from the user.
	cout << "Enter the current time[12:59:59]: ";
	cin >> time2.hours >> dummyChar >> time2.minutes >> dummyChar >> time2.seconds;
	
	// validate the values.
	if(time2.hours <= 0  || time2.hours > 12 ||
	   time2.minutes < 0 || time2.minutes > 59 ||
	   time2.seconds < 0 || time2.seconds > 59)
	{
		cout << "Invalid value entered t2.\n";
		exit(1);
	}
	
	
	// the one to add the previous two.
	Time time3;
	
	unsigned long seconds;
	
	seconds  = (time1.hours   + time2.hours) * 3600;
	seconds += (time1.minutes + time2.minutes) * 60;
	seconds += (time1.seconds + time2.seconds);
	
	// assign the hours.
	time3.hours = seconds / 3600;

	// get the minutes.
	time3.minutes = (seconds - time3.hours * 3600) / 60;
	
	// get the seconds.
	time3.seconds = seconds - (time3.hours * 3600 + time3.minutes * 60);
	
	// validate the time after all.
	if(time3.hours <= 0   || time3.hours > 12 ||
		time3.minutes < 0 || time3.minutes > 59 ||
		time3.seconds < 0 || time3.seconds > 59)
	{
		cout << "Can't add those two times, exceeded the limits.\n";
		exit(1);
	}
	
	// print the time back.
	cout << "You entered: " << time3.hours << ':' << time3.minutes << ':' << time3.seconds << "\n"
		 << "Which it's = " << time3.hours*3600 + time3.minutes*60 + time3.seconds << " seconds.\n\n";
	
	// indicates a successful execution.
	return 0;
	
}