#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    freopen("out.txt", "w", stdout);
    cin >> t;
    while(t--){

        cin >> n;
        vector<int> a(n), b(n), ans(n);
        for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
        int tmp = 0;
        for(int i = n-1; i >= 0; i--){

            int x = a[i]+b[i]+tmp;
            ans[i] = x%10;
            tmp = x/10;
        }
        if(tmp) cout << tmp;
        for(int i = 0; i < n; i++) cout << ans[i];
        cout << endl;
        if(t) cout << endl;
    }
    return 0;
}
