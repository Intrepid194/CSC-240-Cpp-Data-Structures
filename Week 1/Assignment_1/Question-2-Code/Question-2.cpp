/*****************************************************
// Author: Spencer Collins
// Date : 8/23/2025
// This program answers Question 2 for Assignment 1. 
// The 3 listed errors are commented above the line of code that is being corrected.
// ERROR 1 is commented twice since the "Increment()" function is defined twice
// in the program.
//***************************************************/
#include <iostream>

using namespace std;

// ERROR 1: The function return type must be changed to "int" from "void"
// to return an integer. "void" returns nothing from the function.
int Increment(int); 

int main()
{
  int count = 1;
  while(count < 10) {
    cout << " The number after " << count; /* Function Increment*/

    /* ERROR 2: "Increment" function must be assigned equal to 
    "count" to return the value to "count" */
    count = Increment(count); /*adds 1 to count*/

    cout << " is " << count << endl;
  }
  return 0;
}

/* ERROR 1: The function return type must be changed to "int" from "void"
to return an integer. "void" returns nothing from the function. */
int Increment (int nextNumber) 
// Increment the parameter by 1.
{
  nextNumber++;

  /* ERROR 3: "nextNumber" must be returned from the 
  "Increment" function in order for the "count" in "main()" 
  to increment properly. */
  return nextNumber; 
}
