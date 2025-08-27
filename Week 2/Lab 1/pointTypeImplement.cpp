/*****************************************************
// Author: Spencer Collins
// Date : 8/26/2025
// This is the implementation file that defines the 
// pointType class methods for Lab 1.
//***************************************************/


#include "pointType.h"
#include <iostream>

using namespace std;

/*
`pointType` constructor that initializes an instance of the `pointType` class.

Parameters:
-----------
x : `double`
    X coordinate of the point.
y : `double`
    Y coordinate of the point.

Returns:
--------
Nothing.

*/
pointType::pointType(double x, double y) {
    xCoordinate = x;
    yCoordinate = y;
}

/*
Prints the `pointType` class.

Parameters:
-----------
x : `double`
    New X coordinate of the point.
y : `double`
    New Y coordinate of the point.

Returns:
--------
`void`
    Nothing.
*/
void pointType::setPoint(double x, double y) {
    xCoordinate = x;
    yCoordinate = y;
}
/*
Prints the instance of the `pointType` class.

Parameters:
-----------
None.

Returns:
--------
`void`
    Nothing.
*/
void pointType::print() const {

}

/*
Gets the X coordinate of the point.

Parameters:
-----------
None.

Returns:
--------
`double`
    X coordinate of the point.
*/
double pointType::getX() const {
    return xCoordinate;
}

/*
Gets the X coordinate of the point.

Parameters:
-----------
None.

Returns:
--------
`double`
    Y coordinate of the point.
*/
double pointType::getY() const {
    return yCoordinate;
}