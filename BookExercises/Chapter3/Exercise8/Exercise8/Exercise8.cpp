/*
 * Subject: Add two old British monetary amounts.
 *
 * Date: January 29, 2024
 *
 * Author: Alsayed Aldkhakhni
 */

#include <iostream>					// for cin, cout declaration.
using namespace std;				// for cin, cout defintion.

int main()
{
									// declare needed variables to hold the data.
	unsigned int pound1, shilling1, pence1;
	unsigned int pound2, shilling2, pence2;

	char dummyChar, oneMore;		// dummy to hold the dot, oneMore to determine loop or not.

									// to hold the final answer.
	unsigned int totalPounds, totalShillings, totalPence;

	do
	{								// prompt message tells the user what he has to do.
		cout << "Enter first amount: ";
									// get the first amount data.
		cin >> pound1 >> dummyChar >> shilling1 >> dummyChar >> pence1;

		cout << "Enter second amount: ";
									// get the second amount data.
		cin >> pound2 >> dummyChar >> shilling2 >> dummyChar >> pence2;

									// add pence of both amounts.
		totalPence = pence1 + pence2;
									// add shillings of both amounts.
		totalShillings = shilling1 + shilling2;

		if (totalPence >= 12)		// every 12 pence = 1 shilling.
		{
			totalPence -= 12;
			totalShillings++;		// add a shilling.
		}

									// add pounds of the two amounts.
		totalPounds = pound1 + pound2;

		if (totalShillings >= 20) 	// every 20 shillings = 1 pound.
		{
			totalShillings -= 20;
			totalPounds++;			// add a pound.
		}
									// print the final amount.
		cout << "\x9c" << totalPounds << '.' << totalShillings << '.' << totalPence << "\n\n";

									// ask the user whether he wants to do another operation.
		cout << "Do another? (y, n): ";
		cin >> oneMore;				// get his answer.

	} while (oneMore == 'y');		// loop if he wants.

	return 0;						// flag the 'OS' that the program executed successfully.
}
