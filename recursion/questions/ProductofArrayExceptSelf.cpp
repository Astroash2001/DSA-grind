#include <bits/stdc++.h>
using namespace std;

vector<int> ProductofArrayExceptSelf(vector<int>& nums) {
  vector<int> ans(nums.size());
  int prefix_prod = 1;
  for (int i = 0; i < nums.size(); i++) {
    ans[i] = prefix_prod;
    prefix_prod = prefix_prod * nums[i];
  }

  int suffix_prod = 1;
  for (int i = nums.size() - 1; i >= 0; i--) {
    ans[i] = ans[i] * suffix_prod;
    suffix_prod = suffix_prod * nums[i];
  }

  return ans;
}

int main() {
  vector<int> nums = {1, 2, 3, 4};
  vector<int> res = ProductofArrayExceptSelf(nums);
  for (auto x : res) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}