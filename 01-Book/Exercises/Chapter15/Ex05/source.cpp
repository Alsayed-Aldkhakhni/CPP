/*
 * Subject: Merge an array and a set in a vector.
 *
 * Date: July 30, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 30, 2024
 *
 * */

#include <iostream>  // for the declaration of cin, cout objects.
#include <algorithm> // for the merge algorithm.
#include <functional>// for sorting technique used in set definition, less<int>.
#include <vector>    // for the template class vector.
#include <set>	     // for the template class set.
using namespace std; // for the definition of cin, cout.


int main()
{
	// fill the array with evens.
	int evens[10];
	for(int i = 0; i < 10; i++)
		evens[i] = i*2;

	// fill the set with odds.
	set<int, less<int> > odds;
	for(int i = 0; i < 10; i++)
		odds.insert(i*2+1);
	
	// merge both containers in the vector.
	vector<int> both;
	merge(odds.begin(), odds.end(), evens, evens+10, back_inserter(both));

	// display the evens.
	cout << "Array:    ";
	for(int i = 0; i < 10; i++)
		cout << evens[i] << "   ";

	cout << "\n";

	// display the odds.
	cout << "Set:      ";
	set<int, less<int> >::iterator itr = odds.begin();
	while(itr != odds.end()) cout << *itr++ << "   ";

	cout << "\n\n";

	// display both odds and evens.
	cout << "Vector:   ";
	for(int i = 0; i < both.size(); i++)
		cout << both[i] << "   ";

	cout << "\n\n";
	
	// inidcates a successful execution, popping off the stack.
	return 0;
}


