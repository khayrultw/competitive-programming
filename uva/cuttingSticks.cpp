#include<bits/stdc++.h>

using namespace std;
#define INF 1<<31-1
int num[51],cut[51],sum,x,n;
bool used[1000] ;

int cutSticks(int low,int high,int att)
{
    int minn = INF ;
    if(att==n+1)
        return 0;
    for(int i=1;i<=n;i++)
    {
        if(used[num[i]])
        {
            used[num[i]] = false ;
            sum+=high-low+cutSticks(low,num[i],att+1);
            sum+=high-low+cutSticks(num[i],high,att+1);
            if(sum<minn){
                minn = sum ;
                x=num[i];
            }
            used[num[i]] = true ;
        }
    }
    cut[att] = x ;
    return minn;
}

int main()
{
    int t,i;
    while( cin >> t )
    {
        cin >> n ;
        for(i=1;i<=n;i++)
            cin >> num[i] ;
        cutSticks(0,t,1) ;

    }
    for(i=1;i<=n;i++)
    {
        cout << cut[i] << endl;
    }
}
