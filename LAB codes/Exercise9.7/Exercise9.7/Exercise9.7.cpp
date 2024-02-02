/*
 * Subject: C++ Time Class Managing Time by incrementing it Second by second.
 *
 * Date: December 17, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

// preprocessor directive instructs the preprocessor, inside the compiler, to fetch-
// the whole content of that header file, iostream, into the current source file.

#include <iostream>         // cout declaration.
#include"Time.h"            // class interface.

int main()
{
    Time clock(11, 59, 58); // instantiation.

    print(clock);           // print the current time.

    for (int i = 1; i <= 3; i++)
    {
        std::cout << '\f';
        system("pause");    // to freeze the increment process.

        clock.tick();       // increase the clock with a second.
        std::cout << "\n\n";

                            // A light touch :)
        std::cout << (i % 2 == 1 ? "Tick\f" : "Tock\f");

        print(clock);       // print the time again.

    }

    std::cout << "\f--------------------------------\f";
    return 0;               // indicates the operating  system that the program executed successfully.
}