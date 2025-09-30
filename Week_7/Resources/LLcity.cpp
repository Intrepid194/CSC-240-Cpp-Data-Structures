#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct City {
    string name;
    int population;
};

struct Node {
    City city;
    Node* next;
};

class CityStack {
private:
    Node* top;

public:
    CityStack() : top(nullptr) {}

    ~CityStack() {
        while (!isEmpty()) {
            City temp;
            pop(temp);
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    bool push(const City& city) {
        Node* newNode = new Node{ city, top };
        top = newNode;
        return true;
    }

    bool pop(City& city) {
        if (isEmpty()) {
            cout << "Stack underflow: No cities to remove.\n";
            return false;
        }
        Node* temp = top;
        city = top->city;
        top = top->next;
        delete temp;
        return true;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "\nCurrent Cities in Stack:\n";
        Node* current = top;
        while (current) {
            cout << current->city.name << " | Population: " << current->city.population << "\n";
            current = current->next;
        }
    }

    bool modifyByCityName(const string& cityName) {
        Node* current = top;
        while (current) {
            if (current->city.name == cityName) {
                cout << "City found: " << current->city.name << "\n";
                cout << "Current Population: " << current->city.population << "\n";
                cout << "Enter New Population: ";
                cin >> current->city.population;
                cin.ignore();
                cout << "City population updated.\n";
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool searchByCityName(const string& cityName) const {
        Node* current = top;
        while (current) {
            if (current->city.name == cityName) {
                cout << "Found: " << current->city.name << " | Population: " << current->city.population << "\n";
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    CityStack cityStack;
    ifstream infile("citydat.txt");

    if (infile) {
        string line;
        while (getline(infile, line)) {
            stringstream ss(line);
            string name, popStr;
            int population;

            if (getline(ss, name, ',') && getline(ss, popStr)) {
                try {
                    population = stoi(popStr);
                    City city = { name, population };
                    cityStack.push(city);
                }
                catch (...) {
                    cout << "Invalid population format in line: " << line << "\n";
                }
            }
        }
        infile.close();
        cout << "Initial city data loaded from CSV file.\n";
    }
    else {
        cout << "No CSV file found. Starting with empty stack.\n";
    }

    int choice;
    do {
        cout << "\n--- City Stack Menu ---\n";
        cout << "1. Add City\n";
        cout << "2. Modify City Population\n";
        cout << "3. Search City by Name\n";
        cout << "4. Display All Cities\n";
        cout << "5. Pop Top City\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            City city;
            cout << "Enter City Name: ";
            getline(cin, city.name);
            cout << "Enter Population: ";
            cin >> city.population;
            cin.ignore();
            cityStack.push(city);
            cout << "City added.\n";
        }
        else if (choice == 2) {
            string cityName;
            cout << "Enter City Name to Modify: ";
            getline(cin, cityName);
            if (!cityStack.modifyByCityName(cityName)) {
                cout << "City '" << cityName << "' not found.\n";
            }
        }
        else if (choice == 3) {
            string cityName;
            cout << "Enter City Name to Search: ";
            getline(cin, cityName);
            if (!cityStack.searchByCityName(cityName)) {
                cout << "City '" << cityName << "' not found.\n";
            }
        }
        else if (choice == 4) {
            cityStack.display();
        }
        else if (choice == 5) {
            City removed;
            if (cityStack.pop(removed)) {
                cout << "Removed Top City: " << removed.name << "\n";
            }
        }
        else if (choice != 6) {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    cout << "Exiting program. Goodbye!\n";
    return 0;
}