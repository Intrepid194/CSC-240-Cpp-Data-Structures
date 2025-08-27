/*****************************************************
// Author: Spencer Collins
// Date : 8/26/2025
// This is the implementation file that defines the 
// circleType class methods for Lab 1.
//***************************************************/

#include "circleType.h"
#include <iostream>

using namespace std;


/*
`circleType` constructor that initializes an instance of the `circleType` class. Inherits from the `pointType` base class.

Parameters:
-----------
x : `double`
    X coordinate of the circle center.
y : `double`
    Y coordinate of the circle center.
r : `double`
    Input radius of the circle.

Returns:
--------
Nothing.

*/
circleType::circleType(double x, double y, double r) : pointType(x, y) {
    radius = r;
}

/*
Prints the instance of the `circleType` class.

Parameters:
-----------
None.

Returns:
--------
`void`
    Nothing.
*/
void circleType::print() const {
    cout << "center: " ;
    pointType::print();
    cout << "radius = " << radius << endl;
}

/*
Sets the center of the circle.

Parameters:
-----------
point : `pointType&`
    `pointType` class to set X and Y coordinates of the circle.

Returns:
--------
`void`
    Nothing.
*/
void circleType::setCenter(pointType& point) {
    xCoordinate = point.getX();
    yCoordinate = point.getY();

}

/*
Sets the radius of the circle

Parameters:
-----------
r : `double`
    New radius of the circle.

Returns:
--------
`void`
    Nothing.
*/
void circleType::setRadius(double r) {
    radius = r;
}

/*
Gets the radius of the circle.

Parameters:
-----------
None.

Returns:
--------
`double`
    Radius of the circle.
*/
double circleType::getRadius() const {
    return radius;
}

/*
Gets the circumference of the circle.

Parameters:
-----------
None.

Returns:
--------
`double`
    Circumference of the circle.
*/
double circleType::getCircumference() const {
    double pi = 3.141592654;
    return pi*2*radius;
}

/*
Gets the area of the circle.

Parameters:
-----------
None.

Returns:
--------
`double`
    Area of the circle.
*/
double circleType::getArea() const {
    double pi = 3.141592654;
    return pi*radius*radius;
}


