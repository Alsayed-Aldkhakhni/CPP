#include <iostream>
using namespace std;


void display(int arr[], int size);
void makeHeap(int arr[], int size);
//void heapify(int arr[], int size, int prt);

int main()
{
	const int SZ = 4;
	int arr[SZ] = {2, 4, 7, 3};

	display(arr, SZ);
	makeHeap(arr, SZ);
	display(arr, SZ);

	return 0;
}


void display(int arr[], int size)
{
	for(int i = 0; i < size; i++)
		cout << arr[i] << "  ";

	cout << "\n\n";
}

/*
void heapify(int arr[], int size, int prt)
{
	int ch1 = 2*prt+1;
	int ch2 = ch1+1;
	int max = prt;

	if(arr[ch1] > arr[prt] && arr[ch1] > arr[ch2] && ch1 < size)
		max = ch1;
	else if(arr[ch2] > arr[prt] && arr[ch2] > arr[ch1] && ch2 < size)
		max = ch2;

	if(max != prt)
	{
		int temp = arr[prt];
		arr[max] = arr[prt];
		arr[prt] = arr[max];

		heapify(arr, size, max);
	}	
}
*/
/*
void makeHeap(int arr[], int size)
{
	for(int i = size-1; i >= 0; i--)
		heapify(arr, size, i);
}
*/


void makeHeap(int arr[], int size)
{
	int prt;

	for(int i = size-1; i >=0; i--)
	{
		prt = (i-1)/2;

		if(prt >= 0)
		{
			if(arr[i] < arr[prt])
			{
				int temp = arr[i];
				arr[i]   = arr[prt];
				arr[prt] = temp;
			}
		}
	}
}

