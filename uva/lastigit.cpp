#include<bits/stdc++.h>

using namespace std;

int BigMod(int n);

int main()
{
    int n,d ;
    while(cin >> n)
    {
        d = BigMod(n) ;
        cout << d << endl;
    }
    return 0;
}

int BigMod(int n)
{
    if(n==1)
        return 1;
    int x = n ;
    while(x%10==0)
    {
        x=x/10 ;
    }
    cout << x << " x " << endl;
    int tmp = x%10*BigMod(n-1) ;
    if(tmp%10==0)
        tmp=tmp/10;
    cout <<tmp << " " << tmp%10 << "t" << endl;
    return tmp%10 ;
}
