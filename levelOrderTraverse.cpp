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
Node* buildTree(vector<int>& arr) {
  idx++;
  if (arr[idx] == -1) {
    return nullptr;
  }
  Node* root = new Node(arr[idx]);

  root->left = buildTree(arr);
  root->right = buildTree(arr);

  return root;
}

void LevelOrderTraversal(Node* root) {
  if (root == nullptr) return;

  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    Node* curr = q.front();
    q.pop();

    if (curr == NULL) {
      cout << endl;
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {
      cout << curr->data << " ";
      if (curr->left) q.push(curr->left);
      if (curr->right) q.push(curr->right);
    }
  }
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
  Node* root = buildTree(arr);
  cout << "Initial Tree: ";
  printTree(root);
  cout << endl;
  cout << "The Post-order Traversal would be : " << endl;
  LevelOrderTraversal(root);
  return 0;
}