/*
 * Subject: print a table of data.
 *
 * Date: October 11, 2023 
 *
 * Written by: Alsayed Ali
 * 
 * Last modification: April 9, 2024
 */

// preprocessor directives, instruct the compiler to replace these header files with their content.
#include <iostream>  // for 'cout' and 'cin' declaration
#include <iomanip>	 // for 'setw' fucntion declaration.
using namespace std; // This namespace 'std' contains the definition  of 'cin' and 'cout.

// Entry point.
int main()
{
	// print the table.
	cout << setw(4) << 1990 << setw(10) << 135 << endl
		 << setw(4) << 1991 << setw(10) << 7290 << endl
		 << setw(4) << 1992 << setw(10) << 11300 << endl
		 << setw(4) << 1993 << setw(10) << 16200 << endl;

	// indicates the operating system that the program executed successfully.
	return 0;
}
