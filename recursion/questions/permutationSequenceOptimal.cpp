#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) {
  vector<int> fact(n + 1, 1);
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;

  vector<int> numbers;
  for (int i = 1; i <= n; i++) numbers.push_back(i);

  string ans = "";
  k--;  // 0-indexed

  for (int i = n; i >= 1; i--) {
    int index = k / fact[i - 1];
    ans += to_string(numbers[index]);
    numbers.erase(numbers.begin() + index);
    k %= fact[i - 1];
  }
  return ans;
}

int main() {
  int n = 3;
  int k = 3;
  string ans = getPermutation(n, k);

  for (auto x : ans) {
    cout << x << " ";
  }
  return 0;
}