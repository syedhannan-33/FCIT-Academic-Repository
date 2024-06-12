#include <iostream>

using namespace std;

class Array 
{
    int* p;         // Holds reference of array, created on heap
    int size;       // Holds the maximum size of array

public:
    // Default constructor
    Array() : size{ 5 } 
    {
        p = new int[size] {};   // Allocating array on heap and initializing to default data (zeroes)
    }

    // Overloaded constructor. Accepts the size of array as parameter
    Array(int size) : size{ size } 
    {
        p = new int[size] {};   // Allocating array on heap and initializing to default data (zeroes)
    }

    // Overloaded constructor. Accepts an array with its size and initializes object's data with them
    Array(const int ar[], int ar_size) : size{ ar_size } 
    {
        p = new int[size];      // Allocating array on heap
    
        for (int i = 0; i < size; i++) 
        {
            p[i] = ar[i];       // Initializing object's array with the data of array passed as argument
        }
    }

    // Copy constructor
    Array(const Array& obj) : size{ obj.size }
    {
        p = new int[size];      // Allocating array on heap

        for (int i = 0; i < size; i++) 
        {
            p[i] = obj.p[i];    // Initializing object's array with the data of right-hand side object
        }
    }

    // Destructor
    ~Array() 
    {
        delete[] p;    // Free memory resources allocated on heap
    }

    // Overloaded assignment operator
    Array& operator= (const Array& obj) 
    {
        // Check if the objects are not the same and have the same size
        if (this != &obj && this->size == obj.size) 
        {
            for (int i = 0; i < size; i++) 
            {
                p[i] = obj.p[i];    // Initializing object's array with the data of right-hand side object
            }
        }

        return *this;
    }

    // Member function to display array elements
    void print() const 
    {
        for (int i = 0; i < size; i++) 
        {
            cout << p[i] << "\t";
        }

        cout << endl;
    }

    // Overloaded index [] operator for constant objects to handle rvalue
    int operator[] (int index) const 
    {
        if (index >= 0 && index < size) 
        {
            return p[index];    // Returning the value at the specified index
        }
        
        throw out_of_range{ "Error: Array Index Out of Bounds." };
    }

    // Overloaded index [] operator for non-constant objects to handle lvalue and rvalue
    int& operator[] (int index) 
    {
        if (index >= 0 && index < size) 
        {
            return p[index];    // Returning a reference to the value at the specified index
        }

        throw out_of_range{ "Error: Array Index Out of Bounds" };
    }
};

int main() 
{
    int a[] = { 1, 2, 3, 4, 5, 6 };

    Array o1, o2, o3(a, 6), o4;

    o3.print();

    try 
    {
        o3[8] = 99;  // Trying to access an index out of bounds
    }
    catch (const exception& ex) 
    {
        cout << ex.what() << endl;
    }

    o3.print();

    return 0;
}
