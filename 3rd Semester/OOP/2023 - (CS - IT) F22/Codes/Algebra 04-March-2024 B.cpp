#include "iostream"

using namespace std;

class Algebra
{
	//data members of the class
	int a, b;

public:

	//function to take input for object's data
	void input()
	{
		cout << "Enter a = ";
		cin >> a;

		cout << "Enter b = ";
		cin >> b;
	}

	//function to display object's data on screen
	void print()
	{
		cout << "a = " << a << "\tb = " << b << endl;
	}
};

int main()
{
	//declaring objects of Algebra
	Algebra obj1, obj2;

	obj1.input();			//making call to input member function for obj1
	obj2.input();			//making call to input member function for obj2

	obj1.print();			//making call to print member function for obj1
	obj2.print();			//making call to print member function for obj2

	obj1.print();			//making call to print member function for obj1
	obj2.print();			//making call to print member function for obj2

	return 0;
}