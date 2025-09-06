/*****************************************************
// Author: Spencer Collins
// Date : 9/5/2025 
// This is the implementation file that defines the array of Student structs for Assignment 3.
//***************************************************/

#include <iostream>
#include <fstream>
#include <sstream>

#include "Node.h"
#include "StudentObj.h"

void displayStudents(Node* head);

int main() {

    ifstream readFile("Students.txt");

    if(!readFile) {
        cerr << "File could not be opened or read." << endl;
        return 1;
    }

    string line;

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

        Student student;
        student.setFirstName(firstName);
        student.setLastName(lastName);
        student.setDistrictCode(districtCode[0]);
        student.setCurrentCredits(currentCredits);

        // cout << student.getFirstName() << endl;
        Node* newNode = new Node(student);
        if (!head) {
            head = newNode = tail;
        } else {
            tail->next = newNode;
            tail = newNode;
        }


    }

    readFile.close();
    displayStudents(head);

    Node* current = head;
    while(current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}

void displayStudents(Node* head) {

    Node* current = head;

    while(current) {
        cout << "First Name: " << current->student.getFirstName() << endl;
        // cout << "Last Name: " << current->student.getFirstName() << endl;
        // cout << "District Code: " << current->student.getDistrictCode() << endl;
        // cout << "Current Credits: " << current->student.getCurrentCredits() << endl;
        // cout << "Tuition Owed: " << current->student.getTutitionOwed() << endl;
        cout << endl;
    }
    current = current->next;
}