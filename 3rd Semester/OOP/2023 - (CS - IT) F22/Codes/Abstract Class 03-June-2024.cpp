#include "iostream"
#include "vector"

using namespace std;

// Class A definition
class A
{
    int dA;  // Private member variable to store data for class A

public:
    // Default constructor
    A() : dA{ 0 }
    {
        cout << "A's Default Constructor." << endl;
    }

    // Parameterized constructor
    A(int _dA) : dA{ _dA }
    {
        cout << "A's Parameterized Constructor." << endl;
    }

    // Copy constructor
    A(const A& obj) : dA{ obj.dA }
    {
        cout << "A's Copy Constructor." << endl;
    }

    // Virtual destructor
    virtual ~A()
    {
        cout << "A's Destructor." << endl;
    }

    // Virtual print function to be overridden in derived classes
    virtual void print() const
    {
        cout << "dA = " << dA << endl;
    }

    // Pure virtual function, making class A abstract
    virtual void test() const = 0;  // test() must be overridden in derived classes, otherwise they will also be abstract
};

// Class B definition, inheriting from class A
class B : public A
{
    int dB;  // Private member variable to store data for class B

public:
    // Default constructor
    B() : dB{ 0 }
    {
        cout << "B's Default Constructor." << endl;
    }

    // Parameterized constructor, calling A's parameterized constructor
    B(int _dA, int _dB) : A{ _dA }, dB{ _dB }
    {
        cout << "B's Parameterized Constructor." << endl;
    }

    // Copy constructor, calling A's copy constructor
    B(const B& obj) : A{ obj }, dB{ obj.dB }
    {
        cout << "B's Copy Constructor." << endl;
    }

    // Destructor
    ~B()
    {
        cout << "B's Destructor." << endl;
    }

    // Print function to display the values of dA and dB
    void print() const override // Indicates that this function overrides a virtual function in the base class
    {
        A::print();  // Call to A's print function to display dA
        cout << "dB = " << dB << endl;
    }

    // Overridden test function
    void test() const override // Indicates that this function overrides a virtual function in the base class
    {
        cout << "Class B's Test" << endl;
    }
};

// Class C definition, inheriting from class A
class C : public A
{
    int dC;  // Private member variable to store data for class C

public:
    // Default constructor
    C() : dC{ 0 }
    {
        cout << "C's Default Constructor." << endl;
    }

    // Parameterized constructor, calling A's parameterized constructor
    C(int _dA, int _dC) : A{ _dA }, dC{ _dC }
    {
        cout << "C's Parameterized Constructor." << endl;
    }

    // Copy constructor, calling A's copy constructor
    C(const C& obj) : A{ obj }, dC{ obj.dC }
    {
        cout << "C's Copy Constructor." << endl;
    }

    // Destructor
    ~C()
    {
        cout << "C's Destructor." << endl;
    }

    // Overridden print function
    void print() const override // Indicates that this function overrides a virtual function in the base class
    {
        A::print();  // Call to A's print function to display dA
        cout << "dC = " << dC << endl;
    }

    // Overridden test function
    void test() const override // Indicates that this function overrides a virtual function in the base class
    {
        cout << "Class C's Test" << endl;
    }
};

int main()
{
    // A oa(1); // Object of Abstract class A cannot be instantiated.

    // Create objects of derived classes B and C
    B objb;
    C objc;

    // Vector to hold pointers to base class A
    vector<A*> va;

    // Adding addresses of objects of derived classes to the vector
    va.push_back(&objb);
    va.push_back(&objc);

    // Loop through the vector and call the test() function
    for(auto p : va)
    {
        p->test();  // Calls the overridden test() function in derived classes
    }

    return 0;
}