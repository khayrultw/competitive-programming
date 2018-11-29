#include<bits/stdc++.h>

using namespace std;
int arr[11][11],n;
bool vis[11],f;
int check(int a,int b)
{
     int sum=0;
     for(int i=1;i<=n;i++)
     {
        //cout << "NO1" << endl;
        if(a<=n-i+1)
        for(int j=1;j<=n;j++)
        {
            //cout << "NO2" << endl;
            if(b<=n-j+1)
            {
                f = false;
                memset(vis,false,sizeof(vis));
                for(int x=i;x<a+i;x++)
                {
                    //cout << "NO3" << endl;
                    for(int y=j;y<j+b;y++)
                    {
                        //cout << "NO4" << endl;
                        if(vis[arr[x][y]])
                        {
                            f = true;
                                break;
                        }
                        vis[arr[x][y]] = true;
                    }
                    if(f)
                        break;
                }
                if(!f)
                    sum++;
            }
        }
     }
     return sum;
}
int main()
{
    int t,cas=0,i,j;

    cin >> t;
    while(++cas<=t)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin >> arr[i][j];
            }
        }
        int sum=0;
        if(n<5)
            goto l1;
        if(n!=10)
            goto l2;
        sum += check(1,10);
        sum += check(10,1);
    l2: sum += check(2,5);
        sum += check(5,2);
    l1: printf("Case %d: %d\n",cas,sum);
    }
    return 0;
}
