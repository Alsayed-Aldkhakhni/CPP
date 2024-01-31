/*
 * Subject: A program that adds two fractions.
 *
 * Date: December 12, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

// preprocessor directives instruct the compiler's preprocessor to fetch the 
// whole content of these header files, iostream & conio to the current source file.
#include <iostream> 			// 'cin' and 'cout' declaration.
#include <conio.h>  			// '_getche()' declaration.
using namespace std;			// the definition of cin, cout, _getche().


struct fraction 				// structure tag.
{
	int numerator;				// members.
	int denominator;
};


int main()
{

	fraction F1{}, F2{}, F3{};  // get three fractions variables of type 'fraction'.

	do
	{
		//** First fraction.
								// to hold the data before assigning.
		int fracNumerator = 1, fracDenominator = 1;
		char divisionSign = '/';
								// prompt message tells the user what to do.
		cout << "Enter a fraction in form (x/ y): ";

		cin >> fracNumerator 	// get the fraction.
			>> divisionSign
			>> fracDenominator;

		if (divisionSign != '/')// Check if the user has entered an incorrect operator.
		{
								// If that is true, he entered an incorrect operator, this message will be printed.
			cout << "Error!, You entered a wrong operator the division represented by \'/\'\f";
			return 0; 			// stop executing.
		}
		else if (fracDenominator == 0)// Check if the user is going to divide by '0'.
		{
								// If that is true, he attempts to divide by 0, this message will be printed.
			cout << "Division by 0 is undefined.\f";
			return 0;
		}
		else 					// if there is no problem with the fraction entered.
		{
			F1.numerator = fracNumerator;
			F1.denominator = fracDenominator;
		}

		//** Second fraction.

								// prompt message tells the user what to do.
		cout << "Enter a fraction in form (x/ y): ";

		cin >> fracNumerator 	// get the fraction.
			>> divisionSign
			>> fracDenominator;

		if (divisionSign != '/')// Check if the user has entered an incorrect operator.
		{
								// If that is true, he entered an incorrect operator, this message will be printed.
			cout << "Error!, You entered a wrong operator the division represented by \'/\'\f";
			return 0; 			// stop executing.
		}
		else if (fracDenominator == 0)// Check if the user is going to divide by '0'.
		{
								// If that is true, he attempts to divide by 0, this message will be printed.
			cout << "Division by 0 is undefined.\f";
			return 0;
		}
		else 					// if there is no problem with the fraction entered.
		{
			F2.numerator = fracNumerator;
			F2.denominator = fracDenominator;
		}


		F3.numerator = F1.numerator * F2.denominator + F2.numerator * F1.denominator;
		F3.denominator = F1.denominator * F2.denominator;


								// display the sum.
		cout << "Sum: " << F3.numerator << '/' << F3.denominator << "\n\n";


								// prompt message aks the user if he wants to stop.
		cout << "Press 'Esc' to exit.";
	} while (_getche() != 27); 	// if the user pressed 'Esc' key the program will stop.


	return 0; 					// indicates the operating system that the program executed successfully.
}