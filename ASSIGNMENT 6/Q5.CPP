
// Roll No.: 1024031132

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* insertEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head)
        return newNode;

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

Node* makeCircular(Node* head) {
    if (!head) return nullptr;

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = head;
    return head;
}

bool isCircular(Node* head) {
    if (!head) return true;

    Node* temp = head->next;
    while (temp != nullptr && temp != head)
        temp = temp->next;

    return (temp == head);
}

void displayCircular(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(Back to Head)\n";
}

int main() {
    Node* head = nullptr;

    head = insertEnd(head, 2);
    head = insertEnd(head, 4);
    head = insertEnd(head, 6);
    head = insertEnd(head, 7);
    head = insertEnd(head, 5);

    head = makeCircular(head);

    displayCircular(head);

    if (isCircular(head))
        cout << "linked list is circular.\n";
    else
        cout << "linked list is not circular.\n";

    return 0;
}


//
// Created by adity on 26-10-2025.
//