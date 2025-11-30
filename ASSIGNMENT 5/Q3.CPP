
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

// Function to insert at end
void insertAtEnd(Node* &head, int value) {
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

// Function to find middle
int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       
        fast = fast->next->next;  
    }

    return slow->data;
}

// Function to display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    // Input: 1->2->3->4->5
    int arr[] = {1,2,3,4,5};
    for (int i=0; i<5; i++) {
        insertAtEnd(head, arr[i]);
    }

    cout << "Linked List: ";
    display(head);

    cout << "Middle Node: " << findMiddle(head) << endl;

    return 0;
}
