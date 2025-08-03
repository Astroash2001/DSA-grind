#include <bits/stdc++.h>
using namespace std;

int Factorial(int n) {
  if (n == 1) {
    return 1;
  }

  return n * Factorial(n - 1);
}

int main() {
  int n;
  cout << "Enter the number whoese factorial you want!" << endl;
  cin >> n;
  int res = Factorial(n);
  cout << "The factorial of " << n << " is : " << res << endl;

  return 0;
}