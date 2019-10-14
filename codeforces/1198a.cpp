#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

int main()
{
    lint t, a, b, c;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        lint ans;
        lint temp = abs(b-c);
        if(temp <= a)
            ans  = min(b, c)+temp+(a-temp)/2;
        else  
            ans  = min(b, c)+a;
        
        temp = abs(a-c);

        if(temp <= b)
        {
            ans  = max(ans, min(a, c)+temp+(b-temp)/2);
        }
        else  
            ans = max(ans, min(a, c) + b);
        
        temp = abs(a-b);

        if(temp <= c)
        {
            ans  = max(ans, min(a, b)+temp+(c-temp)/2);
        }
        else  
            ans = max(ans, min(a, b) + c);

        cout << ans << endl;
    
    }
    return 0;
}