#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

typedef long long lint;

lint n;

lint pow10(lint a){
    if(a == 0)
        return 1;
    return (1LL*10*pow10(a-1))%MOD;
}

lint go(lint x)
{
    lint i = 0;
    lint ans = 0;
    while(x)
    {
        i++;
        lint tmp = x%10;
        x /= 10;
        ans = (ans + (n*tmp*pow10(2*i-1))%MOD)%MOD;
        ans = (ans + (n*tmp*pow10(2*i-2))%MOD)%MOD;
        //cout << ans << endl;
    }
    return ans;
}
int main(){
    lint tmp, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        ans = (ans + go(tmp)) % MOD;
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}