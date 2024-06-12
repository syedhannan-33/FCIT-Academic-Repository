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
	Algebra(int a1, int b1) : a(a1), b(b1)
	{
		cout << "Parameterized Constructor" << endl;
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

	// Function to set object's data
	void setData(int a1, int b1)
	{
		a = a1;
		b = b1;
	}

	// Function to take input for object's data
	void input()
	{
		cout << "Enter a = ";
		cin >> a;

		cout << "Enter b = ";
		cin >> b;
	}

	// Function to display object's data on screen
	void print()
	{
		cout << "a = " << a << "\tb = " << b << endl;
	}
};

int main()
{
	Algebra obj1;			// Creating object through default constructor

	Algebra obj2(1, 2);		// Creating object through parameterized constructor

	Algebra obj3(obj2);		// Creating object through copy constructor

	Algebra obj4 = obj3;	// Creating object through copy constructor


	obj1.print();	//0	0
	obj2.print();	//1	2
	obj3.print();	//1	2
	obj4.print();	//1	2

	return 0;
}