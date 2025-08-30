#include <bits/stdc++.h>
using namespace std;

void SetMatrixZeroes(vector<vector<int>>& mat) {
  int row = mat.size();
  int col = mat[0].size();
  bool isFirstCol0 = false;
  // checking the first col has zero or not
  for (int i = 0; i < row; i++) {
    if (mat[i][0] == 0) {
      isFirstCol0 = true;
      break;
    }
  }
  // now marking the different rows and col with zero in them skipping the
  // first column
  for (int i = 0; i < row; i++) {
    for (int j = 1; j < col; j++) {
      if (mat[i][j] == 0) {
        mat[0][j] = 0;  // first element of that col is marked zero as a
                        // marker
        mat[i][0] = 0;  // first element of that row is marker zero as a
                        // marker
      }
    }
  }

  // now filling the rows and cols with zero based on the marker
  for (int i = 1; i < row; i++) {
    for (int j = 1; j < col; j++) {
      if (mat[i][0] == 0 || mat[0][j] == 0) {
        mat[i][j] = 0;
      }
    }
  }

  // checking is matrix[0][0] == 0 then making entire row filled with zero
  if (mat[0][0] == 0) {
    for (int j = 0; j < col; j++) {
      mat[0][j] = 0;
    }
  }

  // checking the isFirstCol0 if true then filling them with zero
  if (isFirstCol0) {
    for (int i = 0; i < row; i++) {
      mat[i][0] = 0;
    }
  }
}

int main() {
  vector<vector<int>> matrix1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  vector<vector<int>> matrix2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  SetMatrixZeroes(matrix2);
  for (int i = 0; i < matrix2.size(); i++) {
    cout << "{";
    for (int j = 0; j < matrix2[0].size(); j++) {
      cout << matrix2[i][j] << " ";
    }
    cout << "}";
    cout << endl;
  }
  return 0;
}