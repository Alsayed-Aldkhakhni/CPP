/*
 * Subject: Convert to/from celsuis.
 * 
 * Date: December 5, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cout, cin declaration.
using namespace std;// for cin, cout definition.

int main()
{
	short ans;
	float temprature;
	
	// the operation.
	cout << "1. Celsius to Fahrenheit\n"
			"2. Fahrenheit to Celsius: ";
	cin >> ans;
	
	// the temprature.
	cout << "Enter temprature to convert: ";
	cin >> temprature;

	switch(ans)
	{
	case 1: // °F = °C * 9/5 + 32  
		cout << "Fahrenheit: " << float(temprature) * 9.0/5.0 + 32.0 << "\n";
		break;
				
	case 2: // °C = 5/9(°F – 32)
		cout << "Celsius: " << 5.0/9.0 * (float(temprature) - 32) << "\n";
		break;
		
	default:// invalid section. 
		cout << "Invalid option.\n";
	}

	// indicates a successful execution.
	return 0;
}