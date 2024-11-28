#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Node* push(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root -> data) {
        root -> left = push(root -> left, data);
    } else if (data > root->data) {
        root -> right = push(root -> right, data);
    }
    return root;
}

void recursion_order(Node* node) {
    if (node == NULL) return;
    recursion_order(node -> left);
    cout << node -> data << " ";
    recursion_order(node -> right);
}

int main() {
    int n;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        root = push(root, data);
    }

    recursion_order(root);

    return 0;
}