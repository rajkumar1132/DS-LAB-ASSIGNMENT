//ASSIGNMENT 8 QUESTION 2(a)
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

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);

    return searchRecursive(root->right, key);
}

Node* searchNonRecursive(Node* root, int key) {
    Node* current = root;

    while (current != nullptr) {
        if (key == current->data)
            return current;

        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    return nullptr;
}

int main() {
    Node* root = nullptr;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values)
        root = insertNode(root, v);

    int key = 60;

    Node* result1 = searchRecursive(root, key);
    if (result1 != nullptr)
        cout << "Recursive: " << key << " found in BST\n";
    else
        cout << "Recursive: " << key << " NOT found\n";

    Node* result2 = searchNonRecursive(root, key);
    if (result2 != nullptr)
        cout << "Non-Recursive: " << key << " found in BST\n";
    else
        cout << "Non-Recursive: " << key << " NOT found\n";

    return 0;
}