/*****************************************************
// Author: Spencer Collins
// Date : 8/28/2025
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
the overloaded operator methods of the FractionType 
Class for Exercise 1.
*/
int main() {

	//Initialize all three FractionType test instances
	cout << "Initializing FractionType test instances..." << endl;
	FractionType one;
	FractionType two;

	FractionType three;


	// Unit Tests for + Operator
	cout << "UNIT TESTS FOR + Operator: " << endl;
	cout << "Unit Test - Adding 2 positive fractions" << endl;
	
	one.Initialize(2, 3);
	two.Initialize(4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one + two;
	cout << "Fraction three is: " << endl;
	three.print();

	cout << "Unit Test - Adding 1 positive and 1 negative fraction (1st is negative, 2nd is positive)" << endl;
	one.Initialize(-2, 3);
	two.Initialize(4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one + two;
	cout << "Fraction three is: " << endl;
	three.print();

	cout << "Unit Test - Adding 1 positive and 1 negative fraction (1st is positive, 2nd is negative)" << endl;
	one.Initialize(2, 3);
	two.Initialize(-4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one + two;
	cout << "Fraction three is: " << endl;
	three.print();
	
	cout << "Unit Test - Adding 2 negative fractions" << endl;
	one.Initialize(-2, 3);
	two.Initialize(-4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one + two;
	cout << "Fraction three is: " << endl;
	three.print();


	// Unit Tests for - Operator
	cout << "UNIT TESTS FOR - Operator: " << endl;
	cout << "Unit Test - Subtracting 2 positive fractions" << endl;
	
	one.Initialize(2, 3);
	two.Initialize(4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one - two;
	cout << "Fraction three is: " << endl;
	three.print();

	cout << "Unit Test - Subtracting 1 positive and 1 negative fraction (1st is negative, 2nd is positive)" << endl;
	one.Initialize(-2, 3);
	two.Initialize(4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one - two;
	cout << "Fraction three is: " << endl;
	three.print();

	cout << "Unit Test - Subtracting 1 positive and 1 negative fraction (1st is positive, 2nd is negative)" << endl;
	one.Initialize(2, 3);
	two.Initialize(-4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one - two;
	cout << "Fraction three is: " << endl;
	three.print();
	
	cout << "Unit Test - Subtracting 2 negative fractions" << endl;
	one.Initialize(-2, 3);
	two.Initialize(-4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one - two;
	cout << "Fraction three is: " << endl;
	three.print();

	// Unit Tests for * Operator
	cout << "UNIT TESTS FOR * Operator: " << endl;
	cout << "Unit Test - Multiplying 2 positive fractions" << endl;
	
	one.Initialize(2, 3);
	two.Initialize(4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one * two;
	cout << "Fraction three is: " << endl;
	three.print();

	cout << "Unit Test - Multiplying 1 positive and 1 negative fraction (1st is negative, 2nd is positive)" << endl;
	one.Initialize(-2, 3);
	two.Initialize(4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one * two;
	cout << "Fraction three is: " << endl;
	three.print();

	cout << "Unit Test - Multiplying 1 positive and 1 negative fraction (1st is positive, 2nd is negative)" << endl;
	one.Initialize(2, 3);
	two.Initialize(-4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one * two;
	cout << "Fraction three is: " << endl;
	three.print();
	
	cout << "Unit Test - Multiplying 2 negative fractions" << endl;
	one.Initialize(-2, 3);
	two.Initialize(-4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one * two;
	cout << "Fraction three is: " << endl;
	three.print();

	// Unit Tests for / Operator
	cout << "UNIT TESTS FOR / Operator: " << endl;
	cout << "Unit Test - Dividing 2 positive fractions" << endl;
	
	one.Initialize(2, 3);
	two.Initialize(4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one / two;
	cout << "Fraction three is: " << endl;
	three.print();

	cout << "Unit Test - Dividing 1 positive and 1 negative fraction (1st is negative, 2nd is positive)" << endl;
	one.Initialize(-2, 3);
	two.Initialize(4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one / two;
	cout << "Fraction three is: " << endl;
	three.print();

	cout << "Unit Test - Dividing 1 positive and 1 negative fraction (1st is positive, 2nd is negative)" << endl;
	one.Initialize(2, 3);
	two.Initialize(-4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one / two;
	cout << "Fraction three is: " << endl;
	three.print();
	
	cout << "Unit Test - Dividing 2 negative fractions" << endl;
	one.Initialize(-2, 3);
	two.Initialize(-4, 5);
	cout << "Fraction one is: " << endl;
	one.print();
	cout << "Fraction two is: " << endl;
	two.print();

	three = one / two;
	cout << "Fraction three is: " << endl;
	three.print();


	// This was the original code that was downloaded from the Exercise folder.

	// FractionType x;
	// FractionType y;
	// x.Initialize(1, 3);
	// y.Initialize(2, 3);
	// FractionType z = x + y;
	// z.print();

	// z.reduce();
	// z.print();

	// FractionType g;
	// g.Initialize(15, 20);
	// g.reduce();
	// g.print();


	// //Unit Test for checking overloaded + operator
	// FractionType a;
	// FractionType b;
	// a.Initialize(1, 3);
	// b.Initialize(6, 15);
	// a.print();
	// b.print();

	// FractionType c = a + b;
	// c.print();
	
}
