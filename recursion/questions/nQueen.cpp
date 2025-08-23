#include <bits/stdc++.h>
using namespace std;

// function to check the wheather the queen is safe to be kept
bool isSafe(int n, vector<string> board, int row, int col) {
  // for horizontal check
  for (int j = 0; j < n; j++) {
    if (board[row][j] == 'Q') {
      return false;
    }
  }

  // for vertical check
  for (int i = 0; i < n; i++) {
    if (board[i][col] == 'Q') {
      return false;
    }
  }

  // for left diagonal check here while moving the row decreases by 1 and col
  // also decreases by 1
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 'Q') {
      return false;
    }
  }

  // right diagonal here the row decraeae by 1 and col increase by 1
  for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
    if (board[i][j] == 'Q') {
      return false;
    }
  }

  return true;  // if nothing is false
}

// function to put the queens
void puttingQueens(int n, vector<vector<string>>& res, vector<string> board,
                   int row) {
  if (row == n) {
    res.push_back(board);
    return;
  }
  for (int j = 0; j < n; j++) {
    if (isSafe(n, board, row, j)) {
      board[row][j] = 'Q';
      puttingQueens(n, res, board, row + 1);
      board[row][j] = '.';
    }
  }
}

void nQueen(int n, vector<vector<string>>& res, vector<string> board, int row) {
  puttingQueens(n, res, board, 0);

  for (auto it : res) {
    cout << '[';
    for (int i = 0; i < it.size(); i++) {
      cout << it[i];
      if (i < it.size() - 1) cout << ',';
    }
    cout << ']';
    cout << endl;
  }
}

int main() {
  int n = 4;
  vector<vector<string>> res;
  vector<string> board(n, string(n, '.'));
  int row = 0;  // Start from row 0, not n
  nQueen(n, res, board, row);

  return 0;
}