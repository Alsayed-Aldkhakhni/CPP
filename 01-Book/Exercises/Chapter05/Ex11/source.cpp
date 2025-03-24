/*
 * Subject: Simulate old British monetary system using structure Sterling.
 * 
 * Time: January 1, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 8, 2024
 * 
 * */

#include <iostream> // for objects cin, cout declaration.
using namespace std;// for their definition.

//////////////////////////////
struct Sterling
{
	int pounds;
	int shillings;
	int pence;
};
//////////////////////////////

// functions' declaration.
Sterling readSterling();
Sterling add(Sterling&, Sterling&);
void display(Sterling&);

int main()
{
	// instantiate 3 objects.
	Sterling str1, str2, sum;

	// read the amounts.
	str1 = readSterling();
	str2 = readSterling();
	
	// adding.
	sum = add(str1, str2);
	
	// display the 3 amounts.
	cout << "str1:  "; display(str1);
	cout << "str1:  "; display(str2);
	cout << "sum:   "; display(sum);

	// indicates a successful execution.
	return 0;
}

// functions' definition.
Sterling readSterling()
{
	Sterling str;
	char dummyChar;
	
	// read the amount.
	cout << "Enter an old British amount[5.19.11]: ";
	cin >> str.pounds >> dummyChar >> str.shillings >> dummyChar >> str.pence;
	
	// simple validation.
	if(str.pounds < 0 || (str.shillings < 0 || str.shillings > 19) || (str.pence < 0 || str.pence > 12))
	{
		cout << "Invalid value(s) entered.\n";
		exit(1);
	}
	
	// the value.
	return str;	
}

Sterling add(Sterling& str1, Sterling& str2)
{
	
	Sterling temp;
	
	temp.pounds    = str1.pounds    + str2.pounds;
	temp.shillings = str1.shillings + str2.shillings;
	temp.pence     = str1.pence     + str2.pence;
	
	if(temp.shillings > 19)
	{
		temp.pounds   += temp.shillings / 20;
		temp.shillings = temp.shillings - (temp.shillings / 20) * 20;
	}

	
	if(temp.pence > 11)
	{
		temp.shillings += temp.pence / 12;
		temp.pence      = temp.pence - (temp.pence / 12) * 12;
	}

	return temp;
}

void display(Sterling& str)
{
	cout << "\u00A3" << str.pounds << '.' << str.shillings << '.' << str.pence << ".\n";
}

