/*
 * Subject: Simple calculator.
 * 
 * Date: December 5, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cout, cin declaration.
using namespace std;// for cout, cin definition.

int main()
{
	// declaring variables.
	double operand1, operand2;
	char operation, ans;
	
	do
	{
		// prompt the user to enter the values.
		cout << "Enter 1st number, operator and 2nd number: ";
		cin >> operand1 >> operation >> operand2;
				
		// common statement, avoid dublicating the statment.
		cout << "\n" << operand1 << operation << operand2 << " = ";
		
		switch(operation)
		{
		case '+':
			cout << operand1 + operand2;
			break;
			
		case '-':
			cout << operand1 - operand2;
			break;
			
		case '*':
			cout << operand1 * operand2;
			break;
			
		case '/':
			cout << operand1 / operand2;
			break;
			
		default:
			cout << "Invalid operation.\n";
		}
		
		cout << "\n\nDo one more(y, n): ";
		cin >> ans;
		
	}while(ans == 'y');

	// indicates a successful execution.
	return 0;
}