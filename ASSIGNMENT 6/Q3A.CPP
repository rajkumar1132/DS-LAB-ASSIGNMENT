
// Roll No.: 1024031132

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


Node* insertEnd(Node *head, int val) {
    Node *newNode = new Node(val);
    if (!head)
        return newNode;

    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void display(Node *head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    cout << "Doubly Linked List: ";
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int findSize(Node *head) {
    int count = 0;
    Node *temp = head;

    while (temp) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    Node *head = nullptr;

    // Insert some nodes
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);

    display(head);

    int size = findSize(head);
    cout << "Size of Doubly Linked List: " << size << endl;

    return 0;
}


//
// Created by adity on 26-10-2025.
//