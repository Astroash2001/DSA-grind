#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* left;
  Node* right;

  // constructor
  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};
static int idx = -1;
Node* buildTree(vector<int> preorder) {
  idx++;

  if (preorder[idx] == -1) {
    return NULL;
  }
  // assigning the root node
  Node* root = new Node(preorder[idx]);

  // making the left node
  root->left = buildTree(preorder);

  // making the right node
  root->right = buildTree(preorder);

  return root;
}

int main() {
  vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  Node* root = buildTree(preorder);
  cout << root->data << endl;
  return 0;
}