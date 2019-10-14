#include <bits/stdc++.h>

using namespace std;

vector<int> gp[1001];
bool vis[1001][1001];
int n, m, s, t, k;
bool flag;
int cnt;

void bfs(int u){
    queue<int> que;
    que.push(u);
    while(!que.empty()){
        u = que.front();
        que.pop();
        for(auto v: gp[u]){
            if(!vis[u][v]){
                vis[u][v] = vis[v][v] = true;
                if(v == t)
                    cnt++;
                que.push(v);
            }
        }
    }
}

int main(){
    int cas;
    cin >> cas;
    while(cas--){
        cin >> n >> m >> s >> t >> k;
        int a, b;
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            gp[a].push_back(b);
            gp[b].push_back(a);
        }

        cnt = 0;
        memset(vis, 0, sizeof(vis));
        bfs(s);
        k = (k%3)?1+k/3:k/3;

        cout << cnt*k << endl;
    }
    return 0;
}