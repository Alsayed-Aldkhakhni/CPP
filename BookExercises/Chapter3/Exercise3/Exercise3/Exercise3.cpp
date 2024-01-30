/*
 * Subject: get a 6 digits form the user and return them as a number.
 * 
 * Date: December 16, 2023
 * 
 * Author: Alsayed Aldkhakhni
 */

                                    // preprocessor directive instructs the preprocessor to fetch
                                    //      the whole content of that file to this source file.
#include <iostream>                 // 'cout', 'cin' declaratoin.
#include <conio.h>                  // for _getche

int main()
{
    long num = 0;                   // to hold the numerical value.
    int i = 100000;                 // for the number position tens, hundreds, thousands.

    std::cout << "Enter a number consists of 6-digits [only numbers]: ";

                                    // only 6-digits from 0 up to 5 (6 digits 6 iterations).
    for (int ite = 0; ite <= 5; ite++)
    {
        char ch = _getche();        // get character each iteration.

        if (ch != '\r')
        {
            num += i * (ch - '0');  // reference point the zero to get the actual numeric value form the ASCII.
            i /= 10;                // to get the next position either 10s, 100s, or 1000s.
        }
    }

    std::cout << "\n\n";
                                    // to make sure that the value is numerically not a string.
    std::cout << num << " + " << 123 << " = " << num + 123;
    std::cout << "\n\n";


    return 0;                       // flags the operating system that the program executed successfully.
}