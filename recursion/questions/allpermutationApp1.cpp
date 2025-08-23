#include <bits/stdc++.h>

#include <iostream>
using namespace std;

void check(vector<int>& nums, vector<vector<int>>& res, vector<int>& ds, int freq[])
{
  if (ds.size() == nums.size()) {
    res.push_back(ds);
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (!freq[i]) {
      ds.push_back(nums[i]);       // passing the present element to ds
      freq[i] = 1;                 // marking the present element that is passed
      check(nums, res, ds, freq);  // recursively calling;
      ds.pop_back();  // removing the element to explore more options
      freq[i] = 0;    // marking the present element zero
    }
  }
}

vector<vector<int>> allPermutation(vector<int>& nums) {
  vector<vector<int>> res;
  vector<int> ds;
  int freq[nums.size()];

  for (int i = 0; i < nums.size(); i++) {
    freq[i] = 0;
  }
  check(nums, res, ds, freq);
  return res;
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res = allPermutation(nums);
  for (auto it : res) {
    for (auto x : it) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}