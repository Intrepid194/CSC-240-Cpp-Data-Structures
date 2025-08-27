/*****************************************************
// Author: Spencer Collins
// Date : 8/26/2025
// This is the implementation file that defines the 
// FractionType class methods for Exercise 1.
//***************************************************/
//Class circleType

#ifndef H_CircleType
#define H_CircleType

#include "pointType.h"
 
class circleType: public pointType
{
public:
	void print() const;
	void setRadius(double r);
	double getRadius() const;
	double getCircumference() const;
	double getArea() const;
	void setCenter(pointType&);
	circleType(double x = 0.0, double y = 0.0, double r = 0.0);

protected:
	double radius;
};

#endif