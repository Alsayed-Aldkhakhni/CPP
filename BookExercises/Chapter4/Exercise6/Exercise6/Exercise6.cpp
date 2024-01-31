/*
 * Subject: A small program that take form the user the first character of an employee and print the whole title.
 * 
 * Date: December 12/ 2023
 *
 * Author: Alsayed Aldkhakhni
 */

// preprocessor directive statement instruct the preprocessor inside the compiler to fetch
//  the whole content of that header file included, iostream, to the currnt source file.
#include <iostream> 		// needed since it contains the declaration of 'cin' and 'cout' objects.

							// create an enumeration with its possible values.
enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main()
{
	etype employee{}; 	// declare a variable of type 'etype'.

	char chosen = '0'; // to hold the user's input.
	std::cout << "Enter employee type (first letter only)....\nlaborer, secretary, manager,\naccountant, executive, researcher: ";

	std::cin >> chosen;// take the input.

					   // convert it to lower case.
	chosen = tolower(chosen); 

	switch (chosen) 	// checking.
	{
		case 'l':
			employee = laborer;
			break;

		case 's':
			employee = secretary;
			break;

		case 'm':
			employee = manager;
			break;

		case 'a':
			employee = accountant;
			break;

		case 'e':
			employee = executive;
			break;

		case 'r':
			employee = researcher;
			break;

		default: 		// if the user's input wrong.
			std::cout << "Out of range.\f";
	}

	///////////////////////////////////////////////////////////////////////

	switch (employee) 	// print the employee's title based on user's input.
	{
		case 0:
			std::cout << "\fEmployee type is laborer\f";
			break;

		case 1:
			std::cout << "\fEmployee type is secretary\f";
			break;

		case 2:
			std::cout << "\fEmployee type is manager\f";
			break;

		case 3:
			std::cout << "\fEmployee type is accountant\f";
			break;

		case 4:
			std::cout << "\fEmployee type is executive\f";
			break;

		case 5:
			std::cout << "\fEmployee type is researcher\f";
			break;
	}

	return 0; 		// this statement indicates the operating system that the program executed successfully.
}