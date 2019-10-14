#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, h, m;
    cin >> n >> h >> m;
    vector<int> v(n+1, h);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        for(int i = a; i <= b; i++){
            v[i] = min(v[i], c);
        }
    }
    long long sum = 0;
    for(int i = 1; i <= n; i++)
        sum += v[i]*v[i];
    cout << sum << endl;
    return 0;
}