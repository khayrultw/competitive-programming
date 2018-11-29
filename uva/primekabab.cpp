#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,i,sum,root;
    while(cin >> n && n!=1)
    {
        sum = 0 ;
        while(!(n&1))
        {
            sum++;
            n=n/2;
        }
        root = sqrt(n) ;
        for(i=3;i<=root;)
        {
            if(n%i==0)
            {
                n/=2;
                sum++;
            }
            else
                i+=2;
        }
        if(n>1)
            sum++ ;
        cout << sum << endl;
    }
    return 0;
}
