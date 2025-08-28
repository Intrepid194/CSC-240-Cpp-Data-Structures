/*****************************************************
// Author: Spencer Collins
// Date : 8/28/2025
// This is the test driver file that tests the 
// pointType, circleType and Sphere class methods for Lab 1.
//***************************************************/

#include "circleType.h"
#include "sphere.h"
#include <iostream>

using namespace std;

int main() {

    // Initialize a point
    pointType point1 = pointType(0.5, 5.0);

    

    // Unit Tests for testing the pointType class
    cout << endl;
    cout << endl;
    cout << "******UNIT TESTS for pointType class******" << endl;
    cout << endl;
    cout << "Initializing a new pointType instance..." << endl;
    cout << endl;
    cout << "**Unit Test - Testing pointType.print() Method**" << endl;
    point1.print();
    cout << endl;
    
    cout << "**Unit Test - Testing pointType.getX() Method**" << endl;
    cout << "X coordinate is: " << point1.getX() << endl;
    cout << endl;

    cout << "**Unit Test - Testing pointType.getY() Method**" << endl;
    cout << "Y coordinate is: " << point1.getY() << endl;
    cout << endl;

    cout << "**Unit Test - Testing pointType.setPoint() Method**" << endl;
    point1.setPoint(45.4, -12.2);
    point1.print();
    cout << endl;

    // Unit tests for testing the circleType class
    cout << "******UNIT TESTS for circleType class******" << endl;
    cout << endl;

    cout << "Initializing a new circleType instance..." << endl;
    //Initialize a circle
    circleType circle1 = circleType(3.0, 4.0, 4.5);
    cout << endl;

    cout << "**Unit Test - Testing circleType.print() Method**" << endl;
    circle1.print();
    cout << endl;

    cout << "**Unit Test - Testing circleType.setCenter() Method**" << endl;
    cout << "Setting circle center to: "; 
    point1.print();
    circle1.setCenter(point1);
    cout << "New circle is: " << endl;
    circle1.print();
    cout << endl;
    
    cout << "**Unit Test - Testing circleType.setRadius() Method**" << endl;
    cout << "Setting circle center to: 47.5" << endl;
    circle1.setRadius(47.5);
    circle1.print();
    cout << endl;

    cout << "**Unit Test - Testing circleType.getRadius() Method**" << endl;
    cout << "circle radius is: " << circle1.getRadius() << endl;
    cout << endl;

    cout << "**Unit Test - Testing circleType.getCircumference() Method**" << endl;
    cout << "circle circumference is: " << circle1.getCircumference() << endl;
    cout << endl;

    cout << "**Unit Test - Testing circleType.getArea() Method**" << endl;
    cout << "circle area is: " << circle1.getArea() << endl;
    cout << endl;

    // Unit tests for testing the Sphere class
    cout << "******UNIT TESTS for Sphere class******" << endl;
    cout << endl;

    //Initialize a sphere
    cout << "Initializing a new Sphere instance..." << endl;
    Sphere sphere1 = Sphere(3.0, 4.0, -5.0, 23.0);
    cout << endl;

    cout << "**Unit Test - Testing Sphere.volume() Method**" << endl;
    cout << "sphere volume is: " << sphere1.volume() << endl;
    cout << endl;

    return 0;
}