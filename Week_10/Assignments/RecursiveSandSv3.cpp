/*****************************************************
// Author: Spencer Collins
// Date : 10/20/2025 
// This is the implementation file for Problem 1 Assignment 10.
//***************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Game {
    string name;
    int score;
};

// Quick Sort by score (descending)
int partitionByScore(Game arr[], int low, int high) {
    // add code here
    //assign pivot value as the last element in the array
    
    Game pivot = arr[high];


    //assign swap index as -1, since it is < the counter i
    int swap = -1;

    // iterate through the array
    // for each array element name that is greater than the pivot name swap positions in the array with the swap positions
    // done in place
    for (int i=0; i<high; i++) {
        if (arr[i].score > pivot.score) {
            swap++;
            Game swappedScore = arr[swap];
            Game orgScore = arr[i];
            arr[i] = swappedScore;
            arr[swap] = orgScore;
        }
    };

    //shift all array elements greater than pivot 1 index position to the right
    for (int i = high; i > swap; i--) {
        arr[i] = arr[i-1];
    }
    //assign the pivot element to swap + 1 index so it is in between the two partitioned portions of the array
    arr[swap+1] = pivot;

    return swap + 1;

}

void quickSortByScore(Game arr[], int low, int high) {
    if (low < high) {
        int pi = partitionByScore(arr, low, high);
        quickSortByScore(arr, low, pi - 1);
        quickSortByScore(arr, pi + 1, high);
    }
}

// Quick Sort by name (ascending)
int partitionByName(Game arr[], int low, int high) {
   // Add code here
    //assign pivot value as the last element in the array
    
    Game pivot = arr[high];


    //assign swap index as -1, since it is < the counter i
    int swap = -1;

    // iterate through the array
    // for each array element name that is greater than the pivot name swap positions in the array with the swap positions
    // done in place
    for (int i=0; i<high; i++) {
        if (arr[i].name < pivot.name) {
            swap++;
            Game swappedGame = arr[swap];
            Game orgGame = arr[i];
            arr[i] = swappedGame;
            arr[swap] = orgGame;
        }
    };

    //shift all array elements greater than pivot 1 index position to the right
    for (int i = high; i > swap; i--) {
        arr[i] = arr[i-1];
    }
    //assign the pivot element to swap + 1 index so it is in between the two partitioned portions of the array
    arr[swap+1] = pivot;

    return swap + 1;

}

void quickSortByName(Game arr[], int low, int high) {
   // added code here

    if (low < high) {
        int pivotIndex = partitionByName(arr, low, high);

        quickSortByName(arr, low, pivotIndex-1);
        quickSortByName(arr, pivotIndex+1, high);
    }
}

// Binary Search by name
int binarySearchByName(Game arr[], int low, int high, string target) {
    // add code here
    return 0;
}

// Display games
void displayGames(Game arr[], int n) {
    cout << "\nGame List:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << arr[i].name << " - Score: " << arr[i].score << endl;
    }
}

// Read games from file
bool readFromFile(Game arr[], int& n, const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cout << "Error opening file: " << filename << endl;
        return false;
    }

    n = 0;
    while (n < 10 && infile >> arr[n].name >> arr[n].score) {
        n++;
    }

    infile.close();
    return n == 10;
}

// Main menu
int main() {
    Game games[10];
    int n = 0, choice;
    bool isSortedByScore = false;
    bool isSortedByName = false;

    cout << "Reading game data from 'gamed.txt'...\n";
    if (!readFromFile(games, n, "gamed.txt")) {
        cout << "Failed to read 10 games. Exiting.\n";
        return 1;
    }

    while (true) {
        cout << "\n--- Indie Game Ranking Menu ---\n";
        cout << "1. Sort games by score (recursive quick sort)\n";
        cout << "2. Sort games by name (recursive quick sort)\n";
        cout << "3. Search for a game by name (binary search)\n";
        cout << "4. Display games\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            quickSortByScore(games, 0, n - 1);
            isSortedByScore = true;
            isSortedByName = false;
            cout << "Games sorted by score.\n";
        }
        else if (choice == 2) {
            quickSortByName(games, 0, n - 1);
            isSortedByName = true;
            isSortedByScore = false;
            cout << "Games sorted by name.\n";
        }
        else if (choice == 3) {
            if (!isSortedByName) {
                cout << "Please sort the games by name first.\n";
            }
            else {
                string target;
                cout << "Enter game name to search: ";
                cin >> target;
                int index = binarySearchByName(games, 0, n - 1, target);
                if (index != -1)
                    cout << "Found: " << games[index].name << " with score " << games[index].score << endl;
                else
                    cout << "Game not found.\n";
            }
        }
        else if (choice == 4) {
            displayGames(games, n);
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
