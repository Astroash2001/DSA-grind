#include <bits/stdc++.h>
using namespace std;

//function to check and get the coordinates of the places where '.' is present 
bool Is0Present(vector<vector<char>> &board, int &row, int &col) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == '.') {
        row = i;
        col = j;
        return true;
      }
    }
  }

  return false;
}

// is the number being put logically correct as per the rules of the sudoku 
bool isLegal(vector<vector<char>> &board, int row, int col, int num) {
  char charNum = char(num + '0');
  // checking the col
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == charNum) {
      return false;
    }
  }

  // checking the row
  for (int j = 0; j < 9; j++) {
    if (board[row][j] == charNum) {
      return false;
    }
  }

  // checking the subgrid 3*3
  int startRow = row - row % 3;
  int startCol = col - col % 3;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[startRow + i][startCol + j] == charNum) {
        return false;
      }
    }
  }

  return true;
}

//wrapper function which runs and recursively calls itself to solve the sudoku
bool sudokuSolver(vector<vector<char>> &board) {
  int row;
  int col;
  if (!Is0Present(board, row, col)) {
    return true;
  }
  for (int i = 1; i < 10; i++) {
    if (isLegal(board, row, col, i)) {
      board[row][col] = char(i + '0');

      if (sudokuSolver(board)) {
        return true;
      }

      board[row][col] = '.';
    }
  }
  return false;
}

//function to print the sudoku in a presentable way
void printBoard(const vector<vector<char>> &board) {
  cout << "+-------+-------+-------+" << endl;
  for (int i = 0; i < 9; ++i) {
    cout << "| ";
    for (int j = 0; j < 9; ++j) {
      cout << board[i][j] << " ";
      if ((j + 1) % 3 == 0) {
        cout << "| ";
      }
    }
    cout << endl;
    if ((i + 1) % 3 == 0) {
      cout << "+-------+-------+-------+" << endl;
    }
  }
}

int main() {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  cout << "Unsolved Sudoku Puzzle:" << endl;
  printBoard(board);
  cout << endl;

  if (sudokuSolver(board)) {
    cout << "Sudoku Solved Successfully!" << endl;
    printBoard(board);
  } else {
    cout << "This Sudoku puzzle is unsolvable." << endl;
  }

  return 0;
}