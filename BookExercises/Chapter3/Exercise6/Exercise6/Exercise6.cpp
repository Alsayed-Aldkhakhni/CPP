/*
 * Subject: Get the factorial of a given number.
 *
 * Date: January 29, 2024
 *
 * Author: Alsayed Aldkhakhni
 */

#include <iostream>					// for cin, cout declaration.
using namespace std;				// for cin, cout defintion.

int main()							// start execution.
{

	unsigned long factorial = 1;	// to hold the final result.
	unsigned short num;				// to hold the number wanted to get its factorial.

	while (true)
	{								// ask the user to enter a number to get its factorial.
		cout << "Enter a number to calculate its factorial: ";
		cin >> num;					// get the number in 'num' vairable.

		if (num <= 0) break;		// test the validation of the entered number.
									// notice the test experssion,'i > 1', the last iteration when 'i = 1'
		for (int i = num; i > 1; i--) 
		{							//   isn't neccessary since any number * 1 is the same number.

			factorial *= i;			// calculate the factorial.
		}

		cout << factorial << "\n";	// show it to the user.
		factorial = 1;				// reset the value to get the factorial of anoter number.
	}

	return 0;						// flags the 'OS' that the program executed successfully.
}