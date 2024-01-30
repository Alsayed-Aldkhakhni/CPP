/*
 * Subject: Create four function to perform 4-arithmatic operations on fractions.
 *
 * Date: January 29, 2024
 *
 * Author: Alsayed Aldkhakhni
 */


 // preproccessor directive instructs the compiler, preproccessor namely,
 // to fetch the whole content of that header file, iostream, to the current source file.
#include <iostream>					// for cin, cout declaration.

using namespace std;				// for cin, cout defintion.

int main()
{
	int numerator1, numerator2;		// the numerators of both fractions.
	int denominator1, denominator2;	// the denominators of both fractions.

	char divSign, operation;		// the division sign and the operator.
	char oneMore;					// to get the answer of the user whether he wants to do another operation.

	do
	{
									// prompt message tells the user what to do.
		cout << "Enter two fraction in form [a/b + c/d]: ";

									// read the expression from him.
		cin >> numerator1 >> divSign >> denominator1
			>> operation
			>> numerator2 >> divSign >> denominator2;

									// validate the denominators.
		if (denominator1 == 0 || denominator2 == 0)
		{
			cout << "Can't divid by zero!!";
			break;
		}

		switch (operation)			// start the actual work.
		{
		case '+':					// case the operation entered was addition.
			cout << numerator1 * denominator2 + numerator2 * denominator1
				<< '/'
				<< denominator1 * denominator2;
			break;

		case '-':					// subtraction.
			cout << numerator1 * denominator2 - numerator2 * denominator1
				<< '/'
				<< denominator1 * denominator2;
			break;

		case '*':					// multiplication.
			cout << numerator1 * numerator2
				<< '/'
				<< denominator1 * denominator2;
			break;


		case '/':					// division.
			cout << numerator1 * denominator2
				<< '/'
				<< denominator1 * numerator2;
			break;

		default:					// unknown operator.
			cout << "Something went wrong.\n";
		}

									// ask the user whether he wants to do another operation.
		cout << "\nDo another? (y, n): ";
		cin >> oneMore;				// his answer.

	} while (oneMore == 'y');		// loop depending on his answer.

	return 0;						// flag 'OS' that the program executed successfully.			
}