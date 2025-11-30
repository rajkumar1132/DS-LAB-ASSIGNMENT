//ASSIGNMENT 8 QUESTION 4
//ROLL NO.: 1024031132

#include <iostream>
#include <climits>
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

bool isBSTUtil(Node* root, long minVal, long maxVal) {
    if (root == nullptr)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    if (isBST(root))
        cout << "The given tree IS a BST\n";
    else
        cout << "The given tree is NOT a BST\n";

    return 0;
}