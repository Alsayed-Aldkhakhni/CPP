/*
 * Subject: A program that calculates the power of a double, int and float numbers.
 *
 * Date: November 22, 2023
 *
 * Author: Alsayed Aldkhakhni
 */


#include <iostream>						// for cin, cout declaration.
using namespace std;					// for cin, cout definition.


int power(int , int = 2);				// for integers power.
double power(double , int = 2);			// for double type power.
double power(float, int = 2);			// for float type power.


int main()
{
	cout << power(2, 5);				// call the function that performing on integers.
	cout << "\n++++++++++++++\n";
	
	cout << power(12.5555F, 2);			// call the function working on float '12.5555F' notice 'F' -> float.
	cout << "\n++++++++++++++\n";
	
	cout << power(12.5555, 3);			// since i didn't tell the compiler that i'm passing a float it call the one uses the double type.
	cout << "\n++++++++++++++\n";
	
	return 0;							// flags the 'OS' that the program is done.
}


int power(int base , int exponent)		// the definition of the integer function.
{
	cout << "type integer.\n";			// to show me which function i called.
	int times = base;					// take a copy to multiply by itself.

	// "base *= times" is as same as "base = base * times";
	for(int i = 1; i < exponent ; i++) base *= times;

	return base;						// return the value.
}

double power(float base, int exponent)
{
	cout << "type float.\n";
	float times = base;
	
	for(int i = 1; i < exponent ; i++)	base *= times;
	
	return base;
}

double power(double base, int exponent)	// the double one.
{
	cout << "type double.\n";
	double times = base;
	
	for( int i = 1 ; i < exponent ; i++) base *= times;

	return base;
}

