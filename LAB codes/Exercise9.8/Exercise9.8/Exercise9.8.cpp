/*
 * Subject: A program that assign a date based on whether in a leap year or not.
 *
 * Date: December 17, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

// preprocessor directive instructs the preprocessor, inside the compiler,
//to fetch the whole content of that header file, iostream, to the current source file.

#include <iostream>         // cin, cout declaration.
#include "Date.h"           // class interface.

int main()
{

    //Date D1(2015,12,29);  // a normal year.
    Date D1(2000, 2, 27);   // a leap year.

    printDate(D1);          // friend function did you notice :)
    std::cout << "\n";
                            // print some samples.
    for (int i = 1; i <= 5; i++) 
    {
       
        std::cout << "\n";
        system("pause");    // stop the system to see the changes.

        D1.nextDay();       // increment the day.

        std::cout << "\n\n";
        printDate(D1);      // show the date.
    }

    std::cout << "\n-----------------------------------------";

    return 0;               // program executed successfully.
}