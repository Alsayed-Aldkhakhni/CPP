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
	BMoney(const char s[]) { money = strToNumeric(s);}
	
	explicit BMoney(long double mn)
	{
		if(mn < 0)
		{
			cout << "Invalid money.\n";
			exit(1);
		}
		
		money = mn;
	}
	
	// read an amount as string an convert it.
	void setMoney()
	{
		char s[15];
		cin >> s;
		money = strToNumeric(s);
	}
	
	// display money in standard form[e.g. $123,456.99]
	void getMoney() { numericToStr(money); }

	// operators.	
	BMoney operator+(BMoney& bm1) { return BMoney(money + bm1.money); }
	BMoney operator-(BMoney& bm1) {	return BMoney(money - bm1.money); }
	BMoney operator*(long double mon) { return BMoney(money * mon); }
	
	long double operator/(BMoney& bm1)
	{
		if(bm1.money == 0)
		{
			cout << "Can't divid by zero.\n";
			exit(1);
		}
		
		return (money / bm1.money);
	}

	BMoney operator/(long double numOfWids)
	{
		if(numOfWids <= 0)
		{
			cout << "Invalid number of widgets.\n";
			exit(1);
		}
		
		return BMoney(money / numOfWids);
	}

	friend BMoney round(BMoney&);
};

BMoney round(BMoney& bm)
{
	int iPart = static_cast<int>(bm.money);
	float fPart = bm.money - iPart;

	iPart = fPart >= 0.50 ? iPart+1 : iPart;

	return BMoney(iPart);
}

// function's definition.
void BMoney::numericToStr(long double doubVal)
{
	char temp[30];
	if(doubVal == 0)
	{
		temp[0] = '$';
		temp[1] = '0';
		temp[2] = '.';
		temp[3] = '0';
		temp[4] = '0';
		temp[5] = '\0';
		cout << temp << "\n";
		return;
	}

	// sample: 12345.55
	int intPart = static_cast<int>(doubVal);   // 12345
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
	BMoney total, pricePerWid;
	
	long double numOfWids;
	
	cout << "How many widgets do you have: ";
	cin >> numOfWids;
	
	cout << "Enter the price per widget: ";
	pricePerWid.setMoney();
	
	total = pricePerWid * numOfWids;
	
	cout << "    Total of those:    "; total.getMoney();
	cout << "    # of widgets:      " << (total / pricePerWid) << '\n';
	cout << "    price of a widget: ";   (total / numOfWids).getMoney();
	
	cout << "\n=======================================================\n";
	
	BMoney widget1, widget2;
	
	cout << "Enter the price of the 1st widget: ";
	widget1.setMoney();

	cout << "Enter the price of the 2nd widget: ";
	widget2.setMoney();
	
	cout << "     Total of them:  "; (widget1 + widget2).getMoney();
	cout << "     The difference: "; (widget1 - widget2).getMoney();
	
	cout << "\n";

	BMoney bm1, bm2;

	cout << "Enter an amount of money: ";
	bm1.setMoney();
	bm2 = round(bm1);

	cout << "bm1: "; bm1.getMoney();
	cout << "bm2: "; bm2.getMoney();

	// inidicates a successful execution.
	return 0;
}
