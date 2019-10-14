#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.first < b.first;
}
int main(){
    int n, m;
    vector<pair<int, int>> v1, v2;
    cin >> n >> m;
    for(int i = 0; i < m ;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a)
            v1.push_back(make_pair(b, c));
        else  
            v2.push_back(make_pair(b, c));
    }
    int ans[n+1];
    for(int i = 0; i < n; i++)
        ans[i+1] = n-i;
    sort(v1.begin(), v1.end(), cmp);
    for(auto tmp: v1){
        for(int i = tmp.first+1; i <= tmp.second; i++)
            ans[i] = ans[tmp.first];
    }

    for(auto tmp: v2){
        bool f = false;
        for(int i = tmp.first; i < tmp.second; i++){
            if(ans[i] > ans[i+1]){
                f = true;
                break;
            }
        }
        if(!f){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}