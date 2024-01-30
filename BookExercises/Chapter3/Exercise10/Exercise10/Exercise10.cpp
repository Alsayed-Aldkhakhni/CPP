/*
 * Subject: Calculate the years of investment to get an amount of money.
 *
 * Date: January 29, 2024
 *
 * Author: Alsayed Aldkhakhni
 */

 // preproccessor directive instructs the compiler, preproccessor namely,
 // to fetch the whole content of that header file, iostream, to the current source file.
#include <iostream>				// for cin, cout declaration.
#include <cmath>				// for log, ceil declaration.

using namespace std;			// for cin, cout defintion.

int main()
{
								// declare variables to hold the data entered by the user.
	double finalAmount, initialAmount;
	float  rate, years;
	char oneMore;


	do
	{							// ask the user to enter the initial amount he provided to be invested.
		cout << "Enter initial amount: ";
		cin >> initialAmount;	// get his amount.

		initialAmount = initialAmount > 0 ? initialAmount : 100;

								// ask him to enter the final amount he wants to get.
		cout << "Enter final amount: ";
		cin >> finalAmount;		// get his amount after a few years of investment.

		finalAmount = finalAmount > 0 ? finalAmount : 100;

								// the percent per year provided by the bank.
		cout << "Enter the percent per year: ";
		cin >> rate;			// get the percent.

		rate = rate > 0.0? rate : 1.1;

		rate /= 100.0;			// convert it to percentage.

								// calculate the years.
		years = log(finalAmount / initialAmount) / log(1 + rate);
		years = ceil(years);	// push the years up if there is any fractions.

								// show him the years expected to make him get that amount of money.
		cout << "You need " << years << " years to make such investment.\n\n";

		cout << "Do another? (y, n): ";
		cin >> oneMore;			// user's decision.

	} while (oneMore == 'y');	// loop if he wants.

	return 0;					// flag the 'OS' that the program executed successfully.
}