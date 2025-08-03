#include <bits/stdc++.h>
using namespace std;

bool TargetSumSingleSub(int i, vector<int> ds, int arr[], int n, int target) {
  if (i == n) {
    int sum = 0;
    for (auto it : ds) {
      sum = sum + it;
    }
    if (sum == target) {
      for (auto it : ds) {
        cout << it << " ";
      }
      cout << endl;
      return true;
    }

    else
      return false;
  }

  ds.push_back(arr[i]);
  if (TargetSumSingleSub(i + 1, ds, arr, n, target) == true) return true;
  ds.pop_back();
  if (TargetSumSingleSub(i + 1, ds, arr, n, target) == true) return true;
  return false;
}

int main() {
  int arr[] = {2, 3, 5};
  vector<int> ds;
  int target = 5;
  int n = 3;
  TargetSumSingleSub(0, ds, arr, n, target);

  return 0;
}