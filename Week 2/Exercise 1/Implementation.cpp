/*****************************************************
// Author: Spencer Collins
// Date : 8/28/2025
// This is the implementation file that defines the 
// FractionType class methods for Exercise 1.
//***************************************************/
#include "frac.h"   // Include header file
#include <iostream>

using namespace std;

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
    The whole number for the mixed*/
int FractionType::ConvertToProper() {
    int result;
    result = num / denom;
    num = num % denom;
    if (num == 0) {
        denom = 1;
    }
    return result;
}

/*
Reduces the fraction numerator and denominator to their respective smallest irreducible values.

Parameters:
-----------
None.

Returns:
--------
`void`
    Nothing.
*/
void FractionType::reduce() {
    int gcf = 1;
    for (int i=(num>denom) ? num:denom; i>=1; i--) {
        if (num % i == 0 & denom % i == 0 ) {
            gcf = i;
            break;
        } else {
            continue;
        }
    }
    num = num / gcf;
    denom = denom / gcf;
}

/*
Prints out the fraction.

Parameters:
-----------
None.

Returns:
--------
`void`
    Nothing.
*/
void FractionType::print() {
    cout << num << " / " << denom << endl;
}

/*
Addition (`+`) Operator overloader for FractionType class.

Parameters:
-----------
addend : `const FractionType&`
    Direct reference to the FractionType class instance "addend".

Returns:
--------
`FractionType`
    FractionType class instance with numerator and denominator calculated as follows:
        frac3.num `=` frac1.num`*`frac2.denom `+` frac2.num`*`frac1.denom
        frac3.denom `=` frac1.denom  `*` frac2.denom
*/
FractionType FractionType::operator + (const FractionType& addend) {
    FractionType frac;
    frac.num = num*addend.denom + addend.num*denom;
    frac.denom = denom*addend.denom;
    return frac;
}


/*
Subtraction (`-`) Operator overloader for FractionType class.

Parameters:
-----------
addend : `const FractionType&`
    Direct reference to the FractionType class instance "addend".

Returns:
--------
`FractionType`
    FractionType class instance with numerator and denominator calculated as follows:
        frac3.num `=` frac1.num`*`frac2.denom `-` frac2.num`*`frac1.denom
        frac3.denom `=` frac1.denom  `*` frac2.denom
*/
FractionType FractionType::operator - (const FractionType& addend) {
    FractionType frac;
    frac.num = num*addend.denom - addend.num*denom;
    frac.denom = denom*addend.denom;
    return frac;
}

/*
Subtract (`*`) Operator overloader for FractionType class.

Parameters:
-----------
addend : `const FractionType&`
    Direct reference to the FractionType class instance "addend".

Returns:
--------
`FractionType`
    FractionType class instance with numerator and denominator calculated as follows:
        frac3.num `=` frac1.num `*` frac2.num
        frac3.denom `=` frac1.denom `*` frac2.denom
*/
FractionType FractionType::operator * (const FractionType& addend) {
    FractionType frac;
    frac.num = num * addend.num;
    frac.denom = denom * addend.denom;
    return frac;
}

/*
Division (`/`) Operator overloader for FractionType class.

Parameters:
-----------
addend : `const FractionType&`
    Direct reference to the FractionType class instance "addend".

Returns:
--------
`FractionType`
    FractionType class instance with numerator and denominator calculated as follows:
        frac3.num `=` frac1.num `*` frac2.num
        frac3.denom `=` frac1.denom `*` frac2.denom
*/
FractionType FractionType::operator / (const FractionType& addend) {
    FractionType frac;
    frac.num = num * addend.denom;
    frac.denom = denom * addend.num;
    return frac;
}