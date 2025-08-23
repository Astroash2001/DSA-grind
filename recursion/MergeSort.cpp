#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int>& arr, int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  vector<int> res;
  //we push the smaller element into the result vector
  while (left <= mid && right <= high) {

    //here we are comparing the left sorted half 
    //with the right one and if the left element is smaller 
    // then we push the element in the result vector
    if (arr[left] <= arr[right]) { 
      res.push_back(arr[left]);
      left++;
    }
    // if the element of the right vector is smaller
    // then we push it in the result vector 
    else {
      res.push_back(arr[right]);
      right++;
    }
  }

  //if the elements of the left sorted array is over 
  //then push all the remaining elements of the right
  // subarray to the result vector
  while (left <= mid) {
    res.push_back(arr[left]);
    left++;
  }

  // if the elements of the right sorted array is over
  // then push all the remaining elements of the left
  //  subarray to the result vector

  while (right <= high) {
    res.push_back(arr[right]);
    right++;
  }
  for (int i = low; i <= high; i++) {
    arr[i] = res[i - low];
  }
}

void MergeSort(vector<int>& arr, int low, int high) {
  // base case for the recursion
  if (low >= high) {
    return;
  }

  int mid = (low + high) / 2;
  MergeSort(arr, low, mid);       // sorting from starting to middle
  MergeSort(arr, mid + 1, high);  // sorting from mid to the end
  Merge(arr, low, mid, high);  // after both the parts are being sorted then we
                               // will be merging the subarrays
}

int main() {
  vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4};
  MergeSort(arr, 0, 9);
  for (int i = 0; i < 9; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}