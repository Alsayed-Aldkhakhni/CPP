/*
 * Subject: A program display the table of multiples of a number.
 *
 * Date: December 14, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

												// preprocessor directive instructs the preprocessor to fetch
												// the whole content of that file to this source file.
#include <iostream>								// 'cout' declaratoin.
#include <iomanip>								// 'setw' declaration.

int main()
{
	int num;									// declare the input variable.

	std::cout << "Enter a number: ";			// prompt message tells the user what to do.
	std::cin >> num;							// the number will print its multipliers.

	int temp = 0;								// to hold a copy of the number to preseve the it from overwriting.

	for (int rows = 1; rows <= 20; rows++)		// you got only 20 lines.
	{
		for (int column = 1; column <= 10; column++) // 10 columns for each single line.
		{
			temp += num;
			std::cout << std::setw(6) << temp;	// print the number in 6-digits width.
		}

		std::cout << '\f';						// next line once you finish from the current line.
	}

	return 0;									// indicates the operating system that the program executed successfully.
}