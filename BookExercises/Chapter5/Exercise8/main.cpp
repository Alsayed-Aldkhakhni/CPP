/*
 * Subject: A program that swaps two integers.
 *
 * Date: November 23, 2023
 *
 * Author: Alsayed Aldkhakhni
 */


#include <iostream>				// for cout, cin declaration.

void swap(int &, int &);		// the declarator of the function which swaps the passed two integers.
void print(int, int);			// the declarator of the one which will print the values before and after swapping.

int main()
{
	int num1 = 99, num2 = 55;	// get the two integers.
	
	print(num1, num2);			// print them before swapping.
	
	swap(num1, num2);			// swapping.
	
	print(num1, num2);			// print after swapping.

	return 0;					// flags the 'OS' that the program executed successfully.
}


void swap(int &num1, int &num2)	// the definition of the function which will swap the numbers.
{
	int temp = num1;			// a temporary variables to keep the value of 'num1' from overwritten.

	num1 = num2;				// store the value of 'num2' in 'num1'
	num2 = temp;				// the value of temp, which is num1, stored in 'num2'.
}

void print(int num1, int num2)	// print the numbers passed to the function.
{
	std::cout << "First: " << "\t\tSecond:\n";
	std::cout << num1 << "\t\t" << num2 << "\n";
}