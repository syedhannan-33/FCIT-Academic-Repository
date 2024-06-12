#include "iostream" 
#include "vector"	// Includes the vector container header file

using namespace std; 

// Function to print the elements of a vector
void printVector(const vector<int>& v)
{
	for (const auto& i : v)		// Loop through each element in the vector
		cout << i << "\t";		// Print the current element followed by a tab

	cout << endl;
}

int main()
{
	vector<int> vint;			// Declares a vector of integers named "vint"

	vint.push_back(1);			// Adds 1 to the end of the vector
	vint.push_back(2);			// Adds 2 to the end of the vector
	vint.push_back(3);			// Adds 3 to the end of the vector

	// Inserts 100 at index 1 (second position) in the vector
	vint.insert(vint.begin() + 1, 100);

	// Declares an iterator "it" pointing to the beginning of the vector
	vector<int>::iterator it = vint.begin();

	while (it != vint.end())	// Loops until the iterator reaches the end of the vector
	{
		cout << *it << endl;	// Prints the value pointed to by the iterator
		it++;					// Moves the iterator to the next element
	}

	// Erases the element at index 1 (second position) from the vector
	vint.erase(vint.begin() + 1);

	// Calls the printVector function to print the elements of the vector
	printVector(vint); 

	try
	{
		cout << vint.at(99) << endl;	// Attempts to access the element at index 99
	}
	catch (const exception& ex)			// Catches any exceptions thrown during the attempt
	{
		cout << ex.what() << endl;		// Prints the error message associated with the exception
	}

	return 0;
}