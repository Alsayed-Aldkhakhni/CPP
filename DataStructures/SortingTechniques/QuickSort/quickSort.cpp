/*
 * Subject: Qucik sort technique implementation.
 *
 * Complexity: Time O(n log n)-->[best, average]. O(n^2)-->worst. | Space O(1) --> in-place.
 *
 * Date: July 20, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 20, 2024
 *
 * */

#include <iostream> // for the declaration of cin, cout objects.
using namespace std;// for their definition.

// functions' prototype.
int partitioning(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void display(int arr[], int size);

int main()
{
      int arr[] = {12, 5, 16, 10, 13, 20};
      int size = sizeof(arr) / sizeof(arr[0]);
      
      display(arr, size);
      quickSort(arr, 0, size-1);
      display(arr, size);

      // indicates a successful execution.
      return 0;
}

// functions' bodies.
void display(int arr[], int size)
{
	for(int i = 0; i < size; i++)
		cout << arr[i] << "  ";

	cout << "\n\n";
}

void quickSort(int arr[], int low, int high)
{
	if(low < high)
	{
		int piv = partitioning(arr, low, high);
		quickSort(arr, low, piv);
		quickSort(arr, piv+1, high);
	}
}

// i             j
// 12 5 16 10 13 20 --> 1

// i          j
// 12 5 16 10 13 20 --> 2

// i	   j
// 12 5 16 10 13 20 --> 3

// i       j
// 10 5 16 12 13 20 --> 4

//      i  j
// 10 5 16 12 13 20 --> 5

//      ij
// 10 5 12 16 13 20
int partitioning(int arr[], int low, int high)
{
	int i = low;
	int j = high;

	int pivot = arr[i]; // [0]=12
	int temp;
	
	while(i != j)
	{
		if(arr[i] < arr[j])
		{
			if(arr[i] == pivot)
				j--;
			else 
				i++;
		}
		else
		{
			temp = arr[i];  //12
			arr[i] = arr[j];//10
			arr[j] = temp;  //12
		}
	}

	return i;
}
