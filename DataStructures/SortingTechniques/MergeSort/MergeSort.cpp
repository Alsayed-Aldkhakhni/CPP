//============================================================================
// Name        : MergeSort.cpp
// Date        : June 22, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Complexity  : Time: O(n log n), space: O(n).
// Description : Merge sort technique implementation.
//============================================================================

#include <iostream> // for the declaration of cin, cout objects.
using namespace std;// for their definition.

// functions' prototype.
void merge(int arr[], int l, int m, int r);
void display(int arr[], int size);
void mergeSort(int arr[], int l, int r);

int main()
{
	// array and its size.
	int arr[] = {30, -10, 12,100, 7, 13};
	int sz = sizeof(arr)/sizeof(arr[0]);

	// sort.
	display(arr, sz);
	mergeSort(arr, 0, sz-1);
	display(arr, sz);

	return 0;
}

void display(int arr[], int len)
{
	for(int i = 0; i < len; i++)
		cout << arr[i] << ", ";

	cout << "\n\n";
}

// merge part.
// l, r and m are the indexes of
// left, right and middle of the array.
void merge(int arr[], int l, int m, int r)
{
	// m = (l+r+1)/2;
	int i, j, k;

	// sizes.
	// left sub-array has one more item
	//  if the array is not balanced.
	int s1 = m - l + 1; // left sub-array.
	int s2 = r - m;		// right sub-array.

	// allocate the 2 sub-arrays.
	int *L = new int[s1];
	int *R = new int[s2];

	// fill the 1st array.
	for(i = 0; i < s1; i++)
		L[i] = arr[l+i];

	// fill the 2nd array.
	for(j = 0; j < s2; j++)
		R[j] = arr[m+j+1];

	i = j = 0;

	// start from 1st position of the array.
	k = l;

	// sort the 2 sub-arrays in a big one.
	while(i < s1 && j < s2)
	{
		// if the 1st array has items.
		if(L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}

	// if there are items in one of both arrays.
	while(i < s1)
		arr[k++] = L[i++];

	while(j < s2)
		arr[k++] = R[j++];

	// delete the arrays when we finished.
	delete[] L;
	delete[] R;
}

// sort part.
void mergeSort(int arr[], int l, int r)
{
	// cout << "mergeSort(" << l << ", " << r << ")\n";

	if(l < r)
	{
		// divide the big problem into smaller ones.
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);  // call it for the left side.
		mergeSort(arr, m+1, r);// call it for the right side.

		merge(arr, l, m, r);   // fill the array with the elements.
	}
}


