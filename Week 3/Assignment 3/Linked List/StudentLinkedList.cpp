/*****************************************************
// Author: Spencer Collins
// Date : 9/5/2025 
// This is the implementation file that defines the Linked List for the Student class for Assignment 3.
//***************************************************/

#include <iostream>
#include <fstream>
#include <sstream>

#include "Node.h"
#include "StudentObj.h"

//function prototype for displaying Students
void displayStudents(Node* head);

int main() {

    ifstream readFile("Students.txt");

    if(!readFile) {
        cerr << "File could not be opened or read." << endl;
        return 1;
    }

    string line;

    // here we are maintaining pointer to head (front of the list)
    // and a pointer to the back (last node of the list). 
    // the list starts out empty meaning head and tail are both NULL
    Node* head = nullptr;
    Node* tail = nullptr;

    while(getline(readFile, line)) {
        string fullName, firstName, lastName, districtCode, currentCreditsStr;

        stringstream ss(line);

        getline(ss, fullName, ',');
        getline(ss, districtCode, ',');
        getline(ss, currentCreditsStr, ',');

        stringstream ss1(fullName);
        
        getline(ss1, firstName, ' ');
        getline(ss1, lastName, ' ');

        float currentCredits = stof(currentCreditsStr);

        //create new Student class to add the data to
        Student student;
        student.setFirstName(firstName);
        student.setLastName(lastName);
        student.setDistrictCode(districtCode[0]);
        student.setCurrentCredits(currentCredits);

        // allocated a new node and check for an empty list
        // consider empty lists as a special case
        Node* newNode = new Node(student); //newNode is the newly created node to add to the list
        if (!head) {
            head = newNode; // empty list the first add has head 
            tail = newNode; //and tail pointing to the same node
        } else {
            tail->next = newNode;
            tail = newNode;
        }


    }

    readFile.close();
    displayStudents(head);

    // free up memory before ending
    // c++ implementation will not automatically free memory when the program ends
    Node* current = head;
    while(current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}

void displayStudents(Node* head) {
     cout << "\nStudents List - Linked List Version" << endl << endl;

    Node* current = head;

    // while (current not equal to nullptr) or not at end of the list
    // current pointer will "visit" each node    
    while (current) {
        cout << "First Name: " << current->data.getFirstName() << endl;
        cout << "Last Name: " << current->data.getLastName() << endl;
        cout << "District Code: " << current->data.getDistrictCode() << endl;
        cout << "Current Credits: " << current->data.getCurrentCredits() << endl;
        cout << "Tuition Owed: " << current->data.getTutitionOwed() << endl;
        cout << endl;
        current = current->next; //advnace the current pointer to the next pointer
    }
    
}