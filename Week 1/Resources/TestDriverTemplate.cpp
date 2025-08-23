#include "frac.h";  // File containing the class to be read

FractionType fraction;  // Declaration of FractionType object

// Test driver
#include <iostream>
#include <fstream>
#include <string>

// #include file to be tested below here:

int main() {
    using namespace std;
    ifstream inFile;    // File containing operations, reads text or binary files
    ofstream outFile;   // File containing output, reads text or binary files
    string inFileName;  // Input file external name
    string outFileName; // Output file external name
    string outputLabel;
    string command;     // Operation to be executed
    int numCommands;    // Track current command


    //Declare a variable of the type being tested
    // Prompt for file names, read file names, and prepare files
    cout << "Enter name of input file; press enter (return)." << endl;
    cin >> inFileName;
    inFile.open(inFileName.c_str());    // "open" function requires that a regular string be converted to a C string vai the "c_str()" function

    cout << "Enter name of output file; press enter (return)." << endl;
    cin >> outFileName;
    outFile.open(outFileName.c_str()); // "open" function requires that a regular string be converted to a C string vai the "c_str()" function

    inFile >> command; // ">>" reads the input file token by token 
                       // based on whitespace delimiters (including newlines) 
                       // into variables of appropriate types
    numCommands = 0;
    
    while (command != "Quit") {
        // Put testing code here.
        // The following should be specific to the structure being tested.
        // Execute the command by invoking the member function of the
        // same name
        //Print the results to the output file

        numCommands++;
        cout << "Command number " << numCommands << " completed." << endl;
        inFile >> command;
    }

    cout << "Testing completed." << endl;
    inFile.close();
    outFile.close();
    return 0;
}

