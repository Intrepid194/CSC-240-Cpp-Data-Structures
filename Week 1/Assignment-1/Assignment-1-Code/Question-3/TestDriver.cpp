/*****************************************************
// Author: Spencer Collins
// Date : 8/23/2025
// This program helps answer Question 3 for Assignment 1. 
// This is the test driver file that defines the unit tests 
// for each method in the FractionType class for Question 3.
//***************************************************/
// Test driver for Question 3
#include <iostream>
#include <fstream>
#include <string>

// #include file to be tested below here:
#include "frac.h"

// Declare object/datastructure to be tested
FractionType fraction;

int main() {
    using namespace std;
    ifstream inFile;    // File containing operations, reads text or binary files
    ofstream outFile;   // File containing output, reads text or binary files
    string inFileName;  // Input file external name
    string outFileName; // Output file external name
    string outputLabel;
    string command;     // Operation to be executed
    int numCommands;    // Track current command


    // Declare a variable of the type being tested
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

        // FractionType Unit Tests
        if (command == "Initialize") {
            int numerator;
            int denominator;

            inFile >> numerator;
            inFile >> denominator;

            fraction.Initialize(numerator, denominator);
            outFile << "Numerator: " << fraction.NumeratorIs()
                << " Denominator: " << fraction.DenominatorIs()
                << endl;
        } else if (command == "NumeratorIs") {
            outFile << "Numerator: " << fraction.NumeratorIs() << endl;
        } else if (command == "DenominatorIs") {
            outFile << "Denominator: " << fraction.DenominatorIs() << endl;
        } else if (command == "IsZero") {
            if (fraction.IsZero()) {
                outFile << "Fraction is zero " << endl;
            } else {
                outFile << "Fraction is not zero " << endl;
            }
        } else if (command == "IsNotProper") {
            if (fraction.IsNotProper()) {
                outFile << "Fraction is improper " << endl;
            } else {
                outFile << "Fraction is proper " << endl;
            }
        } else {
            outFile << "Whole number is " << fraction.ConvertToProper() << endl;
            outFile << "Numerator: " << fraction.NumeratorIs()
                << " Denominator: " << fraction.DenominatorIs() << endl;
        }

        numCommands++;
        cout << "Command number " << numCommands << " completed." << endl;
        inFile >> command;
    }

    cout << "Testing completed." << endl;
    inFile.close();
    outFile.close();
    return 0;
}

