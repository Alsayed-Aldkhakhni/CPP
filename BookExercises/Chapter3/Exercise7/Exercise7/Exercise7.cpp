/*
 * Subject: Calculate the amount of money after a few years of investment.
 *
 * Date: January 29, 2024
 *
 * Author: Alsayed Aldkhakhni
 */

 // preproccessor directive instructs the compiler, preproccessor namely,
 // to fetch the whole content of that header file, iostream, to the current source file.
#include <iostream>				// for cin, cout declaration.

using namespace std;			// for cin, cout defintion.

int main()						// start execution.
{
	double initialAmount;		// to hold the amount you invest with.
	unsigned short years;		// the years of investment.

	float rate;					// percent per year.
	char oneMore;				// the answer of doing another investment.

	do
	{							// prompt message tells the user what he has to do.
		cout << "Enter intial amount: ";
		cin >> initialAmount;	// get the amount he will invest with.

								// the years of investment he wants.
		cout << "Enter number of years: ";
		cin >> years;			// get them, 'years'.

								// the rate of investment per year.
		cout << "Enter interest rate (percent per year): ";
		cin >> rate;			// assign it to rate.

		if (rate <= 0) rate = 0;// validate the input.

		rate /= 100;			// make it a percentage.

		for (int i = 0; i < years; i++)
		{						// calculate the amount after n-years of investment.
			initialAmount += initialAmount * rate;
		}
								// print the amount to the user.
		cout << "At the end of " << years
			<< " years, you will have $" << initialAmount;

								// ask him if he wants to do another investment.
		cout << "\n\nDo another? (y, n): ";
		cin >> oneMore;			// his answer.
		cout << '\n';

	} while (oneMore == 'y');	// if he wants do it again, otherwise stop.

	return 0;					// flags the 'OS' that the program executed successfully.
}
