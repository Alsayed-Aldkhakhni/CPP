/*
 * Subject: A program demonstrates the difference between global variable and static variable.
 *
 * Date: November 23, 2023
 *
 * Author: Alsayed Aldkhakhni
 */


#include <iostream>				// for declaration of cout.

int globalCount = 0;			// declare and initialize the global variable will be used in the global function.

void globalFunction();			// the function will work on a global variable.
void localStaticFunction();		// the function will work on a static variable within it.

int main()
{								// call the function which works on the global variable.
	for(int ite = 1; ite <= 5; ite++) globalFunction();
	
								// separate the output of the functions.
	std::cout << "--------------------------------------\n";
	
								// call the function which works on the static variable.
	for(int ite = 1; ite <= 5; ite++) localStaticFunction();


	return 0;					// flags the operating system that the program executed successfully.
}


void globalFunction()			// the definition of the function working on the global variable.
{
	globalCount++;				// increment the global variable by 1.

								// print the number of calls.
	std::cout << "I'm a global function called " << globalCount << " times.\n";
}

void localStaticFunction()		// the definition of the function working on the static variable.
{
	static int count = 0;		// declare the static variable.

	count++;					// increment the static variable by 1.

								// print the number of calls.
	std::cout << "I'm a static function called " << count << " times.\n";
}