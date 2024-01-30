/*
 * Subject: A pyramid of Xs.
 *
 * Date: December 16, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

                                // preprocessor directive instructs the preprocessor to fetch
                                //  the whole content of that file to this source file.
#include <iostream>             // cout declaratoin.

int main()
{
    short xNum;                 // declare the variable to hold the Xs' number.
                                // ask the user to identify the pyramid's size.
    std::cout << "Enter the number of rows: ";
    std::cin >> xNum;           // the row of the pyramid.

    for (int i = 1; i <= xNum; i++)
    {                           // spaces loop.
        for (int space = 1; space <= xNum - i; space++)
        {
            std::cout << " ";
        }
                                // for each line print X = 2 * line number - 1 to print the true pyramid.
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            std::cout << "X";
        }

        std::cout << "\n";      // new line at the end of each line. 
    }

    return 0;                   // flags the 'OS' that the program executed successfully.
}