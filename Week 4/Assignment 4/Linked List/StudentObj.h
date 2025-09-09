/*****************************************************
// Author: Spencer Collins
// Date : 9/8/2025 
// This is the header file that defines the Student class and the Node struct for Assignment 4.
//***************************************************/

#ifndef STUDOBJ_H
#define STUDOBJ_H

#include <iostream>
#include <string>

using namespace std;

class Student {
    private:
        string firstName;
        string lastName;
        char districtCode;
        float currentCredits;
        float tuitionOwed;
    public:
    //default constructor for Student class
    Student () : 
        firstName(""), 
        lastName(""),
        districtCode(' '),
        currentCredits(0.0),
        tuitionOwed(0.0)
    {}
    //Getter Methods
    string getFirstName() const {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    char getDistrictCode() {
        return districtCode;
    }

    float getCurrentCredits() {
        return currentCredits;
    }

    float getTuitionOwed() {
        if (districtCode == 'I') tuitionOwed = 250.0*currentCredits;
        else if (districtCode == 'O') tuitionOwed = 500.0*currentCredits;
        else tuitionOwed = 0.0;

        return tuitionOwed;
    }

    //Setter Methods
    void setFirstName(const string &fN) { //strings passed by reference are more efficent since they are not copied
        firstName = fN;
    }

    void setLastName(const string &lN) {
        lastName = lN;
    }

    void setDistrictCode(const char &dC) {
        districtCode = dC;
    }

    void setCurrentCredits(int cC) {
        currentCredits = cC;
    }
};

#endif