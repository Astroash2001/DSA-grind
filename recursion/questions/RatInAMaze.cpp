#include <bits/stdc++.h>
using namespace std;

void RatInAMaze(vector<vector<int>>& mat, int row, int col, vector<string>& ans,
                string path) {
  // base cases---->

  if (row < 0 || col < 0 || row >= mat.size() || col >= mat[0].size() ||
      mat[row][col] == 0 || mat[row][col] == -1) {
    return;
  }

  if (row == mat.size() - 1 && col == mat[0].size() - 1) {
    ans.push_back(path);
    return;
  }
  //<--------

  //-------> marking the visited cell true
  mat[row][col] = -1;                              // visit
  RatInAMaze(mat, row + 1, col, ans, path + "D");  // down
  RatInAMaze(mat, row - 1, col, ans, path + "U");  // up
  RatInAMaze(mat, row, col - 1, ans, path + "L");  // left
  RatInAMaze(mat, row, col + 1, ans, path + "R");  // right

  // backtrack step
  mat[row][col] = 1;  // not visit
}

vector<string> findPath(vector<vector<int>>& mat) {
  int n = mat.size();
  vector<string> ans;

  // Check if start or end is blocked
  if (n == 0 || mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
    return ans;
  }

  string path = "";
  RatInAMaze(mat, 0, 0, ans, path);
  return ans;
}

int main() {
  int row, col = 0;
  vector<vector<int>> mat = {
      {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

  vector<string> ans = findPath(mat);

  for (auto x : ans) {
    cout << x << " ";
  }

  return 0;
}