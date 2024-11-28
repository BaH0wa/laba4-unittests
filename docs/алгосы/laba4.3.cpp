#include <iostream>
using namespace std;

struct Node {
    int data;
    int subtreeSize;
    Node* left;
    Node* right;

    Node(int val) : data(val), subtreeSize(1), left(NULL), right(NULL) {}
};

class Tree {
public:
    Node* root;

    Tree() : root(NULL) {}

    // Вставка элемента
    Node* push(Node* node, int data) {
        if (!node) return new Node(data);

        if (data < node->data) {
            node -> left = push(node -> left, data);
        } else {
            node -> right = push(node -> right, data);
        }

        update_size(node);
        return balance(node);
    }

    // Удаление элемента
    Node* pop(Node* node, int data) {
        if (!node) return NULL;

        if (data < node -> data) {
            node -> left = pop(node -> left, data);
        } else if (data > node -> data) {
            node -> right = pop(node -> right, data);
        } else {
            // Удаление найденного узла
            if (!node -> left) {
                Node* rightNode = node -> right;
                delete node;
                return rightNode;
            } else if (!node -> right) {
                Node* leftNode = node -> left;
                delete node;
                return leftNode;
            } else {
                Node* minNode = find_node_min(node -> right);
                node -> data = minNode -> data;
                node -> right = pop(node -> right, minNode -> data);
            }
        }

        update_size(node);
        return balance(node);
    }

    // Найти k-й максимум
    int find_k_max(Node* node, int k) {
        int sizeOfRight = node -> right ? node -> right -> subtreeSize : 0;

        if (k == sizeOfRight + 1) {
            return node -> data;
        } else if (k <= sizeOfRight) {
            return find_k_max(node -> right, k);
        } else {
            return find_k_max(node -> left, k - sizeOfRight - 1);
        }
    }

    Node* rotate_Right(Node* y) {
        Node* x = y -> left;
        Node* T2 = x -> right;

        x -> right = y;
        y -> left = T2;

        update_size(y);
        update_size(x);
        return x;
    }

    Node* rotate_Left(Node* x) {
        Node* y = x -> right;
        Node* T2 = y -> left;

        y -> left = x;
        x -> right = T2;

        update_size(x);
        update_size(y);
        return y;
    }

    Node* balance(Node* node) {
        int balanceFactor = balance_factor(node);
        if (balanceFactor > 1) {
            if (balance_factor(node -> left) < 0) {
                node -> left = rotate_Left(node -> left);
            }
            return rotate_Right(node);
        } else if (balanceFactor < -1) {
            if (balance_factor(node -> right) > 0) {
                node -> right = rotate_Right(node -> right);
            }
            return rotate_Left(node);
        }
        return node;
    }

    Node* find_node_min(Node* node) {
        while (node -> left) node = node -> left;
        return node;
    }

    int balance_factor(Node* node) {
        if (!node) return 0;
        return (node -> left ? node -> left -> subtreeSize : 0) - (node -> right ? node -> right -> subtreeSize : 0);
    }

    void update_size(Node* node) {
        if (node) {
            node -> subtreeSize = 1 + (node -> left ? node -> left -> subtreeSize : 0) + (node -> right ? node -> right -> subtreeSize : 0);
        }
    }
};

int main() {
    Tree tree;
    int n;
    cin >> n;
    
    string conclusion;  // Строка для накопления всех результатов команд `0 k`
    
    while (n--) {
        int operations, k;
        cin >> operations >> k;

        if (operations == 1) {
            tree.root = tree.push(tree.root, k);
        } else if (operations == 0) {
            conclusion += to_string(tree.find_k_max(tree.root, k)) + '\n';
        } else if (operations == -1) {
            tree.root = tree.pop(tree.root, k);
        }
    }
    
    cout << conclusion;

    return 0;
}