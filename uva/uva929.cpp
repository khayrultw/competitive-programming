#include<bits/stdc++.h>

using namespace std;

#define _ <<" "<<

struct node{

    int a, b, c;
    node(int i, int j, int k){

        a = i;
        b = j;
        c = k;
    }
};

long long n, m, maze[1000][1000];
long long dist[1000][1000];

bool operator<(const node &a, const node &b){

    return a.c>b.c;
}
void bfs(node p){

    priority_queue<node> que;
    que.push(p);
    dist[1][1] = maze[1][1];
    while(!que.empty()){

        p = que.top();
        //cout << p.a _ p.b _ dist[p.a][p.b] << endl;

        que.pop();
        if(p.a+1<=n && dist[p.a+1][p.b]>dist[p.a][p.b]+maze[p.a+1][p.b]){

            que.push(node(p.a+1, p.b, maze[p.a+1][p.b]));
            dist[p.a+1][p.b]=dist[p.a][p.b]+maze[p.a+1][p.b];
            //cout << p.a+1 _ p.b  _ dist[p.a][p.b] _ dist[p.a+1][p.b] << endl;
        }

        if(p.a-1>=1 && dist[p.a-1][p.b]>dist[p.a][p.b]+maze[p.a-1][p.b]){

            que.push(node(p.a-1, p.b, maze[p.a-1][p.b]));
            dist[p.a-1][p.b]=dist[p.a][p.b]+maze[p.a-1][p.b];
            //cout << p.a-1 _ p.b _ dist[p.a][p.b] _ dist[p.a-1][p.b] << endl;
        }

        if(p.b-1>=1 && dist[p.a][p.b-1]>dist[p.a][p.b]+maze[p.a][p.b-1]){

            que.push(node(p.a, p.b-1, maze[p.a][p.b-1]));
            dist[p.a][p.b-1]=dist[p.a][p.b]+maze[p.a][p.b-1];
            //cout << p.a _ p.b-1 _ dist[p.a][p.b] _ dist[p.a][p.b-1] << endl;
        }
        if(p.b+1<=m && dist[p.a][p.b+1]>dist[p.a][p.b]+maze[p.a][p.b+1]){

            que.push(node(p.a, p.b+1, maze[p.a][p.b+1]));
            dist[p.a][p.b+1]=dist[p.a][p.b]+maze[p.a][p.b+1];
            //cout << p.a _ p.b+1 _ dist[p.a][p.b] _ dist[p.a][p.b+1] << endl;
        }
        //cout << endl;
    }

}

int main(){

    freopen("in.txt","r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){

        scanf("%d%d", &n, &m);
        for(int i = 1; i<=n; i++){

            for(int j = 1; j <= m; j++){

                scanf("%d", &maze[i][j]);
                dist[i][j] = INT_MAX;
            }
        }

        bfs(node(1, 1, maze[1][1]));
        printf("%d\n", dist[n][m]);
    }
    return 0;
}
