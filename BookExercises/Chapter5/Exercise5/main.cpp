/*
 * Subject: A program that gets time form the user, convert it to seconds and then print the seconds.
 *
 * Date: November 21, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

#include <iostream> 			// 'cout', 'cin' declaration.
#include <conio.h> 				// '_getche' declaration.

struct time						// structure tag.
{
	int hours;					// structure members.
	int minutes;
	int seconds;
};

short getTime(time &);			// prototypes.
unsigned long timeToSeconds(time);

//***********************************************************

int main()
{
	time t;						// take a variable of type t.
	
	do
	{
		getTime(t);				// get the time from the user.

								// convert and print the total seconds.
		std::cout << "Time to seconds is: " << timeToSeconds(t);

								// tells the user if he wants to stop.
		std::cout << "\n\nPress Esc to exit.";	
		
	}while(_getche() != 27);	// stop while the charater entered is not 'esc'.
	
	return 0;					// indicates the operating system that the program executed successfully.
}

//***********************************************************

short getTime(time &T)			// function definition.
{
	int h, m, s;				// three temperory variables.
	char ch;
								// ask the user to enter a time in the shown form.
	std::cout << "Enter the time in form (12:59:59): ";

								// get the time from the user.
	std::cin >> h >> ch >> m >> ch >> s;

								// check the validation of the entered values.
	if(h >= 0 && m >= 0 && s >= 0)
	{	
		if(h <= 12 && m <= 59 && s <= 59)
		{						// if the values within the allowed range.
			T.hours = h; T.minutes = m; T.seconds = s;
		}
		else
		{						// if the ranges exceeded.
			std::cout << "Exceeded the valid range.\n";
			return 0;			// stop now.
		}
	}
	else						// also exceeded the range.
	{
		std::cout << "Time can not be with nigative values.\n";
		return 0;
	}	
}
								// return the total seconds.
unsigned long timeToSeconds(time T)
{
	return (T.seconds + T.minutes * 60 + T.hours * 3600) ;
}
