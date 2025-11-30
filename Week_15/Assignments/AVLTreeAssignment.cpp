/*****************************************************
// Author: Spencer Collins
// Date : 11/30/2025 
// This is the implementation file for Problem 1 Assignment 15.
//***************************************************/
#include <iostream>
#include <string>
#include <algorithm> // for max
using namespace std;

class TreeNode {
public:
    TreeNode();
    void SetLastName(string lname);
    string GetLastName();
    TreeNode* Left;
    TreeNode* Right;
    int height;   // track height for AVL balancing

protected:
    string m_lname;
};

// --- Implementation ---
TreeNode::TreeNode() {
    Left = nullptr;
    Right = nullptr;
    m_lname = "";
    height = 1;   // initialize height
}

void TreeNode::SetLastName(string lname) {
    m_lname = lname;
}

string TreeNode::GetLastName() {
    return m_lname;
}

// --- AVL Utilities ---
int GetHeight(TreeNode* node) {
    return (node == nullptr) ? 0 : node->height;
}

void UpdateHeight(TreeNode* node) {
    if (node)
        node->height = 1 + max(GetHeight(node->Left), GetHeight(node->Right));
}

int GetBalance(TreeNode* node) {
    return (node == nullptr) ? 0 : GetHeight(node->Left) - GetHeight(node->Right);
}

// --- Rotations ---
TreeNode* RotateRight(TreeNode* y) {
    TreeNode* x = y->Left;
    TreeNode* T2 = x->Right;

    // add code to rotate right
    x->Right = y;
    y->Left = T2;
    // end of updated code

    UpdateHeight(y);
    UpdateHeight(x);

    return x;
}

TreeNode* RotateLeft(TreeNode* x) {
    TreeNode* y = x->Right;
    TreeNode* T2 = y->Left;

  // add code to rotate left
   y->Left = x;
    x->Right = T2;
  // end of updated code 

    UpdateHeight(x);
    UpdateHeight(y);

    return y;
}

// --- AVL Insert ---
TreeNode* Insert_AVL(TreeNode* node, string lname) {
    if (node == nullptr) {
        TreeNode* newNode = new TreeNode();
        newNode->SetLastName(lname);
        return newNode;
    }

    if (lname < node->GetLastName())
        node->Left = Insert_AVL(node->Left, lname);
    else if (lname > node->GetLastName())
        node->Right = Insert_AVL(node->Right, lname);
    else
        return node; // no duplicates

    UpdateHeight(node);
    int balance = GetBalance(node);

    // add code for balance cases
    // conditions should return RotateRight(node) or RotateLeft(node)
    // condition should check the balance and whether lname is less than node->Left->GetLastName()
    // this is RotateRight
    // condition should also check the balance and whether lname is greater than node->Left->GetLastName()
    // this is RotateLeft
    // remember balance (or out of balance) can be either > 1 or < -1

    if (balance > 1 && lname < node->Left->GetLastName()) return RotateRight(node);
    if (balance < -1 && lname > node->Right->GetLastName()) return RotateLeft(node);

    if (balance > 1 && lname > node->Left->GetLastName()) {
        node->Left = RotateLeft(node->Left);
        return RotateRight(node);
    }

    if (balance < -1 && lname < node->Right->GetLastName()) {
        node->Right = RotateRight(node->Right);
        return RotateLeft(node);
    }

    // end of code update

    return node;
}

// --- Find Minimum Node ---
TreeNode* MinValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current->Left != nullptr)
        current = current->Left;
    return current;
}

// --- AVL Delete ---
TreeNode* Delete_AVL(TreeNode* root, string lname) {
    if (root == nullptr) return root;

    if (lname < root->GetLastName())
        root->Left = Delete_AVL(root->Left, lname);
    else if (lname > root->GetLastName())
        root->Right = Delete_AVL(root->Right, lname);
    else {
        // Node found
        if (root->Left == nullptr || root->Right == nullptr) {
            TreeNode* temp = root->Left ? root->Left : root->Right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else {
                *root = *temp; // copy contents
            }
            delete temp;
        }
        else {
            TreeNode* temp = MinValueNode(root->Right);
            root->SetLastName(temp->GetLastName());
            root->Right = Delete_AVL(root->Right, temp->GetLastName());
        }
    }

    if (root == nullptr) return root;

    UpdateHeight(root);
    int balance = GetBalance(root);

    // add code after delete for balance cases
    //remember balance (or out of balance) can be either > 1 or < -1 as above
    // but need to check GetBalance(root->Left) or GetBalance(root->Right)
    // then RotateLeft or RotateRight as appropriate
   
    if (balance > 1 && GetBalance(root->Left) >= 0) return RotateRight(root);
    if (balance < -1 && GetBalance(root->Right) <= 0) return RotateLeft(root);

    if (balance > 1 && GetBalance(root->Left) <0) {
        root->Left = RotateLeft(root->Left);
        return RotateRight(root);
    }

    if (balance < -1 && GetBalance(root->Right) > 0) {
        root->Right = RotateRight(root->Right);
        return RotateLeft(root);
    }

    // end of code add

    return root;
}

// --- Display In-Order ---
void DisplayTree(TreeNode* tree) {
    if (tree) {
        DisplayTree(tree->Left);
        cout << tree->GetLastName() << " (h=" << tree->height << ")" << endl;
        DisplayTree(tree->Right);
    }
}

// --- Display Sideways ---
void SidePrint(TreeNode* root, int space = 0, int indent = 6) {
    if (root == nullptr) return;
    space += indent;
    SidePrint(root->Right, space);
    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->GetLastName() << " (h=" << root->height << ")" << endl;
    SidePrint(root->Left, space);
}

// --- Check if Tree is Balanced ---
bool IsTreeBalanced(TreeNode* tree) {
    if (tree == nullptr) return true;

    int leftHeight = GetHeight(tree->Left);
    int rightHeight = GetHeight(tree->Right);

    if (abs(leftHeight - rightHeight) > 1)
        return false;

    return IsTreeBalanced(tree->Left) && IsTreeBalanced(tree->Right);
}

// --- Menu ---
void Menu(TreeNode*& tree) {
    int choice = 0;
    string lname;

    while (choice != 6) {
        cout << "\n******** AVL Tree Menu ********\n";
        cout << "1. Display In-Order\n";
        cout << "2. Sideways Print\n";
        cout << "3. Add Name\n";
        cout << "4. Delete Name\n";
        cout << "5. Check Balance\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            DisplayTree(tree);
        }
        else if (choice == 2) {
            SidePrint(tree);
        }
        else if (choice == 3) {
            cout << "Enter name to insert: ";
            cin >> lname;
            tree = Insert_AVL(tree, lname);
        }
        else if (choice == 4) {
            cout << "Enter name to delete: ";
            cin >> lname;
            tree = Delete_AVL(tree, lname);
        }
        else if (choice == 5) {
            cout << "Tree is balanced: "
                << (IsTreeBalanced(tree) ? "Yes" : "No") << endl;
        }
        else if (choice == 6) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
}

// --- Main ---
int main() {
    TreeNode* tree = nullptr;
    string names[] = { "MICHAELS","SMITH","JONES","ADAMS","BAKER","DAVIS","CHANDLER","RICHARDS","HANKS","PEN" };

    for (string lname : names) {
        tree = Insert_AVL(tree, lname);
    }

    cout << "Initial AVL Tree (In-Order Traversal):" << endl;
    DisplayTree(tree);

    cout << "\nPretty Print of AVL Tree (sideways):" << endl;
    SidePrint(tree);

    // Start menu loop
    Menu(tree);

    return 0;
}
