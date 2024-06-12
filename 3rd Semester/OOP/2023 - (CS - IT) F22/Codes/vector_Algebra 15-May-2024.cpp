#include "iostream"
#include "vector"   // Includes the vector container header file

using namespace std;

class Algebra
{
    // Data members of the class
    int a, b;

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
};

// Function to print objects stored in a vector
void print(const vector<Algebra>& v)
{
    for (auto& obj : v)     // Loop through each object in the vector
        obj.print();        // Call the print method of each object

    cout << endl;
}

int main()
{
    Algebra o1{ 7, 8 };     // Creates an Algebra object named "o1" with values 7 and 8

    vector<Algebra> va;     // Declares a vector of Algebra objects named "va"

    va.push_back(o1);               // Adds the object "o1" to the end of the vector
    va.push_back(Algebra());        // Adds a default-constructed Algebra object to the end of the vector
    va.push_back(Algebra(1, 2));    // Adds a custom-constructed Algebra object with values 1 and 2 to the end of the vector
    va.push_back(va[2]);            // Adds a copy of the object at index 2 in the vector to the end of the vector

    try
    {
        // Inserts a custom-constructed Algebra object with values 99 and 100 at index 1 in the vector
        va.insert(va.begin() + 1, Algebra(99, 100));
    }
    catch (const exception& ex)     // Catches any exceptions thrown during the attempt
    {
        cout << ex.what() << endl;  // Prints the error message associated with the exception
    }

    print(va);                      // Calls the print function to print all objects stored in the vector

    va.pop_back();                  // Removes the last object from the vector
    print(va);                      // Calls the print function to print all objects stored in the vector

    return 0;
}

