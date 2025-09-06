/*****************************************************
// Author: Spencer Collins
// Date : 9/2/2025 
// This is the implementation file that defines the array of Student structs for Assignment 3.
//***************************************************/


#include <iostream>
#include <fstream>
#include <sstream>

#include "StudentStruct.h"

void displayStudents(const Student[], const int);

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

        for (int i = 0; i<line.length(); i++) {
            if (line[i] == delim) delimCount++;
            if (line[i] == ' ') spaceCount++;

            if (spaceCount == 0 && line[i] != ' ') students[lineNum].firstName += line[i];
            if (spaceCount == 1 && line[i] != ' ' && delimCount == 0) students[lineNum].lastName += line[i];

            if (delimCount == 1 && line[i] != delim) students[lineNum].districtCode = line[i];
            if (delimCount == 2 && line[i] != delim) temp += line[i];

        }
        tempFlt = stof(temp);
        students[lineNum].currentCredits = tempFlt;
        
        students[lineNum].tuitionOwed = students[lineNum].calcTuition();

        lineNum++;
    }

    displayStudents(students, arrSize);

    readFile.close();

    return 0;
}

/*

*/
void displayStudents(const Student students[], const int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << "First Name: " << students[i].firstName << endl;
        cout << "Last Name: " <<students[i].lastName << endl;
        cout << "District Code: " <<students[i].districtCode << endl;
        cout << "Current Credits: " <<students[i].currentCredits << endl;
        cout << "Tutition Owed: " << students[i].tuitionOwed << endl;
    }
}