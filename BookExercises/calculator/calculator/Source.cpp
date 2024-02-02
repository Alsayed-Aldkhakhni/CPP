/*
 * Subject: If you want to do an operation on the fly, there is no need to get an object
 *					 and aside a space in memory for this object just use utility class.
 * 
 * Date: November 21, 2023
 *
 * Author: Alsayed Aldkhakhni 
 */

#include <iostream>					// declaration of cin, cout.
#include "Calculator.h"				// the class in this situation is called a utility class.

using namespace std;				// the definition of cin, cout.

int main()
{
	/*
		 * Hint: if you use any method of these without class name, will get an error.

		 * utility class means you can use its methods 
		   without any need to get any object just use the methods directly.

		 *But wait a minute, can i do that ?
		   Yes, the reason is the static members belong to the class itself so you can use them directly.	
	 */

	float num1 = 12.55F;			// define the two operands will be used in the program.
	float num2 = 5.12F;

	cout << "addition: "			// the addition process.
		 << Calculator::ADD(num1, num2)
		 << "\n--------------------\n";

	cout << "division: "			// the division.
		 << Calculator::DIV(num1, num2)
		 << "\n--------------------\n";

	cout << "multiplication: "		// multiplication.
		 << Calculator::MUL(num1, num2)
		 << "\n--------------------\n";

	cout << "subtraction: "			// the subtraction.
		 << Calculator::SUB(num1, num2)
		 << "\n--------------------\n";

	cout << "modulus: "				// the reminder.
		 << Calculator::MOD(17, 5) << "\n\n";

	return 0;						// Mission accomplished.
}