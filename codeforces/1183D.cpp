#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        map<int, int> fr;
        int n, x;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x;
            fr[x]++;
        }

        map<int, int> frf;
        for(auto m: fr)
            frf[m.second]++;
        
        vector<pair<int, int>> v;
        v.push_back(make_pair(0, 0));
        for(auto m: frf)
            v.push_back(m);


        long long sum = 0;
        int indx = v.size() - 1;
        int last = v[indx].first;
        while(indx--){
            int k = last - v[indx].first;
            int l = v[indx+1].second;
            while(k-- && l--){
                sum += last--;
            }
            last = v[indx].first;
        }
        cout << sum << endl;
    }
    return 0;
}