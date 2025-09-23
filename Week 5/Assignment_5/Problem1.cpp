/*****************************************************
// Author: Spencer Collins
// Date : 9/15/2025 
// This is the implementation file for Problem 1 Assignment 5.
//***************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int arrSize = 25;

struct Employee {
    string firstName;
    string lastName;
    string department;
    float salary;
};

//displays all the employees in the array
void displayEmployees(Employee Employees[], int size) {
    for (int i = 0; i < 10; i++) {
        cout << Employees[i].firstName << " -" << Employees[i].lastName << " -" << Employees[i].department << " - " << Employees[i].salary << endl;
    }
}



int main() {
    Employee Employees[arrSize];

    //read the employee file
    ifstream readFile("Empldat.txt");

    if(!readFile) {
        cerr << "File could not be opened or read." << endl;
    }

    string line;
    int lineNum = 0;

    //read each line in the file
    while (getline(readFile, line)) {
        string firstName, lastName, dept, salaryStr;
        stringstream ss(line);

        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, dept, ',');
        getline(ss, salaryStr, ',');

        //make new employee
        Employee newEmployee;
        newEmployee.firstName = firstName;
        newEmployee.lastName = lastName;
        newEmployee.department = dept;
        newEmployee.salary = stof(salaryStr);

        int i = lineNum - 1;

        // add employee alphabetically
        while (i >= 0 && Employees[i].lastName > newEmployee.lastName) {
            Employees[i + 1] = Employees[i];
            i--;
        }

        Employees[i + 1] = newEmployee;

        lineNum++;    
    }

    displayEmployees(Employees, lineNum);

    return 0;
}

