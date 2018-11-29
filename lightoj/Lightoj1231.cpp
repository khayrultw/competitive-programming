#include<bits/stdc++.h>

using namespace std;

int dp[1001][51],make,money[51],mmax[51],n ;

int makeMoney(int i,int left,int taken)
{
    if(left==0)
    {
        dp[left][i] = 1 ;
        return 1;
    }

    if(left<0 || i == n+1 )

        return 0;

    if(dp[left][i]!=-1)
    {
        return dp[left][i] ;
    }

    int a,b;

    if(taken<=mmax[i] && left>=money[i])
    {
        a = makeMoney(i,left-money[i],taken+1) ;
    }
    else
        a = 0;

    b = makeMoney(i+1,left,1) ;

    dp[left][i]=(a+b)%100000007 ;

    return dp[left][i];
}

int main()
{
    //ofstream fcout("file.txt");
    int t,cas=0,make,i;
    cin >> t ;
    while( ++cas<=t )
    {
        memset(dp,-1,sizeof(dp)) ;
        scanf("%d%d",&n,&make);

        for(i=1;i<=n;i++)
        {
            scanf("%d",&money[i]) ;
        }

        for(i=1;i<=n;i++)
        {
            scanf("%d",&mmax[i]) ;
        }
        printf("Case %d: %d\n",cas,makeMoney(1,make,1));
    }
    return 0;
}

