#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure for each person
struct Person {
    string lastName;
    int age;
    Person* next;
};

// Function to create a new node
Person* createNode(const string& name, int age) {
    Person* newNode = new Person;
    newNode->lastName = name;
    newNode->age = age;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert node in alphabetical order by last name
void insertAlphabetically(Person*& head, Person* newNode) {
    // Case 1: Empty list or new node goes before head
    if (!head || newNode->lastName < head->lastName) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Find correct position
    Person* current = head;
    while (current->next && current->next->lastName < newNode->lastName) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the list
void printList(const Person* head) {
    cout << "Sorted List by Last Name:\n";
    while (head) {
        cout << head->lastName << " - " << head->age << endl;
        head = head->next;
    }
}

// Function to free memory
void deleteList(Person*& head) {
    while (head) {
        Person* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ifstream inputFile("olist.txt");
    if (!inputFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    Person* head = nullptr;
    string name;
    int age;

    // Read and insert each person into the list in order
    while (inputFile >> name >> age) {
        Person* newNode = createNode(name, age);
        insertAlphabetically(head, newNode);
    }

    inputFile.close();

    printList(head);
    deleteList(head);

    return 0;
}