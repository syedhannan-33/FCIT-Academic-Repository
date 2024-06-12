#include "iostream"

using namespace std;

class Algebra
{
	// Data members of the class
	int a, b;

public:

	// Default Constructor
	Algebra() : a{ 0 }, b{ 0 }
	{
		cout << "Default Constructor" << endl;
	}

	// Parameterized Constructor
	Algebra(int a, int b)
	{
		cout << "Parameterized Constructor" << endl;

		// If a is greater than 0, assign its value to data-member 'a';
		// otherwise, assign 0 to data-member 'a'.
		this->a = a > 0 ? a : 0;

		// If b is greater than 0, assign its value to data-member 'b';
		// otherwise, assign 0 to data-member 'b'.
		this->b = b > 0 ? b : 0;
	}

	// Copy Constructor
	Algebra(const Algebra& obj) : a(obj.a), b(obj.b)
	{
		cout << "Copy Constructor" << endl;
	}

	// Destructor
	~Algebra()
	{
		cout << "Destructor" << endl;
	}

	// Setter for data member a
	void setA(int a)
	{
		// If a is greater than 0, assign its value to data-member 'a';
		// otherwise, keep the current value of data-member 'a'.
		this->a = a > 0 ? a : this->a;
	}

	// Getter for data member a
	int getA() const
	{
		return a;
	}

	// Setter for data member b
	void setB(int b)
	{
		// If b is greater than 0, assign its value to data-member 'b';
		// otherwise, keep the current value of data-member 'b'.
		this->b = b > 0 ? b : this->b;
	}

	// Getter for data member b
	int getB() const
	{
		return b;
	}

	// Function to set object's data
	void setData(int a, int b)
	{
		setA(a);
		setB(b);
	}

	// Function to take input for object's data
	void input()
	{
		cout << "Enter a = ";
		cin >> a;

		cout << "Enter b = ";
		cin >> b;

		this->setA(a);
		this->setB(b);
	}

	// Function to display object's data on screen
	void print() const
	{
		//this->a = 5;	Error, current object's reference is constant

		cout << "a = " << this->a << "\tb = " << (*this).b << endl;
	}

	/**
	 * @brief Overloaded binary addition operator for Algebra objects.
	 *
	 * This operator adds the corresponding 'a' and 'b' values of two Algebra objects and returns a new Algebra object with the result.
	 *
	 * @param obj The Algebra object to be added.
	 * @return A new Algebra object containing the sum of 'a' and 'b' values.
	 */
	Algebra operator+(const Algebra & obj) const
	{
		return Algebra(a + obj.a, b + obj.b);
	}

	/**
	 * @brief Overloaded equality operator for Algebra objects.
	 *
	 * This operator checks if the 'a' and 'b' values of two Algebra objects are equal.
	 *
	 * @param obj The Algebra object to compare with.
	 * @return true if the 'a' and 'b' values of both objects are equal, false otherwise.
	 */
	bool operator==(const Algebra& obj) const
	{
		return ((a == obj.a) && (b == obj.b));
	}

};

int main()
{
	Algebra obj1(1, 2), obj2(3, 4), r;

	r = obj1 + obj2;	//r = obj1.operator+ (obj2);
	
	r.print();	//4	6

	if (obj1 == obj2)
		cout << "Object are equal." << endl;
	else
		cout << "Object are different." << endl;

	return 0;
}