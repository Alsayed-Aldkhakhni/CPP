/*
 * Subject: A program takes time, convert it to seconds and then display the time again.
 *
 * Date: November 21, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

#include <iostream> 		// for cin, cout declaration.
#include <iomanip> 			// for setw, setfill declaration.

struct Time					// structure tag.
{							// members.
	int hours;
	int minutes;
	int seconds;
};

							// functions' prototypes.

void getTime(Time &);		// to get the time form the user.
void printTime(Time);		// to print the time.

							// to convert the time to seconds.
unsigned long timeToSeconds(Time &);
							// one to convert the seconds to the time.
Time secondsToTime(unsigned long );	


int main()
{
	Time clock0, clock1;	// take two variables of type 'time'.
	unsigned long seconds;	// notice the data type since seconds won't be negative.
	
	getTime(clock0);		// get the time form the user, placed it in 'clock0'.
	
							// convert 'clock0' to seconds and place them in 'seconds' variable.
	seconds = timeToSeconds(clock0);

							// convert seconds again to time and place them in 'clock1'.
	clock1 = secondsToTime(seconds);
	
							// print the seconds.
	std::cout << "Total seconds: " << seconds;
	std::cout << "\n\n";
	
	printTime(clock1);		// print the time stored in 'clock1' which is in 'clock0'.
	
	return 0;				// indicates the 'OS' that the program executed successfully.
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

							// functions' definition.

void getTime(Time& T)		// store time passed by the user in a structure variable 'T'.
{
	int h, m, s;			// variables to hold data before assigning to check the validation.
	char ch;
							// ask the user to enter a time.
	std::cout << "Enter the time in form (12:59:59): ";
	
							// get the time from him.
	std::cin >> h >> ch >> m >> ch >> s;
	
							// check validation.
	if(h >= 0 && m >= 0 && s >= 0)
	{
		if(h <= 12 && m <= 59 && s <= 59)
		{					// if there is no problem.
			T.hours = h; T.minutes = m; T.seconds = s;
		}
		else				// if we got a problem.
		{
			std::cout << "Exceeded the valid range.\n";
			exit(1);		// stop after telling the user what happend.
		}
	}
	else					// also we got a problem.
	{
		std::cout << "Time can not be with nigative values.\n";
		exit(1);
	}	
}

							// return the total seconds stored in 'T' variable.
unsigned long timeToSeconds(Time &T)
{
	return T.hours * 3600 + T.minutes * 60 + T.seconds;
}


Time secondsToTime(unsigned long seconds)
{
	Time T;					// variable will be returned.
	
							// minutes and seconds within this variable 'resetSeconds'.
	int resetSeconds = seconds % 3600;

							// the hours.
	T.hours = (seconds - resetSeconds) / 3600; 

							// the seconds
	T.seconds = resetSeconds % 60;

							// the minutes.
	T.minutes = (resetSeconds - T.seconds) / 60;

	return T;				// return the 'T' variable.
}


void printTime(Time T)		// print the time in standard form.
{
	std::cout << "You entered: ";
	std::cout << std::setfill('0') << std::setw(2) << T.hours << ':'
			  << std::setw(2) << T.minutes << ':' << std::setw(2) << T.seconds;
}