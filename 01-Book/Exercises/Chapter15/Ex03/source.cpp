/*
 * Subject: Swap elements of a list.
 *
 * Date: July 29, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 29, 2024
 *
 * */

#include <algorithm>// for the algorithm swap.
#include <iostream> // for the declaration of cin, cout objects.
#include <list>     // for the template class list.
using namespace std;// for the definition of cin, cout objects.

// function's prototype.
void display(list<int>& iList);

int main()
{
	list<int>iList;
	
	// fill the list.
	for(int i = 0; i <= 20; i++)
		iList.push_back(i);

	// prepare the iterators will be used to traverse the list.
	list<int>::iterator itr1 = iList.begin();
	list<int>::iterator itr2 = iList.end();
	
       	// one step back, since the iList.end()
	// is an iterator to the item past-last item of the container.
	itr2--;

	// display before swapping.
	display(iList);

	// swapping.
	for(int i = 0; i < iList.size()/2; i++)
	{
	       	swap(*itr1, *itr2);
		itr1++;	itr2--;
	}

	// after swapping.
	display(iList);

	// a successful execution, inidcates the compiler that
	// the main function is popped off the stack.
	return 0;
}

// the fucntion's definition.
void display(list<int>& iList)
{

	list<int>::iterator itr1 = iList.begin();
	for(; itr1 != iList.end(); itr1++)
		cout << *itr1 << "  ";
	
	cout << "\n\n";
}
