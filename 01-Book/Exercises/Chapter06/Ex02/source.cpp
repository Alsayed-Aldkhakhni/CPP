/*
 * Subject: A class keeps track the cars on a route.
 * 
 * Date: January 15, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 9, 2024
 * 
 * */

#include <iostream> // for the declaration of objects cin, cout.
using namespace std;// for their definition.
////////////////////////////////////////////
class TollBooth     // class definition.
{
private:            // data members.
	unsigned int carsNum;
	double moneyCollected;
	
public:             // member functions.
	TollBooth() : carsNum(0), moneyCollected(0.0) {}
	
	void payingCar() { carsNum++; moneyCollected += 0.50; }
	void nopayCar()  { carsNum++;}
	
	void display() const
	{
		cout << "# of cars:   " << carsNum << "\n"
			 << "Total cash: $" << moneyCollected << '\n';
	}
};
////////////////////////////////////////////

int main()
{
	TollBooth tb1;
	char ch;
	
	do
	{
		// prompt the use to choose the car type.
		cout << "Press:\n"
			 << "   p. paying car\n"
			 << "   n. no pay car: ";
		
		cin >> ch;

		// what did he enter?
		if(ch == 'p')
			tb1.payingCar();
		else if(ch == 'n')
			tb1.nopayCar();
		else
		{
			cout << "\n   Invalid option.\n";
			break;
		}
		
		cout << '\n';
		
	}while(true);
	
	cout << "\n\n";
	
	// display data.
	tb1.display();	
	
	// indicates a successful execution.
	return 0;
}



