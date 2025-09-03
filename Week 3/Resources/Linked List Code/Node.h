#ifndef NODE_H
#define NODE_H

#include "objbooks.h"

// Node contains data as defined by the object and a pointer
// This approach makes the code more re-usable as you can change the data object
// and the base operations of adding, deleting, etc will remain the same code. 

struct Node {
    objBook data;  // this is the based on the objBooks class
    Node* next;    // pointer to next object or nullptr

    Node(const objBook& b) : data(b), next(nullptr) {}
};

#endif
