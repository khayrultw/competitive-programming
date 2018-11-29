#include<bits/stdc++.h>

using namespace std;
#define MAX 101
int main()
{
    int n,white[MAX],black[MAX],i,xsum ;
    while( cin >> n )
    {
        for(i=1;i<=n;i++)
            cin >> white[i] ;
        for(i=1;i<=n;i++)
            cin >> black[i] ;
        sum = 0 ;
        for(i=1;i<n;i++)
            sum ^= (black[i]-white[i])
    }
}
