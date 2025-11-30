//ASSIGNMENT 8 QUESTION 2(C)
//ROLL NO.: 1024031132

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insertNode(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

Node* findMinRecursive(Node* root) {
    if (root == nullptr)
        return nullptr;

    if (root->left == nullptr)
        return root;

    return findMinRecursive(root->left);
}

int main() {
    Node* root = nullptr;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values)
        root = insertNode(root, v);

    Node* minNode = findMinRecursive(root);

    if (minNode)
        cout << "Minimum element (Recursive): " << minNode->data;
    else
        cout << "Tree is empty";

    return 0;
}
