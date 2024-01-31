/*
 * Subject: A structured program to convert an amount of money from the new British system and display it in the old one.

 * Date: December 13, 2023

 * Author: Alsayed Aldkhakhni
 */

 // The preprocessor directive '#include <iostream>' instructs the compiler's preprocessor to 
 // fetch the whole content of the iostream header file into the current source file.
#include <iostream>     // contains the declaration of 'cin', 'cout'.
using namespace std;    // contains the definition of cin, cout.
struct sterling         // structure tag.
{
    int pounds;         // members.
    int shillings;
    int pences;
};

int main()
{
    sterling oldSystem{}; // a variable of type sterling

    double decimalAmount; // to hold the decimal amount entered by the user.

                          // ask the user to enter an amount of money.
    cout << "Enter the amount of money: ";
    cin >> decimalAmount; // get the decimal amount form the user.


    if (decimalAmount > 0) // check the validation.
    {
        // the integer part of the total fraction amount is the same in both systems.
        oldSystem.pounds = static_cast<int>(decimalAmount);

        // the fraction part is in pounds convert it to shilling with '*' it by 20, and also get the integer part.
        oldSystem.shillings = static_cast<int>((decimalAmount - oldSystem.pounds) * 20);

        // the reset fraction part of the shillings is also shillings to get the pences multiply it with 12 and get the integer part.
        oldSystem.pences = static_cast<int>((((decimalAmount - oldSystem.pounds) * 20) - oldSystem.shillings) * 12);
    }
    else
    {
        cout << "Something went wrong.\n";
        return 0;
    }

        // display the converted money.    
    cout << "Amount in old British system: "
         << '\x9c' << oldSystem.pounds << '.' << oldSystem.shillings << '.' << oldSystem.pences << '.' << "\f";

        // indicates the operating system that the program executed successfully.
    return 0; 
}