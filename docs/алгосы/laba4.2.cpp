#include <iostream>
using namespace std;

struct Node_tree {
    int data;
    Node_tree* left;
    Node_tree* right;
};

Node_tree* create_Node_tree(int data) {
    Node_tree* newNode = new Node_tree;
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
Node_tree* push(Node_tree* root, int data) {
    if (root == NULL) {
        return create_Node_tree(data);
    }
    if (data < root->data) {
        root -> left = push(root -> left, data);
    }
    else if (data > root->data) {
        root -> right = push(root -> right, data);
    }
    return root;
}

bool search(Node_tree* root, int data) {
    if (root == NULL) {
        return false;
    }
    if (root -> data == data) {
        return true;
    }
    if (data < root -> data) {
        return search(root -> left, data);
    }
    return search(root -> right, data);
}
Node_tree* findPrevious(Node_tree* root) {
    while (root != NULL && root -> left != NULL) {
        root = root -> left;
    }
    return root;
}

Node_tree* pop(Node_tree* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root -> data) {
        root -> left = pop(root -> left, data);
    }
    else if (data > root  ->data) {
        root -> right = pop(root -> right, data);
    }
    else {
        if (root -> left == NULL) {
            Node_tree* temp = root -> right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            Node_tree* temp = root -> left;
            delete root;
            return temp;
        }
        Node_tree* temp = findPrevious(root -> right);
        root -> data = temp -> data;
        root -> right = pop(root -> right, temp -> data);
    }
    return root;
}
int find_next(Node_tree* root, int data) {
    int result = -1;
    while (root != NULL) {
        if (root -> data > data) {
            result = root -> data;
            root = root -> left;
        }
        else {
            root = root -> right;
        }
    }
    return result;
}

int findPrevious(Node_tree* root, int data) {
    int result = -1;
    while (root != NULL) {
        if (root -> data < data) {
            result = root -> data;
            root = root -> right;
        } else {
            root = root -> left;
        }
    }
    return result;
}

int main() {
    Node_tree* root = NULL;
    int operations;
    int x;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> operations >> x) {
        if (operations == 0) {
            root = push(root, x);
        }
        else if (operations == 1) {
            root = pop(root, x);
        }
        else if (operations == 2) {
            if (search(root, x)) {
                cout << "true\n";
            }
            else {
                cout << "false\n";
            }
        }
        else if (operations == 3) {
            int next = find_next(root, x);
            if (next == -1) {
                cout << "none\n";
            } else {
                cout << next << "\n";
            }
        }
        else if (operations == 4) {
            int previous = findPrevious(root, x);
            if (previous == -1) {
                cout << "none\n";
            } else {
                cout << previous << "\n";
            }
        }
    }
    return 0;
}