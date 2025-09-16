#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

// Structure to hold person data
struct Person {
    string lastName;
    int age;
};

// Function to insert a person into the array in alphabetical order
void insertAlphabetically(Person arr[], int& size, const Person& newPerson) {
    int i = size - 1;

    // Shift elements to the right to make space for newPerson
    while (i >= 0 && arr[i].lastName > newPerson.lastName) {
        arr[i + 1] = arr[i];
        i--;
    }

    // Insert newPerson at the correct position
    arr[i + 1] = newPerson;
    size++;
}

// Function to print the array
void printArray(const Person arr[], int size) {
    cout << "Sorted List by Last Name:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i].lastName << " - " << arr[i].age << endl;
    }
}

int main() {
    ifstream inputFile("Olist.txt");
    if (!inputFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    Person people[MAX_SIZE];
    int size = 0;
    string name;
    int age;

    // Read and insert each person into the array in order
    while (inputFile >> name >> age && size < MAX_SIZE) {
        Person newPerson = { name, age };
        insertAlphabetically(people, size, newPerson);
    }

    inputFile.close();

    printArray(people, size);

    return 0;
}