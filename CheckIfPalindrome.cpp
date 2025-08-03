#include <bits/stdc++.h>
using namespace std;

string arr = "wqhwejldf";
int n = arr.size();
bool CheckPalindromeByRecursion(int i) {
  if (i >= n / 2) {
    return true;
  }

  if (arr[i] != arr[n - i - 1]) {
    return false;
  }

  return CheckPalindromeByRecursion(i + 1);
}

int main() {
  bool res = CheckPalindromeByRecursion(0);
  if (res == true) {
    cout << "It is a palindrome!" << endl;
  }

  else {
    cout << "Not a palindrome!" << endl;
  }

  return 0;
}
