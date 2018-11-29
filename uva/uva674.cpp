#include<bits/stdc++.h>

using namespace std;

int money[] = {0,50,25,10,5,1};

int dp[7490][6],make;

int makeMoney(int i,int left)
{
    if(left==0)
    {
        dp[left][i] = 1 ;
        return 1;
    }

    if(left<0 || i == 6 )

        return 0;

    if(dp[left][i]!=-1)
    {
        return dp[left][i] ;
    }

    int a,b;

    if(left>=money[i])
    {
        a = makeMoney(i,left-money[i]) ;
    }
    else
        a = 0;

    b = makeMoney(i+1,left) ;

    dp[left][i]=a+b ;

    return dp[left][i];
}

int main()
{
    ofstream fcout("file.txt");

    memset(dp,-1,sizeof(dp)) ;

    for(int i=0;i<7490;i++)

        makeMoney(1,i) ;

    while( cin >> make )
    {

        fcout << dp[make][1] << endl;
    }
    return 0;
}
