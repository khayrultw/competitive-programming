#include<bits/stdc++.h>

using namespace std;

bool check(int n,int bit)
{
    return n&(1<<bit) ;
}

int main()
{
    int n, result,i;
    while( cin >> n )
    {
        result = 0 ;
        for(i=7;i>=0;i--)
        {
            if(check(n,i)==1)
            {
                result = result | 1 ;
            }
            result = result << 1 ;
        }
        for(i=15;i>=8;i--)
        {
            if(check(n,i)==1)
            {
                result = result | 1 ;
            }
            result = result << 1 ;
        }
        for(i=23;i>=16;i--)
        {
            if(check(n,i)==1)
            {
                result = result | 1 ;
            }
            result = result << 1 ;
        }
        for(i=31;i>=24;i--)
        {
            if(check(n,i)==1)
            {
                result = result | 1 ;
            }
            if(i!=24)
                result = result << 1 ;
        }
        cout << n << " converts to " << result << endl;
    }
    return 0;
}
