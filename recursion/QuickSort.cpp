#include <bits/stdc++.h>
using namespace std;

int PartitionIndex(vector<int>& arr, int low, int high) {
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
    // if i and j haven't crossed then kindly swap the elements
    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[low], arr[j]);
  return j;
}

void QuickSort(vector<int>& arr, int low, int high) {
  if (low < high)  // this condition only mean that the array is not empty
  {
    int pIndex = PartitionIndex(arr, low, high);
    QuickSort(arr, low, pIndex - 1);
    QuickSort(arr, pIndex + 1, high);
  }
}

int main() {
  vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
  int low = arr[0];
  int high = arr.size() - 1;
  QuickSort(arr, 0, high);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  return 0;
}