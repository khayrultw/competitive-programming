#include<bits/stdc++.h>

using namespace std;

int num[100],n ;
bool used[100];

void permutation(int pos)
{
    if(pos==n+1)
    {
        for(int i=1;i<=n;i++)
            cout << num[i] << " " ;
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
    memset(used,false,sizeof(used)) ;
    while(cin >> n)
    {
        permutation(1);
        cout << endl;
    }
    return 0;
}
