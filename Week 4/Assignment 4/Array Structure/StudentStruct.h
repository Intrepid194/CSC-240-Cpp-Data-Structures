/*****************************************************
// Author: Spencer Collins
// Date : 9/8/2025 
// This is the header file that defines the Student struct for Assignment 4.
//***************************************************/

#ifndef STUD_H
#define STUD_H

#include <string>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    char districtCode;
    float currentCredits;
    float tuitionOwed;

    float calcTuition() {
        if (districtCode == 'I') return 250.0*currentCredits;
        if (districtCode == 'O') return 500.0*currentCredits;
        else return 0.0;
    }
};

#endif