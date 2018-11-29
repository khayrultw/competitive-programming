#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long num[101],sum,i,j,t,cas=0,n;
    cin >> t ;
    FILE *fp = fopen("file.txt","w");
    while( ++cas<=t )
    {
        cin >> n ;
        for(i=1;i<=n;i++)
            cin >> num[i] ;
        long long mx = 0;
        for(i=1;i<=n;i++)
        {
            sum=0;
            for(j=1;j<=i;j++)
            {
                sum^=num[j] ;
                cout << sum << " " << mx << endl;
                if(mx<sum)
                {
                    mx=sum;
                }
            }
        }
        for(i=n;i>0;i--)
        {
            sum=0;
            for(j=i;j<=n;j++)
            {
                sum^=num[j] ;
                cout << sum << " " << mx << endl;
                if(mx<sum)
                {
                    mx=sum;
                }
            }
        }
        fprintf(fp,"Case %lld: %lld\n",cas,mx);
    }
    fclose(fp);
    return 0;
}
