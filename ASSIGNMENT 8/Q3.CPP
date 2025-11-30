//ASSIGNMENT 8 QUESTION 3
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

// Insert
Node* insertNode(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);

    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

// Find Minimum (Used for deletion)
Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

// Delete a Node
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {

        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Maximum Depth of BST
// Height = longest path from root to leaf
int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

// Minimum Depth of BST
// Smallest path from root to any leaf
int minDepth(Node* root) {
    if (root == nullptr)
        return 0;

    // If one child is NULL, return depth of the other
    if (root->left == nullptr)
        return 1 + minDepth(root->right);
    if (root->right == nullptr)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = nullptr;

    // Insert elements
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values)
        root = insertNode(root, v);

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    // Delete example
    root = deleteNode(root, 50);
    cout << "After deleting 50, Max Depth: " << maxDepth(root) << endl;

    return 0;
}