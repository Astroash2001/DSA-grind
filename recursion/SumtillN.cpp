#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
  if(n == 0)
  {
    return 0;
  }

  return n + sum(n-1);
}


int main()
{
  int n ;
  cout << "Number to which you want the sum to:" <<endl;
  cin >> n;
  cout << sum(n);



  return 0;
} 