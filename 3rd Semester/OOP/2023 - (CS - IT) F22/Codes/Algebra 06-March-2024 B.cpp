#include "iostream"

using namespace std;

class Algebra
{
	// Data members of the class
	int a, b;
	
public:

	// Default Constructor
	Algebra() : a(0), b(0)
	{
		cout << "Default Constructor" << endl;		
	}

	// Parameterized Constructor
	Algebra(int a1, int b1)
	{
		cout << "Parameterized Constructor" << endl;

		setA(a1);
		setB(b1);
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

	// Setter for data memeber a
	void setA(int a1)
	{
		// If a1 is greater than 0, assign its value to 'a'; otherwise, keep the current value of 'a'.
		a = a1 > 0 ? a1 : a;
	}

	// Getter for data memeber a
	int getA()
	{
		return a;
	}

	// Setter for data memeber b
	void setB(int b1)
	{
		// If b1 is greater than 0, assign its value to b; otherwise, keep the current value of b.
		b = b1 > 0 ? b1 : b;
	}

	// Getter for data memeber b
	int getB()
	{
		return b;
	}

	// Function to set object's data
	void setData(int a1, int b1)
	{
		setA(a1);
		setB(b1);
	}

	// Function to take input for object's data
	void input()
	{
		cout << "Enter a = ";
		cin >> a;

		cout << "Enter b = ";
		cin >> b;

		setA(a);
		setB(b);
	}

	// Function to display object's data on screen
	void print()
	{
		cout << "a = " << a << "\tb = " << b << endl;
	}
};

int main()
{
	Algebra obj1;				// Creating object through default constructor

	Algebra obj2(-1, 2);		// Creating object through parameterized constructor

	Algebra obj3(obj2);			// Creating object through copy constructor

	obj3.setA(99);

	obj1.print();	//0	0
	obj2.print();	//0	2
	obj3.print();	//1	99

	cout << obj2.getB() << endl;	//2	

	return 0;
}