#include "Calculator.h"             // The header file of the class that makes us use its members.

float Calculator::ADD(float num_one, float num_two)
{                                   // return the sum of two numbers.
    return  float(num_one + num_two);
}

float Calculator::DIV(float num_one, float num_two)
{
    if (num_two != 0)               // if the denominator is not zero
    {                               // retrun the division.
        return  float(num_one / num_two);

    }

    return 0;                       // if the denominator is zero return 0.
}

float Calculator::SUB(float num_one, float num_two)
{
    return float(num_one - num_two);// return the subtraction of them.
}

float Calculator::MUL(float num_one, float num_two)
{
    return float(num_one * num_two);// product.
}

int Calculator::MOD(int num_one, int num_two)
{
    if (num_two != 0)               // we can't get the modulus of number over zero.
    {
        return num_one % num_two;   // if num_two is not zero.
    }

    return 0;                       // the denominator is zero return 0 to the caller.
}