/*
 * Subject: A class that imitates the data type int.
 * 
 * Date: January 15, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 9, 2024
 * 
 * */


#include <iostream> // for the declaration of objects cout, cin.
using namespace std;// for their definition.
///////////////////////////////////////////////
class Int           // class definition.
{
private:            // data hiding, private.	
	int var;
	
public:             // member functions to handle that data.
	Int() : var(0) {}
	Int(int x) : var(x) {}
	
	void display() const { cout << var << "\n"; }
	void add(Int Int1, Int Int2) { var = Int1.var + Int2.var; }
};
///////////////////////////////////////////////

int main()
{
	// instantiate 3 objects.
	Int Int1(100), Int2(200), Int3;

	// add them.
	Int3.add(Int1, Int2);
	
	// display all the values.
	Int1.display();
	Int2.display();
	Int3.display();

	return 0;
}