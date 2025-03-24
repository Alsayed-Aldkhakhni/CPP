/*
 * Subject: Class Sterling that simulates old British monetary representation.
 *
 * Date: July 18, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 20, 2024
 *
 * */

#include <iostream> // for the declaration of objects cin and cout.
using namespace std;// for their definition.

//#################################################################//
class Sterling      // class definition.
{
private:
	long pounds;
	int shillings;
	int pence;

	void validate(long, int, int);
public:
	// no-arg ctor.
	Sterling() : pounds(0), shillings(0), pence(0) {}

	// one-arg ctor.
	Sterling(double val)
	{
		// check the input.
		if(val < 0)
		{
			cout << "Invalid amount of money.\n";
			exit(1);
		}
		
		// exchange from decimal to old notation.
		pounds = static_cast<long>(val);
		shillings = int((val - pounds) * 20);
		pence = static_cast<int>(((val - pounds)*20 - shillings) * 12);
	}

	// three-args ctor.
	Sterling(long p, int sh, int pec)
	{
		validate(p, sh, pec);
	}

	// read the money amount from the user.
	void setSterling()
	{
		long pod;
		int shils, pec;
		char dummy;

		cout << "Enter british money notation.[\u00A39.19.11]: ";
		cin >> pod >> dummy >> shils >> dummy >> pec;
		validate(pod, shils, pec);
	}

	// return it back.
	void getSterling() const {cout << "\u00A3" << pounds << '.' << shillings << '.' << pence << ".\n";}

	// convert from old notation to double.
	operator double()
	{
		return pounds + shillings / 20.0 + pence / 240.0;
	}

	// add two Sterlings.
	Sterling operator+(Sterling& str)
	{
		return Sterling(pounds+str.pounds, shillings+str.shillings, pence+str.pence);
	}

	// subtract.
	Sterling operator-(Sterling& str)
	{
		double val = (pounds + shillings/20.0 + pence/12.0) - (str.pounds + str.shillings/20.0 + str.pence/12.0);
		return Sterling(val);
	}

	// multiply with a double to scale the amount.
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

	// divide two Sterlings.
	Sterling operator/(Sterling& str)
	{
		double val = (pounds + shillings/20.0 + pence/12.0) / (str.pounds + str.shillings/20.0 + str.pence/12.0);
		return Sterling(val);
	}

	// divide one Sterling and a double value.
	Sterling operator/(double doubVal)
	{
		double val = (pounds + shillings/20.0 + pence/12.0) / doubVal;
		return Sterling(val);
	}
};

// validate the input of the user.
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

		// if sh, shillings, >= 20.
		pounds += sh / 20;
		shillings = sh - (sh/20)*20;

		if(pec < 0)
		{
			cout << "Invalid pence.\n";
			exit(1);
		}

		// if pec, pence, >= 12.
		shillings += pec / 12;
		pence = pec - (pec/12)*12;
}
//#################################################################//

int main()
{
	// instantiate the objects.
	Sterling str1, str2, str3(3.51);

	// read the values.
	str1.setSterling();
	str2.setSterling();

	// carry out the operations and display.
	cout << "+. "; (str1+str2).getSterling();
	cout << "-. "; (str1-str2).getSterling();
	cout << "*. "; (str1*12.50).getSterling();
	cout << "/. "; (str1/str2).getSterling();

	cout << "\n-------------------\n";
	cout <<"str3: "; str3.getSterling();

	double val = str3;
	cout << "val: " << val << "\n\n";

	// indicates a successful execution.
	return 0;
}
