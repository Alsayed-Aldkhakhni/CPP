/*
 * Subject: Swap two time structures.
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
void swap(Time&, Time&);

int main()
{
	// declare an object.
	Time time2{5, 16, 20}, time1;
	
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
	// before.
	cout << "Before:\n";
	cout << "You entered:     " << time1.hours << ':' << time1.minutes << ':' << time1.seconds << "\n";
	cout << "I entered:       " << time2.hours << ':' << time2.minutes << ':' << time2.seconds << "\n\n";

	swap(time1, time2);
	
	// after.
	cout << "After:\n";
	cout << "You entered:     " << time1.hours << ':' << time1.minutes << ':' << time1.seconds << "\n";
	cout << "I entered:       " << time2.hours << ':' << time2.minutes << ':' << time2.seconds << "\n";
	
	// indicates a successful execution
	return 0;
}

// function's body.
void swap(Time& time1, Time& time2)
{
	Time temp = time1;
	time1 = time2;
	time2 = temp;	
}





