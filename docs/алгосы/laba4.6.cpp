#include <iostream>
#include <climits>
using namespace std;

struct Node {
    long long value;
    Node* left;
    Node* right;
    bool BST;

    Node(long long val) {
        value = val;
        left = NULL;
        right = NULL;
        BST = false;
    }
};

struct TreeInfo {
    bool BST;
    long long min_of_val;
    long long max_of_val;
    long long treSum;
};

TreeInfo calculate_of_BST(Node* node, long long& max_of_sum) {
    if (node == NULL) {
        return { true, 1000000001, -1000000001, 0 };
    }

    TreeInfo info_of_left = calculate_of_BST(node -> left, max_of_sum);
    TreeInfo info_of_right = calculate_of_BST(node -> right, max_of_sum);

    bool teckBST = info_of_left.BST && info_of_right.BST &&
        (info_of_left.max_of_val < node -> value) &&
        (info_of_right.min_of_val > node -> value);

    node -> BST = teckBST;

    long long teckSum = node -> value + info_of_left.treSum + info_of_right.treSum;

    if (teckBST) {
        if (teckSum > max_of_sum) {
            max_of_sum = teckSum;
        }
    }

    long long min_of_val;
    if (node -> value < info_of_left.min_of_val) {
        min_of_val = node -> value;
    }
    else {
        min_of_val = info_of_left.min_of_val;
    }

    long long max_of_val;
    if (node -> value > info_of_right.max_of_val) {
        max_of_val = node -> value;
    }
    else {
        max_of_val = info_of_right.max_of_val;
    }

    return { teckBST, min_of_val, max_of_val, teckSum };
}

void construct_Sub_tree(Node* node) {
    char operations;
    while (cin >> operations) {
        if (operations == 'l') {
            long long val;
            cin >> val;
            node -> left = new Node(val);
            construct_Sub_tree(node -> left);
        }
        else if (operations == 'r') {
            long long val;
            cin >> val;
            node -> right = new Node(val);
            construct_Sub_tree(node -> right);
        }
        else if (operations == 'u') {
            return;
        }
    }
}

Node* build_of_Tree() {
    long long rootValue;
    cin >> rootValue;
    Node* rootNode = new Node(rootValue);
    construct_Sub_tree(rootNode);
    return rootNode;
}

int main() {
    Node* rootNode = build_of_Tree();

    long long max_of_sum = 0;

    calculate_of_BST(rootNode, max_of_sum);

    cout << max_of_sum << '\n';

    return 0;
}