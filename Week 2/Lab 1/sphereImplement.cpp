/*****************************************************
// Author: Spencer Collins
// Date : 8/26/2025
// This is the implementation file that defines the 
// sphereType class methods for Lab 1.
//***************************************************/

#include "sphere.h"
#include <iostream>

using namespace std;

/*
`Sphere` constructor that initializes an instance of the `Sphere` class. Inherits from the `circleType` base class.

Parameters:
-----------
x : `double`
    X coordinate of the sphere center.
y : `double`
    Y coordinate of the sphere center.
z : `double`
    Z coordinate of the sphere center.
r : `double`
    Input radius of the sphere.

Returns:
--------
Nothing.

*/
Sphere::Sphere(double x, double y, double z, double r) : circleType(x, y, r) {
    zCoordinate = z;
}

/*
Gets the volume of the sphere.

Parameters:
-----------
None.

Returns:
--------
`double`
    Volume of the sphere.
*/
double Sphere::volume() const {
    double pi = 3.141592654;
    return 4 / 3 * pi * radius * radius * radius;
}