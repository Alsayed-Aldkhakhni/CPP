/*
 * Subject: Simulate a ship in the sea.
 *
 * Date: January 14, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 11, 2024
 * */

#include <iostream> // for the declaration of cin, cout objects.
#include "Angle.h"  // for user-defined type Angle.
using namespace std;// for the definition of cin, cout.
//#########################################################################//
class Ship // class definition.
{
private:
	Angle longitude;
	Angle latitute;
	static int serialNumber;
	int myNumber;
	
public:
	// ctor.
	Ship() :myNumber(serialNumber++) {}
	
	// read the data from the user.
	void setData()
	{
		cout << "Data of ship #" << myNumber << "\n";
		cout << "   Latitude: \n";    latitute.setData();
		cout << "\n   Longitude: \n"; longitude.setData();
	}
	
	// display it.
	void getData() const
	{
		cout << "Ship #" << myNumber << "\n";
		latitute.getData();
		longitude.getData();
	}
};

// initialize the static member.
int Ship::serialNumber = 1000;
//#########################################################################//

int main()
{
	// instantiate 2 objects.
	Ship ship1, ship2;
	
	// read the user's data.
	ship1.setData();
	cout << "\n\n";
	ship2.setData();
	
	// display the data.
	ship1.getData();
	cout << "\n";
	ship2.getData();
	
	// indicates a successful execution.
	return 0;
}

