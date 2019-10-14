#include <iostream>
#include <cstdio>

using namespace std;

template<class X>
class Queue{
    X arr[10000];
    int _front, _back;
    public:
    Queue(){
        _front = _back = -1;
    }
    void push(X v){
        _back = (_back+1)%10000;
        arr[_back] = v;
    }

    X front(){
        return arr[(_front+1)%10000];
    }

    void pop(){
        if(!empty()){
            _front = (_front+1)%10000;
        }
    }

    bool empty(){
        return _front == _back;
    }
};

 typedef struct Pair{
    int x, y;
    Pair(){}
    void make_pair(int a, int b){
        x = a;
        y = b;
     }
}Pair;

int r, c;

bool grid[1001][1001];
int dist[1001][1001];


bool isvalid(int x, int y){
    if(x < 0 || y < 0 || x >= r || y >= c)
        return false;
    if(grid[x][y])
        return false;
    return true;
    
}

void bfs(Pair u){
    dist[u.x][u.y] = 0;
    grid[u.x][u.y] = true;
    Queue<Pair> que;
    que.push(u);
    while(!que.empty()){
        Pair tmp = que.front();
        que.pop();
        //cout << tmp.x << " k " << tmp.y << endl;
        int cost = dist[tmp.x][tmp.y]+1;
        if(isvalid(tmp.x-1, tmp.y)){
            tmp.x--;
            que.push(tmp);
            dist[tmp.x][tmp.y] = cost;
            grid[tmp.x][tmp.y] = true;
            tmp.x++;
        }
        if(isvalid(tmp.x+1, tmp.y)){
            tmp.x++;
            que.push(tmp);
            dist[tmp.x][tmp.y] = cost;
            grid[tmp.x][tmp.y] = true;
            tmp.x--;
        }
        if(isvalid(tmp.x, tmp.y-1)){
            tmp.y--;
            que.push(tmp);
            dist[tmp.x][tmp.y] = cost;
            grid[tmp.x][tmp.y] = true;
            tmp.y++;
        }
        if(isvalid(tmp.x, tmp.y+1)){
            tmp.y++;
            que.push(tmp);
            dist[tmp.x][tmp.y] = cost;
            grid[tmp.x][tmp.y] = true;
            tmp.y--;
        }
    }
}
int main(){
    
    while(cin >> r >> c && (r != 0 || c != 0)){
        int rw;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                grid[i][j] = false;
            
        cin >> rw;
        for(int i = 0; i < rw; i++){
            int row, tmp, n;
            cin >> row >> n;
            while(n--){
                cin >> tmp;
                grid[row][tmp] = true;
            }
        }
        Pair p[2];
        cin >> p[0].x >> p[0].y;
        cin >> p[1].x >> p[1].y;
        bfs(p[0]);
        cout << dist[p[1].x][p[1].y] << endl;
        // for(int i = 0; i < r; i++){
        //     for(int j = 0; j < c; j++)
        //         cout << dist[i][j] << " ";
        //     cout << endl;
        // }

    }
    return 0;
}