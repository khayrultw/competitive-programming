#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> flag(n+1, 0);
    vector<int> act(n+1);
    for(int i = 1; i <= k; i++){
        cin >> act[i];
        flag[act[i]]++;
    }
    
    int sum = 2*(n-1) + n;
    if(flag[1]){
        sum--;
        flag[1]--;
    }
    if(flag[2] > 1)
        sum--;
    for(int i = 2; i < n; i++){
        if(flag[i]){
            sum--;
            flag[i]--;
        }
        if(flag[i-1]) sum--;
        if(flag[i+1] > 1) sum--;
    }
    if(flag[n]){
        sum--;
    }
    if(flag[n-1])
        sum--;
    cout << sum << endl;
    return 0;
}