#include<bits/stdc++.h>

using namespace std;

#define MAX 1001

int n,obj[MAX],cost[MAX],cap ;

int dp[MAX][31] ;

int knapshak(int i,int w)
{
    int prof1,prof2;

    if(i==n+1)

        return 0;

    if(dp[i][w]!=-1)

        return dp[i][w] ;

    if(obj[i]<=w)
    {
        prof1 = cost[i]+knapshak(i+1,w-obj[i]) ;
    }

    else
        prof1 = 0 ;

    prof2 = knapshak(i+1,w) ;

    dp[i][w] = max(prof1,prof2) ;

    return dp[i][w] ;
}

int main()
{
    int t,num_mem,i;

    cin >> t ;

    ofstream fcout("file.txt") ;

    while( t-- )
    {
        memset(dp,-1,sizeof(dp));
        cin >> n ;

        for(i=1;i<=n;i++)

            cin  >> cost[i] >> obj[i] ;

        cin >> num_mem ;

        int sum = 0 ;

        for(i=1;i<=num_mem;i++)
        {
            cin >> cap ;

            sum += knapshak(1,cap);
        }
        fcout << sum << endl;
    }
    return 0;
}
