#include <bits/stdc++.h>
using namespace std;

void RotateImage(vector<vector<int>>& matrix) {
  // transposing the matrix
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = i; j < matrix[0].size(); j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // reversing each row
  for (int i = 0; i < matrix.size(); i++) {
    int j = 0, k = matrix.size() - 1;
    while (j < k) {
      swap(matrix[i][j], matrix[i][k]);
      j++;
      k--;
    }
  }
}

int main() {
  vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> matrix2 = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

  // performing rotation of the matrix    
  RotateImage(matrix2);

  //printing the rotated array 
  for (int i = 0; i < matrix2.size(); i++) {
    cout << "{ ";
    for (int j = 0; j < matrix2[0].size(); j++) {
      cout << matrix2[i][j] << " ";
    }

    cout << "}";
    cout << endl;
  }

  return 0;
}