//============================================================================
// Name        : ExpEvaluation.cpp
// Date        : June 17, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Evaluate a post-fix expression.
//============================================================================

// preprocessor directive, instructs the preprocessor to pre-fetch the
// content of this header file, iostream, to the current source file
// since we need it for using 'cin' and 'cout' objects.

#include <iostream> // for 'cin' and 'cout'.
#include <cstring>  // for 'strlen()', atol().
#include "Stack.h"  // reference of Stack data structure.
using namespace std;// contains the definition of cin, cout.

// function's prototype to evaluate an post-fix expression.
int postfixEval(char exp[], const int len);

int main()
{
	// array of characters, i used it since string didn't work.
	char exp[100];

	// prompt the user to enter an expression.
	cout << "Enter a post-fix expression [e.g. 6 9 * 14 +]\n"
			"$leave space among the operators and operands.$\n"
			"$no negative numbers$: ";

	// read it.
	cin.getline(exp, 100);

	// execute.
	cout << exp << " = " << postfixEval(exp, strlen(exp)) << "\n";

	// indicate a successful execution.
	return 0;
}

// function's body.
int postfixEval(char exp[], const int len)
{
	// hold the data.
	Stack<int> st(50);

	// delimit the scope of these functions.
	bool isOperator(char opr);// check if the current char is an operator.
	bool isDigit(char );      // check if the current char is a digit.
	int solve(int, int, char);// carry out the operation.

	// hold the digits to convert to numerical.
	char buff[7]; int k = 0;
	long rslt;

	// Processing the characters in the stack.
	for(int i = 0; i < len; i++)
	{
		if(exp[i] == ' ' && !isOperator(exp[i-1]))
		{
			buff[k] = '\0';

			// evaluate string to numeric.
			rslt = atol(buff);
			st.push(rslt);

			// reset the buffer array.
			k = 0;
			buff[0] = '\0';
		}
		else if(isDigit(exp[i]))
			buff[k++] = exp[i];

		// carry out the operation.
		else if(isOperator(exp[i]))
		{
			int y =  st.pop();
			int x =  st.pop();

			int z = solve(x, y, exp[i]);
			st.push(z);
		}
		else // if there is a non-valid char.
		{
			if(!isDigit(exp[i]) && !isOperator(exp[i]) && exp[i] != ' ')
			{
				cout << "Neither operand nor operator.\n";
				exit(1);
			}
		}
	}

	// return the evaluated expression.
	return st.pop();
}

// is the current character digit ?
bool isDigit(char x) { return x >= '0' && x <= '9';}

// is it an operator?
bool isOperator(char opr)
{
	return (opr == '+' || opr == '-' || opr == '*' || opr == '/' || opr == '%') ? true : !true;
}

// carry out the arithmetic operations.
int solve(int x, int y, char opr)
{
	int z;

	switch(opr)
	{
	case '+':
		z = x + y;
		break;

	case '*':
		z = x * y;
		break;

	case '-':
		z = x - y;
		break;

	case '/':
		if(y == 0)
		{
			cout << "Division by zero is not allowed.\n";
			exit(1);
		}

		z = x / y;
		break;

	case '%':
		if(y == 0)
		{
			cout << "There is not reminder on zero.\n";
			exit(1);
		}

		z = x % y;
	}

	return z;
}
