//============================================================================
// Name        : source.cpp
// Date        : June 17, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Evaluate an infix expression.
//============================================================================

// preprocessor directive, instructs the preprocessor to pre-fetch the
// content of this header file, iostream, to the current source file
// since we need it for using 'cin' and 'cout' objects.

#include <iostream> // for 'cin' and 'cout'.
#include <cstring>  // for 'strlen()', atol().
#include "Stack.h"  // reference of Stack data structure.
using namespace std;// contains the definition of cin, cout.

// functions' prototype.
int evaluate(char exp[], const int len);
void InToPost(char* in,  char* post);

int main()
{
	// array of characters, i used it since string didn't work.
	char infix[100], postfix[100];
	
	// prompt the user to enter an infixression.
	cout << "\n    Enter an infix expression[e.g. 6 * 14 + 5]\n"
			"    $leave space among the operators and operands.$\n"
			"    $no negative numbers$: ";

	// read it.
	cin.getline(infix, 100);

	InToPost(infix, postfix);
	
	cout << "================================\n";
	cout << "    Infix:      " << infix << "\n"
		 << "    Postfix:    " << postfix << "\n";
	
	// execute.
	cout << "    Expression: " << infix << " = " << evaluate(postfix, strlen(postfix));
	cout << "\n================================\n";

	// indicate a successful execution.
	return 0;
}

// function's body.
int evaluate(char exp[], const int len)
{
	// hold the data.
	Stack<int> st(50);

	// delimit the scope of these functions.
	bool isOperator(char opr);// check if the current char is an operator.
	bool isDigit(char );      // check if the current char is a digit.
	int solve(int, int, char);// carry out the operation.

	// hold the digits to convert to numerical.
	char buff[10]; int k = 0;
	long rslt;
	
	// Processing the characters in the stack.
	for(int i = 0; i < len; i++)
	{
		if(isDigit(exp[i]))
			buff[k++] = exp[i];
		else if(exp[i] == ' ' && !isOperator(exp[i-1])  && exp[i-1] != ' ')
		{
			buff[k] = '\0';

			// evaluate string to numeric.
			rslt = atol(buff);
			st.push(rslt);
			
			// reset the buffer array.
			k = 0;
			buff[0] = '\0';
		}
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

	// return the evaluated postfix expression.
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

// converts from infix to postfix.
void InToPost(char* inExp, char* post)
{
	Stack<char>operators(50);
	short opWeight(char op1, char op2); // check the operators' weight.

	int len = strlen(inExp);
	int j = 0;

	for(int i = 0; i < len; i++)
	{
		if(isDigit(inExp[i]))
		   post[j++] = inExp[i];
		else if(isOperator(inExp[i]))
		{
			// push the 1st operator.
			if(operators.isEmpty())
				operators.push(inExp[i]);
			else
			{
				// check the precedence.
				if(opWeight(inExp[i], operators.peek()) > 0)
					operators.push(inExp[i]);
				else
				{
					while(opWeight(inExp[i], operators.peek()) <= 0)
					{
						post[j++] = operators.pop();
						post[j++] = ' '; 
						if(operators.isEmpty()) break;
					}
					
					operators.push(inExp[i]);
				}
			}
		}
		else if(inExp[i] == ' ')
		   post[j++] = inExp[i];
		else // if there is a non-valid char.
		{
			if(!isDigit(inExp[i]) && !isOperator(inExp[i]) && inExp[i] != ' ')
			{
				cout << "Neither operand nor operator.\n";
				exit(1);
			}
		}
	}

	// the rest of operators.
	while(operators.isEmpty() == 0)
	{
	  post[j++] = ' '; 
	  post[j++] = operators.pop();
	}

	// terminate the string.
	post[j] = '\0';
}

short opWeight(char op1, char op2)
{
	// same precedence.
	if(op1 == '+' && op2 == '-' || op1 == '-' && op2 == '+' ||
	   op1 == '+' && op2 == '+' || op1 == '-' && op2 == '-' ||
	   
	   op1 == '*' && op2 == '/' || op1 == '/' && op2 == '*' ||
	   op1 == '/' && op2 == '/' || op1 == '*' && op2 == '*' ||
	   
	   op1 == '%' && op2 == '/' || op1 == '%' && op2 == '*' ||
	   op1 == '/' && op2 == '%' || op1 == '*' && op2 == '%' ||
	   
	   op1 == '%' && op2 == '%')
		
		return 0;
	
	// lower precedence.
	else if(op1 == '+' && op2 == '*' || op1 == '-' && op2 == '/' ||
			op1 == '+' && op2 == '%' || op1 == '-' && op2 == '%' ||
			op1 == '+' && op2 == '/' || op1 == '-' && op2 == '*')	
		
		return -1;
	
	// higher precedence.
	else if(op1 == '*' && op2 == '-' || op1 == '*' && op2 == '+' ||
			op1 == '/' && op2 == '-' || op1 == '/' && op2 == '+' ||
			op1 == '%' && op2 == '-' || op1 == '%' && op2 == '+')
		
		return 1;
	
	// worthless statement but to avoid compiler's warnings.
	return 2;
}



