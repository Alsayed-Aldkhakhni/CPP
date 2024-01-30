/*
 * Subject: A program to add two fractions.

 * Date: 10 / 12 / 2023........12th of October. 
 
 * Written by: Alsayed Aldkhakhni.
*/


#include<iostream>								// for the declaration 'cin' & 'cout'.
using namespace std;							// for the definition of 'cin' & 'cout'.

int main()
{

	int num1, num2,								// declare neede variables.
		dnum1, dnum2;

	char dummyChar;								// to hold the division sign.
								 
	cout << "Enter the first fraction: ";		// I'm asking the user to input the first fraction.
	cin >> num1 >> dummyChar >> dnum1;		    // Get the first fraction.

								 
	cout << "Enter the second fraction: ";		// I'm asking the user to intput the second fraction.
	cin >> num2 >> dummyChar >> dnum2;			// Get the second fraction.

	cout << "Sum = "							// print the answer.
		 << num1 * dnum2 + num2 * dnum1
		 << '/' << dnum1 * dnum2;				
	
								
	cout << "\n";								// To enhance the clarity of the output.

	return 0;									// Flag the 'OS' that the program is done.'successful execution'
}