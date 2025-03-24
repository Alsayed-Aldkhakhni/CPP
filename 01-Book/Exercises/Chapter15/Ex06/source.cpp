/*
 * Subject: Swap elements of a vector.
 *
 * Date: July 29, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 29, 2024
 *
 * */

#include <iostream>  // for the declaration of cin, cout objects.
#include <algorithm> // for the algorithm swap.
#include <vector>    // for the template class vector.
using namespace std; // for the definition of cin, cout.

// function's prototype.
void display(vector<int>& iVect);

int main()
{
	vector<int>iVect;

	// fill the container.
	for(int i = 0; i <= 20; i++)
		iVect.push_back(i);

	// initialize the iterators.
	vector<int>::iterator itr1 = iVect.begin();
	vector<int>::reverse_iterator itr2 = iVect.rbegin();
	
	// display before swapping.
	display(iVect);

	// swapping.
	for(int i = 0; i < iVect.size()/2; i++)
	{
	       	swap(*itr1, *itr2);
		itr1++;
		itr2++;
	}

	// after swapping.
	display(iVect);

	// inidicates a successful popping off the stack.
	return 0;
}

// function's definition.
void display(vector<int>& iVect)
{
	vector<int>::iterator itr1 = iVect.begin();
	for(; itr1 != iVect.end(); itr1++)
		cout << *itr1 << "  ";
	
	cout << "\n\n";
}





