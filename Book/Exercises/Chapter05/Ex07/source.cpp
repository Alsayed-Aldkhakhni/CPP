/*
 * Subject: Overload power function to get the value of x^y of more than one type.
 * 
 * Date: January 1, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 8, 2024
 * 
 * */

#include <iostream> // for objects cin, cout declaration.
using namespace std;// for their definition.

// functions' prototype.
double power(double, int = 2);// for double.
float power(float , int = 2); // for float.
int power(int, int = 2);      // for int.
int power(char, int = 2);     // for char.

int main()
{
	// test the function.
	cout << power(5.55000) << "\n";
	cout << power(5.55F) << "\n";
	cout << power(65) << "\n";
	cout << power('a') << "\n";
	
	// indicates a successful execution.
	return 0;
}

// functions' definition, body.
double power(double base, int expon)
{
	cout << "The double version.: ";
	// take a copy to not change.
	double x  = base;
	for(int i = 1; i < expon; i++) base *= x;
	
	return base;
}

float power(float base, int expon)
{
	cout << "The float version.:  ";
	
	// take a copy to not change.
	double x  = base;
	for(int i = 1; i < expon; i++) base *= x;
	
	return base;
}

int power(int base, int expon)
{
	cout << "The int version.:    ";
	
	// take a copy to not change.
	int x  = base;
	for(int i = 1; i < expon; i++) base *= x;
	
	return base;
}

int power(char base, int expon)
{
	cout << "The char version.:  ";
	
	// take a copy to not change.
	int x  = int(base);
	for(int i = 1; i < expon; i++) base *= x;
	
	return base;
}


