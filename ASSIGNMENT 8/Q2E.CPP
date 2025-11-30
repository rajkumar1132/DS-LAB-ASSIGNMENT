//ASSIGNMENT 8 QUESTION 2(e)
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

// Insert node in BST
Node* insertNode(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

Node* findMax(Node* root) {
    while (root->right != nullptr)
        root = root->right;

    return root;
}
Node* inorderPredecessor(Node* root, Node* keyNode) {
    if (root == nullptr || keyNode == nullptr)
        return nullptr;

    if (keyNode->left != nullptr)
        return findMax(keyNode->left);

    Node* predecessor = nullptr;
    Node* current = root;

    while (current != nullptr) {
        if (keyNode->data > current->data) {
            predecessor = current;
            current = current->right;
        }
        else if (keyNode->data < current->data) {
            current = current->left;
        }
        else {
            break;
        }
    }

    return predecessor;
}

Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int main() {
    Node* root = nullptr;

    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for (int v : values)
        root = insertNode(root, v);

    int key = 50;
    Node* keyNode = search(root, key);

    Node* pred = inorderPredecessor(root, keyNode);

    if (pred)
        cout << "In-order predecessor of " << key << " is: " << pred->data;
    else
        cout << "No in-order predecessor exists for " << key;

    return 0;
}

