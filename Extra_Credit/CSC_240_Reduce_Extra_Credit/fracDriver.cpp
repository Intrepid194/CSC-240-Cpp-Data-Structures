/*****************************************************
// Author: Spencer Collins
// Date : 8/26/2025
// This is the test driver .cpp file that tests
// the FractionType class methods for Exercise 1.
//***************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "frac.h"

using namespace std;

/*
This is the test driver code for testing all 
the methods of the FractionType Class for Exercise 1.

NOTE: The unit tests for the reduce() and print() functions are also in this test driver file.
They have been submitted as their own folder to the respectiveExtra Credits assignment submission area.
*/
int main() {

	//Initialize all three FractionType test instances
	cout << "Initializing FractionType test instances..." << endl;
	FractionType one;
	FractionType two;

	FractionType three;

	// This was also submitted in the Extra Credit Folder
	// Unit Tests for Reducing a Fraction
	cout << "Unit Test - Reducing a Positive Proper Fraction" << endl;
	one.Initialize(2401, 38416);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction one reduced is: " << endl;
	one.reduce();
	one.print();

	cout << "Unit Test - Reducing a Negative Proper Fraction" << endl;
	one.Initialize(-2401, 38416);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction one reduced is: " << endl;
	one.reduce();
	one.print();

	cout << "Unit Test - Reducing a Positive Improper Fraction" << endl;
	one.Initialize(38416, 2401);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction one reduced is: " << endl;
	one.reduce();
	one.print();

	cout << "Unit Test - Reducing a Negative Improper Fraction" << endl;
	one.Initialize(-38416, 2401);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction one reduced is: " << endl;
	one.reduce();
	one.print();

	cout << "Unit Test - Reducing a Positive Irreducible Improper Fraction" << endl;
	one.Initialize(7919, 4441);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction one reduced is: " << endl;
	one.reduce();
	one.print();

	cout << "Unit Test - Reducing a Positive Irreducible Proper Fraction" << endl;
	one.Initialize(4441, 7919);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction one reduced is: " << endl;
	one.reduce();
	one.print();

	cout << "Unit Test - Reducing a Negative Irreducible Improper Fraction" << endl;
	one.Initialize(-7919, 4441);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction one reduced is: " << endl;
	one.reduce();
	one.print();

	cout << "Unit Test - Reducing a Negative Irreducible Proper Fraction" << endl;
	one.Initialize(-4441, 7919);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction one reduced is: " << endl;
	one.reduce();
	one.print();

	//Unit Tests for Printing a Fraction
	cout << "Unit Test - Printing a Positive Proper Fraction" << endl;
	one.Initialize(7, 16);
	cout << "Numerator is: " << one.NumeratorIs() << endl;
	cout << "Denominator is: " << one.DenominatorIs() << endl;
	cout << "Fraction one is: " << endl;
	one.print();

	cout << "Unit Test - Printing a Negative Proper Fraction" << endl;
	one.Initialize(-7, 16);
	cout << "Numerator is: " << one.NumeratorIs() << endl;
	cout << "Denominator is: " << one.DenominatorIs() << endl;
	cout << "Fraction one is: " << endl;
	one.print();

	cout << "Unit Test - Printing a Positive Improper Fraction (num MOD denom != 0)" << endl;
	one.Initialize(16, 7);
	cout << "Numerator is: " << one.NumeratorIs() << endl;
	cout << "Denominator is: " << one.DenominatorIs() << endl;
	cout << "Fraction one is: " << endl;
	one.print();

	cout << "Unit Test - Printing a Positive Improper Fraction (num MOD denom == 0)" << endl;
	one.Initialize(16, 8);
	cout << "Numerator is: " << one.NumeratorIs() << endl;
	cout << "Denominator is: " << one.DenominatorIs() << endl;
	cout << "Testing 16 / 8" << endl;
	cout << "Fraction one is: " << endl;
	one.print();

	cout << "Unit Test - Printing a Negative Improper Fraction (num MOD denom != 0)" << endl;
	one.Initialize(-16, 7);
	cout << "Numerator is: " << one.NumeratorIs() << endl;
	cout << "Denominator is: " << one.DenominatorIs() << endl;
	cout << "Fraction one is: " << endl;
	one.print();

	cout << "Unit Test - Printing a Negative Improper Fraction (num MOD denom == 0)" << endl;
	one.Initialize(-16, 8);
	cout << "Numerator is: " << one.NumeratorIs() << endl;
	cout << "Denominator is: " << one.DenominatorIs() << endl;
	cout << "Fraction one is: " << endl;
	one.print();
}
