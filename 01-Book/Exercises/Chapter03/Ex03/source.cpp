/*
 * Subject: Accumulate digits to form a number.
 * 
 * Date: December 5, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cout, cin declaration.
using namespace std;// for cout, cin definition.

int main()
{
	char digit;
	long num = 0;

	// start with 100,000 since the 1st digit has this value.
	for(int i = 100000; i >= 1; i /= 10)
	{
		// read a char at a time.
		digit = getchar();

		// validate the digits.
		if(digit >= '0' && digit <= '9')
			num += (digit - 48) * i;
		else
		{
			cout << digit << " is not a digit.\n";
			exit(1);
		}
	}

	// print final answer.
	cout << "Number is:  " << num << "\n"
		 << "Number + 1: " << num + 1 << "\n";

	// indicates a successful execution.
	return 0;
}