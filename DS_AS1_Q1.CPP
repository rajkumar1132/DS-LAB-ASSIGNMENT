#include <iostream>
using namespace std;

const int LIMIT = 100;   
int numbers[LIMIT];      
int countItems = 0;   

// 1. Create Array (using for loop)
void createArray() {
    cout << "How many elements? " << endl;
    cin >> countItems;

    if (countItems <= 0 || countItems > LIMIT) {
        cout << "Invalid size! Array not created." << endl;
        countItems = 0;
        return;
    }

    cout << "Enter " << countItems << " values:" << endl;
    for (int i = 0; i < countItems; i++) {
        cin >> numbers[i];
    }
    cout << "Array created." << endl;
}

// 2. Display Array (for loop + pointer arithmetic)
void showArray() {
    if (countItems == 0) {
        cout << "Array is empty." << endl;
        return;
    }

    cout << "Array elements: ";
    int *ptr = numbers;
    for (int i = 0; i < countItems; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

// 3. Insert Element (insert at start if position invalid)
void insertElement() {
    if (countItems >= LIMIT) {
        cout << "Array is full. Cannot insert." << endl;
        return;
    }

    int position, value;
    cout << "Enter position (0 to " << countItems << "): " << endl;
    cin >> position;
    cout << "Enter value: " << endl;
    cin >> value;

    if (position < 0 || position > countItems) {
        cout << "Invalid position! Inserting at start." << endl;
        position = 0;
    }

    for (int i = countItems; i > position; i--) {
        numbers[i] = numbers[i - 1];
    }

    numbers[position] = value;
    countItems++;
    cout << "Element inserted." << endl;
}

// 4. Delete Element (by value instead of index)
void deleteByValue() {
    if (countItems == 0) {
        cout << "Array is empty." << endl;
        return;
    }

    int value;
    cout << "Enter value to delete: " << endl;
    cin >> value;

    int foundIndex = -1;
    for (int i = 0; i < countItems; i++) {
        if (numbers[i] == value) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        cout << "Value not found." << endl;
        return;
    }

    for (int i = foundIndex; i < countItems - 1; i++) {
        numbers[i] = numbers[i + 1];
    }
    countItems--;
    cout << "Value deleted." << endl;
}

// 5. Linear Search (search from end to start)
void searchElement() {
    if (countItems == 0) {
        cout << "Array is empty." << endl;
        return;
    }

    int target;
    cout << "Enter value to search: " << endl;
    cin >> target;

    for (int i = countItems - 1; i >= 0; i--) {
        if (numbers[i] == target) {
            cout << "Value found at index " << i << endl;
            return;
        }
    }
    cout << "Value not found." << endl;
}

int main() {
    int choice;
    do {
        cout << endl << "=== MENU ===" << endl;
        cout << "1. CREATE ARRAY" << endl;
        cout << "2. DISPLAY ARRAY" << endl;
        cout << "3. INSERT ELEMENT" << endl;
        cout << "4. DELETE ELEMENT (BY VALUE)" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice (1-6): " << endl;
        cin >> choice;

        switch (choice) {
            case 1: createArray(); break;
            case 2: showArray(); break;
            case 3: insertElement(); break;
            case 4: deleteByValue(); break;
            case 5: searchElement(); break;
            case 6: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
