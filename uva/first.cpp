#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,num[101];
    cin >> n >> k ;
    for(int i=1;i<=n;i++)
        cin >> num[i];
    int max = -1;
    bool f = true;
    for(int i=1;i<=n;i++)
    {
        if(num[i]==k)
            f = false ;
        if(max<num[i])
            max = num[i];
    }
    int ans = max+1-n;
    if(!f)
        ans++;
    else
        ans--;
    if(ans<0)
        ans = 0;
    if(k>max)
        ans = k - max - 1;
    cout << ans << endl;
    return 0;
}
    
