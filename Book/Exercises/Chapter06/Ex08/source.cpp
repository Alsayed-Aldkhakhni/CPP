/*
 * Subject: Make each object has it own serial number.
 *
 * Date: January 14, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 9, 2024
 * */

#include <iostream> // for the declaration of cin, cout objects.
using namespace std;// for the definition of cin, cout.

//############################################################//
class SerialNumber
{
private:
	static int serial;// start point.
	int myNumber;     // object's number.
	
public:
	SerialNumber() : myNumber(serial++)
	{
		cout << "I am object #" << myNumber << "\n";
	}
};

int SerialNumber::serial = 1000;

//############################################################//

int main()
{
	// instantiate 7 object to diplay their own numbers.
	SerialNumber s1, s2, s3, s4, s5, s6, s7;
	
	// indicates a successful execution.
	return 0;
}