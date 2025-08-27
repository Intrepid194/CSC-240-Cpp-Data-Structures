/*****************************************************
// Author: Spencer Collins
// Date : 8/26/2025
// This is the implementation file that defines the 
// FractionType class methods for Exercise 1.
//***************************************************/
//class Sphere

#ifndef H_Sphere
#define H_Sphere

#include "circleType.h"

class Sphere: public circleType {
    public:
        double volume() const;
        Sphere(
            double x = 0.0, 
            double y = 0.0, 
            double z = 0.0, 
            double r= 0.0
        );

    protected:
        double xCoordinate;
        double yCoordinate;
        double zCoordinate;
        double radius;
};

#endif