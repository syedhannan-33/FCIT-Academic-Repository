#include "iostream"
#include "string"
#include "fstream"

using namespace std;

void readIntegersFromFile(string fileName)
{
    /*Reading integers from file*/

	int a = -1;
    
	//open a file in input (reading) mode
    ifstream inf(fileName); 

    //OR
    //ifstream inf;
    //inf.open(fileName);

	if (inf.is_open())		                //checking file is opened
	{
        while (inf >> a)			    	//taking input (reading) from file till EOF
	    {
		    cout << a << " ";       	    //writing data to console
	    }

	    inf.close();						//closing the file        
	}
    else
    {
        cerr << "Failed to open " << fileName << endl;
        exit(0);            //closes the program
    }
}

void readLinesFromFile(string fileName)
{
    /*Reading lines from file*/

	string line = "";
    
	//open a file in input (reading) mode
    ifstream inf(fileName); 

    //OR
    //ifstream inf;
    //inf.open(fileName);

	if (inf.is_open())		                //checking file is opened
	{
        while (getline(inf, line))		    //taking input (reading) from file till EOF
	    {
		    cout << line << endl;	    //writing data to console
	    }

	    inf.close();						//closing the file        
	}
    else
    {
        cerr << "Failed to open " << fileName << endl;
        exit(0);            //closes the program
    }
}

int main()
{
    readIntegersFromFile("input.txt");   

    cout << endl << endl;

    readLinesFromFile("quotes.txt");

    return 0;
}

