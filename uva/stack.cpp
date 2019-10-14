#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

int main(){
    Int t, n, m, x;
    Int tmp;
    cin >> t;
    while(t--){
        queue<Int> a, b;
        cin >> n >> m >> x;
        for(int i = 0; i < n; i++)
        {
            cin >> tmp;
            a.push(tmp);
        }
        for(int i = 0; i < m; i++){
            cin >> tmp;
            b.push(tmp);
        }
        Int ans = 0, sum = 0;
        while(!a.empty() && !b.empty()){
            if(a.front() <= b.front()){
                sum += a.front();
                a.pop();
            }
            else  {
                sum += b.front();
                b.pop();
            }
            if(sum > x)
                break;
            ans++;
        }
        while(!a.empty()){
            sum += a.front();
            a.pop();
            if(sum > x)
                break;
            ans++;
        }

        while(!b.empty()){
            sum += b.front();
            b.pop();
            if(sum > x)
                break;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}