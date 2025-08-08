#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int>& arr, int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;
  while (i < j) {
    while (arr[i] <= pivot && i <= high - 1) {
      i++;
    }
    while (arr[j] > pivot && j >= low + 1) {
      j--;
    }

    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }

  // swapping the pivot
  swap(arr[low], arr[j]);
  return j;
}

void QuickSort(vector<int>& arr, int low, int high) {
  if (low < high) {
    int pIndex = Partition(arr, low, high);
    QuickSort(arr, low, pIndex - 1);
    QuickSort(arr, pIndex + 1, high);
  }
}

int main() {
  vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4};
  int n = arr.size();
  QuickSort(arr, 0, n - 1);
  for (auto it : arr) {
    cout << it << " ";
  }

  return 0;
}