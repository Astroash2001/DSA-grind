#include <bits/stdc++.h>
using namespace std;

void print2N(int n)
{
    if(n == 1)
    {
        cout << 1 << " ";
       return;
    }

    
    print2N(n-1);
    cout << n << " ";
}


int main() 
{
    int n ;
    cout << "Enter to which place to want the number to be printed recursively";
    cout << endl;
    cin >> n;
    print2N(n);


    return 0; 
}