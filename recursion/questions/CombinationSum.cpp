#include <bits/stdc++.h>
using namespace std;

void CombinationSum(int index, int target, vector<int> &ds, vector<int> &arr,
                    vector<vector<int>> &res) {
  if (index == arr.size()) {
    if (target == 0) {
      res.push_back(ds);
    }
    return;
  }
  // making all the subsequences by picking and not picking
  // picking up

  if (arr[index] <= target) {
    ds.push_back(arr[index]);
    CombinationSum(index, target - arr[index], ds, arr, res);
    ds.pop_back();
  }
  // not picking up
  CombinationSum(index + 1, target, ds, arr, res);
}

vector<vector<int>> FinalCombinationSum(vector<int> &arr, int target) {
  vector<vector<int>> res;
  vector<int> ds;
  CombinationSum(0, target, ds, arr, res);
  return res;
}

int main() {
  vector<int> arr = {2, 3, 6, 7};
  int target = 7;
  vector<vector<int>> res = FinalCombinationSum(arr, target);
  for (auto it : res) {
    for (auto num : it) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}