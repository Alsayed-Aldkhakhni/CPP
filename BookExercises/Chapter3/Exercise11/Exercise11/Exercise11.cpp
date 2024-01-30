/*
 * Subject: Allow the user to add, subtract two British monetary amount and multiply by a float number.
 *
 * Date: January 29, 2024
 *
 * Author: Alsayed Aldkhakhni
 */

#include <iostream>							// for cin, cout declaration.
using namespace std;						// for cin, cout defintion.

int main()
{
	unsigned int pound1, shilling1, pence1;	// declare needed variables to hold the data.
	unsigned int pound2, shilling2, pence2;
	float num;

	char dummyChar, oneMore;				// dummy to hold the dot, oneMore to determine loop or not.
	char operation;
											// to hold the final answer.
	unsigned int totalPounds, totalShillings, totalPence;

	do
	{
		cout << "Chose the operation:\n"
				"'+' add two amounts,\n"
				"'-' subtract two amounts,\n"
				"'*' multiply an amount by a float number: ";

		cin >> operation;

		switch (operation)
		{
		case '+':	
			cout << "Enter first amount: ";// prompt message tells the user what he has to do.
										   // get the first amount data.
			cin >> pound1 >> dummyChar >> shilling1 >> dummyChar >> pence1;

			cout << "Enter second amount: ";// get the second amount data.
			cin >> pound2 >> dummyChar >> shilling2 >> dummyChar >> pence2;

			
			totalPence = pence1 + pence2;	// add pence of both amounts.
											// add shillings of both amounts.
			totalShillings = shilling1 + shilling2;

			if (totalPence >= 12)			// every 12 pence = 1 shilling.
			{
				totalPence -= 12;
				totalShillings++;			// add a shilling.
			}

											
			totalPounds = pound1 + pound2;	// add pounds of the two amounts.

			if (totalShillings >= 20) 		// every 20 shillings = 1 pound.
			{
				totalShillings -= 20;
				totalPounds++;				// add a pound.
			}
			break;

		case '-':
			cout << "Enter first amount: ";
			cin >> pound1 >> dummyChar >> shilling1 >> dummyChar >> pence1;

			cout << "Enter second amount: ";
			cin >> pound2 >> dummyChar >> shilling2 >> dummyChar >> pence2;

			if (pound1 >= pound2 && shilling1 >= shilling2 && pence1 >= pence2)
			{

											// subtract pence of both amounts.
				totalPence = pence1 - pence2;
											// subtract shillings of both amounts.
				totalShillings = shilling1 - shilling2;

				if (totalPence >= 12)		// every 12 pence = 1 shilling.
				{
					totalPence -= 12;
					totalShillings++;		// add a shilling.
				}

											// add pounds of the two amounts.
				totalPounds = pound1 - pound2;

				if (totalShillings >= 20)	// every 20 shillings = 1 pound.
				{
					totalShillings -= 20;
					totalPounds++;			// add a pound.
				}
			}
			else
			{
				cout << "Something went wrong.\n";
				break;
			}

			break;

		case '*':

			cout << "Enter an amount: ";
			cin >> pound1 >> dummyChar >> shilling1 >> dummyChar >> pence1;

			cout << "Enter the number you want to multiply with: ";
			cin >> num;

			if (num > 0)					// check validation.
			{
				totalPounds = pound1 * num;
				totalShillings = shilling1 * num;
				totalPence = pence1 * num;
			}
			else
			{
				cout << "Can't multiply by that value.\n";
				break;
			}
			break;

		default:
			cout << "Try again, invalid input.\n";
		}
											// print the final amount.
		cout << "\x9c" << totalPounds << '.' << totalShillings << '.' << totalPence << "\n\n";

		cout << "Do another? (y, n): ";		// ask the user whether he wants to do another operation.
		cin >> oneMore;						// get his answer.

	} while (oneMore == 'y');				// loop if he wants.

	return 0;								// flag the 'OS' that the program executed successfully.
}