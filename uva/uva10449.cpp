
#include<bits/stdc++.h>

using namespace std;

struct node{

    int u, v, cost;
};

vector<node> gp;
int n, t, m;
long long dist[300], dist2[300];

void bell(){

    dist[1] = 0;
    for(int i = 1; i < t; i++){

        for(int j = 0; j < n; j++){

            if(dist[gp[j].u] != INT_MAX && dist[gp[j].v]>dist[gp[j].u]+gp[j].cost){

                dist[gp[j].v] = dist[gp[j].u]+gp[j].cost;
            }
        }
        for(int k = 1; k <= t; k++) dist2[k] = dist[k];
        //cout << endl;
    }
    for(int j = 0; j < n; j++){

        if(dist[gp[j].u] != INT_MAX && dist[gp[j].v]>dist[gp[j].u]+gp[j].cost){
            dist[gp[j].v] = dist[gp[j].u]+gp[j].cost;
        }
    }
}

int main(){

    node tmp;
    int cas = 0;
    freopen("in.txt","r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> t){

        vector<int> v(t+1);
        for(int i = 1; i <= t; i++){

            cin >> v[i];
        }
        cin >> n;
        for(int i = 0; i < n; i++){

            scanf("%d%d", &tmp.u, &tmp.v);
            tmp.cost = v[tmp.v]-v[tmp.u];
            tmp.cost = tmp.cost*tmp.cost*tmp.cost;
            //cout << "r" << tmp.cost << endl;
            gp.push_back(tmp);
        }
        for(int k = 1; k <= t; k++) dist[k] = INT_MAX;
        //cout << "hello"<< endl;
        bell();
        cin >> m;
        int k;
        cout << "Set #" << ++cas << endl;
        while(m--){

            cin >> k;
            if(dist[k] < dist2[k] || dist[k]<3 || dist[k] == INT_MAX)
                printf("?\n");
            else
                printf("%d\n", dist[k]);
        }
        gp.clear();

    }
    return 0;
}
