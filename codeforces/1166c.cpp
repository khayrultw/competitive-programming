#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

int main(){
    int n;
    cin >> n;
    vector<lint> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        if(p[i] < 0)
            p[i] = -p[i];
    }
    sort(p.begin(), p.end());
    lint ans = 0;
    for(int i = 0; i < n; i++){
        lint indx = upper_bound(p.begin(), p.end(), 2*p[i])-p.begin();
        //cout << indx << endl;
        indx = (indx-i-1);
            ans += (lint)(indx>0)*indx;
    }
    cout << ans << endl;
    return 0;
}