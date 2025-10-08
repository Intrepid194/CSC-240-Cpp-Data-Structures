#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int MAX_CITIES = 10;

struct CityNode {
    string name;
    int population;
    CityNode* prev;
    CityNode* next;
    CityNode(string n, int p) : name(n), population(p), prev(nullptr), next(nullptr) {}
};

// Count cities
int countCities(CityNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

bool isFull(CityNode* head) {
    return countCities(head) >= MAX_CITIES;
}

int isEmpty(CityNode* head) {
    return countCities(head); // returns number of active nodes
}

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
    if (isFull(head)) {
        cout << "List is full. Cannot add more cities.\n";
        return;
    }

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

// Search city
void searchCity(CityNode* head) {
    string name;
    cin.ignore();
    cout << "Enter city name to search: ";
    getline(cin, name);

    while (head) {
        if (head->name == name) {
            cout << "Found: " << head->name << " - " << head->population << endl;
            return;
        }
        head = head->next;
    }
    cout << "City not found.\n";
}

// Modify city
void modifyCity(CityNode* head) {
    string name;
    cin.ignore();
    cout << "Enter city name to modify: ";
    getline(cin, name);

    while (head) {
        if (head->name == name) {
            string newName, popStr;
            int newPop;
            cout << "Enter new city name: ";
            getline(cin, newName);
            cout << "Enter new population: ";
            getline(cin, popStr);
            newPop = stoi(popStr);
            head->name = newName;
            head->population = newPop;
            cout << "City updated.\n";
            return;
        }
        head = head->next;
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
        cout << "5. Search city\n";
        cout << "6. Modify city\n";
        cout << "7. Check if list is full\n";
        cout << "8. Check active city count (isEmpty)\n";
        cout << "9. Exit\n";
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
            searchCity(head);
        }
        else if (choice == 6) {
            modifyCity(head);
        }
        else if (choice == 7) {
            int remaining = MAX_CITIES - countCities(head);
            cout << (isFull(head) ? "List is full.\n" : "List is not full. Remaining slots: " + to_string(remaining) + "\n");
        }
        else if (choice == 8) {
            int active = isEmpty(head);
            cout << (active == 0 ? "List is empty.\n" : "Active cities: " + to_string(active) + "\n");
        }
        else if (choice == 9) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice.\n";
        }
    } while (choice != 9);
}

int main() {
    string filename = "citydat.txt";
    CityNode* head = nullptr;
    CityNode* tail = nullptr;
    loadFromCSV(filename, head, tail);
    menu(head, tail);
    return 0;
}
