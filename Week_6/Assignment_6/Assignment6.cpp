/*****************************************************
// Author: Spencer Collins
// Date : 9/26/2025 
// This is the implementation file for Problem 1 Assignment 6.
//***************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/*
StringWrapper class to add functionality to the string class
*/
class StringWrapper {
    public:
    string s;
        StringWrapper(const string& str = "") {
            s = str;
        }

        /*
        Removes the leading and trailign whitespaces from a string

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `None`

        */
        void removeWhiteSpace() {
            int start = 0;
            int end = s.length() - 1;

            //iterates through the string and gets the location of leading and trailing whitespaces, when both locations != " ", get the substring.
            for (int i = 0; i<s.length(); i++) {
                if (s[i] == ' ') {
                    start++;
                } else if (s[end - i] == ' ') {
                    end--;
                } else if (s[i] != ' ' && s[s.length() - i] != ' ') {
                    s = s.substr(start, end-start+1);
                    break;
                }
            }
        }
};

//Struct for storing employee record
struct Employee {
    string firstName;
    string lastName;
    string department;
    float salary;
};

//Class for creating and maintaining the stack of Employees
class EmployeeStack {
    private:
        Employee employeeStack[25];
        int length;

    public:

        EmployeeStack() {
            length = 0;
        }

        /*
        Removes the leading and trailign whitespaces from a string

        Parameters:
        -----------
        newEmployee : `Employee&`

        Returns:
        --------
        `bool`

        */
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
            if (length > 0) {
                for (int i = 0; i <length; i++) {
                    cout << "<---Employee No. " << i+1 << "--->" << endl;
                    cout << "First name: " << employeeStack[i].firstName << endl;
                    cout << "Last name: " << employeeStack[i].lastName << endl;
                    cout << "Department: " << employeeStack[i].department << endl;
                    cout << "Salary: " << employeeStack[i].salary << endl << endl;
                }
            } else {
                cout << "No Employees found in Stack!" << endl << endl;
            }
        }

        bool isFull() {
            return (length == 25) ? 1 : 0;
        }

        bool isEmpty() {
            return (length > 0) ? 0 : 1;
        }

        bool modifyEmployee(const string& lastName, const string& newDept, float newSalary) {
            for (int i = length - 1; i >= 0; i--) {
                if (employeeStack[i].lastName == lastName) {
                    employeeStack[i].department = newDept;
                    employeeStack[i].salary = newSalary;
                    return 1;
                }
            }
            cout << "Employee with last name of " << lastName << "was not found in the stack." << endl << endl;
            return 0;
        }

        bool searchByLastName(const string& lastName) {
            for (int i = 0; i < length; i++) {
                if (employeeStack[i].lastName == lastName) {
                    cout << "<---Employee No. " << i+1 << "--->" << endl;
                    cout << "First name: " << employeeStack[i].firstName << endl;
                    cout << "Last name: " << employeeStack[i].lastName << endl;
                    cout << "Department: " << employeeStack[i].department << endl;
                    cout << "Salary: " << employeeStack[i].salary << endl;
                    return 1;
                } 
            }
            cout << "Employee with last name of " << lastName << " was not found in the stack." << endl;
            return 0;
        }

        //Added methods for the interactive portion of the assignment
        bool restoreStack() {
            length = 0;
            return 1;
        }

        void runUnitTests() {
            //reset the stack to 0
            this->restoreStack();

            //display the stack
            this->display();

            //add a new employee
            Employee newEmployee = {"Test First Name", "Test Last Name", "Test Department", 100000.0};
            this->push(newEmployee);

            //display the stack
            this->display();

            //test case for no employee found
            this->searchByLastName("Not found");

            //modify the employee by last name
            this->modifyEmployee("Test Last Name", "New Test Department", 200000.0);

            //display the modified employee
            this->display();

            //pop the employee
            this->pop();

            //display the stack
            this->display();

            //readfile test case
            this->readFromFile("Empldat.txt");

            //display the stack
            this->display();

            //check if stack is empty
            int empty = this->isEmpty();
            (empty == 0) ? cout << "Stack is empty" << endl : cout << "Stack is not empty" << endl;

            //check if stack is full
            int full = this->isFull();
            (full == 0) ? cout << "Stack is not full" << endl : cout << "Stack is full" << endl;
        }

        void readFromFile(const string& fileName) {
            ifstream inputFile(fileName);
            if (!inputFile) {
                cerr << "Error opening or reading file." << endl;
                return;
            }

            string line;
            StringWrapper firstName, lastName, department, salaryStr;

            while(getline(inputFile, line)) {
                
                stringstream ss(line);
                
                Employee newEmployee;

                getline(ss, firstName.s, ',');
                getline(ss, lastName.s, ',');
                getline(ss, department.s, ',');
                getline(ss, salaryStr.s, ',');

                firstName.removeWhiteSpace();
                lastName.removeWhiteSpace();
                department.removeWhiteSpace();

                float salary = stof(salaryStr.s);    

                newEmployee.firstName = firstName.s;
                newEmployee.lastName = lastName.s;
                newEmployee.department = department.s;
                newEmployee.salary = salary;

                this->push(newEmployee);
            }
        }
};



