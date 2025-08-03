#include <bits/stdc++.h>
using namespace std;

void Nto1(int n)
{
  if(n == 1)
  {
      cout << 1 <<" ";
      return ;
  }

  cout << n<<" ";
  Nto1(n-1);
}


int main()
{
  int n ;
  cout << "ENter the number to which you want the counting to:"<<endl;\
  cin >> n;
  Nto1(n);

  return 0;
}