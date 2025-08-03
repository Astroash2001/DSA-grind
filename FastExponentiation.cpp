#include <bits/stdc++.h>
using namespace std;

long long Power(long long base, long long exp) {
  long long res = 1;
  long long mod = 1e9 + 7;

  base = base % mod;
  while (exp > 0) {
    if (exp % 2 == 1) {
      res = (res * base) % mod;
    }

    base = (base * base) % mod;  // squaring the base for faster calculation
    exp = exp / 2;               // same as floor function
  }

  return res;
}

int main() {
  int base = 2;
  int exp = 10;
  int res = Power(base, exp);
  cout << base << "^" << exp << ":" << res << endl;

  return 0;
}