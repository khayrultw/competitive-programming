#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, pr[200001], total=0, sum=0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        scanf("%lld", &pr[i]);
        total += pr[i];
    }
    for(int i=0; i<n; i++)
    {
        sum += pr[i];
        if(2*sum >= total)
        {
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}