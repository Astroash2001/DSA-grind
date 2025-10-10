#include <bits/stdc++.h>
using namespace std;

// structure of tree
class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {  // constructor
    data = val;
    left = right = nullptr;
  }
};

static int idx = -1;
Node* buildTree(vector<int>& preorderarr) {
  idx++;
  if (preorderarr[idx] == -1) {
    return NULL;
  }

  Node* root = new Node(preorderarr[idx]);
  root->left = buildTree(preorderarr);
  root->right = buildTree(preorderarr);

  return root;
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
  vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  Node* root = buildTree(preorder);
  printTree(root);

  return 0;
}