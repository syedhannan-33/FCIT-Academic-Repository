#include "iostream"

using namespace std;

// Define the Teacher class
class Teacher
{
    // Private member variables to store the employee code and name of the teacher
    int eCode;
    string tName;

public:
    // Parameterized constructor with member initializer list
    Teacher(int eCode, string tName) : eCode{ eCode }, tName{ tName }
    {}

    // Member function to print the Teacher's information
    void teacherInfo()
    {
        cout << "e-code = " << eCode << "\tt-name = " << tName << endl;
    }
};

// Define the Department class
class Department
{
    // Private member variables to store the department number and name
    int dNo;
    string dName;

    // Pointer to a Teacher object
    // Aggregation relationship: Department "has-a" Teacher
    // The Teacher object is not owned by the Department. It is just referenced.
    Teacher* teacher;

public:
    // Parameterized constructor with member initializer list
    Department(int dNo, string dName, Teacher* teacher) : dNo{ dNo }, dName{ dName }, teacher{ teacher }
    {}

    // Member function to print the Department's information
    void departmentInfo()
    {
        cout << "d-no = " << dNo << "\td-name = " << dName << endl; // Print dNo and dName

        // If a teacher is assigned to the department, print the teacher's information
        if (teacher != NULL)
            teacher->teacherInfo(); // Call Teacher's teacherInfo to display teacher's data
    }
};

// Main function
int main()
{
    // Create a Teacher object using the parameterized constructor
    Teacher t(100, "Khan");

    // Create a Department object using the parameterized constructor and assign the Teacher object to it
    // This shows aggregation: Department object 'd' references the Teacher object 't' without owning it
    Department d(1, "DIT", &t); // &t is the reference to the Teacher object

    // Print the information of the Department object, which includes the Teacher's information
    d.departmentInfo();
        
    return 0;
}