#include <bits/stdc++.h>
using namespace std;

int MaximumProductSubarray(vector<int> nums, int start, int end) {
  int max_prod = 1;
  int prod = 1;

  if (start == nums.size()) return;
  if (end == nums.size()) {
    MaximumProductSubarray(nums, start + 1, start + 1);
    return;
  }
  for (int i = start; i <= end; i++) {
    prod = prod * nums[i];
  }
  max_prod = max(max_prod, prod);
  MaximumProductSubarray(nums, start, end + 1);
  return max_prod;
}

int main() {
  vector<int> nums = {2, 3, -2, 4};
  return 0;
}