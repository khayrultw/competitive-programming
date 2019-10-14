#include <bits/stdc++.h>

using namespace std;

pair<int,int> p[8];
bool flag[8];
int dist;

int go(int x, int y){
    int dis = INT_MAX;
    for(int i = 0; i < 8; i++){
        if(!flag[i]){
            int x = x-p[i].first;
            int y = y-p[i].second;
            flag[i] = true;
            dis = min(dis, x*x + y*y+go(p[i].first, p[i].second));
        }
        flag[i] = false;
    }
    if(dis == INT_MAX)
        return 0;
    return dis;
}

int main(){
    int n;
    while(cin >> n && n!=0){
        for(int i = 0; i < n; i++){
            cin >> p[i].first >> p[i].second;
        }
        memset(flag, false, sizeof(flag));
        dist = INT_MAX;
        go();
    }
}