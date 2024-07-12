//============================================================================
// Name        : source.cpp
// Date        : July 12, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Class Matrix that stores data in 2D-array.
//============================================================================
#include <iostream> // for cin, cout objects declaration.
#include <iomanip>  // for setw, setfill
using namespace std;// for their definition.

//############################################################################//
class Matrix
{
private:
	int rows;
	int cols;
	enum {LIM = 10};
	int items[LIM][LIM];
	
public:
	Matrix(int r, int c)
	{
		if((r <= LIM && c <= LIM) && (r > 0 && c > 0))
		{
			rows = r; cols = c;
		}
		else
		{
			cout << "Invalid dimensions.\n";
			exit(1);
		}
	}
	
	// store an item in the index items[r-1][c-1].
	void store(int r, int c, int val)
	{
		if( (r <= rows && c <= cols) && (r > 0 && c > 0) )
		{
			items[r-1][c-1] = val;
		}
		else
		{
			cout << "Invalid dimensions.\n";
		}
	}

	// get back an item.
	int retrieve(int r, int c)
	{
		if( !(r <= rows && c <= cols) && !(r > 0 && c > 0) )
		{
			cout << "Invalid dimensions.\n";
			exit(1);
		}
		
		return items[r-1][c-1];
	}
	
	// display the matrix.
	void display() const
	{
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				cout << left << setw(5) << items[i][j];
			}
			
			cout << "\n";
		}
	}
};

//############################################################################//

int main()
{
	// instantiate an object of the Matrix class.
	Matrix matrix1(5, 5);
	
	// fill the matrix.
	for(int i = 1; i <= 5; i++)
	{
		for(int j = 1; j <= 5; j++)
			matrix1.store(i, j, i*j);
	}
	
	// matrix1.store(6,6, 10); // invalid index.
	
	// display the content.
	matrix1.display();
	
	return 0;
}


