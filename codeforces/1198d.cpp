#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        string str;
        cin >> n >> k;
        cin >> str;
        string color = "RGB";

        int change[n+1];
        change[0] = 0;

        int now = 0, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(str[i] != color[now])
            {
                sum++;
            }
            change[i+1] = sum;
            now = (now+1)%3;
        }

        int ans = INT_MAX;
        for(int i = 0; i+k-1 < n; i++)
        {
            ans = min(ans, change[i+k] - change[i]);
        }

        change[0] = 0;
        now = 1, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(str[i] != color[now])
            {
                sum++;
                
            }
            change[i+1] = sum;
            now = (now+1)%3;
        }


        for(int i = 0; i+k-1 < n; i++)
        {
            ans = min(ans, change[i+k] - change[i]);
        }

        change[0] = 0;
        now = 2, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(str[i] != color[now])
            {
                sum++;
                
            }
            change[i+1] = sum;
            now = (now+1)%3;
        }

        for(int i = 0; i+k-1 < n; i++)
        {
            ans = min(ans, change[i+k] - change[i]);
        }

        cout << ans << endl;
    }
    return 0;
}