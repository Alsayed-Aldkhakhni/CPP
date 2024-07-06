/*
 * Subject: Calculate the factorial.
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
	int num;
	char ans;
	
	do
	{
		// read a number to calculate its factorial.
		cout << "Enter a number: ";
		cin >> num;
		
		// calculate the factorial.
		unsigned long factorial = 1;
		for(int i = 1; i <= num; i++)
			factorial *= i;

		// display the result.
		cout << "\nFactorial of " << num << " is " << factorial << "\n\n";
		
	}while(num != 0);
	
	// indicates a successful execution.
	return 0;
}
