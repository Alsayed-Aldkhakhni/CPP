/*
 * Subject: Class angle simulates ocean navigation.
 *
 * Date: January 14, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 9, 2024
 * */


#include <iostream> // for the declaration of cin, cout objects.
using namespace std;// for the definition of cin, cout.
//###############################################################################//
class Angle
{
private:
	int degree;
	float minute;
	char direction;
public:
	// constructors.
	Angle() : degree(0), minute(0.0), direction('E') {}
	Angle(int deg, float min, char dir)
	{
		setDirection(dir);
		setMinute(min);
		setDegree(deg);		
	}
	
	/////////////////////////////////// mutators ///////////////////////////////////////////
	void setDirection(char dir)
	{
		// avoid case senstivity.
		dir = toupper(dir);
		
		if(dir == 'N' || dir == 'S' || dir == 'E' || dir == 'W')
			direction = dir;
		else
		{
			cout << "Invalid direction.\n";
			exit(1);
		}
	}
	
	//  Longitude is measured from 0 to 180 degrees, east or west.
	//  Latitude  is measured from 0 to 90  degrees, north or south.
	void setDegree(int deg)
	{
		if(direction == 'E' || direction == 'W') // this is a Longitude.
		{
			if(deg >= 0 && deg < 180)
				degree = deg;
			else
			{
				cout << "Invalid degree for longitude.\n";
				exit(1);
			}
		}
		else                        // this is a Latitude.
		{
			if(deg >= 0 && deg < 90)
				degree = deg;
			else
			{
				cout << "Invalid degree for latitude.\n";
				exit(1);
			}
		}
	}
	
	void setMinute(float min)
	{
		if(min >= 0 && min < 60)
			minute = min;
		else
		{
			cout << "Invalid minute.\n";
			exit(1);
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////

	void setData()
	{
		int deg; float min; char dir;
		cout << "     Enter a location[50 16.5 E]: ";
		cin >> deg >> min >> dir;
		
		setDirection(dir);
		setMinute(min);
		setDegree(deg);
	}
	
	void getData() const
	{
		
		if(direction == 'E' || direction == 'W') // this is a Longitude.
			cout << "     The Longitude: ";
		else
			cout << "     The Latitude:  ";
		
		cout << degree << "\u00B0" << minute << "\'" << direction << "\n";		
	}
};
//###############################################################################//

