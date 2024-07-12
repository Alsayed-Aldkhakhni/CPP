//============================================================================
// Name        : source.c
// Date        : July 12, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : A class that services big money exchanges.
//============================================================================
#include <iostream> // for cin, cout declaration.
#include <cstring>  // for strlen
using namespace std;// for cin, cout definition.

//###########################################################################//
class BMoney
{
private:
	long double money;
	
	void numericToStr(long double doubVal);
	long double strToNumeric(const char str[]);
	
public:
	// ctors.
	BMoney() : money(0) {}
	BMoney(const char s[])
	{
		money = strToNumeric(s);
	}
	
	// read an amount as string an convert it.
	void setMoney()
	{
		char s[15];
		cout << "Enter an amount of money[$123,456.55]: ";
		cin >> s;
		
		money = strToNumeric(s);
	}
	
	// display money in standard form[e.g. $123,456.99]
	void getMoney() { numericToStr(money); }
	
	// add 3 BMoney objects.
	void add(BMoney& bm1, BMoney& bm2)
	{
		money = bm1.money + bm2.money ;
	}
};

// function's definition.
void BMoney::numericToStr(long double doubVal)
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

	cout << temp << '\n';
}


// function's body.
long double BMoney::strToNumeric(const char str[])
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
//###########################################################################//

int main()
{
	BMoney bm1("$998,778.99"), bm2, sum;
	
	bm2.setMoney();
	sum.add(bm1, bm2);

	// display both amounts.
	cout << "     bm1: "; bm1.getMoney();
	cout << "     bm2: "; bm2.getMoney();
	cout << "     sum: "; sum.getMoney();

	// inidicates a successful execution.
	return 0;
}

