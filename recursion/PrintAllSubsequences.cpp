#include <bits/stdc++.h>
using namespace std;

void AllSubsequences(int index, vector<int>& sub, int arr[], int n) {
  //base case 
  if (index == n) {
    for (auto it : sub) {
      cout << it << " ";
    }
    if (sub.size() == 0) {
      cout << "{}";
    }
    cout << endl;
    return;
  }
  //decision point
  // now we take a particular element in sub
  sub.push_back(arr[index]);
  AllSubsequences(index + 1, sub, arr, n);
  sub.pop_back();// this step is important because it undo's the take decision

  //not pick or not take condition, this element is not allowed 
  AllSubsequences(index + 1, sub, arr, n);
}

int main() {
  int arr[] = {3, 1, 2};
  int n = 3;
  vector<int> sub;
  AllSubsequences(0, sub, arr, n);

  return 0;
}