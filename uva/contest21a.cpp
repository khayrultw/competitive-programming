#include<bits/stdc++.h>

using namespace std;

long long rev(long long n)
{
    long long sum = 0,fact=10;
    while(n)
    {
        sum = sum*fact+(n%10);
        //cout << sum << endl;
        n = n/10;
    }
    return sum;
}

int main()
{
    long long n;
    cin >> n;
    while(n%10==0)
        n = n/10;
    if(n==rev(n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
