#include <bits/stdc++.h>
using namespace std;

bool search(vector<vector<char>>& grid, int row, int col, string word, int k) {
  // base cases
  if (k == word.length()) {
    return true;
  }

  if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ||
      grid[row][col] != word[k]) {
    return false;
  }
  char presentChar = grid[row][col];
  grid[row][col] = '#';
  bool res = search(grid, row + 1, col, word, k + 1) ||
             search(grid, row - 1, col, word, k + 1) ||
             search(grid, row, col + 1, word, k + 1) ||
             search(grid, row, col - 1, word, k + 1);
  grid[row][col] = presentChar;
  return res;
}

bool searchWord(vector<vector<char>>& grid, int row, int col, string word) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (grid[i][j] == word[0]) {
        if (search(grid, i, j, word, 0)) {
          return true;
        }
      }
    }
  }

  return false;
}

int main() {
  vector<vector<char>> grid = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "ABCCED";
  int row = grid.size();
  int col = grid[0].size();
  bool res = searchWord(grid, row, col, word);
  cout << res;
  return 0;
}