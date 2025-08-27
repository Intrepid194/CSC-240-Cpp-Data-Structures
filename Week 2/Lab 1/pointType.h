
/*****************************************************
// Author: Spencer Collins
// Date : 8/26/2025
// This is the implementation file that defines the 
// FractionType class methods for Exercise 1.
//***************************************************/
//Class pointType

#ifndef H_PointType
#define H_PointType

class pointType
{
public:
    void setPoint(double x, double y);
    void print() const;
    double getX() const;
    double getY() const;
    pointType(double x = 0.0, double y = 0.0);

protected:
    double xCoordinate;
    double yCoordinate;
};

#endif