//============================================================================
// Name        : source.cpp
// Date        : July 12, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Convert an amount of money from string to numerical value.
//============================================================================

#include <iostream> // for cin, cout objects declaration.
#include <cstring>  // for strlen
#include <math.h>
#include <stdlib.h>
using namespace std;// for cin, cout definition.

// function's prototype.
long double strToNumeric(char[]);

int main()
{
	char strMoney[30];
	
	for(int i = 0; i < 10; i++)
	{
		cout << "Enter an amount of money[$123,456.12]: ";
		cin >> strMoney;
		
		cout << "----> As numeric: " << strToNumeric(strMoney) << "\n\n";
		strMoney[0] = '\0';
	}
	
	return 0;
}

// function's body.
long double strToNumeric(char str[])
{
	short len = strlen(str);
	char temp[len];
	bool oneTime = false;
	
	for(int i = 0, j = 0; i < len; i++)
	{
		if(str[i] <= '9' && str[i] >= '0')
			temp[j++] = str[i];
		else if(str[i] == '.')
		{
			if(!oneTime) // read dot one time.
			{
				temp[j++] = str[i];
				oneTime = true;
			}
		}
	}
	
	return atof(temp);	
}