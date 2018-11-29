#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,i,j,mat[1001][1001],ima[1000][1000],sum,tmp ;
    bool f = false ;
    while(cin >> n >> m )
    {
        for(j=0;j<=n;j++)
            mat[j][0]=0;

        for(i=n;i>0;i--)
        {
            sum=0;
            for(j=1;j<=n;j++)
            {
                cin >> tmp ;
                sum+=tmp;
                mat[i][j] = sum ;
            }
        }
        tmp = n-m+1 ;
        long long sumt= 0 ;
        if(f)
            cout << endl;
        f = true;
        for(int k=0;k<tmp;k++)
        {
            for(j=0;j<tmp;j++)
            {
                sum=0;
                for(i=n-k;i>=n-m-k+1;i--)
                {
                    sum+=mat[i][j+m]-mat[i][j];
                }
                sumt+=sum ;
                cout << sum << endl;
            }
        }
        cout << sumt << endl;
    }
    return 0;
}
