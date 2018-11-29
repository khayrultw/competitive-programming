#include<bits/stdc++.h>

using namespace std ;

#define INF 1<<30
#define MAX 1<<10
int dp[MAX][MAX];
int row[MAX],col[MAX],visited[MAX][MAX] ;

using namespace std;

int matrixChain(int beg,int end)
{
    if(beg>=end)
        return 0 ;
    if(visited[beg][end]==1)
        return dp[beg][end] ;
    int ans = INF ;
    for(int mid = beg;mid < end; mid++)
    {
        int operation_left = matrixChain(beg,mid) ;
        int operation_right = matrixChain(mid+1,end);
        int operation_total = operation_left + operation_right + row[beg]*col[mid]*col[end] ;
        ans = min(ans,operation_total) ;
    }
    dp[beg][end] = ans ;
    visited[beg][end] = 1 ;
    return dp[beg][end] ;
}

int main()
{
    memset(visited,0,sizeof(visited)) ;
    int i,n;
    cout << "Number of matrix : " ;
    cin >> n ;
    for(i=1;i<=n;i++)
           cin >> row[i] >> col[i] ;
    int multiply = matrixChain(1,n) ;
    cout << "Minimum : " << multiply << endl;
    return 0;
}
