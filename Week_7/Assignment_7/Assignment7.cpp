/*****************************************************
// Author: Spencer Collins
// Date : 9/29/2025 
// This is the implementation file for Problem 1 Assignment 7.
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
        Removes the leading and trailign whitespaces from a string.

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

class Node {
    public:
        Employee employee;
        Node* next;

        Node(Employee employee) {
            this->employee = employee;
            this->next = nullptr;
            
        }
};

class EmployeeStack {
    private:
        int length;
        Node* top;
    public:

        EmployeeStack() {
            top = nullptr;
            length = 0;
        }

        EmployeeStack(Employee employee) {
            Node* newNode = new Node(employee);
            top = newNode;
            length = 1;
        }

        /*
        Adds the new employee to the top of the stack.

        Parameters:
        -----------
        newEmployee : `Employee&`
            Employee object to be added to the stack.

        Returns:
        --------
        `bool`
            Numerical value of 1.
        */
        void push(Employee employee) {
            Node* newNode = new Node(employee);
            newNode->next = top;
            top = newNode;
            length++;
        }

        /*
        Removes the most recent employee from the top of the stack.

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `bool`
            1 for success, 0 for failure.
        */
        void pop() {
            if (top == nullptr) {
                cout << "Stack is empty" << endl << endl;
                return;
            } else {
                Node* temp = top->next;
                top = temp;
                delete temp;
                length--;
                return;
            }
        }

        /*
        Displays all employees in the stack.

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `void`

        */
        void display() {
            if (length ==0) {
                cout << "Stack is empty" << endl << endl;
                return;
            }
            Node* current = top;
            int i = 0;
            while (current) {
                cout << "<---Employee No. " << length-i << "--->" << endl;
                cout << "First Name: " << current->employee.firstName << endl;
                cout << "Last Name: " << current->employee.lastName << endl;
                cout << "Department: " << current->employee.department << endl;
                cout << "Salary: " << current->employee.salary << endl;
                i++;
                current = current->next;
            }
        }

        /*
        Checks if the stack is full or not.

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `bool`
            1 if full, 0 if not full.
        */
        bool isFull() {
            return (length == 25) ? 1 : 0;
        }

        /*
        Checks if the stack is empty or not.

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `bool`
            1 if empty, 0 if not empty.
        */
        bool isEmpty() {
            return (length == 0) ? 1 : 0;
        }
        
        /*
        Modifies an existing employee in the stack by last name.

        Parameters:
        -----------
        lastName : `const string&`
            Employee's last name.
        firstName : `const string&`
            Employee's first name.
        newDept : `const string&`
            Employee's new department.
        newSalary : `float`
            Employee's new salary.                

        Returns:
        --------
        `bool`
            1 if modified, 0 if not modified.
        */
        void modifyEmployee(const string& lastName, const string& newDept, float newSalary) {
            Node* current = top;
            int i = 0;
            while (current) {
                if(current->employee.lastName == lastName) {
                    current->employee.department = newDept;
                    current->employee.salary = newSalary;
                    return;
                }
                i--;
                current = current->next;
            }
        }

        /*
        Searches for an employee by last name in the stack.

        Parameters:
        -----------
        lastName : `const string&`
            Employee's last name.

        Returns:
        --------
        `bool`
            1 if found, 0 if not found.
        */
        void searchByLastName(const string& lastName) {
            Node* current = top;
            int i = 0;
            while (current) {
                if(current->employee.lastName == lastName) {
                    cout << "<---Employee No. " << length-i << "--->" << endl;
                    cout << "First Name: " << current->employee.firstName << endl;
                    cout << "Last Name: " << current->employee.lastName << endl;
                    cout << "Department: " << current->employee.department << endl;
                    cout << "Salary: " << current->employee.salary << endl;
                    return;
                }
                i++;
                current = current->next;
            }
            return;
        }

        /*
        Empties the stack.

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `bool`
            Numerical value of 1.
        */
        void restoreStack() {
            Node* current = top;
            while (current) {
                this->pop();
                current = current->next;
            }
        }

        /*
        Runs unit tests on the class methods.

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `void`

        */
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
            this->readFile("Empldat.txt");
            
            //get legnth of the stack
            this->getLength();

            //display the stack
            this->display();

            //check if stack is empty
            int empty = this->isEmpty();
            (empty == 0) ? cout << "Stack is empty" << endl : cout << "Stack is not empty" << endl;

            //check if stack is full
            int full = this->isFull();
            (full == 0) ? cout << "Stack is not full" << endl : cout << "Stack is full" << endl;

            //reset the stack to 0
            this->restoreStack();
        }
        
        /*
        Reads employee data from a file and adds it to the stack.

        Parameters:
        -----------
        fileName : `const string&`
            Name of the file.

        Returns:
        --------
        `void`

        */
        void readFile(const string& fileName) {

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

        /*
        Reads employee data from a file and adds it to the stack.

        Parameters:
        -----------
        fileName : `const string&`
            Name of the file.

        Returns:
        --------
        `void`

        */
        void getLength() {
            cout << "Length: " << length << endl;
        }
};

int main() {
    EmployeeStack employeeStack;

    //this is the interactive part of the program
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
        cout << "8: Get Stack length\n";
        cout << "9: Exit Program\n";

        cin >> choice;
        cin.ignore();

        if (choice == "0") {

            employeeStack.runUnitTests();
            cout << endl;

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

            employeeStack.readFile(fileName);

        } else if (choice == "7") {

            employeeStack.restoreStack();

        } else if (choice == "8") {

            employeeStack.getLength();
            cout << endl;

        } else if (choice == "9") {
            employeeStack.restoreStack();
            cout << "Exiting Program..." << endl;
            break;
        }
    }
    return 0;
};