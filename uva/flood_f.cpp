#include<bits/stdc++.h>

using namespace std;

int danger,n ;
char str[502][502] ;
void dfs2(int i,int j) ;

void dfs1(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=n)
        return ;
    if(str[i][j]=='#')
    {
        str[i][j] = '.' ;
        if(str[i+1][j]=='*')
        {
            danger++;
            dfs2(i+1,j) ;
        }
        if(str[i][j+1]=='*')
        {
            danger++;
            dfs2(i,j+1) ;
        }
        if(str[i][j-1]=='*')
        {
            danger++;
            dfs2(i,j-1) ;
        }
        if(str[i-1][j]=='*')
        {
            danger++;
            dfs2(i-1,j) ;
        }
        if(str[i+1][j+1]=='*')
        {
            danger++;
            dfs2(i+1,j+1) ;
        }
        if(str[i-1][j-1]=='*')
        {
            danger++;
            dfs2(i-1,j-1) ;
        }
         if(str[i+1][j-1]=='*')
        {
            danger++;
            dfs2(i+1,j-1) ;
        }
         if(str[i-1][j+1]=='*')
        {
            danger++;
            dfs2(i-1,j+1) ;
        }
        dfs1(i+1,j);
        dfs1(i,j+1);
        dfs1(i-1,j);
        dfs1(i,j-1);
        dfs1(i+1,j+1);
        dfs1(i-1,j-1);
        dfs1(i+1,j-1);
        dfs1(i-1,j+1);
    }
}

void dfs2(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=n)
        return ;
    if(str[i][j]=='*')
    {
        str[i][j] = '.' ;
        dfs2(i+1,j);
        dfs2(i,j+1);
        dfs2(i-1,j);
        dfs2(i,j-1);
    }
}

int main()
{
    int t,flood,cas=0,i,j ;
    cin >> t ;
    while( ++cas<=t )
    {
        danger=flood=0;
        cin >> n ;
        for(i=0;i<n;i++)
            cin >> str[i] ;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(str[i][j]=='#')
                {
                    flood++;
                    dfs1(i,j) ;
                }
            }
        }
        cout << "Case " << cas << ": " << flood << " " << danger << endl;
    }
    return 0;
}
