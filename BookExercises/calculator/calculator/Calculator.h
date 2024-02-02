#pragma once			// preprocessor wrapper, forbids header file redefinition.

class Calculator		// class definition, tag.
{
						// there is no data members since it is utility class.

public:					// static member functions.
						// ADD function to add two floats.
	static float ADD(float num_one, float num_two);

						// DIV member that divides two floats.
	static float DIV(float num_one, float num_two);

						// SUB function that subtracts two floats.
	static float SUB(float num_one, float num_two);

						// MUL function that multiplyes two floats.
	static float MUL(float num_one, float num_two);

						// MOD that find the reminder of two integers.
	static int MOD(int num_one, int num_two);
};