#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {4,8,15,16,23,42};
    map<int, bool> mp, ch;
    for(int i = 0; i < 6; i++)
        ch[arr[i]] = true;
    vector<int> ans;
    cout << "? 1 2" << endl;
    fflush(stdout);
    int x;
    cin >> x;
    cout << "? 2 3" << endl;
    fflush(stdout);
    int y;
    cin >> y;
    int a, b;
    for(int i = 0; i < 6; i++){
        for(int j = i+1; j < 6; j++){
            if(arr[i]*arr[j] == y){
                a = arr[i];
                b = arr[j];
                goto L1;
            }
        }
    }
    L1: if(ch[x/a] && x/a!=a){
        ans.push_back(x/a);
        ans.push_back(a);
        ans.push_back(b);
        mp[x/a] = true;
        mp[a] = true;
        mp[b] = true;
    }
    else if(ch[x/b] && x/b!=b){
        ans.push_back(x/b);
        ans.push_back(b);
        ans.push_back(a);
        mp[x/b] = true;
        mp[a] = true;
        mp[b] = true;
    }
    cout << "? 3 4" << endl;
    fflush(stdout);
    cin >> x;
    ans.push_back(x/ans.back());
    mp[ans.back()] = true;
    cout << "? 4 5" << endl;
    fflush(stdout);
    cin >> x;
    ans.push_back(x/ans.back());
    mp[ans.back()] = true;
    for(int i = 0; i < 6; i++)
        if(!mp[arr[i]]) 
            ans.push_back(arr[i]);
    cout << "!";
    for(auto i: ans)
        cout << " " << i;
    cout << endl;
    return 0;
}