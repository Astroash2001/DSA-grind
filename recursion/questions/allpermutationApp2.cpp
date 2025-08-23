#include <bits/stdc++.h>
using namespace std;

void check(int index, vector<int>& nums, vector<vector<int>>& res) {
  if (index == nums.size()) {
    res.push_back(nums);
    return;
  }
  for (int i = index; i < nums.size(); i++) {
    swap(nums[index], nums[i]);
    check(index + 1, nums, res);
    swap(nums[index], nums[i]);
  }
}

vector<vector<int>> allPermutationApp2(vector<int>& nums) {
  vector<vector<int>> res;
  check(0, nums, res);
  return res;
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res = allPermutationApp2(nums);

  for (auto it : res) {
    for (auto x : it) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}