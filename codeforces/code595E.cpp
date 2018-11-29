#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, sum;
    cin >> n;
    if(n==2)
        sum = 1;
    else if(n < 5)
        sum = n;
    else
    {
        sum = 8 + 2*(n-5);
    }
    cout << sum << endl;
}