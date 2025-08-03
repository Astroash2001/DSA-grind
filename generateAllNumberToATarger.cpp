#include <bits/stdc++.h>

#include <numeric>
using namespace std;

void TargetSum(int i, vector<int> &ds, int arr[], int target, int n) {
  if (i == n) {
    int sum = 0;
    for (auto it : ds) {
      sum = sum + it;
    }
    if (sum == target) {
      if (ds.empty()) {
        cout << "{}";
      }

      else {
        for (auto it : ds) {
          cout << it << " ";
        }
      }
      cout << endl;
    }
    return;
  }

  ds.push_back(arr[i]);
  TargetSum(i + 1, ds, arr, target, n);
  ds.pop_back(); 
  TargetSum(i + 1, ds, arr, target, n);
}

int main() {
  int arr[] = {2, 3, 5};
  int target = 5;
  int n = 3;
  vector<int> ds;
  TargetSum(0, ds, arr, target, n);

  return 0;
}