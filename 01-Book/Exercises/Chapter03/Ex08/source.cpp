/*
 * Subject: Add two old British monetary amounts.
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
				// summing them.
				p1  += p2;
				sh1 += sh2;
				pc1 += pc2;
				
				// 7.19.11
				// 7.19.11
				// 14.28.22
				// 15.9.10
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
				
				// print the sum of those amounts.
				cout << "The total is: \u00A3" << p1 << '.' << sh1 << '.' << pc1 << ".\n\n";
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
		
		// loop again?
		cout << "Do one more(y, n): ";
		cin >> ans;
		
	}while(ans == 'y');
	
	// indicates a successful execution.
	return 0;
}