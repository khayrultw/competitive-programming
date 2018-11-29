#include<bits/stdc++.h>

using namespace std;

int logg2(int n)
{
    if(n==0 || n==1)
        return 0;
    return 1+logg2(n/2) ;
}

int pow2(int p)
{
    if(p==0)
        return 1 ;
    return 2*pow2(p-1) ;
}

int main()
{
    int n,t,i=0,ceo,power;
    cin >> t ;
    while( ++i<=t )
    {
        ceo=0;
        cin >> n ;
        while(n>1)
        {
            power = logg2(n) ;
            ceo++;
            if(n==pow2(power+1)-1)
                break;
            n = n-pow2(power)+1 ;

        }
        if(n==1)
            ceo++;
        cout << "Case " << i << ": " << ceo << endl;
    }
    return 0;
}
