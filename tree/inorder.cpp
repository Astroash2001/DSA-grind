#include <bits/stdc++.h>
using namespace std;
// structure of tree
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

  // marking the root
  Node* root = new Node(arr[idx]);
  // making the left subtree
  root->left = BuildTree(arr);
  // making the right subtree
  root->right = BuildTree(arr);

  return root;
}

void inorder(Node* root) {
  if (root == nullptr) {
    return;
  }

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void printTree(Node* root) {
  if (root == nullptr) {
    return;
  }
  cout << root->data << " ";
  printTree(root->left);
  printTree(root->right);
}

int main() {
  vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  Node* root = BuildTree(arr);
  cout << "The preorder of the tree is: ";
  printTree(root);
  cout << "\n";
  cout << "The inorder of the tree is: ";
  inorder(root);

  return 0;
}