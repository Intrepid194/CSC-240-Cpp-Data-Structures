/*****************************************************
// Author: Spencer Collins
// Date : 9/5/2025 
// This is the header file that defines the Student class and the Node struct for Assignment 3.
//***************************************************/

#ifndef NODE_H
#define NODE_H

#include <string>
#include "StudentObj.h"

using namespace std;

// Node contains data as defined by the object and a pointer
// This approach makes the code more re-usable as you can change the data object
// and the base operations of adding, deleting, etc will remain the same code. 

struct Node {
    Student data; //this the data based on the Student class
    Node* next; // pointer to next object or nullptr

    Node(const Student& s) : data(s), next(nullptr) {}
};



#endif