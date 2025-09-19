#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


struct Employee {
    string firstName;
    string lastName;
    string department;
    float salary;
    Employee* next;
};

// // Structure for each person
// struct Employee {
//     string lastName;
//     int age;
//     Employee* next;
// };

// Function to create a new node
Employee* createNode(const string& firstName, const string& lastName, const string& department, float salary) {
    Employee* newNode = new Employee;
    newNode->lastName = lastName;
    newNode->firstName = firstName;
    newNode->department = department;
    newNode->salary = salary;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert node in alphabetical order by last name
void insertAlphabetically(Employee*& head, Employee* newNode) {
    // Case 1: Empty list or new node goes before head
    if (!head || newNode->lastName < head->lastName) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Find correct position
    Employee* current = head;
    while (current->next && current->next->lastName < newNode->lastName) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the list
void printList(const Employee* head) {
    cout << "Sorted List by Last Name:\n";
    while (head) {
        cout << head->firstName << " - " << head->lastName << " - " << head->department << " - " << head->salary << " - " << endl;
        head = head->next;
    }
}

// Function to free memory
void deleteList(Employee*& head) {
    while (head) {
        Employee* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ifstream inputFile("Empldat.txt");
    if (!inputFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    string line;
    Employee* head = nullptr;
    int age;

    // // Read and insert each person into the list in order
    // while (inputFile >> name >> age) {
    //     Employee* newNode = createNode(firstName, lastName, department, salary);
    //     insertAlphabetically(head, newNode);
    // }

    while(getline(inputFile, line)) {
        string firstName, lastName, dept, salaryStr;
        stringstream ss(line);

        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, dept, ',');
        getline(ss, salaryStr, ',');

        float salary = stof(salaryStr);
        Employee* newNode = createNode(firstName, lastName, dept, salary);
        insertAlphabetically(head, newNode);
    }


    inputFile.close();

    printList(head);
    deleteList(head);

    return 0;
}



// /*****************************************************
// // Author: Spencer Collins
// // Date : 9/15/2025 
// //
// //***************************************************/

// #include <fstream>
// #include <iostream>
// #include <string>
// #include <sstream>

// using namespace std;

// struct Employee {
//     string firstName;
//     string lastName;
//     string department;
//     float salary;
// };

// class Node {
//     public:
//         Employee employee;
//         Node* next;

//     Node(Employee& employee) {
//         this->employee = employee;
//         next = nullptr;
//     }
// };

// class LinkedList {
//     private:
//         Node* head;
//         Node* tail;
//         int length;
//     public:
//         // LinkedList(Employee& employee) {
//         //     Node* newNode = new Node(employee);
//         //     head = newNode;
//         //     tail = newNode;
//         //     length = 1;
//         // }

//         LinkedList() {
//             Node* head = nullptr;
//             Node* tail = nullptr;
//             length = 0;
//         }

//         ~LinkedList() {
//             Node*temp = head;
//             while (head !=nullptr) {
//                 head = head->next;
//                 delete temp;
//                 temp = temp->next;
//             }
//         }

//         void append(Employee& employee) {
//             Node* newNode = new Node(employee);
//             if (head == nullptr) {
//                 head = newNode;
//                 tail = newNode;
//             } else {
//                 tail->next = newNode;
//                 tail = newNode;
//             }
//             length++;
//         }

        

//         int getIndex(Employee& employee) {
//             Node* current = head;
//             int i = 0;
//             if (current == nullptr) {
//                 return 0;
//             }
//             for (int i = 0; i < length; i++) {
//                 if (current->employee.lastName < employee.lastName) {
//                 // cout << current->employee.lastName << endl;
//                 // cout << employee.lastName << endl;
//                 cout << i << endl;
//                 // return i;
//                 }
//                 current  = current->next;
//             }
//             // while (current) {
//             //     // cout << employee.lastName << endl;
//             //     // if (employee.lastName < current->employee.lastName) {
//             //     //     i++;
//             //     //     return i;
//             //     // }
//             //     // i++;
//             //     current = current->next;
//             // }
//             return 0;
//         }
        
//         bool insert(int index, Employee& employee) {
//             if (index < 0 || index > length) {
//                 return 0;
//             } else if (index == 0) {
//                 this->prepend(employee);
//                 return 1;
//             } else if(index == length) {
//                 this->append(employee);
//                 return 1;
//             } else {
//                 Node* pre = head;
//                 Node* post = head;
//                 for (int i = 0; i < length; i++) {
//                     if (i == index) {
//                         Node* temp = new Node(employee);
//                         pre->next = temp;
//                         temp->next = post;
//                         length++;
//                         return 1;
//                     }
//                     pre = post;
//                     post = post->next;
//                 }
//                 return 1;
//             }
//         }

//         void prepend(Employee& employee) {
//             Node* newNode = new Node(employee);
//             if (head ==nullptr) {
//                 head = newNode;
//                 tail = newNode;
//                 length = 1;
//                 return;
//             }
//             newNode->next = head;
//             head = newNode;
//             length++;
//         }
//     // void insert(Employee& employee) {
//     //     if (head == nullptr) {
//     //         Node* newNode = new Node(employee);
//     //         if (head == nullptr) {
//     //             head = newNode;
//     //             tail = newNode;
//     //         } else {
//     //             tail->next = newNode;
//     //             tail = newNode;
//     //         }
//     //         return;
//     //     } 
//     //     else if (employee.lastName < head->employee.lastName) {
//     //         // this->prepend(employee);
//     //         Node* newNode = new Node(employee);
//     //         if (head ==nullptr) {
//     //             head = newNode;
//     //             tail = newNode;
//     //         }
//     //         newNode->next = head;
//     //         head = newNode;
//     //         return;
//     //     } 
//     //     else {
//     //         Node* post = head;
//     //         Node* pre = head;
            
//     //         while (post) {
//     //             if (post->employee.lastName > employee.lastName) {
//     //                 Node* temp = new Node(employee);
//     //                 pre->next = temp;
//     //                 temp->next = post;
//     //             }
//     //             pre=post;
//     //             post = post->next;
//     //         }
//     //     }
//     // }

//     // void insert(Employee& employee) {
//     //     if (head == nullptr || employee.lastName < head->employee.lastName) {
//     //         Node* newNode = new Node(employee);
//     //         newNode->next = head;
//     //         head = newNode;
//     //         return;
//     //     }

//     //     Node* current = head;

//     //     while(current->next != nullptr) {
//     //         if (current->next->employee.lastName > employee.lastName) {

//     //         }
//     //     }

//     // }
//     void printList(ofstream& resultFile) {
//         Node* temp = head;
//         while (temp != nullptr) {
//             resultFile << "First Name: " << temp->employee.firstName << endl;
//             resultFile << "Last Name: " << temp->employee.lastName << endl;
//             resultFile << "Department: " << temp->employee.department << endl;
//             resultFile << "Salary: " << temp->employee.salary << endl;
//             temp = temp->next;
//         }
//     }
// };

// int main() {

//     LinkedList* Employees = new LinkedList;

//     ifstream readFile("Empldat.txt");

//     if(!readFile) {
//         cerr << "File could not be opened or read." << endl;
//     }

//     string line;
//     int lineNum = 0;
//     Employee newEmployee;
//     newEmployee.firstName = "John";
//     newEmployee.lastName = "Jones";
//     newEmployee.department = "IT";
//     newEmployee.salary = 100000.00;

//     Employees->append(newEmployee);
//     // int index = Employees->getIndex(newEmployee);
//     // cout << index << endl;

//     // Employees->insert(index, newEmployee);

//     newEmployee.firstName = "Sue";
//     newEmployee.lastName = "Davis";
//     newEmployee.department = "Sales";
//     newEmployee.salary = 125000.00;
//     Employees->prepend(newEmployee);
//     // index = Employees->getIndex(newEmployee);
//     // cout << index << endl;
//     // Employees->insert(index, newEmployee);

//     newEmployee.firstName = "Jane";
//     newEmployee.lastName = "Smith";
//     newEmployee.department = "Marketing";
//     newEmployee.salary = 140000.00;

    
//     int index = Employees->getIndex(newEmployee);
//     cout << index << endl;
//     // Employees->insert(index, newEmployee);
//     // while(getline(readFile,line)) {
//     //     string firstName, lastName, dept, salaryStr;
//     //     stringstream ss(line);

//     //     getline(ss, firstName, ',');
//     //     getline(ss, lastName, ',');
//     //     getline(ss, dept, ',');
//     //     getline(ss, salaryStr, ',');

//     //     Employee newEmployee;
//     //     newEmployee.firstName = firstName;
//     //     newEmployee.lastName = lastName;
//     //     newEmployee.department = dept;
//     //     newEmployee.salary = stof(salaryStr);
//     //     int index = Employees->getIndex(newEmployee);
//     //     // cout << index << endl;
//     //     // Employees->insert(index, newEmployee);

//     // }

//     ofstream resultFile("results.txt");

//     Employees->printList(resultFile);
//     delete Employees;

//     readFile.close();
//     resultFile.close();
//     return 0;
// }
