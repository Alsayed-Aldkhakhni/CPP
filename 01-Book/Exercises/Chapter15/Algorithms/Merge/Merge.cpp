//============================================================================
// Name        : Copy.cpp
// Date        : July 15, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Test 'merge()' algorithm.
//============================================================================

#include <iostream> // for objects cin, cout declaration.
#include <algorithm>// for algorithm 'merge()'.
using namespace std;// the definition of cin, cout.

// template function's prototype.
template <class T>
void display(T*, int);

int main()
{
	// integers.
	int seq1[] = {1, 3, 5, 7};
	int seq2[] = {2, 4, 6, 8};

	int isize1 = sizeof(seq1) / sizeof(seq1[0]);
	int isize2 = sizeof(seq2) / sizeof(seq2[0]);
	int iDest[isize1+isize2];

	cout << "Src1: "; display(seq1, isize1);
	cout << "Src2: "; display(seq2, isize2);

	merge(seq1, seq1 + isize1, seq2, seq2+isize2, iDest);
	cout << "dest: "; display(iDest, isize2+isize1);

	cout << "\n\n********************************************\n\n";

	// characters.
	char word1[] = {'A', 'B', 'C', 'D'};
	char word2[] = {'E', 'F', 'G', 'H'};

	int csize1 = sizeof(word1) / sizeof(word1[0]);
	int csize2 = sizeof(word2) / sizeof(word2[0]);

	char cDest[csize1+csize2];

	cout << "word1: "; display(word1, csize1);
	cout << "word2: "; display(word2, csize2);

	merge(word1, word1 + csize1, word2, word2+csize2, cDest);
	cout << "dest: "; display(cDest, csize2+csize1);

	// indicates a successful execution.
	return 0;
}

// function's body.
template <class T>
void display(T* arr, int size)
{
	cout << "\n================================================================\n";
	for(int i = 0; i < size; i++)
		cout << "   " << arr[i] << "   |";
	cout << "\n================================================================\n";
}
