/*
 * Subject: A program allows the user to convert temperatures to and from Fahrenheit.
 *
 * Date: December 14, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

                            // preprocessor directive instructs the preprocessor to fetch
                            // the whole content of that file to this source file.
#include <iostream>         // 'cout', 'cin' declaratoin.

int main()
{
    char option = '0';      // declare the variable that hold the user's answer.

    std::cout << "Press\f"  // prompt message tells the user what to do.
                 "1 to convert from Celsius to Fahrenheit, \f"
                 "2 to convert from Fahrenheit to Celsius: ";
                            // get the value.
    std::cin >> option;
    std::cout << '\f';

    switch (option)         // take actions depending on the 'option'.
    {
    case '1':               // case converting to Fahrenheit.
        float C;

        std::cout << "Enter temperature in Celsius: ";
        std::cin >> C;
        std::cout << "Temperature in Fahrenheit: " << 9 * C / 5 + 32;

        break;              // stop immediately.

    case '2':               // case converting to Celsius.
        float F;

        std::cout << "Enter temperature Fahrenheit: ";
        std::cin >> F;
        std::cout << "Temperature in Celsius: " << 5 * (F - 32) / 9;

        break;

    default:                // errors section.
        std::cout << "Invalid choice.";
    }

    std::cout << "\n--------------------------------------";
    return 0;               // indicates the operating system that the program executed successfully.
}