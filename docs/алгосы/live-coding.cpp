#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

Node* push(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data < root -> data) {
        root -> left = push(root -> left, data);
    } 
    else {
        root -> right = push(root -> right, data);
    }
    return root;
}

void findMinMaxDepth(Node* root, int current_depth, int& min_depth, int& max_depth) {
    if (root == NULL) return;

    if (!root -> left && !root -> right) {
        min_depth = min(min_depth, current_depth);
        max_depth = max(max_depth, current_depth);
        return;
    }

    findMinMaxDepth(root -> left, current_depth + 1, min_depth, max_depth);
    findMinMaxDepth(root -> right, current_depth + 1, min_depth, max_depth);
}

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    Node* root = NULL;
    for (int i = 0; i < n; ++i) {
        int height;
        cin >> height;
        root = push(root, height);
    }

    int min_depth = 1000000;
    int max_depth = -1000000;

    findMinMaxDepth(root, 1, min_depth, max_depth);
;
    cout << max_depth - min_depth;

    return 0;
}
