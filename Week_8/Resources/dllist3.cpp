#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct CityNode {
    string name;
    int population;
    CityNode* prev;
    CityNode* next;
    CityNode(string n, int p) : name(n), population(p), prev(nullptr), next(nullptr) {}
};

// Print forward
void printList(CityNode* head) {
    cout << "\nCity List (Forward):\n";
    while (head) {
        cout << head->name << " - " << head->population << endl;
        head = head->next;
    }
}

// Print backward
void printReverse(CityNode* tail) {
    cout << "\nCity List (Reverse):\n";
    while (tail) {
        cout << tail->name << " - " << tail->population << endl;
        tail = tail->prev;
    }
}

// Load from CSV
void loadFromCSV(const string& filename, CityNode*& head, CityNode*& tail) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file.\n";
        return;
    }

    string line;
    head = tail = nullptr;

    while (getline(file, line)) {
        stringstream ss(line);
        string city, popStr;
        if (!getline(ss, city, ',')) continue;
        if (!getline(ss, popStr)) continue;

        int pop = stoi(popStr);
        CityNode* newNode = new CityNode(city, pop);

        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    file.close();
}

// Add city
void addCity(CityNode*& head, CityNode*& tail) {
    string name, popStr;
    int population;

    cin.ignore();
    cout << "Enter city name: ";
    getline(cin, name);
    cout << "Enter population: ";
    getline(cin, popStr);
    population = stoi(popStr);

    CityNode* newNode = new CityNode(name, population);
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Delete city
void deleteCity(CityNode*& head, CityNode*& tail) {
    string name;
    cin.ignore();
    cout << "Enter city name to delete: ";
    getline(cin, name);

    CityNode* current = head;
    while (current) {
        if (current->name == name) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == head) head = current->next;
            if (current == tail) tail = current->prev;
            delete current;
            cout << "City deleted.\n";
            return;
        }
        current = current->next;
    }
    cout << "City not found.\n";
}

// Menu
void menu(CityNode*& head, CityNode*& tail) {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Display cities\n";
        cout << "2. Display cities in reverse\n";
        cout << "3. Add city\n";
        cout << "4. Delete city\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            printList(head);
        }
        else if (choice == 2) {
            printReverse(tail);
        }
        else if (choice == 3) {
            addCity(head, tail);
        }
        else if (choice == 4) {
            deleteCity(head, tail);
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

int main() {
    string filename = "citydat.txt";
    CityNode* head = nullptr;
    CityNode* tail = nullptr;
    loadFromCSV(filename, head, tail);
    menu(head, tail);
    return 0;
}
