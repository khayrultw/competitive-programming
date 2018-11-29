#include<bits/stdc++.h>

using namespace std;

struct node{

    int u, v, cost;
};

vector<node> gp;
int n, m, t, a, b, c;
int dist[1001];

bool bell(){

    dist[0] = 0;
    for(int i = 1; i < n; i++){

        for(int j = 0; j < m; j++){

            if(dist[gp[j].v]>dist[gp[j].u]+gp[j].cost){

                dist[gp[j].v] = dist[gp[j].u]+gp[j].cost;
            }
        }
    }
    for(int j = 0; j < m; j++){

        if(dist[gp[j].v]>dist[gp[j].u]+gp[j].cost){

            return false;
        }
    }
    return true;
}

int main(){

    cin >> t;
    node tmp;
    while(t--){

        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++){

            scanf("%d%d%d", &a, &b, &c);
            tmp.u = a;
            tmp.v = b;
            tmp.cost = c;
            gp.push_back(tmp);
        }
        memset(dist, INT_MAX, sizeof(dist));
        if(!bell())
            printf("possible\n");
        else
            printf("not possible\n");
        gp.clear();

    }
    return 0;
}
