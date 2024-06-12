#include <iostream>

using namespace std;

// Function to perform division
int divide(int numerator, int denominator)
{
    // Check if the denominator is not zero
    if(denominator != 0)
        return numerator / denominator; // Perform division

    // If denominator is zero, throw an exception
    throw "Division by zero error";
}

int main() 
{
    double numerator, denominator;

    cout << "Enter numerator: ";
    cin >> numerator;

    cout << "Enter denominator: ";
    cin >> denominator;

    try 
    {
        // Try to perform division
        double result = divide(numerator, denominator);
        
        // Display the result if successful
        cout << "Result: " << result << endl; 
    } 
    catch (const char* ex) 
    {
        // Handle the exception if division by zero occurs
        cerr << "Error: " << ex << endl;
    }

    return 0;
}