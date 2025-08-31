#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end) {
  while (start <= end) {
    if (s[start] != s[end]) {
      return false;
    }

    start++;
    end--;
  }

  return true;
}

// valid palindrome partition
void Partition(vector<vector<string>>& res, vector<string>& path,
               string s,  // Fixed: path passed by reference
               int index) {
  // base case
  if (index == s.size()) {
    res.push_back(path);
    return;
  }

  for (int i = index; i < s.size(); i++) {
    if (isPalindrome(s, index, i)) {
      path.push_back(s.substr(
          index,
          i - index + 1));  // Fixed: start from index, length is i-index+1
      Partition(res, path, s, i + 1);
      path.pop_back();
    }
  }
}

int main() {
  vector<vector<string>> res;
  vector<string> path;
  string s = "aab";
  Partition(res, path, s, 0);
  for (int i = 0; i < res.size(); i++) {
    cout << "{ ";
    for (int j = 0; j < res[i].size();
         j++) {  // Fixed: use res[i].size() instead of res[0].size()
      cout << res[i][j] << " ";
    }
    cout << "}";
    cout << endl;
  }
  return 0;
}