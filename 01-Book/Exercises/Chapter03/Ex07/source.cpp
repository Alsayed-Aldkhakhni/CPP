/*
 * Subject: How much money you'll end up with after years of investment.
 * 
 * Date: December 5, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cout, cin declaration.
using namespace std;// for cout, cin definition.

int main()
{
	// declare the variables.
	double initAmount;
	int years;
	float rate;
	
	// read the base amount.
	cout << "Enter initial amount: ";
	cin >> initAmount;
	
	if(initAmount <= 0)
	{
		cout << "Invalid amount.\n";
		exit(1);
	}
	
	// how many years of investment.
	cout << "Enter # of years: ";
	cin >> years;
	
	if(years < 0)
	{
		cout << "Invalid years number.\n";
		exit(1);
	}
	
	// how much per year.
	cout << "Enter interest rate(percent per year): ";
	cin >> rate;
	
	if(rate < 0)
	{
		cout << "Invalid rate.\n";
		exit(1);
	}
	
	// convert it to be a dicimal.
	rate /= 100;

	// calculate the final amount.
	for(int i = 1; i <= years; i++)
		initAmount += initAmount * rate;

	// print the amount.
	cout << "After " << years << " years, you'll have $" << initAmount << "\n\n";
	
	// indicates a successful execution.
	return 0;
}