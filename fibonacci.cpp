#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
  // this fuunction is an example of multiple
  // recursion calls

  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int n;
  cout << "Enter the required value n: ";
  cin >> n;
  cout << "The fibonacci series is: ";
  for (int i = 0; i <= n; i++) {
    cout << fibonacci(i) << " ";
  }

  return 0;
}