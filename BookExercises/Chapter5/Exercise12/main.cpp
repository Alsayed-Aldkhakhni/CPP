/*
 * Subject: A program that performs 4-arithmatic operations on fractions.
 *
 * Date: November 25, 2023
 *
 * Author: Alsayed Aldkhakhni
 */


#include <iostream>                // for cin, cout declaration.
using namespace std;               // for the definition of cin, cout.

struct fraction                    // structure's tag.
{
    int numerator;                 // structure's members.
    int denominator;
};

///////////////////////////////////////////////////////////////////////////////////////////////////

                                   // functions' declarators.


void getFraction(fraction &);      // function that takes the fraction from the user.

fraction ADD(fraction, fraction);  // the ADD function which adds two fractions and return the sum.
fraction SUB(fraction, fraction);  // the SUB function that subtracts two fractions and return the difference.
fraction MUL(fraction, fraction);  // the product.
fraction DIV(fraction, fraction);  // the division.

void print(fraction);              // print the fraction.

///////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    fraction frac1 , frac2;         // get two fractions 'frac1', 'frac2'.

	getFraction(frac1);             // get the first fraction.
    getFraction(frac2);             // get the second from the user.

    /*
        * after getting the fractions from the user,using getFraction(), call the-
            functions that perform the operations on them, fractions, and they, the called functions,
            return the final result to the function 'print' to display the fraction.

        * use nested function to avoid the wasting of the memory.
    */

    std::cout << "\n\n";

    print(ADD(frac1, frac2));       // print the sum.
    print(SUB(frac1, frac2));       // difference.
    print(MUL(frac1, frac2));       // product.
    print(DIV(frac1, frac2));       // division.

    return 0;                       // flags the operating system that the program executed successfully.
}


void getFraction(fraction &frac)    // get the fraction from the user.
{
	char sign;                      // to hold the division sign.
	
                                    // ask the user to input a fraction.
	std::cout << "Enter a fraction in form (a/ b): ";

                                    // get the fraction from the user.
	std::cin >> frac.numerator >> sign >>  frac.denominator;
	
    if(frac.denominator == 0)       // check the validation of the denominator.
    {
        std::cout << "Can't divid by 0.";
        exit(1);                    // stop immediately
    }
}


void print(fraction frac)           // print the fraction in the mathmatic form.
{
    cout << frac.numerator << '/' << frac.denominator << " = "
         << float(frac.numerator) / float(frac.denominator) << "\n\n";
}

                                    // adding two fractions.
fraction ADD(fraction frac1, fraction frac2)
{
    fraction sum;                   // the sum to hold the summation of two fraction.

                                    // set the numerator of the sum variable.
    sum.numerator = frac1.numerator * frac2.denominator +
                    frac1.denominator * frac2.numerator;

                                    // set the denominator of the sum.
    sum.denominator = frac1.denominator * frac2.denominator;

    cout << "Sum: ";                // the result name.

    return sum;                     // return the result.
}

                                    // subtracting two fractions.
fraction SUB(fraction frac1, fraction frac2)
{
    fraction diff;                  // the diff to hold the difference of the fractions.

                                    // the numerator.
    diff.numerator = frac1.numerator * frac2.denominator -
                     frac1.denominator * frac2.numerator;

                                    // the denominator.
    diff.denominator = frac1.denominator * frac2.denominator;

    cout << "Difference: ";         // the label of the operation.

    return diff;                    // the result.
}

                                    // multiplication.
fraction MUL(fraction frac1, fraction frac2)
{
    fraction mult;

    mult.numerator = frac1.numerator * frac2.numerator;
    mult.denominator  = frac1.denominator * frac2.denominator;

    cout << "Product: ";
    return mult;
}

                                    // division.
fraction DIV(fraction frac1, fraction frac2)
{
    fraction quation;

    quation.numerator = frac1.numerator * frac2.denominator;
    quation.denominator = frac1.denominator * frac2.numerator;

    cout << "Division: ";

    return quation;
}