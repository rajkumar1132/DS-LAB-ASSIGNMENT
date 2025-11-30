
//1024031132

#include<iostream>
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

    // Insert at end (for building the list)
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

    // Delete all occurrences of key & count them
    int deleteOccurrences(int key) {
        int count = 0;

        // First, handle nodes at head
        while (head != NULL && head->data == key) {
            Node* del = head;
            head = head->next;
            delete del;
            count++;
        }

        // Now handle the rest
        Node* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->data == key) {
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
                count++;
            } else {
                temp = temp->next;
            }
        }
        return count;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;

    int arr[] = {1,2,1,2,1,3,1};
    for (int i=0; i<7; i++) {
        list.insertAtEnd(arr[i]);
    }

    cout << "Original List: ";
    list.display();

    int key = 1;
    int count = list.deleteOccurrences(key);

    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    list.display();

    return 0;
}
