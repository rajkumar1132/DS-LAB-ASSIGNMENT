#include <iostream>
using namespace std;

int main() {
    int data[100], size;

    // Step 1: Get array size from user
    cout << "Enter number of elements (1-100): " << endl;
    cin >> size;

    if (size <= 0 || size > 100) {
        cout << "Invalid size! Please enter between 1 and 100." << endl;
        return 1;
    }

    // Step 2: Input elements
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }

    // Step 3: Remove duplicates
    int uniqueCount = 0; // Tracks number of unique elements

    for (int i = 0; i < size; i++) {
        bool duplicateFound = false;

        // Compare with already stored unique values
        for (int j = 0; j < uniqueCount; j++) {
            if (data[i] == data[j]) {
                duplicateFound = true;
                break;
            }
        }

        // If not found, add to unique list
        if (!duplicateFound) {
            data[uniqueCount] = data[i];
            uniqueCount++;
        }
    }

    // Step 4: Display array without duplicates
    cout << "Array without duplicates:" << endl;
    for (int i = 0; i < uniqueCount; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
