/*
 * Subject: Exchange money from old British monetary to the global notation.
 *
 * Date: July 18, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 20, 2024
 *
 * */

#include <iostream> // for the declaration of objects cin, cout.
#include <cstring>  // for strlen library function.
using namespace std;// the definition of cin, cout.

////################################################################################//
class Sterling      // class definition.
{
private:
	long pounds;
	int shillings;
	int pence;

	void validate(long, int, int);
public:
	// ctors.
	// no-args.
	Sterling() : pounds(0), shillings(0), pence(0) {}

	// one-arg.
	Sterling(double val)
	{
		if(val < 0)
		{
			cout << "Invalid amount of money.\n";
			exit(1);
		}

		pounds = static_cast<long>(val);
		shillings = int((val - pounds) * 20);
		pence = static_cast<int>(((val - pounds)*20 - shillings) * 12);
	}

	// three-args.
	Sterling(long p, int sh, int pec)
	{
		validate(p, sh, pec);
	}

	// read the data from the user.
	void setSterling()
	{
		long pod;
		int shils, pec;
		char dummy;

		cout << "Enter british money notation.[\u00A39.19.11]: ";
		cin >> pod >> dummy >> shils >> dummy >> pec;
		validate(pod, shils, pec);
	}

	// return it back to him.
	void getSterling() const {cout << "\u00A3" << pounds << '.' << shillings << '.' << pence << ".\n";}
	
	// overloaded operators.
	// (+) operator.
	Sterling operator+(Sterling& str) { return Sterling(pounds+str.pounds, shillings+str.shillings, pence+str.pence); }

	// (-) operator.
	Sterling operator-(Sterling& str) 
	{
		double val = (pounds + shillings/20.0 + pence/12.0)- (str.pounds + str.shillings/20.0 + str.pence/12.0);
		return Sterling(val);
	}

	// (*) operator.
	Sterling operator*(double scale)
	{
		if(scale <= 0)
		{
			cout << "Invalid value to scale with.\n";
			exit(1);
		}
		
		double val = (pounds + shillings/20.0 + pence/12.0) * scale;
		return Sterling(val);
	}

	// (/) operator.
	Sterling operator/(Sterling& str)
	{
		double val = (pounds + shillings/20.0 + pence/12.0) / (str.pounds + str.shillings/20.0 + str.pence/12.0);
		return Sterling(val);
	}

	// another version of (/) operator.
	Sterling operator/(double doubVal)
	{
		double val = (pounds + shillings/20.0 + pence/12.0) / doubVal;
		return Sterling(val);
	}
	
	// getters, return the value of the data members.
	long getPounds() { return pounds; }
	int  getShillis(){ return shillings;}
	int  getPence()  { return pence;}
	
	// conversion operator to double.
	operator double()
	{
		return pounds + shillings / 20.0 + pence / 240.0;
	}
};

// validate the amount of money.
void Sterling::validate(long pod, int sh, int pec)
{
	if(pod < 0)
	{
		cout << "Invalid pounds.\n";
		exit(1);
	}

	pounds = pod;

	if(sh < 0)
	{
		cout << "Invalid shillings.\n";
		exit(1);
	}

	pounds += sh / 20;
	shillings = sh - (sh/20)*20;

	if(pec < 0)
	{
		cout << "Invalid pence.\n";
		exit(1);
	}

	shillings += pec / 12;
	pence = pec - (pec/12)*12;
}
//################################################################################//

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
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
	
	// prevent impilict conversion.
	explicit BMoney(long double mn)
	{
		if(mn < 0)
		{
			cout << "Invalid money.\n";
			exit(1);
		}
		
		money = mn;
	}
	
	// convert Sterling object to BMoney.
	BMoney(Sterling& str)
	{
		money = (str.getPounds() + str.getShillis()/20.0 + str.getPence()/240.0) * 50.0;
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
	BMoney operator+(BMoney& bm1)     { return BMoney(money + bm1.money); }
	BMoney operator-(BMoney& bm1)     { return BMoney(money - bm1.money); }
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
	
	// conversion operator from BMoney to Sterling.
	operator Sterling() const { return Sterling(money / 50.0); }
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
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

int main()
{
	// instantiate objects and exchange.
	BMoney   bm1(50);
	Sterling str1 = bm1, str2(3.51);
	BMoney   bm2 = str2;
	
	// display the values.
	cout << "str1: "; str1.getSterling();// str1: £1.0.0.
	cout << "str2: "; str2.getSterling();// str2: £3.10.2.
	
	cout << "bm1:  "; bm1.getMoney();    // bm1:  $50.00
	cout << "bm2:  "; bm2.getMoney();    // bm2:  $175.41
	
	// indicates a successful execution.
	return 0;
}
