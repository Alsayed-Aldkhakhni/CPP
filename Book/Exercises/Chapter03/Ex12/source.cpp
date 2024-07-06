/*
 * Subject: Four-function calculator for fractions.
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
	// declare neede variables.
	int a, b;      // 1st fraction.
	int c, d;      // 2nd fraction.
	char dummy;    // / sign.
	char operation;// operator.
	char ans;	   // user's answer to loop again.
	
	do
	{
		// read the fractions and the operation.
		cout << "Enter 1st fraction, operator and 2nd fraction: ";
		cin >> a >> dummy >> b
			>> operation
			>> c >> dummy >> d;
	
		if(d == 0 || b == 0)
		{
			cout << "Can't divid by zero.\n";
			exit(1);
		}
		
		// [x/y] +,-,*,/ [a/b]
		switch(operation)
		{
		case '+':
			cout << (a*d) + (b*c) << '/' << (b*d) << " = " << float((a*d) + (b*c)) / float(b*d) << "\n\n";
			break;
	
		case '-':
			cout << (a*d) - (b*c) << '/' << (d*b) << " = " << float((a*d) - (b*c)) / float(b*d) << "\n\n";
			break;
		
		case '*':
			cout << (a*c) << '/' << (b*d) << " = " << float(a*c) / float(b*d) << "\n\n";
			break;
		
		case '/':
			cout << (a*d) << '/' << (b*c) << " = " << float(a*d) / float(b*c) << "\n\n";
			break;
		
		default:
			cout << "Invalid operation.\n";	
		}

		cout << "One more time(y, n): ";
		cin >> ans;
		
	}while(ans == 'y');
	
	
	// indicates a successful execution.
	return 0;
}