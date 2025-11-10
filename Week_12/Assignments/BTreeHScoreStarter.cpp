#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// add structure or class
struct SnackNode {
    string name;
    int healthScore;
    int calories;
    SnackNode* left;
    SnackNode* right;
    SnackNode(string name, int hs, int cal) : name(name), healthScore(hs), calories(cal), left(nullptr), right(nullptr) {}
};
// Insert snack into tree
SnackNode* insertSnack(SnackNode* root, string name, int hs, int cal) {
    if (!root) return new SnackNode(name, hs, cal);
    
    // add code to insert into the tree
    if (hs < root->healthScore) {
        root->left = insertSnack(root->left, name, hs, cal);
    } else {
        root->right = insertSnack(root->right, name, hs, cal);
    }
    return root;
}

// Convert string to lowercase
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Search by snack name
SnackNode* searchSnack(SnackNode* root, string target) {
    // add code to search by snack name
    // You can recursivley search the tree in order but check for the search name equal to node name
    if(root == nullptr) return nullptr;

    if(toLower(target) == toLower(root->name)) return root;

    SnackNode* foundSnack = searchSnack(root->left, target);
    if (foundSnack) return foundSnack;
    return searchSnack(root->right, target);
}

// In-order traversal
void printSnackTree(SnackNode* root) {
    // add code - recursively visit each node and display node values
    if (root == nullptr) {
        return;
    }

    printSnackTree(root->left);
    cout << "Snack Name: " << root->name << endl;
    cout << "Health Score: " << root->healthScore << endl;
    cout << "Calories: " << root->calories << endl;
    printSnackTree(root->right);
}

int main() {
    SnackNode* root = nullptr;

    // Sample data - you may place in a text file and add a loop to create nodes, add the data and inseert into the tree
    root = insertSnack(root, "Granola Bar", 5, 180);
    root = insertSnack(root, "Apple", 2, 95);
    root = insertSnack(root, "Chocolate Cake", 9, 350);
    root = insertSnack(root, "Carrot Sticks", 1, 50);
    root = insertSnack(root, "Potato Chips", 7, 250);
    root = insertSnack(root, "Yogurt", 4, 120);
    root = insertSnack(root, "Cheese Stick", 14, 200);

    cout << "SnackTree (Healthiest to Least Healthy):\n";
    printSnackTree(root);

    // Interactive search loop
    string query;
    while (true) {
        cout << "\nEnter a snack name to search (or type 'exit' to quit): ";
        getline(cin, query);
        if (toLower(query) == "exit") break;

        SnackNode* result = searchSnack(root, query);
        if (result) {
            cout << "Found: " << result->name << " (Health: " << result->healthScore
                << ", Calories: " << result->calories << ")\n";
        }
        else {
            cout << "Snack not found in the tree.\n";
        }
    }

    cout << "Thanks for exploring the SnackTree!\n";
    return 0;
}