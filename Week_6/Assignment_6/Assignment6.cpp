/*****************************************************
// Author: Spencer Collins
// Date : 9/22/2025 
// This is the implementation file for Problem 1 Assignment 6.
//***************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Employee {
    string firstName;
    string lastName;
    string department;
    float salary;
};

class EmployeeStack {
    private:
        Employee employeeStack[25];
        int length;

    public:

        EmployeeStack() {
            int length = 0;
        }

        bool push(Employee& newEmployee) {
            employeeStack[length] = newEmployee;
            length++;
            return 1;
        }

        bool pop() {
            if (length > 0) {
                length--;
                return 1;
            }
            return 0;
        }

        void display() {
            for (int i = 0; i <length; i++) {
                cout << "<---Employee No. " << i+1 << "--->" << endl;
                cout << "First name: " << employeeStack[i].firstName << endl;
                cout << "Last name:" << employeeStack[i].lastName << endl;
                cout << "Department:" << employeeStack[i].department << endl;
                cout << "Salary: " << employeeStack[i].salary << endl << endl;
            }
        }

        bool isFull() {
            return (length == 25) ? 1 : 0;
        }

        bool isEmpty() {
            return (length > 0) ? 0 : 1;
        }

        void modifyEmployee(const string& lastName, const string& newDept, const string& newSalStr) {
            for (int i = length - 1; i >= 0; i--) {
                if (employeeStack[i].lastName == lastName) {
                    employeeStack[i].department = newDept;
                    float newSalary = stof(newSalStr);
                    employeeStack[i].salary = newSalary;
                    break;
                }
            }
            cout << "Employee with last name of " << lastName << "was not found in the stack." << endl;
        }

        bool searchByLastName(const string& lastName) {
            for (int i = 0; i < length; i++) {
                if (employeeStack[i].lastName == lastName) {
                    cout << "<---Employee No. " << i+1 << "--->" << endl;
                    cout << "First name: " << employeeStack[i].firstName << endl;
                    cout << "Last name:" << employeeStack[i].lastName << endl;
                    cout << "Department:" << employeeStack[i].department << endl;
                    cout << "Salary: " << employeeStack[i].salary << endl;
                    return 1;
                } 
            }
            cout << "Employee with last name of " << lastName << " was not found in the stack." << endl;
            return 0;
        }

};

int main() {

    ifstream inputFile("Empldat.txt");
    if (!inputFile) {
        cerr << "Error opening or reading file." << endl;
        return 1;
    }

    string line;
    EmployeeStack employeeStack;

    while(getline(inputFile, line)) {
        string firstName, lastName, department, salaryStr;
        stringstream ss(line);
        
        Employee newEmployee;

        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, department, ',');
        getline(ss, salaryStr, ',');

        float salary = stof(salaryStr);    

        newEmployee.firstName = firstName;
        newEmployee.lastName = lastName;
        newEmployee.department = department;
        newEmployee.salary = salary;

        employeeStack.push(newEmployee);
    }
    // employeeStack.isFull();
    // employeeStack.pop();
    employeeStack.modifyEmployee(" Taylor", "IT", "86000.00");
    employeeStack.searchByLastName(" Taylor");
    // employeeStack.display();
    return 0;
}