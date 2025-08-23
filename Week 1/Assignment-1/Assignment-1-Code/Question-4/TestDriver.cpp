/*****************************************************
// Author: Spencer Collins
// Date : 8/23/2025
// This program helps answer Question 4 for Assignment 1. 
// This is the test driver file that defines the unit tests 
// for each method in the FractionType class for Question 4.
//***************************************************/

// Test driver for Question 4
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
        // Unit test for intitializing the FractionType class
        if (command == "Initialize") {
            int numerator;
            int denominator;

            inFile >> numerator;
            inFile >> denominator;

            fraction.Initialize(numerator, denominator);
            outFile << "Numerator: " << fraction.NumeratorIs()
                << " Denominator: " << fraction.DenominatorIs()
                << endl;
        
        // Unit test for returning fraction numerator.
        } else if (command == "NumeratorIs") {
            outFile << "Numerator: " << fraction.NumeratorIs() << endl;

        // Unit test for returning fraction denominator.
        } else if (command == "DenominatorIs") {
            outFile << "Denominator: " << fraction.DenominatorIs() << endl;
        
        // Unit test for checking if fraction is zero.
        } else if (command == "IsZero") {
            if (fraction.IsZero()) {
                outFile << "Fraction is zero " << endl;
            } else {
                outFile << "Fraction is not zero " << endl;
            }

        // Unit test for checking if fraction is negative.
        //Answers Question 4 Part C of Assignment 1.
        } else if (command == "IsNegative") {
        if (fraction.IsNegative()) {
            outFile << "Fraction is negative " << endl;
        } else {
            outFile << "Fraction is positive " << endl;
        }

        // Unit test for checking if fraction is not proper.
        } else if (command == "IsNotProper") {
            if (fraction.IsNotProper()) {
                outFile << "Fraction is improper " << endl;
            } else {
                outFile << "Fraction is proper " << endl;
            }
            
        // Unit test for converting improper fraction to proper fraction (mixed number).
        // Answers Question 4 part D of Assignment 1.
        } else if (command == "ConvertToProper") {
            if (fraction.DenominatorIs() == 0) {
                outFile << "Denominator: " << fraction.DenominatorIs() << " == 0. Fraction is undefined " << endl;
            } else {
                outFile << "Whole number is " << fraction.ConvertToProper() << endl;
                outFile << "Numerator: " << fraction.NumeratorIs()
                << " Denominator: " << fraction.DenominatorIs() << endl;
            }
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

