#pragma once					// Preprocessor wrapper, prevents the redefinition of header file.
class Distance					// A specifier, define a class.
{
friend void display(Distance);	// friend function that can access the private members of the passed object.

private:						// Data members.
	int feet;
	float inches;

public:							// Function members.

	void setFeet(int foot);		// setters, mutators.
	void setInches(float inche);

	int getFeet() const;		// getters, accessors.
	float getInches() const;

								// other functions to add distances.
								// this function adds the parameter and the caller object together, without modifying the parameter.
	Distance add(const Distance ) const;
								// this one adds two objects and place the sum in the caller's attributes.
	void add(Distance , Distance); 

								// A static function belongs to the class itself not to any object.
	static Distance addDistance(Distance dist1, Distance dist2);

								// this two methods won't modify the objects.
	Distance operator + (Distance inputDist) const; 
	Distance operator - (Distance inputDist) const;

	void displayDistance() const;// print the distacne.

								// other special methods.

	Distance();					// default constructor.
	Distance(int ft, float in); // overloaded constructor.
	~Distance();				// destructor.
};