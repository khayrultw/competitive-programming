#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    bool ans[n];
    memset(ans, false, sizeof(ans));
    vector<pair<char, int>> v;
    string str;
    cin >> str;
    int k = 0;
    for(auto i: str){
        v.push_back(make_pair(i, k++));
    }
    
}