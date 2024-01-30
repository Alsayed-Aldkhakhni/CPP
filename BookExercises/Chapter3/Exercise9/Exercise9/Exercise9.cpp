/*
 * Subject: Calculate the number of possible arrangement of x-guests on y-charis at a table.
 *
 * Date: January 29, 2024
 *
 * Author: Alsayed Aldkhakhni
 */

#include <iostream>					// for cin, cout declaration.
using namespace std;				// for cin, cout defintion.

int main()
{
	unsigned short chairsNum;		// to hold the number of chairs available at a table.
	unsigned short guestsNum;		// to hold the number of guests who will come. 
	unsigned int possibilities;		// the available possibilities.

	char oneMore;					// to hold the user's answer to do one more time or not.

	do
	{
		possibilities = 1;			// set the possiblities with 1 to avoid garbage value.

									// prompt message tells the user what's going on.
		cout << "Enter the number of guests: ";
		cin >> guestsNum;			// the number of guests camed.

									// ask him how many chairs are avaliable.
		cout << "Enter the number of chairs: ";
		cin >> chairsNum;			// get the free chairs.


									// calculate the possiblities.
		for (int i = 0; i < chairsNum; i++)
		{
			possibilities *= guestsNum;
			guestsNum--;
		}

									// print the possiblities.
		cout << "number of possiblities is: " << possibilities << "\n\n";

									// ask the user if he wants to do another iteration.
		cout << "Do another? (y, n): ";
		cin >> oneMore;				// his answer.

	} while (oneMore == 'y');		// if he wants loop again.

	return 0;						// flags the 'OS' that the program executed successfully.
}
