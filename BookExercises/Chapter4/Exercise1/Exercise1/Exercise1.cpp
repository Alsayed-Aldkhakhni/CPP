/*
 * Subject: A phone structure to handle the phone data.
 
 * Date: December 11, 2023
 
 * Author: Alsayed Aldkhakhni
 */


// Preprocessor directive instruct the compiler's preprocessor 
// to fetch the whole content of that header file inside this source file.
#include <iostream>                     // cin, cout declaration.
using namespace std;                    // contains the defination of 'cin', 'cout' objects.

struct Phone                            // Structure defination.
{                                       
    int areaCode;                       // members.
    int exchangeCode;
    int phoneNumber;
};

int main()
{

    Phone mine{}, his{};                // These, {}, just to initialize the members with nothing.
    mine.areaCode = 212; mine.exchangeCode = 767; mine.phoneNumber = 8900;

                                        // prompt message tells the user what to do.
    cout << "Enter area code, exchange, number: ";
                                        // get his phone number.
    cin >> his.areaCode >> his.exchangeCode >> his.phoneNumber;

    cout << "\fMine: "                  // print two numbers, mine and his
         << '(' << mine.areaCode << ") "
         << mine.exchangeCode << '-'
         << mine.phoneNumber;


    cout << "\fYours: "
         << '(' << his.areaCode << ") "
         << his.exchangeCode << '-'
         << his.phoneNumber;

    cout << '\f';                       // for output's clarity.
    return 0;                           //  flag the 'OS' that the program executed successfully.
}