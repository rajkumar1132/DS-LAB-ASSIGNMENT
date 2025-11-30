
//1024031132

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    // (a) Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // (b) Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // (c) Insert before/after a node with given value
    void insertBefore(int target, int value) {
        if (head == NULL) return;

        // Special case: insert before head
        if (head->data == target) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != target) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Node with value " << target << " not found!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int target, int value) {
        Node* temp = head;
        while (temp != NULL && temp->data != target) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node with value " << target << " not found!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // (d) Deletion from beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // (e) Deletion from end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // (f) Deletion of a specific node
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Node not found!" << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // (g) Search for a node and display position
    void search(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << value << " not found!" << endl;
    }

    // (h) Display all nodes
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// =============================
// Main Menu Driven Program
// =============================
int main() {
    SinglyLinkedList sll;
    int choice, value, target;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete a Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                sll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                sll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                sll.insertBefore(target, value);
                break;
            case 4:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                sll.insertAfter(target, value);
                break;
            case 5:
                sll.deleteFromBeginning();
                break;
            case 6:
                sll.deleteFromEnd();
                break;
            case 7:
                cout << "Enter node value to delete: ";
                cin >> value;
                sll.deleteNode(value);
                break;
            case 8:
                cout << "Enter node value to search: ";
                cin >> value;
                sll.search(value);
                break;
            case 9:
                sll.display();
                break;
            case 10:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
