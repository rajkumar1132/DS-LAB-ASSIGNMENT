
// Roll no.: 1024031132

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

    if (!head) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

void displayCircularList(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;
}

int main() {
    Node* head = nullptr;

    head = insertEnd(head, 20);
    head = insertEnd(head, 100);
    head = insertEnd(head, 40);
    head = insertEnd(head, 80);
    head = insertEnd(head, 60);

    cout << "Circular Linked List Values (head repeated at end):\n";
    displayCircularList(head);

    return 0;
}


//
// Created by adity on 26-10-2025.
//