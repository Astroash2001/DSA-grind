#include <bits/stdc++.h>
using namespace std;

vector<int> arr = {1, 2, 3, 4, 5};
int n = arr.size();

// the below approach uses two variables
void ReverseArr(vector<int>& arr, int l, int r) {
  if (l >= r) {
    return;
  }

  swap(arr[l], arr[r]);
  ReverseArr(arr, l + 1, r - 1);
}

// the below approach uses one variable only
void ReverseByOneVariable(vector<int>& arr, int i) {
  if (i >= n / 2) return;
  swap(arr[i], arr[n - i - 1]);
  ReverseByOneVariable(arr, i + 1);
}

int main() {
  cout << "The reversed array is:" << endl;
  //   ReverseArr(arr, 0, arr.size() - 1);
  ReverseByOneVariable(arr, 0);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  return 0;
}