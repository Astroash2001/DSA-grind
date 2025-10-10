#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

static int idx = -1;
Node* BuildTree(vector<int>& arr) {
  idx++;
  if (arr[idx] == -1) {
    return NULL;
  }
  // creating the root node
  Node* root = new Node(arr[idx]);

  // creating the left subtree
  root->left = BuildTree(arr);

  // creating the right subtree
  root->right = BuildTree(arr);

  return root;
}

void PostOrderTraversal(Node* root) {
  if (root == nullptr) {
    return;
  }

  PostOrderTraversal(root->left);
  PostOrderTraversal(root->right);
  cout << root->data << " ";
}

void PrintTree(Node* root) {
  if (root == nullptr) {
    return;
  }
  cout << root->data << " ";
  PrintTree(root->left);
  PrintTree(root->right);
}
int main() {
  vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  Node* root = BuildTree(arr);
  cout << "Initial Tree: ";
  PrintTree(root);
  cout << endl;
  cout << "The Post-order Traversal would be : ";
  PostOrderTraversal(root);

  return 0;
}