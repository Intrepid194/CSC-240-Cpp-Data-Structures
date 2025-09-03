#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "objbooks.h"
#include "Node.h"
using namespace std;
// function prototype
void DisplayBooks(Node* head);

int main() {
    // here we are maintaining pointer to head (front of the list)
    // and a pointer to the back (last node of the list). 
    // the list starts out empty meaning head and tail are both NULL
    Node* head = nullptr;
    Node* tail = nullptr;

    ifstream file("books.txt");
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string title, author, pagesStr, priceStr;

        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, pagesStr, ',');
        getline(ss, priceStr, ',');

        // load the object with data
        objBook b;
        b.setTitle(title);
        b.setAuthor(author);
        b.setPages(stoi(pagesStr));
        b.setPrice(stod(priceStr));

        // allocated a new node and check for an empty list
        // consider empty lists as a special case
        Node* newNode = new Node(b);  //newNode is the newly created node to add to the list
        if (!head) {
            head = tail = newNode;  // empty list the first add has head and tail pointing to the same node
        }
        else {
            tail->next = newNode;  // tail's next (not tail) points to the new node
            tail = newNode;        // tail must be updated to point to the new node
        }
    }

    file.close();
    DisplayBooks(head);

    // free up memory before ending
    // c++ implementation will not automatically free memory when the program ends
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

void DisplayBooks(Node* head) {
    cout << "\nBook List - Linked List Version" << endl << endl;

    Node* current = head;
    while (current)   // while (current not equal to nullptr) or not at end of the list
                      // current pointer will "visit" each node    
    {
        cout << "Title:        " << current->data.getTitle() << endl;
        cout << "Author:       " << current->data.getAuthor() << endl;
        cout << "Pages:        " << current->data.getPages() << endl;
        cout << "Price:       $" << current->data.getPrice() << endl;
        cout << endl;
        current = current->next; // advance the current pointer
    }
}