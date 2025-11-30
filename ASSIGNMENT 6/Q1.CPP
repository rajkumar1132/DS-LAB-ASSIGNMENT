
//Roll no.: 1024031132

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};


void displayDLL(Node *head) {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }
    Node *temp = head;
    cout << "List: ";
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node* insertBeginningDLL(Node *head, int val) {
    Node *newNode = new Node(val);
    if (head) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    cout << val << " inserted at beginning.\n";
    return head;
}

Node* insertEndDLL(Node *head, int val) {
    Node *newNode = new Node(val);
    if (!head) return newNode;

    Node *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;

    cout << val << " inserted at end.\n";
    return head;
}

Node* insertAfterDLL(Node *head, int key, int val) {
    Node *temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) {
        cout << "Node " << key << " not found.\n";
        return head;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;

    cout << val << " inserted after " << key << ".\n";
    return head;
}

Node* insertBeforeDLL(Node *head, int key, int val) {
    if (!head) return nullptr;
    if (head->data == key) return insertBeginningDLL(head, val);

    Node *temp = head;
    while (temp && temp->data != key) temp = temp->next;

    if (!temp) {
        cout << "Node " << key << " not found.\n";
        return head;
    }

    Node *newNode = new Node(val);
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;

    cout << val << " inserted before " << key << ".\n";
    return head;
}

Node* deleteNodeDLL(Node *head, int key) {
    if (!head) {
        cout << "List is empty.\n";
        return head;
    }

    Node *temp = head;
    while (temp && temp->data != key) temp = temp->next;

    if (!temp) {
        cout << "Node " << key << " not found.\n";
        return head;
    }

    if (temp == head) head = head->next;
    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;

    delete temp;
    cout << "Node " << key << " deleted.\n";
    return head;
}

void searchDLL(Node *head, int key) {
    int pos = 1;
    Node *temp = head;
    while (temp) {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node " << key << " not found.\n";
}


void displayCDLL(Node *head) {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;
    cout << "Circular List: ";
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(Back to Head)\n";
}

Node* insertEndCDLL(Node *head, int val) {
    Node *newNode = new Node(val);
    if (!head) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    Node *tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;

    cout << val << " inserted in circular list.\n";
    return head;
}

Node* deleteCDLL(Node *head, int key) {
    if (!head) {
        cout << "List is empty!\n";
        return head;
    }

    Node *temp = head;
    do {
        if (temp->data == key) {
            if (temp->next == temp) {
                delete temp;
                return nullptr;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (temp == head)
                head = temp->next;

            delete temp;
            cout << "Node " << key << " deleted from circular list.\n";
            return head;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Node " << key << " not found.\n";
    return head;
}

void searchCDLL(Node *head, int key) {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }

    int pos = 1;
    Node *temp = head;
    do {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    cout << "Node " << key << " not found.\n";
}


int main() {
    Node *headDLL = nullptr;
    Node *headCDLL = nullptr;
    int choice, val, key, listChoice;

    cout << "\n=== LINKED LIST MENU PROGRAM ===\n";
    cout << "1. Doubly Linked List (DLL)\n";
    cout << "2. Circular Doubly Linked List (CDLL)\n";
    cout << "Enter your choice: ";
    cin >> listChoice;

    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                if (listChoice == 1) headDLL = insertBeginningDLL(headDLL, val);
                else headCDLL = insertEndCDLL(headCDLL, val);
                break;

            case 2:
                cout << "Enter value: "; cin >> val;
                if (listChoice == 1) headDLL = insertEndDLL(headDLL, val);
                else headCDLL = insertEndCDLL(headCDLL, val);
                break;

            case 3:
                cout << "Enter existing node value: "; cin >> key;
                cout << "Enter new value: "; cin >> val;
                if (listChoice == 1) headDLL = insertAfterDLL(headDLL, key, val);
                else cout << "Insert after not implemented for circular list.\n";
                break;

            case 4:
                cout << "Enter existing node value: "; cin >> key;
                cout << "Enter new value: "; cin >> val;
                if (listChoice == 1) headDLL = insertBeforeDLL(headDLL, key, val);
                else cout << "Insert before not implemented for circular list.\n";
                break;

            case 5:
                cout << "Enter value to delete: "; cin >> key;
                if (listChoice == 1) headDLL = deleteNodeDLL(headDLL, key);
                else headCDLL = deleteCDLL(headCDLL, key);
                break;

            case 6:
                cout << "Enter value to search: "; cin >> key;
                if (listChoice == 1) searchDLL(headDLL, key);
                else searchCDLL(headCDLL, key);
                break;

            case 7:
                if (listChoice == 1) displayDLL(headDLL);
                else displayCDLL(headCDLL);
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}


//
// Created by adity on 17-10-2025.
//