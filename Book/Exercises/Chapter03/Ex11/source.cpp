/*
 * Subject: Add, subtract and scale old British monetary amounts.
 * 
 * Date: December 5, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cout, cin declaration.
using namespace std;// for cout, cin definition.


int main()
{
	int p1, p2;  // pounds.
	int sh1, sh2;// shilligs.
	int pc1, pc2;// pence.
	char dummy;  // to read the dot.
	char ans;    // user's answer to continue.
	
	do
	{	
		char operation;
		
		// the avaliable operations.
		cout << "Enter the character: \n"
			 << "+. add two amounts\n"
			 << "-. subtract two amounts\n"
			 << "*. scale an amount: ";
		
		cin >> operation;
		
		// operate on those operations.
		switch(operation)
		{
		// case adding or subtracting.
		case '+':
		case '-':
			// read the 1st amount.
			cout << "Enter the 1st British amount: \u00A3[5.19.11]: ";
			cin >> p1 >> dummy >> sh1 >> dummy >> pc1;
			
			// check the values.
			if(p1 >= 0 && (sh1 >= 0 && sh1 <= 19) && (pc1 >= 0 && pc1 <= 11))
			{
				// read the 2nd if the 1st was valid.
				cout << "Enter the 2nd British amount: \u00A3[5.19.11]: ";
				cin >> p2 >> dummy >> sh2 >> dummy >> pc2;
				
				// validate the 2nd.
				if(p2 >= 0 && (sh2 >= 0 && sh2 <= 19) && (pc2 >= 0 && pc2 <= 11))
				{
					if(operation == '+')
					{
						// summing them.
						p1  += p2;
						sh1 += sh2;
						pc1 += pc2;

						if(sh1 >= 20)
						{
							p1 += sh1 / 20;
							sh1 = sh1 % 20;
						}
						
						if(pc1 >= 12)
						{
							sh1 += pc1 / 12;
							pc1  = pc1 % 12;
						}
					}
					else 
					{
						p1  -= p2;
						sh1 -= sh2;
						pc1 -= pc2;
					}
					
					// print the result.
					cout << "The result: \u00A3" << p1 << '.' << sh1 << '.' << pc1 << ".\n\n";
				}
				else
				{
					cout << "Invalid value entered.\n";
					exit(1);
				}
			}
			else
			{
				cout << "Invalid value entered.\n";
				exit(1);
			}
			
			break;
			
		case '*':
			// read the 1st amount.
			cout << "Enter the British amount: \u00A3[5.19.11]: ";
			cin >> p1 >> dummy >> sh1 >> dummy >> pc1;
			
			// check the values.
			if(p1 >= 0 && (sh1 >= 0 && sh1 <= 19) && (pc1 >= 0 && pc1 <= 11))
			{
				float scale;
				cout << "Enter a value to multiply: ";
				cin >> scale;
				
				if(scale > 1 || scale < 0)
				{
					cout << "Invalid value entered.\n";
					exit(1);
				}
				
				// just scale with (0, 1)
				p1  *= scale;
				sh1 *= scale;
				pc1 *= scale;
				
				cout << "The result: \u00A3" << p1 << '.' << sh1 << '.' << pc1 << ".\n\n";
			}
			else
			{
				cout << "Invalid value entered.\n";
				exit(1);
			}
			
			break;
			
		default:
			cout << "Invalid operation.\n";
		}

		// loop again?
		cout << "Do one more(y, n): ";
		cin >> ans;
		
	}while(ans == 'y');
	
	// indicates a successful execution.
	return 0;
}

