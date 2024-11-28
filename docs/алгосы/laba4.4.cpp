#include <iostream>
using namespace std;

struct Node {
 int data;
 Node* left, * right;

 Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* push(Node* root, int data)
{
 if (root == NULL) {
  return new Node(data);
 }

 if (data < root  ->  data) {
  root  ->  left = push(root  ->  left, data);
 }
 else if (data > root  ->  data) {
  root  ->  right = push(root  ->  right, data);
 }

 return root;
}


void last_right_on_level(Node* root, int level, int& max_level)
{
 if (!root) {
  return;
 }

 if (level > max_level) {
  cout << root -> data << " ";
  max_level = level;
 }

 if (root -> right) {
  last_right_on_level(root -> right, level + 1, max_level);
 }

 if (root -> left) {
  last_right_on_level(root -> left, level + 1, max_level);
 }
}

void conclusion(Node* root) {
 if (!root) {
  return;
 }

 int max_level = -1;

 last_right_on_level(root, 0, max_level);

 cout << '\n';
}


int main() {
 int n,k;
 cin >> n;

 Node* root = NULL;

 for (int i = 0; i < n; ++i) {
  cin >> k;
  root = push(root, k);
 }

 conclusion(root);

 return 0;
}