/*****************************************************
// Author: Spencer Collins
// Date : 9/8/2025 
// This is the implementation file that defines the array of Student structs for Assignment 4.
//***************************************************/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <functional>
#include <vector>

#include "StudentStruct.h"

void displayStudents(const Student[], const int); //function prototype for displayStudents

bool SequentialSearch(
    const Student[], 
    const int,
    const string& firstName = "",
    const string& lastName = "",
    char districtCode = '\0',
    float currentCredits = -1.0,
    float tuitionOwed = -1.0
);

const int arrSize = 10;
Student students[arrSize];

int main() {
   
    string line;


    ifstream readFile("Students.txt");

    if (!readFile) {
        cerr<< "File could not be opened." << endl;
        return 1;
    }

    char delim = ',';
    int lineNum = 0;

    while (getline(readFile, line)){

        float tempFlt = 0.0;
        
        int delimCount = 0;
        int spaceCount = 0;
        string temp = "";

        //check for delimiter in each .txt file line that is read
        for (int i = 0; i<line.length(); i++) {
            if (line[i] == delim) delimCount++; //',' counter
            if (line[i] == ' ') spaceCount++; // ' ' counter

            if (spaceCount == 0 && line[i] != ' ') students[lineNum].firstName += line[i]; //get first name
            if (spaceCount == 1 && line[i] != ' ' && delimCount == 0) students[lineNum].lastName += line[i]; //get last name

            if (delimCount == 1 && line[i] != delim) students[lineNum].districtCode = line[i]; //get district code
            if (delimCount == 2 && line[i] != delim) temp += line[i]; //get the currentCredits and store in temp string

        }
        tempFlt = stof(temp); //convert temp string to temp float
        students[lineNum].currentCredits = tempFlt; //set currentCredits to the temp float
        
        students[lineNum].tuitionOwed = students[lineNum].calcTuition(); //set tuitionOwed using calcTuition() method

        lineNum++;
    }

    displayStudents(students, arrSize); //display the students
    
    // Sequential Search using an array of Student Structs
    bool result1 = SequentialSearch(students, 10, "", "", '\0', -1.0, -1.0);
    cout << "result for ("", "", 'O', -1.0, -1.0) is: " << result1 << endl;
    
    bool result2 = SequentialSearch(students, 10, "Everett", "", 'I', -1.0, -1.0);
    cout << "result for ('Everett', "", 'O', -1.0, -1.0) is: " << result2 << endl;

    bool result3 = SequentialSearch(students, 10, "Miles", "Reed", 'O', -1.0, -1.0);
    cout << "result for ('Miles', 'Reed', 'O', -1.0, -1.0) is: " << result3 << endl;

    bool result4 = SequentialSearch(students, 10, "", "", 'O', 468.0, -1.0);
    cout << "result for ("", "", 'O', 468.0, -1.0) is: " << result4 << endl;

    bool result5 = SequentialSearch(students, 10, "Noah", "King", 'I', 14, 3500.0);
    cout << "result for ('Noah', 'King', 'I', 14, 3500.0) is: " << result5 << endl;

    readFile.close();

    return 0;
}

/*
Displays the students in the array of Student structs
*/
void displayStudents(const Student students[], const int arrSize) {
    cout << "\nStudents List - Linked List Version" << endl << endl;

    for (int i = 0; i < arrSize; i++) {
        cout << "First Name: " << students[i].firstName << endl;
        cout << "Last Name: " <<students[i].lastName << endl;
        cout << "District Code: " <<students[i].districtCode << endl;
        cout << "Current Credits: " <<students[i].currentCredits << endl;
        cout << "Tutition Owed: " << students[i].tuitionOwed << endl;
        cout << endl;
    }
}

/*
Implements a sequential search on the Array of Student structs starting from the head using various search filters that stack.

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
    1 if the student exists in the array of Student structs, otherwise 0.

*/
bool SequentialSearch(
    const Student students[], 
    const int arrSize, 
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


    for (int i = 0; i < arrSize; i++) {

        int searchCt = 0; //set number of conditions that current student meets to 0.

        //for each search condition that a student meets, increment the searchCt.
        if (students[i].firstName == firstName) searchCt++;
        if (students[i].lastName == lastName) searchCt++;
        if (students[i].districtCode == districtCode) searchCt++;
        if (students[i].currentCredits == currentCredits) searchCt++;
        if (students[i].tuitionOwed == tuitionOwed) searchCt++;

        if (searchCt == conditionCt) return 1; //if the number of search conditions met == the number of search conditions applied, student exists
    }
    return 0; // default return is student does not exist
}
