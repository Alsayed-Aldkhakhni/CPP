// 'Header file' declaration or prototype of the class.

#pragma once			// preprocessor wrapper, prevents the redefinition of the header file.
class Rectangle			// define class, A specifier.
{
private:				// Data members.
	float length;
	float width;

public:					// Function members.

						// setters, mutators.
	void setLength(float Len);
	void setWidth(float Wid);

						// getters, accessors.
	float getLength() const;
	float getWidth() const;

	float getArea() const;
	float getCircumference() const;

	void display() const;

						// special methods.
	Rectangle();		// default ctor.

						// overloaded ctor.
	Rectangle(float Len, float Wid); 

	~Rectangle();		// destructor.

						// I'm telling 'C++' what it has to do if it instructed to add or subtract two objects of type 'Rectangle'.
	Rectangle operator + (Rectangle) const;
	Rectangle operator - (Rectangle) const;
};