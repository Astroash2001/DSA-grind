#include <bits/stdc++.h>
using namespace std;

void pushTillN(int n, vector<int>& nums) {
  for (int i = 1; i <= n; i++)

  {
    nums.push_back(i);
  }
}

void permutation(int n, int index, vector<int>& nums,
                 vector<vector<int>>& res) {
  if (index == n) {
    res.push_back(nums);
    return;
  }
  for (int i = 1; i < n; i++) {
    swap(nums[index], nums[i]);
    permutation(n, index + 1, nums, res);
    swap(nums[index], nums[i]);
  }
}

int main() {
  int n = 3;
  int k = 4;
  vector<int> nums;
  pushTillN(n, nums);
  vector<vector<int>> res;
  permutation(n, 0, nums, res);
  sort(res.begin(), res.end());

  for (int num : res[k - 1]) {
    cout << num;
  }
  cout << endl;

  return 0;
}