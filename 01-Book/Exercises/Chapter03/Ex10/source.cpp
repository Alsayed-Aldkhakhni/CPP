/*
 * Subject: Calculate the needed years to end up with an amount of money.
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
	// declaring the variables.
	double initAmount;
	float rate;
	double finalAmount;
	
	// read the base amount.
	cout << "Enter the inital amount: ";
	cin >> initAmount;

	// validate it.
	if(initAmount < 0)
	{
		cout << "Invalid initial amount.\n";
		exit(1);
	}
	
	// read the rate.
	cout << "Enter interest rate(percent per year): ";
	cin >> rate;
	
	// validate it.
	if(rate < 0)
	{
		cout << "Invalid rate.\n";
		exit(1);
	}
	
	// read the final amount.
	cout << "Enter final amount: ";
	cin >> finalAmount;
	
	if(finalAmount < 0)
	{
		cout << "Invalid final amount.\n";
		exit(1);
	}
	
	rate /= 100;
	int years = 0;
	
	// calculate the years.
	while(finalAmount >= initAmount)
	{
		++years;
		finalAmount = finalAmount - finalAmount*rate; 
	}
	
	// print the years.
	cout << "You need " << years << " years to get that amount.\n";
	
	// indicates a successful execution.
	return 0;
}