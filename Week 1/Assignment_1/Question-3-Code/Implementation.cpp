/*****************************************************
// Author: Spencer Collins
// Date : 8/23/2025
// This program helps answer Question 3 for Assignment 1. 
// This is the implementation file that defines the 
// FractionType class methods for Question 3.
//***************************************************/
#include "frac.h"   // Include header file

/*
Initializes the FractionType class and its properties.

Parameters:
-----------
numerator : `int`
    Fraction numerator.
denominator : `int`
    Fraction denominator.

Returns:
--------
`void`
    Nothing.
*/
void FractionType::Initialize(int numerator, int denominator) {
    num = numerator;
    denom = denominator;
}

/*
Gets the fraction numerator.

Parameters:
-----------
None.

Returns:
--------
`int`
    Fraction numerator.
*/
int FractionType::NumeratorIs() {
    return num;
}

/*
Gets the fraction denominator.

Parameters:
-----------
None.

Returns:
--------
`int`
    Fraction denominator.
*/
int FractionType::DenominatorIs() {
    return denom;
}

/*
Checks if the fraction is zero.

Parameters:
-----------
None.

Returns:
--------
`bool`
    1 (true) if fraction is zero (num == 0), 0 (false) otherwise (num > 0 | num < 0).
*/
bool FractionType::IsZero() {
    return (num == 0);
}

/*
Checks if the fraction is proper or not.

Parameters:
-----------
None.

Returns:
--------
`bool`
    1 (true) if fraction is not proper (num >= denom), 0 (false) otherwise (num < denom).
*/
bool FractionType::IsNotProper() {
    return (num >= denom);
}

/*
Converts improper fraction to mixed fraction (or number).

Parameters:
-----------
None.

Returns:
--------
`int`
    The whole number for the mixed fraction.
*/
int FractionType::ConvertToProper() {
    int result;
    result = num / denom;
    num = num % denom;
    if (num == 0) {
        denom = 1;
    }
    return result;
}