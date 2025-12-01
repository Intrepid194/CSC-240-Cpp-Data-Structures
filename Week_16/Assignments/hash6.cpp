/*****************************************************
// Author: Spencer Collins
// Date : 11/30/2025 
// This is the implementation file for Problem 1 Assignment 16.
//***************************************************/
// interactive phone book
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>
using namespace std;

// -----------------------------
// Hash Table with Chaining
// -----------------------------
class PhoneBook {
private:
    int tableSize;
    vector<list<pair<string, string>>> table;
    int collisions;

    int hashFunction(const string& key) const {
        std::hash<string> str_hash;
        
        // add code here to calculate and the hash key
        size_t hashValue = str_hash(key);

        return hashValue % table.size();
    }

public:
    PhoneBook(int size = 10) : tableSize(size), collisions(0) {
        table.resize(tableSize);
    }

    void insert(const string& name, const string& phone) {
        int index = hashFunction(name);

        // add code
        // 1. use has to the get the place in the table (vector<list<pair<string,string>>>)
        auto& currentItem = table[index]; 

        // 2. check each entry in the chain (at the hash) - use range based for loop
        // 3. If name exists, update the phone and then return
        for (auto& element : currentItem) {
            if (name == element.first) {
                element.second = phone;
                return;
            }
        }
        // end of code

        // add code
        // 1. check if position is not empty - collision occurred
        // 2. if collision update the collision counter
        // 3. add name and phone to the table (chain) using pushback (actually is a doubly linked list)
        if (currentItem.size() != 0) {
            collisions++;           
        }

        currentItem.push_back({name, phone});
    }

    string search(const string& name) const {
        int index = hashFunction(name);
        for (auto& entry : table[index]) {
            if (entry.first == name) {
                return entry.second;
            }
        }
        return "Not found";
    }

    void remove(const string& name) {
        // deletion function
        int index = hashFunction(name);
        // find the bucket
        auto& bucket = table[index];

        // add code
        // 1. loop through each element in the hashed locations list
        // 2. if the current name matches the one to delete, remove it bucket.erase(it)
        // 3. return
        auto it = bucket.begin();
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (name == it->first) {
                bucket.erase(it);
                return;
            };
        }

        return;
        // end of code
    }

    void display() const {
        cout << "\n--- Phone Book Contents ---\n";
        for (int i = 0; i < tableSize; i++) {
            cout << i << ": ";
            for (auto& entry : table[i]) {
                cout << "[" << entry.first << " -> " << entry.second << "] ";
            }
            cout << endl;
        }
    }

    void reportStats() const {
        cout << "\n--- Performance Report ---\n";
        cout << "Table size: " << tableSize << endl;
        cout << "Collisions: " << collisions << endl;
    }
};

// -----------------------------
// Menu Function
// -----------------------------
void printMenu() {
    cout << "\n--- Phone Book Menu ---\n";
    cout << "1. Add/Update Contact\n";
    cout << "2. Find Contact\n";
    cout << "3. Delete Contact\n";
    cout << "4. Display Phone Book\n";
    cout << "5. Report Stats\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}

// -----------------------------
// Main Program
// -----------------------------
int main() {
    PhoneBook pb(7); // small size to force collisions
    int choice = -1;
    string name, phone;

    while (choice != 0) {
        printMenu();
        cin >> choice;

        if (choice == 1) {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phone;
            pb.insert(name, phone);
            cout << "Contact added/updated.\n";
        }
        else if (choice == 2) {
            cout << "Enter name to search: ";
            cin >> name;
            cout << "Result: " << pb.search(name) << endl;
        }
        else if (choice == 3) {
            cout << "Enter name to delete: ";
            cin >> name;
            pb.remove(name);
            cout << "Contact deleted (if it existed).\n";
        }
        else if (choice == 4) {
            pb.display();
        }
        else if (choice == 5) {
            pb.reportStats();
        }
        else if (choice == 0) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}





