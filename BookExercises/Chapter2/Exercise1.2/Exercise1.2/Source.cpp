/*
 * Subject: A program to print some years and some values in a specific format.
 *
 * Date: 10 / 11 / 2023 .. 11th October
 *
 * Written by: Alsayed Ali
 */

#include<iostream>   // for 'cout' and 'cin' declaration
#include<iomanip>	 // for 'setw' fucntion declaration.

using namespace std; // This namespace 'std' contains the definition  of 'cin' and 'cout.

int main()			 // Entry point.
{

					 // print a table with a separated columns.
	cout << setw(4) << 1990 << setw(10) << 135 << endl
		 << setw(4) << 1991 << setw(10) << 7290 << endl
		 << setw(4) << 1992 << setw(10) << 11300 << endl
		 << setw(4) << 1993 << setw(10) << 16200 << endl
		 << endl;


	return 0; 		 // indicates the operating system that the program executed successfully.
}