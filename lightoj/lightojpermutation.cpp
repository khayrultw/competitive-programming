#include<bits/stdc++.h>

using namespace std;

int num[100],n,k ;
bool used[100];

void permutation(int pos)
{
    if(k==0)
        return ;
    if(pos==n+1)
    {
        k--;
        for(int i=1;i<=n;i++)
            printf("%c",num[i]+64);
        cout << endl;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!used[i])
        {
            num[pos] = i ;
            used[i] = true ;
            permutation(pos+1);
            used[i] = false ;
        }
    }
}

int main()
{
    int t,cas=0;
    cin >> t ;
    while( ++cas<=t )
    {
        memset(used,false,sizeof(used)) ;
        cin >> n >> k ;
        cout << "Case " << cas << ":\n" ;
        permutation(1);
    }
    return 0;
}