int main() {
    EmployeeStack employeeStack;
    
    //this is the interactive part of the programs
    while (true) {

        string choice; 

        cout << "See the menu below for options on interacting with the Employee Stack: " << endl;

        cout << "0: Run Unit Tests\n";
        cout << "1: Add New Employee\n";
        cout << "2: Modify Existing Employee by Last Name\n";
        cout << "3: Search for Existing Employee by Last Name\n";
        cout << "4: Display All Employees\n";
        cout << "5: Pop First Employee\n";
        cout << "6: Read from txt File\n";
        cout << "7: Empty Stack\n";
        cout << "8: Exit Program\n";

        cin >> choice;
        cin.ignore();

        if (choice == "0") {
            employeeStack.runUnitTests();
        } else if (choice == "1") {

            StringWrapper firstName, lastName, department, salaryStr;
            cout << "Enter First Name: " << endl;
            cin >> firstName.s;
            cin.ignore();

            cout << "Enter Last Name: " << endl;
            cin >> lastName.s;
            cin.ignore();

            cout << "Enter Department: " << endl;
            cin >> department.s; 
            cin.ignore();

            cout << "Enter Salary: " << endl;
            cin >> salaryStr.s;
            cin.ignore();

            float salary = stof(salaryStr.s);

            Employee addEmployee;

            firstName.removeWhiteSpace();
            lastName.removeWhiteSpace();
            department.removeWhiteSpace();

            addEmployee.firstName = firstName.s;
            addEmployee.lastName = lastName.s;
            addEmployee.department = department.s;
            addEmployee.salary = salary;
            
            employeeStack.push(addEmployee);

            cout << "The following Employee was added: " << endl;
            cout << "First Name: " << firstName.s << endl;
            cout << "Last Name: " << lastName.s << endl;
            cout << "Department: " << department.s << endl;
            cout << "Salary: " << salary << endl;

        } else if (choice == "2") {

            StringWrapper lastName, department, salaryStr;

            cout << "Enter Last Name for Modifying Employee: " << endl;
            cin >> lastName.s;
            cin.ignore();   

            cout << "Enter New Department: " << endl;
            cin >> department.s;
            cin.ignore();

            cout << "Enter New Salary: " << endl;
            cin >> salaryStr.s;
            cin.ignore();

            lastName.removeWhiteSpace();
            department.removeWhiteSpace();
            float salary = stof(salaryStr.s);

            employeeStack.modifyEmployee(lastName.s, department.s, salary);

            cout << "Employee was successfully modified!" << endl;
            employeeStack.searchByLastName(lastName.s);
            cout << endl;

        } else if (choice == "3") {

            string lastName;
            cout << "Enter the Last Name of Employee you would like to search: " << endl;
            cin >> lastName;
            cin.ignore();

            employeeStack.searchByLastName(lastName);

            cout << endl;

        } else if (choice == "4") {

            employeeStack.display();
            cout << endl;

        } else if (choice == "5") {

            employeeStack.pop();
            cout << "Employee was successfully removed!" << endl << endl;

        } else if (choice == "6") {

            string fileName;
            cout << "Enter File Name: " << endl;
            cin >> fileName;
            cin.ignore();

            employeeStack.readFromFile(fileName);

        } else if (choice == "7") {

            employeeStack.restoreStack();

        } else if (choice == "8") {
            cout << "Exiting Program..." << endl;
            break;
        }
    }
    return 0;
}