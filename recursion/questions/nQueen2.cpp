#include <bits/stdc++.h>
using namespace std;

bool isSafe(int n, vector<string>& board, int row, int col) {
  // horizontal check
  for (int j = 0; j < n; j++) {
    if (board[row][j] == 'Q') {
      return false;
    }
  }

  // vertical check
  for (int i = 0; i < n; i++) {
    if (board[i][col] == 'Q') {
      return false;
    }
  }

  // left diagonal check
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 'Q') {
      return false;
    }
  }

  // right diagonal check
  for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    if (board[i][j] == 'Q') {
      return false;
    }

  return true;
}

void Nqueen2(int n, vector<vector<string>>& res, vector<string>& board,
             int row) {
  if (row == n) {
    res.push_back(board);
    return;
  }

  for (int j = 0; j < n; j++) {
    if (isSafe(n, board, row, j)) {
      board[row][j] = 'Q';
      Nqueen2(n, res, board, row + 1);
      board[row][j] = '.';
    }
  }
}

int main() {
  vector<vector<string>> res;
  int n = 4;
  vector<string> board(n, string(n, '.'));
  Nqueen2(n, res, board, 0);
  cout << res.size();

  return 0;
}