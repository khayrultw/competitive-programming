#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];
        vector<int> x = a;
        vector<int> y = b;
        vector<int> xx = a;
        reverse(xx.begin(), xx.end());
        vector<int> yy = b;
        reverse(yy.begin(), yy.end());
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        if(x == y && b <= a && yy <= xx)
            cout << "YES" << endl;
        else  
            cout << "NO" << endl;
    }
    return 0;
}