#include <bits/stdc++.h>
using namespace std;

vector<int> SpiralMatrix(vector<vector<int>>& Matrix) {
  int left = 0;
  int right = Matrix[0].size() - 1;
  int top = 0;
  int bottom = Matrix.size() - 1;
  vector<int> res;
  while (left <= right && top <= bottom) {
    // traversing the first row
    for (int j = left; j <= right; j++) {
      res.push_back(Matrix[top][j]);
    }
    top++;

    // traversing the righmost column
    for (int i = top; i <= bottom; i++) {
      res.push_back(Matrix[i][right]);
    }
    right--;

    // traversing the bottom most row
    if (top <= bottom)  // edge case check for single row
    {
      for (int j = right; j >= left; j--) {
        res.push_back(Matrix[bottom][j]);
      }

      bottom--;
    }

    // traversing the remaining element of the first col
    if (left <= right)  // edge case for single columns check
    {
      for (int i = bottom; i >= top; i--) {
        res.push_back(Matrix[i][left]);
      }
      left++;
    }
  }
  return res;
}

int main() {
  vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  vector<int> res = SpiralMatrix(matrix2);

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}