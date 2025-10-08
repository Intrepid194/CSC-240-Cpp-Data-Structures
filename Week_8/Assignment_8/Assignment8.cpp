/*****************************************************
// Author: Spencer Collins
// Date : 10/7/2025 
// This is the implementation file for Problem 1 Assignment 8.
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
        Node* prev;

        Node (Employee& employee) {
            this->employee = employee;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class EmployeeDblLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:

        EmployeeDblLinkedList() {
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        EmployeeDblLinkedList(Employee& employee) {
            Node* newNode = new Node(employee);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        /*
        Displays all employees in the DLL.

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `void`

        */
        void print() {
            if (length == 0) {
                cout << "DLL is empty" << endl << endl;
                return;
            }
            Node* current = head;
            int i = 1;
            while (current) {
                cout << "<---Employee No. " << i << "--->" << endl;
                cout << "First Name: " << current->employee.firstName << endl;
                cout << "Last Name: " << current->employee.lastName << endl;
                cout << "Department: " << current->employee.department << endl;
                cout << "Salary: " << current->employee.salary << endl;
                i++;
                current = current->next;
            }
            return;
        }
        
        /*
        Displays all employees in the DLL in reverse order.

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `void`

        */
        void reversePrint() {
            if (length == 0) {
                cout << "DLL is empty" << endl << endl;
                return;
            }
            Node* current = tail;
            int i = length;
            while (current) {
                cout << "<---Employee No. " << i << "--->" << endl;
                cout << "First Name: " << current->employee.firstName << endl;
                cout << "Last Name: " << current->employee.lastName << endl;
                cout << "Department: " << current->employee.department << endl;
                cout << "Salary: " << current->employee.salary << endl;
                i--;
                current = current->prev;
            }
        }

        /*
        Appends the new employee to the back of the DLL.

        Parameters:
        -----------
        newEmployee : `Employee&`
            Employee object to be appended to the DLL.

        Returns:
        --------
        `void`

        */
        void addEmployee(Employee newEmployee) {
            Node* newNode = new Node(newEmployee);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
            return;
        }

        /*
        Removes the employee by last name from the DLL.

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `void`

        */
        void deleteEmployee(const string& lastName) {
            if (head == nullptr) {
                cout << "DLL is empty" << endl << endl;
                return;
            } else {
                Node* current = head;

                while(current) {
                    if(current->employee.lastName == lastName) {
                        
                        if (current == head) {
                            head = current->next;
                        } else if (current == tail) {
                            tail = current->prev;
                        } else {
                            current->prev->next = current->next;
                            current->next->prev = current->prev;
                        }
                        
                        delete current;

                        length--;
                        cout << "Employee with last name of " << lastName << " was successfully deleted." << endl;
                        return;

                    }
                    current = current->next;
                }
                cout << "Employee with last name " << lastName << " could not be found and cannot be deleted." << endl;
                return;
            }
        }

        /*
        Checks if the DLL is empty or not.

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `int`
            0 if empty, length if not empty.
        */
        int isEmpty() {
            return (length == 0) ? 0 : length;
        }

        /*
        Checks if the DLL is full or not.

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `bool`
            1 if full, 0 if not full.
        */
        bool isFull() {
            return (length >= 10) ? 1 : 0;
        }

        /*
        Modifies an existing employee in the DLL by last name.

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
        `void`

        */
        void modifyEmployee(const string& lastName, const string& newDept, float newSalary) {
            Node* current = head;
            while (current) {
                if(current->employee.lastName == lastName) {
                    current->employee.department = newDept;
                    current->employee.salary = newSalary;
                    return;
                }
                current = current->next;
            }
        }

        /*
        Searches for an employee by last name in the DLL.

        Parameters:
        -----------
        lastName : `const string&`
            Employee's last name.

        Returns:
        --------
        `void`

        */
        void searchByLastName(const string& lastName) {
            Node* current = head;
            int i = 1;
            while (current) {
                if(current->employee.lastName == lastName) {
                    cout << "<---Employee No. " << i << "--->" << endl;
                    cout << "First Name: " << current->employee.firstName << endl;
                    cout << "Last Name: " << current->employee.lastName << endl;
                    cout << "Department: " << current->employee.department << endl;
                    cout << "Salary: " << current->employee.salary << endl;
                    return;
                }
                i++;
                current = current->next;
            }
            cout << "Employee with last name " << lastName << "was not found." << endl;
            return;
        }
        
        /*
        Reads employee data from a file and adds it to the DLL.

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

                this->addEmployee(newEmployee);
            }
        }

        /*
        Gets the length of the DLL.

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `void`

        */
        void getLength() {
            cout << "Length: " << length << endl;
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
            //reset the DLL to 0
            this->emptyDLL();

            //display the DLL
            this->print();

            //add a new employee
            Employee newEmployee = {"Test First Name", "Test Last Name", "Test Department", 100000.0};
            this->addEmployee(newEmployee);

            //display the DLL
            this->print();

            //test case for no employee found
            this->searchByLastName("Not found");

            //modify the employee by last name
            this->modifyEmployee("Test Last Name", "New Test Department", 200000.0);

            //display the modified employee
            this->print();

            // //pop the employee
            this->deleteEmployee("Test Last Name");

            //display the DLL
            this->print();

            //readfile test case
            this->readFile("Empldat.txt");
            
            //get length of the DLL
            this->getLength();
            
            //display the DLL
            this->print();

            //display the DLL in reverse
            this->reversePrint();

            //check if DLL is empty
            int empty = this->isEmpty();
            (empty == 0) ? cout << "DLL is empty" << endl : cout << "DLL length is " << empty << endl;

            //check if DLL is full
            int full = this->isFull();
            (full == 0) ? cout << "DLL is not full" << endl : cout << "DLL is full" << endl;

            //reset the DLL to 0
            this->emptyDLL();

            return;
        }
        
        /*
        Empties the DLL.

        Parameters:
        -----------
        `None`

        Returns:
        --------
        `void`

        */
        void emptyDLL() {
            if (head == nullptr) {
                cout << "DLL is empty" << endl << endl;
                return;
            } else {
                Node* current = head;

                while (current) {
                    Node* temp = current->next;
                    delete current;
                    current = temp;
                }
                head = nullptr;
                tail = nullptr;
            }
            this->length = 0;
            return;
        }


};


