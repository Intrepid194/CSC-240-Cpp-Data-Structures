/*****************************************************
// Author: Spencer Collins
// Date : 10/31/2025 
// This is the implementation file for Problem 1 Assignment 10.
//***************************************************/


#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Recursive function to remove all occurrences of target
Node* removeAll(Node* head, int target) {
    if (head == nullptr) {
        return nullptr;
    }

    head->next = removeAll(head->next, target);
    cout << "head: " << head->data << endl;
    if (head->data == target) {
        Node* temp = head->next;

        delete head;
        return temp;
        
    } else {
        return head;
    }
}

// Recursive function to display list in reverse
void printReverse(Node* head) {
    // add code here
    Node* current = head;
    if (current != nullptr) {
        printReverse(current->next);
        cout << current->data << " ";
    }
}

// Insert at end (iterative)
void insertEnd(Node*& head, int val) {
    // add code here
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current) {
            if (current->next == nullptr) {
                current->next = newNode;
                break;
            }
            current = current->next;
        }
    }
}

// Display list (forward)
void printList(Node* head) {
    // add code here
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
}

// Free memory
void deleteList(Node*& head) {
   // add code here
    while (head) {
        Node* current = head;
        head = head->next;
        delete current;
    }
}

// Menu
void showMenu() {
    cout << "\n--- Linked List Menu ---\n";
    cout << "1. Insert value\n";
    cout << "2. Display list\n";
    cout << "3. Remove all occurrences (recursive)\n";
    cout << "4. Clear list\n";
    cout << "5. Display list in reverse (recursive)\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Node* head = nullptr;
    int choice = 0, val;

    while (choice != 6) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to insert: ";
            cin >> val;
            insertEnd(head, val);
        }
        else if (choice == 2) {
            cout << "Current list: ";
            printList(head);
        }
        else if (choice == 3) {
            cout << "Enter value to remove: ";
            cin >> val;
            head = removeAll(head, val);
            cout << "head: " << head->data << endl;
            cout << "Updated list: ";
            printList(head);
        }
        else if (choice == 4) {
            deleteList(head);
            cout << "List cleared.\n";
        }
        else if (choice == 5) {
            cout << "List in reverse: ";
            printReverse(head);
            cout << endl;
        }
        else if (choice == 6) {
            deleteList(head);
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
