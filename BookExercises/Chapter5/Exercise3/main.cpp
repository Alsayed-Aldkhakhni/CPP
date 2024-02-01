/*
 * Subject: A program to take two numbers and make the smaller 0.
 *
 * Date: November 20, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

// preprocessor directive instruction to fetch 
// the whole content of that header file to the current source file.

#include <iostream> 			 // cout, cin declaration.

								 // functions prototypes.

void zeroSmaller(int& x, int& y);// to make the smallest 0.
void print(int x);				 // to print the passed integer.

int main()
{
	int num1, num2;				 // declare the two numbers to get them from the user.
	
								 // ask the user to enter the first number.
	std::cout << "Enter a number: ";
	std::cin >> num1;			 // get the first number.
	
								 // the second number.
	std::cout << "Enter another number: ";
	std::cin >> num2;			 // get the second number.
	
								 // print the two numbers before changing.
	std::cout << "Before: "; print(num1); print(num2);
	
	
	
	zeroSmaller(num1, num2);	 // set the smallest one 0.
	
								 // print the numbers after changing.
	std::cout << "\nAfter: "; print(num1); print(num2);
	
	return 0;					 // indicates the Operating System that the program is done.
}

///***********************************************************************

								 // functions defination.
void zeroSmaller(int &num1, int &num2)
{
	if(num1 > num2)				 // check if the first is bigger than the second.
	{
		num2 = 0;				 // make the second 0.
	}
	else if(num1 < num2)		 // else 
	{
		num1 = 0;				 // make the first 0.
	}
}

void print(int num)				  // print the number.
{
	std::cout << num << '\t';
}