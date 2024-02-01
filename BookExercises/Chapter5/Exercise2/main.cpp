/*
 * Subject: A program to calculate the power of a number.
 *
 * Date: November 20, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

// preprocessor directive instruction to fetch the whole 
//	content of that header file to the current source file.

#include <iostream> 			// cout declaration.

double power(double, int = 2); 	// function 'power' declaration, notice the default exponent 'int = 2'.

int main()
{
	double base = 1;			// initialze the needed variables.
	int exponent = 1;

	std::cout << "Enter base: ";// ask the user to enter the base of the number.
	std::cin >> base;			// get the base.

								// enter the exponent.
	std::cout << "Enter exponent: ";
	std::cin >> exponent;
								// call the function to get the value of 'base' of the power 'exponent'.
	std::cout << power(base, exponent);	
	return 0;					// indicates the operating system that the program executed successfully.
}

								// function definition.
double power(double num, int exponent)
{
	double result = 1;			// initialize the variable to hold the result.
								// loop n-times = exponent value.
	for(int i = exponent; i > 0; i--)
	{
		result	*= num;			// every iteration multiply the base by itself.
	}

	return result;				// finally return the result to the calling program.
}