#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> ans(nums.size(), 1);

  // calculating the prefix product
  int prefix_prod = 1;
  for (int i = 0; i < nums.size(); i++) {
    ans[i] = ans[i] * prefix_prod;
    prefix_prod = prefix_prod * nums[i];
  }

  // calculating the suffix product
  int suffix_prod = 1;
  for (int i = nums.size() - 1; i >= 0; i--) {
    ans[i] = ans[i] * suffix_prod;
    suffix_prod = suffix_prod * nums[i];
  }
  return ans;
}
int main() {
  vector<int> nums = {1, 2, 3, 4};
  vector<int> ans = productExceptSelf(nums);
  for (auto x : ans) {
    cout << x << " ";
  }

  return 0;
}