
// Roll No.: 1024031132

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *next;
    Node *prev;

    Node(char val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node* insertEnd(Node *head, char val) {
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
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

bool isPalindrome(Node *head) {
    if (!head) return true;

    Node *tail = head;
    while (tail->next)
        tail = tail->next;

    while (head != tail && head->prev != tail) {
        if (tolower(head->data) != tolower(tail->data))
            return false;
        head = head->next;
        tail = tail->prev;
    }

    return true;
}

int main() {
    Node *head = nullptr;

    head = insertEnd(head, 'L');
    head = insertEnd(head, 'E');
    head = insertEnd(head, 'V');
    head = insertEnd(head, 'E');
    head = insertEnd(head, 'L');

    display(head);

    if (isPalindrome(head))
        cout << "List is a palindrome.\n";
    else
        cout << "Linked List is not a palindrome.\n";

    return 0;
}


//
// Created by adity on 26-10-2025.
//