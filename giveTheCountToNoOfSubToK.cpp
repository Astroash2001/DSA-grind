#include <bits/stdc++.h>
using namespace std;

void GiveCountToNoOfSubToK(int i, vector<int> ds, int arr[], int n, int target,
                           int& count) {
  if (i == n) {
    int sum = 0;
    for (auto it : ds) {
      sum = sum + it;
    }

    if (sum == target) {
      count++;
    }

    return;
  }
  ds.push_back(arr[i]);
  GiveCountToNoOfSubToK(i + 1, ds, arr, n, target, count);
  ds.pop_back();
  GiveCountToNoOfSubToK(i + 1, ds, arr, n, target, count);
}

int main() {
  int arr[] = {2, 3, 5};
  vector<int> ds;
  int n = 3;
  int target = 5;
  int count = 0;
  GiveCountToNoOfSubToK(0, ds, arr, n, target, count);
  cout << "The total number of subsequence which adds up to target is :"
       << count << endl;
  return 0;
}