


#include <iostream>
#include <string>

using namespace std;

int partition(string arr[], int low, int high) {

    string pivot = arr[high];
    int swap = -1;
    
    for (int i = 0; i < high; i++) {

        if (arr[i] > pivot) {
            swap++;
            string swappedVal = arr[swap];
            string orgVal = arr[i];
            arr[i] = swappedVal;
            arr[swap] = orgVal;
        }
    }


    // for (int i = high; i > swap; i--) {
    //     arr[i] = arr[i-1];
    // }
    // arr[swap+1] = pivot;
    cout << pivot << endl;
    return swap++;
}

int main() {

    string arr[10] = {
        "Celeste 92",
        "HollowKnight 95",
        "StardewValley 89",
        "Undertale 94",
        "Cuphead 90",
        "Oxenfree 85",
        "Limbo 88",
        "Inside 87",
        "Fez 91",
        "Braid 86",
    };
    
    int pivotIdx = partition(arr, 0, 9);
    cout << to_string(pivotIdx) << endl;
    
    // for (int i = 0; i < 10-1; i++) {
    //     cout << arr[i] << endl;
    // }
    // int low = 0;
    // int high = ;
    // if (0 < )
    return 0;
}