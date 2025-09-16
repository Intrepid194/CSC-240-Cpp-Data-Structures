#include <iostream>
using namespace std;

const int MAX_SIZE = 25; // Total array capacity
int lastIndex = 9;       // Index of the last used item (0-based, so 10 items)

void insertionSort(int arr[], int usedSize) {
    for (int i = 1; i <= usedSize; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int usedSize) {
    for (int i = 0; i <= usedSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[MAX_SIZE] = { 5, 3, 8, 6, 2, 9, 1, 4, 7, 0 }; // Only first 10 items are used

    cout << "Original array (used portion): ";
    printArray(arr, lastIndex);

    insertionSort(arr, lastIndex);

    cout << "Sorted array (used portion): ";
    printArray(arr, lastIndex);

    cout << "Last item in the list: " << arr[lastIndex] << endl;

    return 0;
}