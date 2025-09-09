/*****************************************************
// Author: Spencer Collins
// Date : 9/8/2025 
// This is the implementation file that defines the Linked List for the Student class for Assignment 4.
//***************************************************/

#include <iostream>
#include <fstream>
#include <sstream>

#include "Node.h"
#include "StudentObj.h"

//function prototype for displaying Students
void displayStudents(Node* head);

bool SequentialSearch(
    Node* head,
    const string& firstName = "",
    const string& lastName = "",
    char districtCode = '\0',
    float currentCredits = -1.0,
    float tuitionOwed = -1.0
);

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

    // Sequential Search using a Linked List
    bool result1 = SequentialSearch(head, "", "", '\0', -1.0, -1.0);
    cout << "result for ("", "", 'O', -1.0, -1.0) is: " << result1 << endl;
    
    bool result2 = SequentialSearch(head, "Everett", "", 'I', -1.0, -1.0);
    cout << "result for ('Everett', "", 'O', -1.0, -1.0) is: " << result2 << endl;

    bool result3 = SequentialSearch(head, "Miles", "Reed", 'O', -1.0, -1.0);
    cout << "result for ('Miles', 'Reed', 'O', -1.0, -1.0) is: " << result3 << endl;

    bool result4 = SequentialSearch(head, "", "", 'O', 468.0, -1.0);
    cout << "result for ("", "", 'O', 468.0, -1.0) is: " << result4 << endl;

    bool result5 = SequentialSearch(head, "Noah", "King", 'I', 14, 3500.0);
    cout << "result for ('Noah', 'King', 'I', 14, 3500.0) is: " << result5 << endl;

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
        cout << "Tuition Owed: " << current->data.getTuitionOwed() << endl;
        cout << endl;
        current = current->next; //advnace the current pointer to the next pointer
    }
    
}

/*
Implements a sequential search on the Linked List starting from the head using various search filters that stack.

Parameters:
-----------
head : `Node*`
    Start of the Linked List to search in.
firstName : `const string&`
    Search for a student by their first name.
lastName : `const string&`
    Search for a student by their last name.
districtCode : `char`
    Search by the districtCode for a student.
currentCredits : `float`
    Search by the amount of currentCredits a student currently has.
tuitionOwed : `float`
    Search by the tuitionOwed by a student.

Returns:
--------
`bool`
    1 if the student exists in the Linked List, otherwise 0.

*/
bool SequentialSearch(
    Node* head,
    const string& firstName,
    const string& lastName,
    char districtCode,
    float currentCredits,
    float tuitionOwed
) {
    int conditionCt = 0; //set current number of search conditions to 0

    //for each function argument that is not a default value, add to the number of search conditions to apply
    if (firstName != "") conditionCt++;
    if (lastName != "") conditionCt++;
    if (districtCode != '\0') conditionCt++;
    if (currentCredits != -1.0) conditionCt++;
    if (tuitionOwed != -1.0) conditionCt++;


    Node* current = head;

    while (current) {
        int searchCt = 0; //set number of conditions that current student meets to 0.

        //for each search condition that a student meets, increment the searchCt.
        if (current->data.getFirstName() == firstName) searchCt++;
        if (current->data.getLastName() == lastName) searchCt++;
        if (current->data.getDistrictCode() == districtCode) searchCt++;
        if (current->data.getCurrentCredits() == currentCredits) searchCt++;
        if (current->data.getTuitionOwed() == tuitionOwed) searchCt++;

        if (searchCt == conditionCt) return 1; //if the number of search conditions met == the number of search conditions applied, student exists

        current = current->next;
    }
    return 0; // default return is student does not exist
}