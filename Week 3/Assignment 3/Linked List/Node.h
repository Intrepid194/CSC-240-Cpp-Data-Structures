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

struct Node {
    Student student;
    Node* next;

    Node(const Student& s) : student(s), next(nullptr) {}
};



#endif