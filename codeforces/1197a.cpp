#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        if(n <= 2)
        {
            cout << 0 << endl;
            continue;
        }

        sort(v.begin(), v.end());
        int ans = min(n-2, v[n-2]-1);
        cout << ans << endl;
    }
    return 0;
}