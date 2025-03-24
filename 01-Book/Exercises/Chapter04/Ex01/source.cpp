/*
 * Subject: Simulate phone number structure.
 * 
 * Date: December 12, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 7, 2024
 * 
 * */

#include <iostream> // for cin, cout declaration.
using namespace std;// for their definition.


struct Phone // structure tag.
{
	// sample: (212) 767-8900
	short areaCode; // 212
	short exchange; // 767
	short number;   // 8900
};


int main()
{
	// two phone numbers.
	Phone phone1{123, 567, 7500};
	Phone phone2;
	
	// read the user's phone.
	cout << "Enter your phone number as\n"
		 << "areacode exchange number: ";
	
	cin >> phone2.areaCode >> phone2.exchange >> phone2.number;
	
	// validate the input.
	if(phone2.areaCode <= 0 || phone2.exchange <= 0 || phone2.number <= 0)
	{
		cout << "Invalid value(s) entered.\n";
		exit(1);
	}
	
	// display the phones.
	cout << "Your phone: (" << phone2.areaCode << ") " << phone2.exchange << "-" << phone2.number << "\n";
	cout << "My phone:   (" << phone1.areaCode << ") " << phone1.exchange << "-" << phone1.number << "\n";

	
	// indicates a successful execution.
	return 0;
}

