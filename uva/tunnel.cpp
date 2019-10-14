#include <bits/stdc++.h>

using namespace std;

vector<int> graph[51];
bool visit[51];
int r, t;

int countzero(int v){
    int k = 0;
    for(auto u: graph[v])
        if(!u)
            k++;
    return k;
}
int bfs(int root){
    //visit[0] = true;
    visit[root] = true;
    int ans = (int)graph[root].size();
    queue<pair<int, int>> que;

    que.push({root, countzero(root)});
    while(!que.empty()){
        pair<int, int> u = que.front();
        que.pop();
        int ans_temp = INT_MIN;
        for(auto v: graph[u.first]){
            if(!visit[v]){
                ans_temp = max(ans_temp, u.second+(int)graph[v].size());
                //cout << ans_temp << endl;
                visit[v] = true;
                que.push({v, u.second + countzero(v)});
            }
            if(ans_temp != INT_MIN)
                ans = min(ans, ans_temp);
        }
        
    }
    return ans;
}
int main()
{
    int cas = 0;
    while(cin >> r >> t && (r!=0 || t!=0)){
        for(int i = 0; i < t; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        memset(visit, false, sizeof(visit));
        cout << "Case " << ++cas << ": " << min((int)graph[0].size(), bfs(1)) << "\n\n";
        for(int i = 0; i < 51; i++)
            graph[i].clear();
    }
    return 0;
}