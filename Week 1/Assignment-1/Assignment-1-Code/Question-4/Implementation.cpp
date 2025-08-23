/*****************************************************
// Author: Spencer Collins
// Date : 8/23/2025
// This program helps answers Question 4 for Assignment 1.
// This is the implentation file that defines the FractionType
// class methods for Question 4.
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
    // This method was rewritten to always assign the negative sign, "-", to the fraction "num" property.
    // Also checks for if the "numerator" or "denominator" args are also 
    // both < 0 and makes both "num" and "denom" positive if true.
    if ((denominator < 0) | (denominator < 0 && numerator < 0)) {
        num = -1*numerator;
        denom = -1*denominator;
    } else {
        num = numerator;
        denom = denominator;
    }
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
Checks if the fraction is negative.

Parameters:
-----------
None.

Returns:
--------
`bool`
    1 (true) if fraction is negative (num < 0), 0 (false) otherwise (num >= 0).
*/
bool FractionType::IsNegative() {
    return (num < 0);
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
    // Line below added to get abs. value of "num" and assign to newNum
    int newNum = (num < 0) ? -1*num : num; 
    return (newNum >= denom);
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

    // Line below added to remove negative sign from "num" 
    // so only "result" has a negative sign to indicate 
    // a negative fraction.
    num = (num < 0) ? -1*num : num; 

    num = num % denom;
    if (num == 0) {
        denom = 1;
    }

    return result;
}