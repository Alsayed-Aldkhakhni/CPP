//============================================================================
// Name        : List.cpp
// Author      : Alsayed-Aldkhakhni
// Version     :
// Copyright   : Nothing to be mentioned.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
#include <deque>
#include <iterator>
using namespace std;


int main()
{
	list<int> iList(5);

//  iterate on the list in reversed order.
//	list<int>::reverse_iterator lstIter;
//	for(lstIter = iList.rbegin(); lstIter != iList.rend(); lstIter++)
//		cout<< *lstIter << "  ";
//	cout << "\n\n";

//  iterate on the list in a normal order.
//	list<int>::iterator lstIter;
//	for(lstIter = iList.begin(); lstIter != iList.end(); lstIter++)
//		cout<< *lstIter << "  ";

//	list<int>::iterator lstIter;
//
//	int x = 10;
//
//	for(lstIter = iList.begin(); lstIter != iList.end(); lstIter++)
//	{
//		*lstIter = x;
//		x *= 2;
//		cout<< *lstIter << "  ";
//	}
//
//
//	for(lstIter = iList.begin(); lstIter != iList.end(); lstIter++)
//	{
//		*lstIter = x;
//		x *= 2;
//		cout<< *lstIter << "  ";
//	}


	istream_iterator<int> cin_itr(cin);
	istream_iterator<int> eof;

	copy(cin_itr, eof, iList.begin());

	ostream_iterator<int> ositr(cout, ", ");
	copy(iList.begin(), iList.end(), ositr);



	return 0;
}
