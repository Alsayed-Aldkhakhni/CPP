/*
 * Subject: A simple calculator perform 4 basic operations.
 *
 * Date: December 16, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

                             // preprocessor directive instructs the preprocessor to fetch
                             //     the whole content of that file to this source file.
#include <iostream>          // 'cout', 'cin' declaratoin.
using namespace std;         // 'cout', 'cin' defintion.
int main()
{
                            // initialize variables to hold the data.
    float OP1 = 0, OP2 = 0;
    char operation = '0', answer;

    do
    {
                             // prompt message tells the user what to do.
        std::cout << "Enter an expression in form [2+55] 'no spaces': ";
        std::cin >> OP1 >> operation >> OP2; // get them.
        cout << '\n';

        switch (operation)  // take actions depending on the input, namely the operation variable.
        {
            case '+':
                cout << OP1 << operation << OP2 << " = " << OP1 + OP2;
                break;

            case '-':
                cout << OP1 << operation << OP2 << " = " << OP1 - OP2;
                break;

            case '*':
                cout << OP1 << operation << OP2 << " = " << OP1 * OP2;
                break;

            case '/':
                cout << OP1 << operation << OP2 << " = " << (OP2 == 0 ? 0 : OP1 / OP2);
                break;
            
            default:
                std::cout << "Invalid operation.\f";
        }

                            // ask the user if he wants to do another operation.
        cout << "\f\fDo another (y,n)? ";

        cin.ignore();       // ignore spaces.
        cin >> answer;      // get the answer of the user.

    } while (answer == 'y');

    return 0;               // flags the 'OS' that the program is done.
}