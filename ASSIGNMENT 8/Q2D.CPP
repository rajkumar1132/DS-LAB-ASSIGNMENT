//ASSIGNMENT 8 QUESTION 2(d)
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

Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;

    while (root->left != nullptr)
        root = root->left;

    return root;
}

Node* inorderSuccessor(Node* root, Node* keyNode) {
    if (root == nullptr || keyNode == nullptr)
        return nullptr;

    if (keyNode->right != nullptr)
        return findMin(keyNode->right);

    Node* successor = nullptr;
    Node* current = root;

    while (current != nullptr) {
        if (keyNode->data < current->data) {
            successor = current;
            current = current->left;
        }
        else if (keyNode->data > current->data) {
            current = current->right;
        }
        else {
            break;
        }
    }

    return successor;
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

    Node* successor = inorderSuccessor(root, keyNode);

    if (successor)
        cout << "In-order successor of " << key << " is: " << successor->data;
    else
        cout << "No in-order successor exists for " << key;

    return 0;
}