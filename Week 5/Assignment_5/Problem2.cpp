/*****************************************************
// Author: Spencer Collins
// Date : 9/15/2025 
//
//***************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Employee {
    string firstName;
    string lastName;
    string department;
    float salary;
};

class Node {
    public:
        Employee employee;
        Node* next;

    Node(Employee& employee) {
        this->employee = employee;
        next = nullptr;
    }
};

class LinkedList: public Node {
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList(Employee& employee) {
            Node* newNode = new Node(employee);
            head = newNode;
            tail = newNode;
        }

        ~LinkedList() {
            Node*temp = head;
            while (head !=nullptr) {
                head = head->next;
                delete temp;
                temp = temp->next;
            }
        }

        void append(Employee& employee) {
            Node* newNode = new Node(employee);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void prepend(Employee& employee) {
            Node* newNode = new Node(employee);
            if (head ==nullptr) {
                head = newNode;
                tail = newNode;
            }
            newNode->next = head;
            head = newNode;
        }

    void insert(Node& node) {

    }
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    ifstream readFile("Empldat.txt");

    if(!readFile) {
        cerr << "File could not be opened or read." << endl;
    }


    return 0;
}