int main() {

    EmployeeDblLinkedList employeesDLL;

    //this is the interactive part of the program
    while (true) {

        string choice; 

        cout << "See the menu below for options on interacting with the Employee DLL: " << endl;

        cout << "0: Run Unit Tests\n";
        cout << "1: Add New Employee\n";
        cout << "2: Modify Existing Employee by Last Name\n";
        cout << "3: Search for Existing Employee by Last Name\n";
        cout << "4: Display All Employees\n";
        cout << "5: Delete Employee By Last Name\n";
        cout << "6: Read from txt File\n";
        cout << "7: Empty DLL\n";
        cout << "8: Get DLL length\n";
        cout << "9: Display Employees in Reverse Order\n";
        cout << "10: Exit Program\n";

        cin >> choice;
        cin.ignore();

        if (choice == "0") {

            employeesDLL.runUnitTests();
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
            
            employeesDLL.addEmployee(addEmployee);

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

            employeesDLL.modifyEmployee(lastName.s, department.s, salary);

            cout << "Employee was successfully modified!" << endl;
            employeesDLL.searchByLastName(lastName.s);
            cout << endl;

        } else if (choice == "3") {

            string lastName;
            cout << "Enter the Last Name of Employee you would like to search: " << endl;
            cin >> lastName;
            cin.ignore();

            employeesDLL.searchByLastName(lastName);

            cout << endl;

        } else if (choice == "4") {

            employeesDLL.print();
            cout << endl;

        } else if (choice == "5") {
            
            string lastName;
            cout << "Enter the Last Name of Employee you would like to delete: " << endl;
            cin >> lastName;
            cin.ignore();

            employeesDLL.deleteEmployee(lastName);

        } else if (choice == "6") {

            string fileName;
            cout << "Enter File Name: " << endl;
            cin >> fileName;
            cin.ignore();

            employeesDLL.readFile(fileName);

        } else if (choice == "7") {

            employeesDLL.emptyDLL();

        } else if (choice == "8") {

            employeesDLL.getLength();
            cout << endl;
        
        } else if (choice == "9") { 

            employeesDLL.reversePrint();
            cout << endl;

        } else if (choice == "10") {
            employeesDLL.emptyDLL();
            cout << "Exiting Program..." << endl;
            break;
        }
    }

    return 0;
};