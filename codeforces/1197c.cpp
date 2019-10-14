#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

bool cmp(const pair<lint, lint> a, const pair<lint, lint> b)
{
    return a.second > b.second;
}

int main()
{
    lint n, k;
    cin >> n >> k;
    vector<lint> v(n);

    for(lint i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<pair<lint, lint>> big;
    for(lint i = 0; i < n-1; i++)
    {
        big.push_back({i, v[i+1]-v[i]});
    }
    sort(big.begin(), big.end(), cmp);
    bool flag[n];
    memset(flag, false, sizeof(flag));
    for(int i = 0; i < k-1; i++)
        flag[big[i].first] = true;
    
    lint prev = 0;
    lint ans = 0;
    for(int i = 0; i < n; i++)
    {
       // cout << i << endl;
        if(flag[i])
        {
            //cout << i << endl;
            ans += v[i] - v[prev];
            //cout << ans << endl;
            prev = i+1;
        }
    }
    ans += v[n-1] - v[prev];
    cout << ans << endl;
    return 0;
}