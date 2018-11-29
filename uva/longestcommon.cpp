#include<bits/stdc++.h>

using namespace std;

#define MAX 10000
string s1,s2;
int dp[MAX][MAX];

int longestCommon(int i,int j)
{
    if(dp[i][j]!=-1)
        return dp[i][j] ;
    if(i==s1.size() || j==s2.size())
        return 0;
    if(s1[i]==s2[j])
        return dp[i][j] =1+longestCommon(i+1,j+1) ;
     return dp[i][j] =max(longestCommon(i,j+1),longestCommon(i+1,j)) ;
}

int main()
{
    while(getline(cin,s1) && getline(cin,s2) )
    {
        memset(dp,-1,sizeof(dp)) ;
        cout << longestCommon(0,0) << endl;
        s1.clear();
        s2.clear();
    }
    return 0;
}
