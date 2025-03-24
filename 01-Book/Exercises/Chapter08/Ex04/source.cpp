/*
 * Subject: Carry out some arithmetic operations on Int class.
 * 
 * Date: January 15, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 16, 2024
 * 
 * */

#include <iostream> // for the declaration of objects cout, cin.
using namespace std;// for their definition.

//###########################################################################//
class Int           // class definition.
{
private:            // data hiding, private.	
	int var;
	enum{LIM = 2147483648};
	
public:             // member functions to handle that data.
	Int() : var(0) {}
	Int(int x) : var(x) {}
	
	void display() const { cout << var << "\n"; }

	// operators.
	//
	Int operator+(Int& Int1)
	{
		if(Int1.var + var > LIM)
		{
			cout << "+ Overflow.\n";
			exit(1);
		}

		return Int(var+Int1.var);
	}

	Int operator-(Int& Int1)
	{
		return Int(var-Int1.var);
	}

	Int operator*(Int& Int1)
	{
		if(Int1.var * var > LIM)
		{
			cout << "* Overflow.\n";
			exit(1);
		}

		return Int(var*Int1.var);
	}

	Int operator/(Int& Int1)
	{
		if(Int1.var == 0)
		{
			cout << "Division by zero not allowed.\n";
			exit(1);
		}

		return Int(var/Int1.var);
	}

};
//###########################################################################//

int main()
{
	// instantiate 6 objects.
	Int Int1(150), Int2(2950), sum, sub, mul, div;

	// invoke the operators.
	sum = Int1 + Int2;
	sub = Int1 - Int2;
	mul = Int1 * Int2;
	div = Int2 / Int1;

	// display all the values.
	cout << "Int1:  "; Int1.display();
	cout << "Int2:  "; Int2.display();
	cout << "sum:   "; sum.display();
	cout << "sub:   "; sub.display();
	cout << "mul:   "; mul.display();
	cout << "div:   "; div.display();

	// indicates a successful execution.
	return 0;
}
