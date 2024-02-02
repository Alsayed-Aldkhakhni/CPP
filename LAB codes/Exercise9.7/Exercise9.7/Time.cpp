#include "Time.h"		// class interface.
#include<iomanip>		// setw, setfill declaration.
#include<iostream>		// cout declaration.
using namespace std;	// cin, cout definition.

Time::Time(unsigned short h, unsigned short m, unsigned  short s)
{						// check validation.
	if ((h > 0 && h <= 24) && (m > 0 && m <= 59) && (s > 0 && s <= 59))
	{					// assigning the values to the data members.
		hours = h; minutes = m; seconds = s; 
	}
}

//*******************************************************************************

void Time::tick()		// Tick-tock
{
	if (seconds < 59)	// if we still less than 59 add one second.
	{
		seconds++;
	}
	else				// if they are 59
	{
		seconds = 0;	// set it with zero.

						// if the minutes are avaliable to be incremented, then do it.
		if (minutes < 59)
		{
			minutes++;	// then do it, increment the minutes by 1.
		}
		else			// if the minutes is 59
		{
			minutes = 0;// set it with 0

						// if the hours is valid to be incremented.
			if (hours < 24)
			{
				hours++;// then do it.
			}
			else		// otherwise start the afternoon period.
			{			// set it with one to go to the afternoon period.
				hours = 1;
			}
		}
	}
}

//*******************************************************************************

void print(Time clock) // friend function that display the time normally without (.) operator.
{
					   // check validation.
	if ((clock.hours > 0 && clock.hours <= 24) &&
		(clock.minutes >= 0 && clock.minutes <= 59) &&
		(clock.seconds >= 0 && clock.seconds <= 59))
	{
						// say cheese! :)
		cout << setfill('0') << setw(2) << (clock.hours <= 12 ? clock.hours : clock.hours - 12) << ':' << setw(2)
			 << clock.minutes << ':' << setw(2) << clock.seconds << (clock.hours < 12 ? " PM" : " AM");
	}
	else				// never mind.
	{
		cout << "out of range.";
	}
}