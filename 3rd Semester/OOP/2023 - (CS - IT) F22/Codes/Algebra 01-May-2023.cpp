#include <iostream>

using namespace std;

class Algebra 
{
    // Data members of the class
    int a, b;

    // Declaration of static data member
    static int S;

public:
    // Default Constructor
    Algebra() : a{ 0 }, b{ 0 } 
    { }

    // Parameterized Constructor
    Algebra(int a, int b) : a{ a }, b{ b } 
    { }

    // Copy Constructor
    Algebra(const Algebra& obj) : a(obj.a), b(obj.b) 
    { }

    // Destructor
    ~Algebra() 
    { }

    // Setter for data member 'a'
    void setA(int a) 
    {
        this->a = a;
    }

    // Getter for data member 'a'
    int getA() const 
    {
        return a;
    }

    // Setter for data member 'b'
    void setB(int b) 
    {
        this->b = b;
    }

    // Getter for data member 'b'
    int getB() const 
    {
        return b;
    }

    // Function to set object's data
    void setData(int a, int b) 
    {
        this->a = a;
        this->b = b;
    }

    // Function to take input for object's data
    void input() 
    {
        cout << "Enter value for a: ";
        cin >> a;

        cout << "Enter value for b: ";
        cin >> b;
    }

    // Function to display object's data on screen
    void print() const 
    {
        cout << "a = " << a << "\tb = " << b << endl;
    }

    // Static member function to set the value of static data member 'S'
    static void setS(int S) 
    {
        Algebra::S = S;
    }

    // Static member function to get the value of static data member 'S'
    static int getS() 
    {
        return S;
    }
};

// Static data member definition and initialization
int Algebra::S;

int main() {
    // Accessing static member function with class name
    cout << "Initial value of S: " << Algebra::getS() << endl;

    // Setting new value for static data member 'S'
    Algebra::setS(9);

    // Accessing static member function with class name to get updated value
    cout << "Updated value of S: " << Algebra::getS() << endl;

    // Creating object of class Algebra
    Algebra obj1;

    // Accessing static member using object
    cout << "Value of S accessed via object: " << obj1.getS() << endl;

    return 0;
}