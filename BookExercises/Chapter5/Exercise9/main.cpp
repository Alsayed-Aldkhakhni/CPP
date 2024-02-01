/*
 * Subject: A program that swaps two times obtained form the user.
 *
 * Date: November 23, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

#include <iostream>			// the declaration of cin, cout.
#include <iomanip>			// the declaration of setw, setfill.
using namespace std;		// the definition of them, cin, setw, etc.


struct Time 				// structure tag.
{
	int hours;				// structure's members.
	int minutes;
	int seconds;
};

							// functions' prototypes.
void getTime(Time &);		// the function declarator that gets the time from the user.
void printTime(Time);		// the function that will print the time in standard form.

void swap(Time &, Time &);	// the function that swaps the two times.

int main()
{
	
	Time clock1, clock2;	// get two variables of type 'Time'.
	
	getTime(clock1);		// set the first time by the user.
	getTime(clock2);		// set the second by the user.

							// print the time values entered by the user before swapping.
	std::cout << "\nFirst clock:  "; printTime(clock1);
	std::cout << "Second clock: "; printTime(clock2);
	
	swap(clock1,clock2);	// swapping the variables.
	
							// print the time values entered by the user after swapping.
	std::cout << "\nFirst clock:  "; printTime(clock1);
	std::cout << "Second clock: "; printTime(clock2);
		
	return 0;				// indicates the operating system that the program executed successfully.
}


void getTime(Time &T)		// the definition of the function which sets the time.
{
	int h, m, s;			// temporary variables to hold the data to check it before assinging.
	char ch;
							// prompt message tells the user what to do.
	std::cout << "Enter the time in form (12:59:59): ";

							// get the input.
	std::cin >> h >> ch >> m >> ch >> s;
	
							// check the validation of the input.
	if(h >= 0 && m >= 0 && s >= 0)
	{		
		if(h <= 12 && m <= 59 && s <= 59)
		{					// assign the values if they are valid.
			T.hours = h; T.minutes = m; T.seconds = s;
		}
		else
		{					// otherwise prompt the user the problem and stop immediately.
			std::cout << "Exceeded the valid range.\n";
			exit(1);
		}
	}
	else
	{						// other nonvalidation reasons.
		std::cout << "Time can not be with negative values.\n";
		exit(1);
	}	
}

void printTime(Time T)		// print the time in the standard form.
{
	std::cout << std::setfill('0') << std::setw(2) << T.hours << ':'
			  << std::setw(2) << T.minutes << ':' << std::setw(2) << T.seconds << "\n";
}

							// the definition of the function which will swap the values of two time variables.
void swap(Time &clock0, Time &clock1)
{
							// temporary variables to save the values from overwritting. 
	short int hTemp, mTemp, sTemp;
	
	hTemp = clock0.hours;	// swapping the hours.
	clock0.hours = clock1.hours;
	clock1.hours = hTemp;


	mTemp = clock0.minutes;	// swapping the minutes.
	clock0.minutes = clock1.minutes;
	clock1.minutes = mTemp;

	sTemp = clock0.seconds;	// swapping the seconds.
	clock0.seconds = clock1.seconds;
	clock1.seconds = sTemp;
}