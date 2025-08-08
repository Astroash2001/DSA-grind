#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int>& arr, int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  vector<int> res;
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      res.push_back(arr[left]);
      left++;
    }

    else {
      res.push_back(arr[right]);
      right++;
    }
  }

  while (left <= mid) {
    res.push_back(arr[left]);
    left++;
  }

  while (right <= high) {
    res.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++) {
    arr[i] = res[i - low];
  }
}

void MergeSort(vector<int>& arr, int low, int high) {
  if (low >= high) {
    return;
  }

  int mid = (low + high) / 2;
  MergeSort(arr, low, mid);
  MergeSort(arr, mid + 1, high);
  Merge(arr, low, mid, high);
}

int main() {
  vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4};
  int n = arr.size();
  MergeSort(arr, 0, n - 1);
  for (int i = 0; i < 9; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}