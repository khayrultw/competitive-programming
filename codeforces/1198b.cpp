#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

int main()
{
    lint t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<lint> v(n+1);
        for(int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }

        lint sum = 0;
        vector<lint> ans;
        for(int i = 1; i <= n; i++)
        {
            sum += v[i];
            if(sum%2 && k > 1)
            {
                ans.push_back(i);
                sum = 0;
                k--;
            }
        }
        if(k == 1 && sum%2)
        {
            cout << "YES" << endl;
            for(auto i: ans)
                cout << i << " ";
            cout << n << endl;
            continue; 
        }

        cout << "NO" << endl;
    }
    return 0;
}