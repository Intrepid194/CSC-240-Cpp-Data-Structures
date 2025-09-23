// /*****************************************************
// Author: Spencer Collins
// Date : 9/15/2025 
// This is the implementation file for Problem 2 Assignment 5.
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
    Employee* next;
};

// Function to create a new node
Employee* createNode(const string& firstName, const string& lastName, const string& department, float salary) {
    Employee* newNode = new Employee;
    newNode->lastName = lastName;
    newNode->firstName = firstName;
    newNode->department = department;
    newNode->salary = salary;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert node in alphabetical order by last name
void insertAlphabetically(Employee*& head, Employee* newNode) {
    // Case 1: Empty list or new node goes before head
    if (!head || newNode->lastName < head->lastName) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Find correct position
    Employee* current = head;
    while (current->next && current->next->lastName < newNode->lastName) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the list
void printList(const Employee* head) {
    cout << "Sorted List by Last Name:\n";
    while (head) {
        cout << head->firstName << " - " << head->lastName << " - " << head->department << " - " << head->salary << " - " << endl;
        head = head->next;
    }
}

// Function to free memory
void deleteList(Employee*& head) {
    while (head) {
        Employee* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {

    //read employee input file
    ifstream inputFile("Empldat.txt");
    if (!inputFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    string line;
    Employee* head = nullptr;
    int age;


    //read each line in the file
    while(getline(inputFile, line)) {
        string firstName, lastName, dept, salaryStr;
        stringstream ss(line);

        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, dept, ',');
        getline(ss, salaryStr, ',');

        float salary = stof(salaryStr);

        //create new node for each employee and and insert alphabetically
        Employee* newNode = createNode(firstName, lastName, dept, salary);
        insertAlphabetically(head, newNode);
    }


    inputFile.close();

    printList(head);
    deleteList(head);

    return 0;
}





