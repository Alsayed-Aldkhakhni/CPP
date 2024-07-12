//=============================================================================
// Name        : source.cpp
// Date        : July 12, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Convert money to into standared form[e.g. $12,550.99].
//=============================================================================
#include <iostream> // for cin, cout objects declaration.
using namespace std;// for their definition.

// function's prototype.
void numericToStr(long double);

int main()
{
	long double amount;
	
	for(int i = 0; i < 5; i++)
	{
		cout << "Enter an amount of money: ";
		cin >> amount;
		
		numericToStr(amount);
		cout << "\n";
	}

	return 0;
}

// function's definition.
void numericToStr(long double doubVal)
{
	char temp[30];
	
	// sample: 12345.55
	int intPart = static_cast<int>(doubVal); // 12345
	float fracPart = (doubVal - intPart) * 100;// 55
	
	temp[0] = '$';
	int i = 1;
	int z = 0;

	while(intPart != 0) // 12345
	{

		if(z == 3)
		{
			temp[i++] = ','; // 54,321
			z = 0;
		}

		// [1 + 48] -> '1'
		temp[i++] = static_cast<char>((intPart%10)+48);
		intPart /= 10;
		z++;
	}
	
	// terminate the string.
	temp[i] = '\0';
	
	// reverse the order.
	char swap;
	for(int k = 1, j = i-1; k < (i/2) +1; k++, j--)
	{
		swap = temp[k];
		temp[k] = temp[j];
		temp[j] = swap;
	}

	// add just 2 digits after the precision.
	temp[i++] = '.';
	int x1 = fracPart / 10;
	temp[i++] = static_cast<char>(x1 + 48);
	temp[i++] = static_cast<char>( (int(fracPart) - x1 * 10) + 48);

	// terminate the processed string.
	temp[i] = '\0';

	cout << "    Processed: " << temp << '\n';
}





