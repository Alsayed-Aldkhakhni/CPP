/*
 * Subject: A program has 3-Functions to set, print and find the biggest vaiable of type 'Distance'.
 *
 * Date: November 20, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

#include <iostream>				// for cin, cout declaration.

struct Distance					// structure tag.
{								// structure members.
	int feet;
	float inches;	
};
								// functions prototype.

void getDistance(Distance &);	// a function to take a Distance.
void printDistance(Distance);	// a function to display a Distance.
								// a function to find the biggest Distanse and return it.
Distance whichIsBigger(Distance&, Distance& );

//***********************************************************

int main()
{
	Distance D0, D1, D2;		// get three variables of type 'Distance'.
	
	getDistance(D0);			// get form the user 'D0' and 'D1'.
	getDistance(D1);
	
	D2 = whichIsBigger(D0,D1);	// get the biggest.
	
	printDistance(D0);			// print 3-Distance variables.
	printDistance(D1);
	printDistance(D2);
	
	return 0;					// indicates the 'OS' that the program executed successfully.
}

//*****************************************************************************************

void getDistance(Distance& D0)
{
	Distance temp;				// temparory variables of type 'Distance' to hold data before assigning to check.
	
								// ask the user to enter the feet of the distance.
	std::cout << "Enter the feet: ";
	std::cin >> temp.feet;		// get the feet.
	
								// check the validation of the feet.
	D0.feet = temp.feet >= 0 ? temp.feet : 0;
	
								// ask the user to enter the inches.
	std::cout << "Enter the inches: ";
	std::cin >> temp.inches;	// get the inches.
	
								// check the inches validation.
	D0.inches = temp.inches >= 0 ? temp.inches : 0;
	
	if(D0.inches >= 12)			// check the amount of inches since 12 inches = a foot.
	{
		D0.feet++;				// increase the feet with one.
		D0.inches -= 12;		// subtract that foot from these inches.
	}

	std::cout << "\n";			// print a new line.
}

//***********************************************************

Distance whichIsBigger(Distance& D0, Distance& D1)
{
	
	if(D1.feet > D0.feet)		// if the feet of the first is bigger than the second's.
	{
		return D1;				// return the first.
	}
	else if(D0.feet > D1.feet)	// else if the second's is bigger than the first's
	{
		return D0;				// return the second.
	}
	else if(D1.feet == D0.feet)	// if the feet are equal, check the inches.
	{							// if the inches of the D1 if bigger that the D0's
		if(D1.inches > D0.inches)
		{
			return D1;			// return the D1.
		}
		else					// else if the D0's is bigger.
		{
			return D0;			// return it.
		}
	}
}

//***********************************************************

void printDistance(Distance D0)
{								// print a distance in English form.
	std::cout << D0.feet << "\'-" << D0.inches << '\"' << '\n';
}