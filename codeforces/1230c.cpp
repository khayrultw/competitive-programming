#include <bits/stdc++.h>

using namespace std;

int dom[7];
vector<int> gp[8];
int status[8];
int n, m;



void bfs(int u){
    queue<int> que;
    que.push(u);
    for(int i = 1; i < n; i++){
        if(dom[i]>0)
        {
            status[i] = i;
            dom[i]--;
        }
    }

    while(!que.empty()){
        u = que.front();
        que.pop();
        int k = status[u];
        
        for(auto v: gp[u]){
            
        }
    }
}

int main(){
    
    memset(status, false, sizeof(status));
    for(int i = 1; i < 7; i++){
        dom[i] = 6;
    }
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!status[i])
            bfs(i);
    }
}