#include <iostream>
using namespace std;
// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Insert a node into the BST
Node* insertBST(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else
        root->right = insertBST(root->right, value);

    return root;
}

// In-order traversal (Left, Root, Right)
void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Pre-order traversal (Root, Left, Right)
void preOrder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Post-order traversal (Left, Right, Root)
void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    int data[] = {50, 30, 20, 40, 70, 60, 80};
    int size = sizeof(data) / sizeof(data[0]);
     Node* root = nullptr;
    for (int i = 0; i < size; ++i)
        root = insertBST(root, data[i]);

    // Perform traversals
    cout << "In-order Traversal   : ";
    inOrder(root);
    cout << endl;

    cout << "Pre-order Traversal  : ";
    preOrder(root);
    cout << endl;
    cout << "Post-order Traversal : ";
    postOrder(root);
    cout << endl;
     return 0;
}
